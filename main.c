#include "lvgl/lvgl.h"
#include <unistd.h>

static void event_cb(lv_event_t *e)
{
    static uint32_t count = 1;
    lv_obj_t *btn = lv_event_get_target(e);
    lv_obj_t *label = lv_obj_get_child(btn, 0);
    lv_label_set_text(label, "Touch registered!");
}

int main(void)
{
    lv_init();

    // Set up the display
    lv_display_t *disp = lv_linux_fbdev_create();
    lv_linux_fbdev_set_file(disp, "/dev/fb0"); // linux framebuffer device

    // Set up the touchscreen
    lv_indev_t *touch = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event4"); // RPi TFT touchscreen device
    lv_indev_set_display(touch, disp);

    // Set the background colour
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x003a57), LV_PART_MAIN);

    // Create a button in the centre of the screen
    lv_obj_t *btn = lv_button_create(lv_screen_active());
    lv_obj_set_size(btn, 150, 50);
    lv_obj_center(btn);
    lv_obj_add_event_cb(btn, event_cb, LV_EVENT_CLICKED, NULL);

    // Add a label to the button
    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, "Click Me");
    lv_obj_center(label);


    while(1)
    {
        lv_tick_inc(5);
        lv_timer_handler();
        usleep(5000);
    }
    
    return 0;
}
