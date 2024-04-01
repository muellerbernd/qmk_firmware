const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
    'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'z', 'y',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ',', '.', '-', ' ', ' ', ' '};

#define KEYLOG_LEN 6
// char keylog_str[KEYLOG_LEN] = {};
char keylog_str[KEYLOG_LEN] = {};
// uint8_t keylogs_str_idx = 0;
// uint16_t log_timer = 0;

void add_keylog(uint16_t keycode, keyrecord_t *record)
{
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX))
    {
        keycode = keycode & 0xFF;
    }

    // for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--)
    // {
    //     keylog_str[i] = keylog_str[i - 1];
    // }
    // if (keycode < 60)
    // {
    //     keylog_str[0] = code_to_name[keycode];
    // }
    // keylog_str[KEYLOG_LEN - 1] = 0;

    // if (record != NULL)
    // {
    keylog_str[0] = record->event.key.row + '0';
    keylog_str[1] = 'x';
    keylog_str[2] = record->event.key.col + '0';
    keylog_str[3] = ':';
    if (keycode < 60)
    {

        keylog_str[4] = code_to_name[keycode];
    }
    else
    {
        keylog_str[4] = ' ';
    }
    // }
    // else
    // {
    //     // matr_str[0] = '0';
    //     // matr_str[1] = 'x';
    //     // matr_str[2] = '0';
    //     // matr_str[3] = ':';
    //     // matr_str[4] = '-';
    // }
    // log_timer = timer_read();
}

// void update_log(void)
// {
//     if (timer_elapsed(log_timer) > 750)
//     {
//         add_keylog(0, NULL);
//     }
// }

void render_keylogger_status(void)
{
    // oled_write_P(PSTR("KLogr"), false);
    oled_write_ln(keylog_str, false);

    // oled_write_ln(keylog_str, false);
}
