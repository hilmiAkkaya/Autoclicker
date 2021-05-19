#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

int x = 0;
int y = 0;
int cps;

bool click = false;

void menu (){
    printf("'W' ile başlatın 'Q' ile durdurun\n");
    printf("Saniyede yapılacak tıklama sayısını giriniz: ");
    scanf("%d", &cps);
    printf("Saniyede %d tıklama yapılacak", cps);
}

void clicker (){
    while (true){
        if (GetAsyncKeyState(0x57)) click = true;
        if (GetAsyncKeyState(0x51)) click = false;

        if (click == true){
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
            Sleep(1000/cps);
        }

    }
}
int main (void){
    menu();
    clicker();
    return 0;
}