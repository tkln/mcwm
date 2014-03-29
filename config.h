/* User configurable stuff. */

/*
 * Move this many pixels when moving or resizing with keyboard unless
 * the window has hints saying otherwise.
 */
#define MOVE_STEP 32

/*
 * Use this modifier combined with other keys to control wm from
 * keyboard. Default is Mod4, which on my keyboard is the Alt key but
 * is usually the Windows key on more normal keyboard layouts.
 */
#define MODKEY XCB_MOD_MASK_4

/* Extra modifier for resizing. Default is Shift. */
#define SHIFTMOD XCB_MOD_MASK_SHIFT

/*
 * Modifier key to use with mouse buttons. Default Mod1, Meta on my
 * keyboard.
 */
#define MOUSEMODKEY MODKEY

/*
 * Start this program when pressing MODKEY + USERKEY_TERMINAL. Needs
 * to be in $PATH.
 *
 * Change to "xterm" if you're feeling conservative.
 *
 * Can be set from command line with "-t program".
 */
#define TERMINAL "urxvtc"
#define RUNCMD "dmenu_run"

/*
 * Do we allow windows to be iconified? Set to true if you want this
 * behaviour to be default. Can also be set by calling mcwm with -i.
 */ 
#define ALLOWICONS false

/*
 * Start these programs when pressing MOUSEMODKEY and mouse buttons on
 * root window.
 */
#define MOUSE1 ""
#define MOUSE2 ""
#define MOUSE3 ""

/*
 * Default colour on border for focused windows. Can be set from
 * command line with "-f colour".
 */
#define FOCUSCOL "chocolate1"

/* Ditto for unfocused. Use "-u colour". */
#define UNFOCUSCOL "grey40"

/* Ditto for fixed windows. Use "-x colour". */
#define FIXEDCOL "grey90"

/* Default width of border window, in pixels. Used unless -b width. */
#define BORDERWIDTH 1

/* Default snap margin in pixels. Used unless -s width. */
#define SNAPMARGIN 0

/*
 * Keysym codes for window operations. Look in X11/keysymdefs.h for
 * actual symbols. Use XK_VoidSymbol to disable a function.
 */
#define USERKEY_FIX         XK_F
#define USERKEY_MOVE_LEFT   XK_H
#define USERKEY_MOVE_DOWN   XK_J
#define USERKEY_MOVE_UP     XK_K
#define USERKEY_MOVE_RIGHT  XK_L
#define USERKEY_MAXVERT     XK_M
#define USERKEY_RAISE       XK_R
#define USERKEY_TERMINAL    XK_Return
#define USERKEY_RUNCMD      XK_P
#define USERKEY_MAX         XK_X
#define USERKEY_CHANGE      XK_Tab
#define USERKEY_BACKCHANGE  XK_VoidSymbol
#define USERKEY_WS1         XK_1
#define USERKEY_WS2         XK_2
#define USERKEY_WS3         XK_3
#define USERKEY_WS4         XK_4
#define USERKEY_WS5         XK_5
#define USERKEY_WS6         XK_6
#define USERKEY_WS7         XK_7
#define USERKEY_WS8         XK_8
#define USERKEY_WS9         XK_9
#define USERKEY_WS10        XK_0
#define USERKEY_PREVWS      XK_C
#define USERKEY_NEXTWS      XK_V
#define USERKEY_TOPLEFT     XK_Y
#define USERKEY_TOPRIGHT    XK_U
#define USERKEY_BOTLEFT     XK_B
#define USERKEY_BOTRIGHT    XK_N
#define USERKEY_DELETE      XK_End
#define USERKEY_PREVSCREEN  XK_comma
#define USERKEY_NEXTSCREEN  XK_period
#define USERKEY_ICONIFY     XK_I

struct key keys[] =
{

    /* keysym, keycode, mod, cb_func, client, cb_arg */
    { XK_F, 0, MODKEY, fixwindow_, &focuswin, {.b = true} },
    { XK_H, 0, MODKEY, movestep, &focuswin, {.c = 'h'} },
    { XK_J, 0, MODKEY, movestep, &focuswin, {.c = 'j'} },
    { XK_K, 0, MODKEY, movestep, &focuswin, {.c = 'k'} },
    { XK_L, 0, MODKEY, movestep, &focuswin, {.c = 'l'} },
    { XK_H, 0, MODKEY | SHIFTMOD, resizestep, &focuswin, {.c = 'h'} },
    { XK_J, 0, MODKEY | SHIFTMOD, resizestep, &focuswin, {.c = 'j'} },
    { XK_K, 0, MODKEY | SHIFTMOD, resizestep, &focuswin, {.c = 'k'} },
    { XK_L, 0, MODKEY | SHIFTMOD, resizestep, &focuswin, {.c = 'l'} },
    { XK_M, 0, MODKEY, maxvert, &focuswin, {} },
    { XK_R, 0, MODKEY, raiseorlower_, &focuswin, {} },
    { XK_Return, 0, MODKEY, runcmd, NULL, {.s = TERMINAL} },
    { XK_P, 0, MODKEY, runcmd, NULL, {.s = RUNCMD} },
    { XK_X, 0, MODKEY, maximize, &focuswin, {} },
    { XK_Tab, 0, MODKEY, focusnext, NULL, {.b = false} },
    { XK_Tab, 0, MODKEY | SHIFTMOD, focusnext, NULL, {.b = true} },
    { XK_VoidSymbol, 0, MODKEY, focusnext, NULL, {.b = true} },
    { XK_1, 0, MODKEY, changeworkspace_, NULL, {.ui = 0}},
    { XK_2, 0, MODKEY, changeworkspace_, NULL, {.ui = 1} },
    { XK_3, 0, MODKEY, changeworkspace_, NULL, {.ui = 2} },
    { XK_4, 0, MODKEY, changeworkspace_, NULL, {.ui = 3} },
    { XK_5, 0, MODKEY, changeworkspace_, NULL, {.ui = 4} },
    { XK_6, 0, MODKEY, changeworkspace_, NULL, {.ui = 5} },
    { XK_7, 0, MODKEY, changeworkspace_, NULL, {.ui = 6} },
    { XK_8, 0, MODKEY, changeworkspace_, NULL, {.ui = 7} },
    { XK_9, 0, MODKEY, changeworkspace_, NULL, {.ui = 8} },
    { XK_0, 0, MODKEY, changeworkspace_, NULL, {.ui = 9} },
    { XK_Y, 0, MODKEY, topleft, NULL, {} },
    { XK_U, 0, MODKEY, topright, NULL, {} },
    { XK_B, 0, MODKEY, botleft, NULL, {} },
    { XK_N, 0, MODKEY, botright, NULL, {} },
    { XK_End, 0, MODKEY, deletewin, NULL, {} },
    { XK_comma, 0, MODKEY, prevscreen, NULL, {} },
    { XK_period, 0, MODKEY, nextscreen, NULL, {} },
    { XK_I, 0, MODKEY, iconify, &focuswin, {} },
    { XK_C, 0, MODKEY, prevws, NULL, {} },
    { XK_V, 0, MODKEY, nextws, NULL, {} },
};
