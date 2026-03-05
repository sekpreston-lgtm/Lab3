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

int main() {
	MYDISP display;
	display.begin();
	display.displayOn(true);
	XGpio input;
	XGpio output;

	XGpio_Initialize(&input, XPAR_AXI_GPIO_0_DEVICE_ID);
	XGpio_Initialize(&output, XPAR_AXI_GPIO_1_DEVICE_ID);

	XGpio_SetDataDirection(&input, 1, 0xF);
	XGpio_SetDataDirection(&output, 1, 0x0l);

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
	int ydirr=0;
	int xdirr=0;
	int colr=0;

	int x1r=cxr-(wr/2);
	int y1r=cyr-(wr/2);
	int x2r=cxr+(wr/2);
	int y2r=cyr+(wr/2);

	display.drawRectangle(true, x1, y1, x2, y2);

//Circle
	while(true){
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

		int curr_buttons = XGpio_DiscreteRead(&input, 1);

        if (curr_buttons & 0b0001){
            col = (col + 1) % 4;
        }

		switch (col){
			case 0:
				display.setForeground(clrBlue);
				break;

			case 1:
				display.setForeground(clrBlack);
				break;

			case 2:
				display.setForeground(clrGreen);
				break;

			case 3:
				display.setForeground(clrYellow);
				break;
			}

			x1=cx-(w/2);
			y1=cy-(w/2);
			x2=cx+(w/2);
			y2=cy+(w/2);

			display.clearDisplay(clrWhite);
			display.drawEllipse(true, x1, y1, x2, y2);

//Rectangle
			for (int count = 0; count < 33000000; count++){
			}

			if (cyr>=320-(wr/2) || cyr<=0+(wr/2)){
						ydirr = (ydirr + 1) % 2;
					}
					else{
						ydirr = ydirr;
					}

					switch (ydirr){
						case 0:
							cyr-=8;
							break;

						case 1:
							cyr+=8;
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

					curr_buttons = XGpio_DiscreteRead(&input, 1);

			        if (curr_buttons & 0b0010){
			            col = (col + 1) % 4;
			        }

					switch (colr){
						case 0:
							display.setForeground(clrBlue);
							break;

						case 1:
							display.setForeground(clrBlack);
							break;

						case 2:
							display.setForeground(clrGreen);
							break;

						case 3:
							display.setForeground(clrYellow);
							break;
						}

						x1r=cxr-(wr/2);
						y1r=cyr-(wr/2);
						x2r=cxr+(wr/2);
						y2r=cyr+(wr/2);

						display.clearDisplay(clrWhite);
						display.drawRectangle(true, x1, y1, x2, y2);
						for (int count = 0; count < 33000000; count++){
						}
	}

	return 0;
}
