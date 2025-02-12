SET(SOURCES screens/ui_AppUART.c
    screens/ui_AppMain.c
    screens/ui_AppSettings.c
    ui_theme_manager.c
    ui_themes.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    fonts/ui_font_Font1.c)

add_library(ui ${SOURCES})
