
/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const Bool viewontag         = True;     /* Switch view on tag switch */
static const double activeopacity   = 1.0f;     /* Window opacity when it's focused (0 <= opacity <= 1) */
static const double inactiveopacity = 0.775f;   /* Window opacity when it's inactive (0 <= opacity <= 1) */
static const char *fonts[]          = {
  "JetBrains Mono:size=15", /* Normal font */
  "JetBrainsMono Nerd Font Mono:size=30" /* Icon Font */
};
static const char dmenufont[]       = "Iosevka";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_black[]       = "#000000";
static const char col_white[]       = "#FFFFFF";
static const char *colors[][4]      = {
  /*               fg         bg         border     float */
  [SchemeNorm] = { col_gray3, col_gray1, col_gray2, col_black },
  [SchemeSel]  = { col_gray4, col_cyan,  col_cyan,  col_white },
  [SchemeHid]  = { col_cyan,  col_gray1, col_cyan,  col_black },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "辶", "", "" }; /*  */
static const char *tagsalt[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
  /* xprop(1):
   *	WM_CLASS(STRING) = instance, class
   *	WM_NAME(STRING) = title
   */
  /* class               instance    title
   * tags mask,          switchtotag, isfloating, monitor,    scratch key */
  { "code-oss",          NULL,       NULL,
    1 << 0,              1,          0,           -1,         0,0,0,0,0, 0 },
  { "Emacs",             NULL,       NULL,
    1 << 0,              1,          0,           -1,         0,0,0,0,0, 0 },
  { "firefox",           NULL,       NULL,
    1 << 1,              1,          0,           -1,         0,0,0,0,0, 0 },
  { "Brave-browser",     NULL,       NULL,
    1 << 1,              1,          0,           -1,         0,0,0,0,0, 0 },
  { "qutebrowser",       NULL,       NULL,
    1 << 1,              1,          0,           -1,         0,0,0,0,0, 0 },
  { "Pcmanfm",           NULL,       NULL,
    1 << 3,              1,          0,           -1,         0,0,0,0,0, 0 },
  { "Thunar",            NULL,       NULL,
    1 << 3,              1,          0,           -1,         0,0,0,0,0, 0 },
  { NULL,                "St",       NULL,
    1 << 4,              1,          0,           -1,         0,0,0,0,0, 0 },
  { NULL,                "Alacritty",       NULL,
    0,                   0,          0,           -1,         0,0,0,0,0, 0 },
  { "Sxiv",              NULL,       NULL,
    1 << 5,              1,          0,           -1,         0,0,0,0,0, 0 },
  { "Viewnior",          NULL,       NULL,
    1 << 5,              1,          0,           -1,         0,0,0,0,0, 0 },
  { "mpv",               NULL,       NULL,
    1 << 6,              1,          0,           -1,         0,0,0,0,0, 0 },
  { "Parole",            NULL,       NULL,
    1 << 6,              1,          0,           -1,         0,0,0,0,0, 0 },
  { "Virt-manager",      NULL,       NULL,
    1 << 7,              1,          0,           -1,         0,0,0,0,0, 0 },
  { "VirtualBox Manager",NULL,       NULL,
    1 << 7,              1,          0,           -1,         0,0,0,0,0, 0 },

  { NULL,                "Scratchpad",       NULL,
    0,                   0,          1,           -1,         460,165,1000,750,0, 'S' },
  { NULL,                NULL,       "ranger",
    0,                   0,          1,           -1,         915,0,1000,750,0, 'R' },
  { NULL,                NULL,       "btop",
    0,                   0,          1,           -1,         0,0,1000,750,0, 'B' },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int attachdirection = 0;    /* 0 default, 1 above, 2 aside, 3 below, 4 bottom, 5 top */

/* mouse scroll resize */
static const int scrollsensetivity = 30; /* 1 means resize window by 1 pixel for each scroll event */

#include "fibonacci.c"
static const Layout layouts[] = {
  /* symbol     arrange function */
  { "",      tile },    /* first entry is default */
  { "",      monocle }, /*    */
  { "|M|",      centeredmaster },
  { ">M>",      centeredfloatingmaster },
  { "TTT",      bstack },
  { "",      bstackhoriz },
  { "",       doubledeck },
  { "",      spiral }, /*   */
  { "[\\]",      dwindle },
  { "",      NULL }, /*   */   /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(CHAIN,KEY,TAG) \
{ MODKEY,                       CHAIN,    KEY,      view,           {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask,           CHAIN,    KEY,      toggleview,     {.ui = 1 << TAG} }, \
{ MODKEY|ShiftMask,             CHAIN,    KEY,      tag,            {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask|ShiftMask, CHAIN,    KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { "tabbed", "-c", "-n", "St", "-r", "2", "st", "-w", "''", NULL };
/*First arg only serves to match against key in rules*/
static const char *scratchpadcmd[] = {"S", "tabbed", "-f", "-r", "2", "-n", "Scratchpad", "st", "-w", "''", NULL};
static const char *sfilemanagercmd[] = {"R", "tabbed", "-f", "-r", "2", "st", "-w", "''", "-t", "ranger", "-e", "ranger", NULL};
static const char *sbtopcmd[] = {"B", "st", "-t", "btop", "-e", "btop", NULL};

/* for XF86 Media Keys */
#include <X11/X.h>
#include <X11/XF86keysym.h>

void resetnmaster(const Arg *arg);
static Key keys[] = {
  /* modifier     chain     key     function    argument */
  /***** Layout *****/
  { MODKEY, -1, XK_p, spawn, SHCMD("dwm_layout") }, // Spawn dwm_layout
  { MODKEY|ControlMask, -1, XK_b, togglebar, {0} }, // Toggle bar
  { MODKEY|ALTKEY, -1, XK_j, incnmaster, {.i = +1 } }, // Increase master
  { MODKEY|ALTKEY, -1, XK_k, incnmaster, {.i = -1 } }, // Decrease master
  { MODKEY|ControlMask, -1,XK_j, pushdown, {0} }, // Push up
  { MODKEY|ControlMask, -1,XK_k, pushup, {0} }, // Push down
  { MODKEY, -1, XK_Tab, zoom, {0} }, // Zoom
  { MODKEY, -1, XK_t, setlayout, {.v = &layouts[0]} }, // First layout
  { MODKEY, -1, XK_m, setlayout, {.v = &layouts[1]} }, // Second layout
  { MODKEY|ShiftMask, -1, XK_space, setlayout, {.v = &layouts[9]} }, // Last layout
  { MODKEY|ControlMask, -1, XK_space, setlayout, {0} }, // Previous layout
  { MODKEY|ShiftMask, -1, XK_o, resetnmaster, {0} }, // Reset master
  /******************/

  { MODKEY|ControlMask, -1, XK_Up, movethrow, {.ui = DIR_N  }}, // Move in nord
  { MODKEY|ControlMask, -1, XK_Down, movethrow, {.ui = DIR_S  }}, // Move in sud
  { MODKEY|ControlMask, -1, XK_Left, movethrow, {.ui = DIR_W  }}, // Move in west
  { MODKEY|ControlMask, -1, XK_Right, movethrow, {.ui = DIR_E  }}, // Move in east
  { MODKEY|ControlMask, -1, XK_c, movethrow, {.ui = DIR_C  }}, // Move in center

  /***** Spawn *****/
  // { ALTKEY, -1, XK_F1, spawn, SHCMD("launcher_misc") },
  { MODKEY, -1, XK_colon, spawn, SHCMD("dwm_help") }, // Spawn key helper
  { ALTKEY, -1, XK_F1, spawn, SHCMD("dm_launcher") }, // Spawn launcher
  { MODKEY, -1, XK_Return, spawn, {.v = termcmd } }, // Spawn term
  { MODKEY|ShiftMask, -1, XK_Return, togglescratch, {.v = scratchpadcmd } }, // Spawn scratchpad terminal
  { MODKEY, -1, XK_r, togglescratch, {.v = sfilemanagercmd } }, // Spawn scratchpad ranger
  { MODKEY, -1, XK_b, togglescratch, {.v = sbtopcmd } }, // Spawn scratchpad btop
  { MODKEY, XK_x, XK_b, spawn, SHCMD("$browser") }, // Spawn browser
  { MODKEY, XK_x, XK_e, spawn, SHCMD("$editor") }, // Spawn editor
  { MODKEY, XK_x, XK_f, spawn, SHCMD("$file_manager") }, // Spawn file_manager
  { MODKEY, XK_x, XK_h, spawn, SHCMD("$hypervisor") }, // Spawn hypervisor
  /*****************/

  /****** Focus *****/
  { MODKEY, -1, XK_j, focusstackvis, {.i = +1 } }, // Move focus in visible window +1
  { MODKEY, -1, XK_k, focusstackvis, {.i = -1 } }, // Move focus in visible window -1
  { MODKEY|ShiftMask, -1, XK_j, focusstackhid, {.i = +1 } }, // Move focus in hidden window +1
  { MODKEY|ShiftMask, -1, XK_k, focusstackhid, {.i = -1 } }, // Move focus in hidden window +1
  /******************/

  /***** Resize *****/
  { MODKEY, -1, XK_h, setmfact, {.f = -0.05} }, // Decrease mfact
  { MODKEY, -1, XK_l, setmfact, {.f = +0.05} }, // Increase mfact
  { MODKEY|ShiftMask, -1, XK_h, setcfact, {.f = +0.25} }, // Increase cfact
  { MODKEY|ShiftMask, -1, XK_l, setcfact, {.f = -0.25} }, // Decrease cfact
  { MODKEY, -1, XK_o, setcfact, {.f =  0.00} }, // Reset cfact
  { MODKEY|ControlMask, -1, XK_l, aspectresize, {.i = +24} }, // Increase aspectresize
  { MODKEY|ControlMask, -1, XK_h, aspectresize, {.i = -24} }, // Decrease aspectresize
  /******************/

  { MODKEY, -1, XK_Escape, view, {0} }, // View in previous tag

  /***** Client *****/
  { MODKEY, -1, XK_q, killclient, {0} }, // Kill window
  { MODKEY, -1, XK_space, togglefloating, {0} }, // Float window
  { MODKEY, -1, XK_f, togglefullscr, {0} }, // Toggle fullscreen
  { MODKEY, -1, XK_agrave, view, {.ui = ~0 } }, // View all window
  { MODKEY|ShiftMask, -1, XK_agrave, tag, {.ui = ~0 } }, // Sticky window
  { MODKEY|ShiftMask, -1, XK_s, show, {0} }, // Show hidden window
  { MODKEY|ALTKEY,-1,XK_s, hide, {0} }, // Hide window
  { MODKEY, -1, XK_s, scratchpad_show, {0} }, // Show scratchpad window
  { MODKEY|ShiftMask|ControlMask, -1,XK_s, scratchpad_hide, {0} }, // Add in scratchpad
  { MODKEY|ALTKEY|ControlMask, -1,XK_s,scratchpad_remove,{0} }, // Remove in scratchpad

  { MODKEY, -1, XK_comma, focusmon, {.i = -1 } }, // Move focus in monitor -1
  { MODKEY, -1, XK_semicolon, focusmon, {.i = +1 } }, // Move focus in monitor +1
  { MODKEY|ShiftMask, -1, XK_comma, tagmon, {.i = -1 } }, 
  { MODKEY|ShiftMask, -1, XK_semicolon, tagmon, {.i = +1 } },

  { MODKEY, -1, XK_a, togglealttag, {0} }, // Toggle alternative tag

  { MODKEY|ShiftMask, -1, XK_q, try_quit, {0} }, // Quit dwm if no client
  { MODKEY|ShiftMask|ControlMask, -1, XK_q, quit, {0} }, // Quit dwm
  { MODKEY|ControlMask, -1, XK_q, quit, {1} }, // Restart dwm 

  /***** Dmenu *****/
  { MODKEY, -1, XK_v, spawn, SHCMD("dm_clip") }, // Spawn clipboard helper
  { MODKEY, -1, XK_n, spawn, SHCMD("dm_network") }, // Spawn network helper
  { MODKEY|ShiftMask, -1, XK_n, spawn, SHCMD("dm_bluetooth") }, // Spawn bluetooth helper
  { MODKEY, XK_d, XK_t, spawn, SHCMD("dm_todo") }, // Spawn todo helper
  { MODKEY, XK_d, XK_l, spawn, SHCMD("dm_mpd -l") }, // Spawn mpd helper
  { MODKEY, XK_d, XK_p, spawn, SHCMD("dm_mpd -p") }, // Spawn mpd helper
  { 0, -1, XK_Print, spawn, SHCMD("dm_screenshot") }, // Spawn screenshot helper
  { MODKEY, -1, XK_Print, spawn, SHCMD("dm_shot") }, // Spawn screenshot helper
  /*****************/

  /***** Audio and brightness *****/
  { 0, -1, XF86XK_AudioPlay, spawn, SHCMD("playerctl play-pause") },
  { 0, -1, XF86XK_AudioPause, spawn, SHCMD("playerctl play-pause") },
  { 0, -1, XF86XK_AudioNext, spawn, SHCMD("playerctl next") },
  { 0, -1, XF86XK_AudioPrev, spawn, SHCMD("playerctl previous") },

  { 0, -1, XF86XK_MonBrightnessUp, spawn, SHCMD("light_up") },
  { 0, -1, XF86XK_MonBrightnessDown, spawn, SHCMD("light_down") },
  { MODKEY, -1, XK_z, spawn, SHCMD("light_off") },

  { 0, -1, XF86XK_AudioRaiseVolume, spawn, SHCMD("vol_up") },
  { 0, -1, XF86XK_AudioLowerVolume, spawn, SHCMD("vol_down") },
  { 0, -1, XF86XK_AudioMute, spawn, SHCMD("vol_mute") },

  { 0, -1, XF86XK_AudioMicMute, spawn, SHCMD("mic_mute") },
  { MODKEY, -1, XF86XK_AudioRaiseVolume, spawn, SHCMD("mic_up") },
  { MODKEY, -1, XF86XK_AudioLowerVolume, spawn, SHCMD("mic_down") },

  TAGKEYS(-1, XK_ampersand,  0)
  TAGKEYS(-1, XK_eacute,     1)
  TAGKEYS(-1, XK_quotedbl,   2)
  TAGKEYS(-1, XK_apostrophe, 3)
  TAGKEYS(-1, XK_parenleft,  4)
  TAGKEYS(-1, XK_minus,      5)
  TAGKEYS(-1, XK_egrave,     6)
  TAGKEYS(-1, XK_underscore, 7)
  TAGKEYS(-1, XK_ccedilla,   8)
};

/* resizemousescroll direction argument list */
static const int scrollargs[][2] = {
  /* width change         height change */
  { +scrollsensetivity,	0 },
  { -scrollsensetivity,	0 },
  { 0, +scrollsensetivity },
  { 0, -scrollsensetivity },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
  /* click                event mask      button          function        argument */
  { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
  { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
  { ClkWinTitle,          0,              Button1,        togglewin,      {0} },
  { ClkWinTitle,          0,              Button2,        zoom,           {0} },
  { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
  { ClkClientWin,         MODKEY,         Button4,        resizemousescroll, {.v = &scrollargs[0]} },
  { ClkClientWin,         MODKEY,         Button5,        resizemousescroll, {.v = &scrollargs[1]} },
  { ClkClientWin,         MODKEY,         Button6,        resizemousescroll, {.v = &scrollargs[2]} },
  { ClkClientWin,         MODKEY,         Button7,        resizemousescroll, {.v = &scrollargs[3]} },
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

/* how many windows should be open when quitting? */
/* on a stock dwm install, this seems to be two; however, you'll have to
   + * change it depending on how many invisible X windows exist */
/* you can get a list with `xwininfo -tree -root`. */
static const int EMPTY_WINDOW_COUNT = 8;

void
resetnmaster(const Arg *arg)
{
	selmon->nmaster = 1;
	arrange(selmon);
}

  void
setlayoutex(const Arg *arg)
{
  setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

  void
viewex(const Arg *arg)
{
  view(&((Arg) { .ui = 1 << arg->ui }));
}

  void
viewall(const Arg *arg)
{
  view(&((Arg){.ui = ~0}));
}

  void
toggleviewex(const Arg *arg)
{
  toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

  void
tagex(const Arg *arg)
{
  tag(&((Arg) { .ui = 1 << arg->ui }));
}

  void
toggletagex(const Arg *arg)
{
  toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

  void
tagall(const Arg *arg)
{
  tag(&((Arg){.ui = ~0}));
}

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
  /* signum           function */
  { "focusstackvis",  focusstackvis },
  { "focusstackhid",  focusstackhid },
  { "setmfact",       setmfact },
  { "togglebar",      togglebar },
  { "incnmaster",     incnmaster },
  { "togglefloating", togglefloating },
  { "focusmon",       focusmon },
  { "tagmon",         tagmon },
  { "zoom",           zoom },
  { "view",           view },
  { "viewall",        viewall },
  { "viewex",         viewex },
  { "toggleview",     view },
  { "toggleviewex",   toggleviewex },
  { "tag",            tag },
  { "tagall",         tagall },
  { "tagex",          tagex },
  { "toggletag",      tag },
  { "toggletagex",    toggletagex },
  { "killclient",     killclient },
  { "quit",           quit },
  { "setlayout",      setlayout },
  { "setlayoutex",    setlayoutex },
};
