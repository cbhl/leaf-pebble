#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"


#define MY_UUID { 0x31, 0x4A, 0x08, 0xB2, 0x48, 0x98, 0x4C, 0x33, 0x85, 0xD9, 0xB1, 0x3D, 0xEA, 0x16, 0x91, 0xBB }
PBL_APP_INFO(MY_UUID,
             "Leaf", "Michael Chang",
             0, 1, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_STANDARD_APP);

Window window;


void handle_init(AppContextRef ctx) {
  (void)ctx;

  window_init(&window, "Window Name");
  window_stack_push(&window, true /* Animated */);
}


void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  app_event_loop(params, &handlers);
}
