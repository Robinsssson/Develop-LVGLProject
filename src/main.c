#include "porting/lv_porting.h"
#include "lvgl.h"
#include "GUI_APP/all_gui.h"

int main(int argc, char* argv[])
{
    lv_porting_init();
    All_Gui();
    while (1) {
        lv_timer_handler();
        lv_porting_delay();
    }
}
