#include "type.h"
#include "stdio.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "fs.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"
#include "DrawingTools.h"
PUBLIC void boot_animation()
{
	char* p = (char *) 0xa0000;
    int delay=10000;
    for (int y = 0; y < 200; ++y) {
        for (int x = 0; x < 320; ++x) {
            p[y*320 + x] = 15;//灰色 
        }
    }
    
    // vm_print_letter(15, 5,7,"     ******               *******    ");
    // vm_print_letter(15,21,7,"   ***    ***           **           ");
    // vm_print_letter(15,37,7,"  **        **            ***        ");
    // vm_print_letter(15,53,7,"  **        **               ***     ");
    // vm_print_letter(15,69,7,"   ***    ***                   **   ");
    // vm_print_letter(15,85,7,"     ******              *******     ");

    milli_delay(delay);
    vm_print_letter(15, 5,7,"     ******               *******    ");
    milli_delay(delay);
    vm_print_letter(15,21,7,"   ***    ***           **           ");
    milli_delay(delay);
    vm_print_letter(15,37,7,"  **        **            ***        ");
    milli_delay(delay);
    vm_print_letter(15,53,7,"  **        **               ***     ");
    milli_delay(delay);
    vm_print_letter(15,69,7,"   ***    ***                   **   ");
    milli_delay(delay);
    vm_print_letter(15,85,7,"     ******              *******     ");
    milli_delay(delay);

    vm_print_letter(30,100,7,"Created By:");
    vm_print_letter(60,116,7,"1952723 Li Sheng");
    vm_print_letter(60,132,7,"1951106 Sun Yijia");
    vm_print_letter(60,148,7,"1952554 Wu Chenwei");
    vm_print_letter(60,164,7,"1952730 Jin Xiangwen");
    vm_print_letter(60,180,7,"1952737 Li Zhiruo");
    milli_delay(delay*6);
    clear();
    for (int y = 0; y < 200; ++y) {
        for (int x = 0; x < 320; ++x) {
            p[y*320 + x] = 15;
        }
    }
}
