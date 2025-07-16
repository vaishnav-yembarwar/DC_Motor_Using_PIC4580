#include<p18f4580.h>
#define		IN1		PORTCbits.RC0
#define		IN2		PORTCbits.RC1
#define		EN1		PORTCbits.RC2
#define		IN3		PORTCbits.RC4
#define		IN4		PORTCbits.RC5
#define		EN2		PORTCbits.RC3
#define 	SW1		PORTBbits.RB0
#define 	SW2		PORTBbits.RB1
#define 	SW3		PORTBbits.RB2
#define 	SW4		PORTBbits.RB3

#define RS  PORTCbits.RC6

#define E	PORTCbits.RC7



void lcd_cmd(char c);
void lcd_data(char dt);
void lcd_string(rom const char *str);
void delay(int a);
void main()
{

TRISD=0X00;
PORTD=0XFF;
ADCON1=0xFF;

TRISB=0XFF;
TRISC=0X00;



  lcd_cmd(0xe);
 //lcd_cmd(0x01);
  lcd_cmd(0x06);
  lcd_cmd(0x38);
while(1)
{
if(SW1==0)
{
EN1=1;
EN2=1;
IN1=1;
IN2=0;
IN3=1;
IN4=0;
lcd_cmd(0x80);
lcd_string("ALL_MOTOR_CLK");
lcd_cmd(0x01);
}
else if(SW2==0)
{
EN1=1;
EN2=1;
IN1=0;
IN2=1;
IN3=0;
IN4=1;
lcd_cmd(0x80);
lcd_string("ALL_MOTOR_ANTICLK");
lcd_cmd(0x01);
}
else if(SW3==0)
{
EN1=0;
EN2=1;
IN1=0;
IN2=1;
IN3=0;
IN4=1;
lcd_cmd(0x80);
lcd_string("3&4MOTOR_ANTICLK");
lcd_cmd(0x01);
}
else if(SW4==0)
{
EN1=1;
EN2=0;
IN1=0;
IN2=1;
IN3=0;
IN4=1;
lcd_cmd(0x80);
lcd_string("1&2MOTOR_ANTICLK");
lcd_cmd(0x01);
}
else
{
EN1=0;
EN2=0;
IN1=0;
IN2=1;
IN3=0;
IN4=1;
}
}
}



void lcd_string(rom const char *str)
{
	  while(*str!='\0')
    {
       lcd_data(*str);
       str++;
    }
}
	
void lcd_cmd(char c)
{
   PORTD=c;
   RS=0;
  // RW=0;
   E=1;
   delay(100);
   E=0;
}

void lcd_data(char dt)
{
   
   PORTD=dt;
   RS=1;
 //  RW=0;
   E=1;
   delay(100);
   E=0; 
}

void delay(int a)
{
  int i,j;
  for(i=0;i<a;i++)
  for(j=0;j<i;j++);
}
