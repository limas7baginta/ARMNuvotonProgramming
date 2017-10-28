#include "DrvGPIO.h" //Program ini menggunakan library DrvSYS.h, dan DrvGPIO.h sebagai dasar
#include "DrvSYS.h"
#include "Seven_Segment.h" //Seven_segment.h sebagai library untuk mengakses 7 segment
#include "ScanKey.h" // Scankey.h berfung sebagai library untuk mengakses keypad
#include "LCD_Driver.h" //LCD_Driver.h sebagai library untuk mengakses LCD
#include "DrvADC.h" //DrvADC.h sebagai library untuk mengakses ADC(Analog to Digital Converter)
int key,adc; //variabel key digunakan sebagai variabel pada fungsi keypad 
void Init(); //memanggil fungsi Init
int main(void) //program utama
{
    Init(); //fungsi Init 
    Initial_pannel(); //fungsi Init pannel Nuvoton
    DrvGPIO_ClrBit(E_GPD, 14); // untuk memberikan logika LOW pada pin 14 yang mana Pushbutton switch dihubungkan ke PORT D
    while(1) //while(1) digunakan saat keypad ditekan maka akan bernilai 1
    {
    	key=Scankey(); //variabel key pada program akan disamakan dengan fungsi keypad
    	if(key!=0){ //(If) Jika key tidak sama dengan 0 maka lakukan fungsi dibawah ini
    	close_seven_segment();
    	show_seven_segment(0, key); //menampilkan output pada Seven_Segment
    	DrvGPIO_ClrBit(E_GPB, 11); //clear bit GPIO pada pin 11 (LED nyala) yang mana Pushbutton switch dihubungkan ke PORT B
    	DrvSYS_Delay(1000000); //delay setelah dilakukan clear
    	DrvGPIO_SetBit(E_GPB, 11); //untuk memberikan logika HIGH  pada pin 11 (LED mati) yang mana Pushbutton switch dihubungkan ke PORT B
			if (key==1){
				print_lcd(0,"Hasilnya adalah"); //melakukan print pada LCD
				print_lcd(1,"1");
		    	DrvGPIO_ClrBit(E_GPC, 12); //untuk memberikan logika LOW pada pin 11 (LED nyala) yang mana Pushbutton switch dihubungkan ke PORT C
		    	DrvSYS_Delay(1000000);
		    	DrvGPIO_SetBit(E_GPC, 12); //untuk memberikan logika HIGH pada pin 11 (LED mati) yang mana Pushbutton switch dihubungkan ke PORT C
		    	DrvSYS_Delay(1000000);
			}
			if (key==2){
				clr_all_pannal();
				print_lcd(0,"Hasilnya adalah");
				print_lcd(1,"2");
		    	DrvGPIO_ClrBit(E_GPC, 13);
		    	DrvSYS_Delay(1000000);
		    	DrvGPIO_SetBit(E_GPC, 13);
		    	DrvSYS_Delay(1000000);
			}
			if (key==3){
				clr_all_pannal();
				print_lcd(0,"Hasilnya adalah");
				print_lcd(1,"3");
		    	DrvGPIO_ClrBit(E_GPC, 14);
		    	DrvSYS_Delay(1000000);
		    	DrvGPIO_SetBit(E_GPC, 14);
		    	DrvSYS_Delay(1000000);
			}
			if (key==4){
				clr_all_pannal();
				print_lcd(0,"Hasilnya adalah");
				print_lcd(1,"4");
		    	DrvGPIO_ClrBit(E_GPC, 15);
		    	DrvSYS_Delay(1000000);
		    	DrvGPIO_SetBit(E_GPC, 15);
		    	DrvSYS_Delay(1000000);
			}
			if (key==5){
				clr_all_pannal();
				print_lcd(0,"Hasilnya adalah");
				print_lcd(1,"5");
		    	DrvGPIO_ClrBit(E_GPC, 12);
		    	DrvSYS_Delay(1000000);
		    	DrvGPIO_SetBit(E_GPC, 12);
		    	DrvSYS_Delay(1000000);
			}
			if (key==6){
				clr_all_pannal();
				print_lcd(0,"Hasilnya adalah");
				print_lcd(1,"6");
		    	DrvGPIO_ClrBit(E_GPC, 13);
		    	DrvSYS_Delay(1000000);
		    	DrvGPIO_SetBit(E_GPC, 13);
		    	DrvSYS_Delay(1000000);
			}
			if (key==7){
				clr_all_pannal();
				print_lcd(0,"Hasilnya adalah");
				print_lcd(1,"7");
		    	DrvGPIO_ClrBit(E_GPC, 14);
		    	DrvSYS_Delay(1000000);
		    	DrvGPIO_SetBit(E_GPC, 14);
		    	DrvSYS_Delay(1000000);
			}
			if (key==8){
				clr_all_pannal();
				print_lcd(0,"Hasilnya adalah");
				print_lcd(1,"8");
		    	DrvGPIO_ClrBit(E_GPC, 15);
		    	DrvSYS_Delay(1000000);
		    	DrvGPIO_SetBit(E_GPC, 15);
		    	DrvSYS_Delay(1000000);
			}
			if (key==9){
				clr_all_pannal();
				print_lcd(0,"Hasilnya adalah");
				print_lcd(1,"9");
		    	DrvGPIO_ClrBit(E_GPC, 12);
		    	DrvSYS_Delay(1000000);
		    	DrvGPIO_SetBit(E_GPC, 12);
		    	DrvSYS_Delay(1000000);
			}
    	}

    	if (DrvGPIO_GetBit(E_GPB, 15)==0){ //Fungsi DrvGPIO_GetBit menghasilkan nilai 0 jika logika LOW (pushbutton ditekan), atau 1 jika logika HIGH (pushbutton tidak ditekan)
    	DrvGPIO_ClrBit(E_GPC, 12); //untuk memberikan logika LOW pada pin 12 (LED nyala) yang mana Pushbutton switch dihubungkan ke PORT C
    	DrvSYS_Delay(1000000);
    	} //(If) Jika diberi logika LOW (pushbutton ditekan) maka LED nyala
    	else { //(else) lainnya diberi logika HIGH (pushbutton tidak ditekan) maka LED mati
    	DrvGPIO_SetBit(E_GPC, 12); //untuk memberikan logika HIGH pada pin 12 (LED mati) yang mana Pushbutton switch dihubungkan ke PORT C
    	DrvSYS_Delay(1000000);
    	} 
    }
}
