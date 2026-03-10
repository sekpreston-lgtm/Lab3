/*
	----------------------------------------------------------------------
	University at Buffalo, EE379, Spring 2020	
	----------------------------------------------------------------------
	File Name: Lab3.cc
	Description: Strating point for Lab 3 code - include MTDS libraries.
	
	Revision History:
	Date      By          Change
	----------------------------------------------------------------------
	20200707  cvfritz     Original

*/

#include <MyDisp.h>
#include <xgpio.h>
#include <stdio.h>
#include <mtds.h>


int main() {
	MYDISP display;
	display.begin();
	display.displayOn(true);
	XGpio input;
	XGpio output;
	MTDS mtds;

	XGpio_Initialize(&input, XPAR_AXI_GPIO_0_DEVICE_ID);
	XGpio_Initialize(&output, XPAR_AXI_GPIO_1_DEVICE_ID);

	XGpio_SetDataDirection(&input, 1, 0xF);
	XGpio_SetDataDirection(&output, 1, 0x0);

//Handles touch activation
	MDFNG fng;

//Circle
	int cx =120;
	int cy=160;
	int w =50;
	int ydir=0;
	int xdir=0;
	int col=0;

	int x1=cx-(w/2);
	int y1=cy-(w/2);
	int x2=cx+(w/2);
	int y2=cy+(w/2);

	display.drawEllipse(true, x1, y1, x2, y2);

//Rectangle
	int cxr =120;
	int cyr=160;
	int wr =50;
	int hr=100;
	int ydirr=0;
	int xdirr=0;

	int x1r=cxr-(wr/2);
	int y1r=cyr-(hr/2);
	int x2r=cxr+(wr/2);
	int y2r=cyr+(hr/2);

	display.drawRectangle(true, x1r, y1r, x2r, y2r);

//oval
	int cxo =120;
	int cyo=160;
	int wo =50;
	int ho=100;
	int ydiro=0;
	int xdiro=0;

	int x1o=cxo-(wo/2);
	int y1o=cyo-(ho/2);
	int x2o=cxo+(wo/2);
	int y2o=cyo+(ho/2);

	display.drawEllipse(true, x1o, y1o, x2o, y2o);

//square
	int cxs =120;
	int cys=160;
	int ws =50;
	int ydirs=0;
	int xdirs=0;

	int x1s=cxs-(ws/2);
	int y1s=cys-(ws/2);
	int x2s=cxs+(ws/2);
	int y2s=cys+(ws/2);

	display.drawRectangle(true, x1s, y1s, x2s, y2s);

//Circle
	while(true){

		display.setBackground(clrWhite);
		display.setForeground(col);
		display.clearDisplay(clrWhite);

		if (cy>=320-(w/2) || cy<=0+(w/2)){
			ydir = (ydir + 1) % 2;
		}
		else{
			ydir = ydir;
		}

		switch (ydir){
			case 0:
				cy+=8;
				break;

			case 1:
				cy-=8;
				break;
		}

		if (cx>=240-(w/2) || cx<=0+(w/2)){
			xdir = (xdir + 1) % 2;
		}
		else{
			xdir = xdir;
		}

		switch (xdir){
			case 0:
				cx+=10;
				break;

			case 1:
				cx-=10;
				break;
		}

		x1=cx-(w/2);
		y1=cy-(w/2);
		x2=cx+(w/2);
		y2=cy+(w/2);

//Rectangle
		if (cyr>=320-(wr/2) || cyr<=0+(wr/2)){
			ydirr = (ydirr + 1) % 2;
		}
		else{
			ydirr = ydirr;
		}

		switch (ydirr){
			case 0:
				cyr-=10;
				break;

			case 1:
				cyr+=10;
				break;
		}

		if (cxr>=240-(wr/2) || cxr<=0+(wr/2)){
			xdirr = (xdirr + 1) % 2;
		}
		else{
			xdirr = xdirr;
		}

		switch (xdirr){
			case 0:
				cxr-=10;
				break;

			case 1:
				cxr+=10;
				break;
		}

		x1r=cxr-(wr/2);
		y1r=cyr-(hr/2);
		x2r=cxr+(wr/2);
		y2r=cyr+(hr/2);

//Oval
		if (cyo>=320-(wo/2) || cyo<=0+(wo/2)){
			ydiro = (ydiro + 1) % 2;
		}
		else{
			ydiro = ydiro;
		}

		switch (ydiro){
			case 0:
				cyo+=12;
				break;

			case 1:
				cyo-=12;
				break;
		}

		if (cxo>=240-(wo/2) || cxo<=0+(wo/2)){
			xdiro = (xdiro + 1) % 2;
		}
		else{
			xdiro = xdiro;
		}

		switch (xdiro){
			case 0:
				cxo+=20;
				break;

			case 1:
				cxo-=20;
				break;
		}

			x1o=cxo-(wo/2);
			y1o=cyo-(ho/2);
			x2o=cxo+(wo/2);
			y2o=cyo+(ho/2);

//square
		if (cys>=320-(ws/2) || cys<=0+(ws/2)){
			ydirs = (ydirs + 1) % 2;
		}
		else{
			ydirs = ydirs;
		}

		switch (ydirs){
			case 0:
				cys+=4;
				break;

			case 1:
				cys-=4;
				break;
		}

		if (cxs>=240-(ws/2) || cxs<=0+(ws/2)){
			xdirs = (xdirs + 1) % 2;
		}
		else{
			xdirs = xdirs;
		}

		switch (xdirs){
			case 0:
				cxs+=5;
				break;

			case 1:
				cxs-=5;
				break;
		}

			x1s=cxs-(ws/2);
			y1s=cys-(ws/2);
			x2s=cxs+(ws/2);
			y2s=cys+(ws/2);

//Touch Interaction (Color)
		bool fingerDown = false;

		display.checkTouch();
		if(display.getFinger(1, &fng)) {
			if (fng.st) {
			        fingerDown = true;
			    } else if (fingerDown && !fng.st) {
			        col = (col + 1) % 4;
			        fingerDown = false;
			    }
			} else {
			    fingerDown = false;
			}

			switch (col){
				case 0:
					display.setForeground(clrMedBlueGray);
					break;

				case 1:
					display.setForeground(clrGreen);
					break;

				case 2:
					display.setForeground(clrBlue);
					break;

				case 3:
					display.setForeground(clrBlack);
					break;
				}

			display.drawRectangle(true, x1r,y1r, x2r, y2r);
			display.drawRectangle(true, x1s, y1s, x2s, y2s);
			display.drawEllipse(true, x1o, y1o, x2o, y2o);
			display.drawEllipse(true, x1, y1, x2, y2);
	}
	return 0;
}
