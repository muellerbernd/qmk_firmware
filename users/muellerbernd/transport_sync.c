#include "transactions.h"
#include <string.h>
typedef union
{
    uint32_t raw;
    struct
    {
        bool isJumping : 1;
        bool isSneaking : 1;
        bool showedJump : 1;
    };
    // bool isScrolling : 1;
} user_runtime_config_t;

user_runtime_config_t user_state;

void keylogger_string_sync(uint8_t initiator2target_buffer_size,
                           const void *initiator2target_buffer,
                           uint8_t target2initiator_buffer_size,
                           void *target2initiator_buffer)
{
    if (initiator2target_buffer_size == KEYLOG_LEN)
    {
        memcpy(&keylog_str, initiator2target_buffer,
               initiator2target_buffer_size);
    }
}
void user_sync_a_slave_handler(uint8_t in_buflen, const void *in_data,
                               uint8_t out_buflen, void *out_data)
{
    // if buffer length matches size of data structure (simple error checking)
    if (in_buflen == sizeof(user_state))
    {
        // copy data from master into local data structure
        memcpy(&user_state, in_data, in_buflen);
    }
}
// void user_state_sync(uint8_t initiator2target_buffer_size,
//                      const void *initiator2target_buffer,
//                      uint8_t target2initiator_buffer_size,
//                      void *target2initiator_buffer)
// {
//     if (initiator2target_buffer_size == sizeof(transport_user_state))
//     {
//         memcpy(&transport_user_state, initiator2target_buffer,
//                initiator2target_buffer_size);
//     }
// }

void keyboard_post_init_user(void)
{
    transaction_register_rpc(RPC_ID_USER_KEYLOG_STR, keylogger_string_sync);
    // transaction_register_rpc(RPC_ID_USER_LUNA, user_sync_a_slave_handler);
}

void user_transport_update(void)
{
#ifdef LUNA_ENABLE
    if (is_keyboard_master())
    {

        user_state.isJumping = isJumping;
        user_state.isSneaking = isSneaking;
        user_state.showedJump = showedJump;
        // user_state.isScrolling = isScrolling;
    }
    else
    {
        isJumping = user_state.isJumping;
        isSneaking = user_state.isSneaking;
        showedJump = user_state.showedJump;
        // isScrolling = user_state.isScrolling;
    }
#endif // KEYLOGGER_ENABLE
}

void user_transport_sync(void)
{
    if (is_keyboard_master())
    {
        static char keylog_temp[KEYLOG_LEN] = {0};
        bool needs_sync = false;
        static uint32_t last_sync[2];
        // static user_runtime_config_t last_user_state;

        // Check if the state values are different
        if (memcmp(&keylog_str, &keylog_temp, KEYLOG_LEN))
        {
            needs_sync = true;
            memcpy(&keylog_temp, &keylog_str, KEYLOG_LEN);
        }
        if (timer_elapsed32(last_sync[0]) > 250)
        {
            needs_sync = true;
        }

        if (needs_sync)
        {
            if (transaction_rpc_send(RPC_ID_USER_KEYLOG_STR, KEYLOG_LEN,
                                     &keylog_str))
            {
                last_sync[0] = timer_read32();
                needs_sync = false;
            }
        }
        // luna sync
        // if value is different, then needs syncing
        // if (memcmp(&user_state, &last_user_state, sizeof(user_state)))
        // {
        //     needs_sync = true;
        //     // copy local user state to verify changes
        //     memcpy(&last_user_state, &user_state, sizeof(user_state));
        // }
        // // Send to slave every 250ms regardless of state change
        // if (timer_elapsed32(last_sync[1]) > 250)
        // {
        //     needs_sync = true;
        // }
        //
        // // if it needs syncing:
        // if (needs_sync)
        // {
        //     // send user_data stuct over to slave
        //     if (transaction_rpc_send(RPC_ID_USER_LUNA, sizeof(user_state),
        //                              &user_state))
        //     {
        //         // reset sync checks
        //         last_sync[1] = timer_read32();
        //         needs_sync = false;
        //     }
        // }
    }
}
void housekeeping_task_user(void)
{

    // Update kb_state so we can send to slave
    // user_transport_update();
    // Data sync from master to slave
    user_transport_sync();
}
// #endif // CUSTOM_SPLIT_TRANSPORT_SYNC
