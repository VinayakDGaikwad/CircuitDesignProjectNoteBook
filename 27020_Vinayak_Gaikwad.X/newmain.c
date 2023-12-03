#include<xc.h>
#include<pic18f4550.h>

//#pragma config OSC = HS
#pragma config PWRT = OFF
#pragma config WDT = OFF
#pragma config DEBUG = OFF , LVP = OFF

#define ldata PORTD
#define rs PORTEbits.RE0
#define rw PORTEbits.RE1
#define en PORTEbits.RE2

void msdelay(unsigned int len){
    for(int i=0;i<len;i++);
}

void lcd_cmd(unsigned char value) {
	ldata = value;
	rs = 0;
	rw = 0;
	en = 1;
	msdelay(50);
	en = 0;
}

void lcd_data(unsigned char value) {
	ldata = value;
	rs = 1;
	rw = 0;
	en =  1;
	msdelay(50);
	en =  0;
}

void main(void) {

	TRISD = 0x00;
	ADCON1 = 0x0f;

	TRISE = 0x00;
	msdelay(50);

	lcd_cmd(0x38);
	msdelay(50);

	lcd_cmd(0x01);
	msdelay(50);

	lcd_cmd(0x06);
	msdelay(50);

	lcd_cmd(0x80);
	msdelay(50);

    lcd_data('H');
    msdelay(10);
    lcd_data('I');
	return;
}