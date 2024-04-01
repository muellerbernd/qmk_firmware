void render_logo(void)
{
    static const char PROGMEM font_qmk_logo[16] = {
        0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0xaa, 0xab, 0xac,
        0xad, 0xae, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0};
    oled_write_P(font_qmk_logo, false);
}

// 5x2 Keyboard, Controller logos

void render_keyboard(void)
{
    static const char PROGMEM font_keyboard[11] = {
        0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0};
    oled_write_P(font_keyboard, false);
};

void render_kb_split(void)
{
    static const char PROGMEM font_kb_split[11] = {
        0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0};
    oled_write_P(font_kb_split, false);
};

// 5x1 Layer indicator

void render_layer(void)
{
    static const char PROGMEM font_layer[4][6] = {
        {0x85, 0x86, 0x87, 0x88, 0x89, 0},
        {0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0},
        {0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0},
        {0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0},
    };
    uint8_t layer = 0;
    switch (get_highest_layer(layer_state))
    {
        case _RAISE:
            layer = 2;

            break;
        case _LOWER:

            layer = 1;

            break;
        case _ADJUST:
            layer = 3;
            break;
        default:
            layer = 0;
    }
    oled_write_P(font_layer[layer], false);
};
// 2x1 Ctrl, Alt, Shift, GUI, Mouse

void render_mod_ctrl(void)
{
    static const char PROGMEM font_ctrl[3] = {0x93, 0x94, 0};
    oled_write_P(font_ctrl, false);
};

void render_mod_alt(void)
{
    static const char PROGMEM font_alt[3] = {0xb3, 0xb4, 0};
    oled_write_P(font_alt, false);
};

void render_mod_shift(void)
{
    static const char PROGMEM font_shift[3] = {0xd3, 0xd4, 0};
    oled_write_P(font_shift, false);
};

void render_mod_gui(void)
{
    static const char PROGMEM font_gui[3] = {0x95, 0x96, 0};
    oled_write_P(font_gui, false);
};

#ifdef MOUSEKEY_ENABLE
void render_mod_mouse(void)
{
    static const char PROGMEM font_mouse[3] = {0x97, 0x98, 0};
    oled_write_P(font_mouse, false);
};
#endif

void render_mod_status(void)
{
#ifdef NO_ACTION_ONESHOT
    uint8_t modifiers = get_mods();
#else
    uint8_t modifiers = get_mods() | get_oneshot_mods();
#endif

    (modifiers & MOD_MASK_CTRL) ? render_mod_ctrl()
                                : oled_write_P(PSTR("  "), false);
    oled_write_P(PSTR(" "), false);
    (modifiers & MOD_MASK_SHIFT) ? render_mod_shift()
                                 : oled_write_P(PSTR("  "), false);

    (modifiers & MOD_MASK_ALT) ? render_mod_alt()
                               : oled_write_P(PSTR("  "), false);
    oled_write_P(PSTR(" "), false);
    (modifiers & MOD_MASK_GUI) ? render_mod_gui()
                               : oled_write_P(PSTR("  "), false);
}

void render_prompt(void)
{
    bool blink = (timer_read() % 1000) < 500;
    switch (get_highest_layer(layer_state))
    {
        case _RAISE:
            oled_write_ln_P(blink ? PSTR("> hi_") : PSTR("> hi "), false);
            break;
        case _LOWER:

            oled_write_ln_P(blink ? PSTR("> lo_") : PSTR("> lo "), false);

            break;
        case _ADJUST:
            oled_write_ln_P(blink ? PSTR("> aj_") : PSTR("> aj "), false);
            break;
        case _NAV:
            oled_write_ln_P(blink ? PSTR("> nv_") : PSTR("> nv "), false);
            break;
        default:
            oled_write_ln_P(blink ? PSTR("> _  ") : PSTR(">    "), false);
    }
};

static void print_status_narrow(void)
{
    /* Print current mode */
    oled_set_cursor(0, 0);

    /** oled_set_cursor(0, 3); */

    switch (get_highest_layer(default_layer_state))
    {
        case _QWERTZ:
            oled_write_P(PSTR("QWRTZ"), false);
            break;
        case _COLDH:
            oled_write_P(PSTR("COLDH"), false);
            break;
        default:
            oled_write_P(PSTR("UNDEF"), false);
    }

    oled_set_cursor(0, 3);

    /* Print current layer */
    oled_write_P(PSTR("LAYER"), false);

    oled_set_cursor(0, 4);

    switch (get_highest_layer(layer_state))
    {
        case _QWERTZ:
        case _COLDH:
            oled_write_P(PSTR("Base "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj  "), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav  "), false);
            break;
        case _POINTER:
            oled_write_P(PSTR("Ptr  "), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    // Host Keyboard LED Status
    led_t led_usb_state = host_keyboard_led_state();
    /* caps lock */
    oled_set_cursor(0, 7);
    oled_write_P(PSTR("CPSLK"), led_usb_state.caps_lock);

#ifdef KEYLOGGER_ENABLE
    oled_set_cursor(0, 10);
    // oled_write(luna_keylog_str, false);
    render_keylogger_status();
    // oled_write_ln(keylog_str, false);
#endif // KEYLOGGER_ENABLE

    // oled_write(get_u8_str(luna_keylog_str, '0'), false);

    /* KEYBOARD PET RENDER START */
#ifdef LUNA_ENABLE
    render_luna(0, 13, led_usb_state);
#endif
    /* KEYBOARD PET RENDER END */
}

bool oled_task_user(void)
{
    /* KEYBOARD PET VARIABLES START */

    /** led_usb_state = host_keyboard_led_state(); */

    /* KEYBOARD PET VARIABLES END */
    // update_log();
    if (is_keyboard_master())
    {
        // if (last_input_activity_elapsed() >= OLED_TIMEOUT &&
        //     get_current_wpm() == 0)
        if (last_input_activity_elapsed() >= OLED_TIMEOUT)
        {
            oled_off();
        }
    }
    // if (is_keyboard_master() && is_oled_on())
    if (is_oled_on())
    {
        print_status_narrow();
    }
    //     else if (!is_keyboard_master() && is_oled_on())
    //     {
    // #ifdef CAT_ENABLE
    //         bongo_render_anim();
    // #else
    //
    //         // oled_set_cursor(0, 12);
    //         render_kb_split();
    //         oled_write_ln("", false);
    //         oled_write_ln("", false);
    //         // render_layer();
    //         // oled_write_ln("", false);
    //         // oled_write_ln("", false);
    //         // render_prompt();
    //         render_mod_status();
    //         oled_write_ln("", false);
    //         oled_write_ln("", false);
    // #endif
    //         // oled_set_cursor(0, 12);
    //         oled_write_P(PSTR("WPM: "), false);
    //         oled_write(get_u8_str(get_current_wpm(), '0'), false);
    //     }
    return false;
}

bool process_record_user_oled(uint16_t keycode, keyrecord_t *record)
{
    if (record->event.pressed)
    {
        add_keylog(keycode, record);
    }
    return true;
}
