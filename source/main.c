#include <string.h>
#include <stdio.h>
#include <switch.h>




u32 sq1,sq2,sq3,sq4,sq5,sq6,sq7,sq8,sq9;// Squares
int turn = 1;
int winner = 0;


int main(int argc, char *argv[])
{	
	
	consoleInit(NULL);
	
	
	
	//board
	
	printf("\x1b[19;31H     |     |     ");
	printf("\x1b[20;31H     |     |     ");
	printf("\x1b[21;31H_____|_____|_____");
	printf("\x1b[22;31H     |     |     ");
	printf("\x1b[23;31H     |     |     ");
	printf("\x1b[24;31H_____|_____|_____");
	printf("\x1b[25;31H     |     |     ");
	printf("\x1b[26;31H     |     |     ");
	printf("\x1b[27;31H     |     |     ");
	while(appletMainLoop()) {
	touchPosition touch;
	u32 touch_count = hidTouchCount();
	u32 i;
	u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
	u64 kHeld = hidKeysHeld(CONTROLLER_P1_AUTO);
	hidScanInput();
	printf("\x1b[2;23HTic Tac Toe made by Canaan Watts");
	printf("\x1b[3;25HPlayer 1 (X)  -  Player 2 (O)");
	printf("\x1b[33;31HPress X to restart.");
	printf("\x1b[4;31HPress '+' to exit.");
	if(kHeld&KEY_X){
		sq1=0;printf("\x1b[20;33H ");
		sq2=0;printf("\x1b[20;39H ");
		sq3=0;printf("\x1b[20;45H ");
		sq4=0;printf("\x1b[23;33H ");
		sq5=0;printf("\x1b[23;39H ");
		sq6=0;printf("\x1b[23;45H ");
		sq7=0;printf("\x1b[26;33H ");
		sq8=0;printf("\x1b[26;39H ");
		sq9=0;printf("\x1b[26;45H ");
		winner=0;
		printf("\x1b[36;32H              ");
		touch.px=0;
		touch.py=0;
	}
		
		
		
		
		
			//X turn
			
		if (turn==1&touch.px>480&touch.px<565&touch.py<335&touch.py>285&sq1 != 2) {sq1=1;turn=2;}
		if (turn==1&touch.px>569&touch.px<663&touch.py<335&touch.py>285&sq2 != 2) {sq2=1;turn=2;}
		if (turn==1&touch.px>665&touch.px<753&touch.py<335&touch.py>285&sq3 != 2) {sq3=1;turn=2;}
		if (turn==1&touch.px>480&touch.px<565&touch.py<385&touch.py>335&sq4 != 2) {sq4=1;turn=2;}
		if (turn==1&touch.px>569&touch.px<663&touch.py<385&touch.py>335&sq5 != 2) {sq5=1;turn=2;}
		if (turn==1&touch.px>665&touch.px<753&touch.py<385&touch.py>335&sq6 != 2) {sq6=1;turn=2;}
		if (turn==1&touch.px>480&touch.px<565&touch.py<435&touch.py>380&sq7 != 2) {sq7=1;turn=2;}
		if (turn==1&touch.px>569&touch.px<663&touch.py<435&touch.py>380&sq8 != 2) {sq8=1;turn=2;}
		if (turn==1&touch.px>665&touch.px<753&touch.py<435&touch.py>380&sq9 != 2) {sq9=1;turn=2;}
		
		//Y turn
		if (turn==2&touch.px>480&touch.px<565&touch.py<335&touch.py>285&sq1 != 1) {sq1=2;turn=1;}
		if (turn==2&touch.px>569&touch.px<663&touch.py<335&touch.py>285&sq2 != 1) {sq2=2;turn=1;}
		if (turn==2&touch.px>665&touch.px<753&touch.py<335&touch.py>285&sq3 != 1) {sq3=2;turn=1;}
		if (turn==2&touch.px>480&touch.px<565&touch.py<385&touch.py>335&sq4 != 1) {sq4=2;turn=1;}
		if (turn==2&touch.px>569&touch.px<663&touch.py<385&touch.py>335&sq5 != 1) {sq5=2;turn=1;}
		if (turn==2&touch.px>665&touch.px<753&touch.py<385&touch.py>335&sq6 != 1) {sq6=2;turn=1;}
		if (turn==2&touch.px>480&touch.px<565&touch.py<435&touch.py>380&sq7 != 1) {sq7=2;turn=1;}
		if (turn==2&touch.px>569&touch.px<663&touch.py<435&touch.py>380&sq8 != 1) {sq8=2;turn=1;}
		if (turn==2&touch.px>665&touch.px<753&touch.py<435&touch.py>380&sq9 != 1) {sq9=2;turn=1;}
			
		 for(i=0; i<touch_count; i++)
        {
            //Read the touch screen coordinates
            hidTouchRead(&touch, i);

            
        }
		if (sq1==1&sq2==1&sq3==1) winner=1;
		if (sq4==1&sq5==1&sq6==1) winner=1;
		if (sq7==1&sq8==1&sq9==1) winner=1;
		if (sq1==1&sq4==1&sq7==1) winner=1;
		if (sq2==1&sq5==1&sq8==1) winner=1;
		if (sq3==1&sq6==1&sq9==1) winner=1;
		if (sq1==1&sq5==1&sq9==1) winner=1;
		if (sq3==1&sq5==1&sq7==1) winner=1;
		
		if (sq1==2&sq2==2&sq3==2) winner=2;
		if (sq4==2&sq5==2&sq6==2) winner=2;
		if (sq7==2&sq8==2&sq9==2) winner=2;
		if (sq1==2&sq4==2&sq7==2) winner=2;
		if (sq2==2&sq5==2&sq8==2) winner=2;
		if (sq3==2&sq6==2&sq9==2) winner=2;
		if (sq1==2&sq5==2&sq9==2) winner=2;
		if (sq3==2&sq5==2&sq7==2) winner=2;
		
	
	

        
		if(winner==1){printf("\x1b[36;32HPlayer 1 Wins!");}
		if(winner==2){printf("\x1b[36;32HPlayer 2 Wins!");}
		
	
	
	

        
	
	
	consoleUpdate(NULL);
	if (sq1 == 1) printf("\x1b[20;33HX");
	if (sq1 == 2) printf("\x1b[20;33HO");
	if (sq2 == 1) printf("\x1b[20;39HX");
	if (sq2 == 2) printf("\x1b[20;39HO");
	if (sq3 == 1) printf("\x1b[20;45HX");
	if (sq3 == 2) printf("\x1b[20;45HO");
	if (sq4 == 1) printf("\x1b[23;33HX");
	if (sq4 == 2) printf("\x1b[23;33HO");
	if (sq5 == 1) printf("\x1b[23;39HX");
	if (sq5 == 2) printf("\x1b[23;39HO");
	if (sq6 == 1) printf("\x1b[23;45HX");
	if (sq6 == 2) printf("\x1b[23;45HO");
	if (sq7 == 1) printf("\x1b[26;33HX");
	if (sq7 == 2) printf("\x1b[26;33HO");
	if (sq8 == 1) printf("\x1b[26;39HX");
	if (sq8 == 2) printf("\x1b[26;39HO");
	if (sq9 == 1) printf("\x1b[26;45HX");
	if (sq9 == 2) printf("\x1b[26;45HO");
	if (kDown & KEY_PLUS) {consoleClear();break;}
	
	//Cases
	}
	
	consoleExit(NULL);
    return 0;
}
