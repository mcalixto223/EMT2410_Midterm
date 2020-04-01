#include "mbed.h"
Ticker timers_interrupt; 

DigitalOut a = D7;
DigitalOut b = D6;
DigitalOut c = D5;
DigitalOut d = D11;
DigitalOut e = D10;
DigitalOut f = D8;
DigitalOut g = D9;
DigitalOut dp= D4;

int display_state=0;


int timer1=0;
int timer2=0;

void init_function(void);
void seven_segment_control(void);
void seven_segment_display(void);
void digital_point_control(void);
void timers_control(void);

void display_charater_0(void);
void display_charater_1(void);
void display_charater_2(void);
void display_charater_3(void);
void display_charater_4(void);
void display_charater_5(void);
void display_charater_6(void);
void display_charater_7(void);
void display_charater_8(void);
void display_charater_9(void);

int main()
{
    init_function();
    while(1)
    {
        seven_segment_display();
        seven_segment_control();
        digital_point_control();
        
        }
    }
void init_function(void)
{
    timers_interrupt.attach(&timers_control,0.1);// call this interrupt
   }
 void display_character_0(void)
{
    a=1;
    b=1;
    c=1;
    d=1;
    e=1;
    f=1;
    }
void display_character_1(void)
{
    b=1;
    c=1;
    }
void display_character_2(void)
{
    a=1;
    b=1;
    d=1;
    e=1;
    g=1;
    }
void display_character_3(void)
{
    a=1;
    b=1;
    c=1;
    d=1;
    g=1;
    }
void display_character_4(void)
{
    b=1;
    c=1;
    f=1;
    g=1;
    }
void display_character_5(void)
{
    a=1;
    c=1;
    d=1;
    f=1;
    g=1;
    }
void display_character_6(void)
{
    a=1;
    c=1;
    d=1;
    e=1;
    f=1;
    g=1;
    }
void display_character_7(void)
{
    a=1;
    b=1;
    c=1;
    }
void display_character_8(void)
{
    a=1;
    b=1;
    c=1;
    d=1;
    e=1;
    f=1;
    g=1;
    }
void display_character_9(void)
{
    a=1;
    b=1;
    c=1;
    d=1;
    f=1;
    g=1;
    }
 void seven_segment_control(void)
 {
    // Change else if to all if
    if(display_state == 0)
        {
      display_character_0();
        }
    if(display_state == 1)
        {
        display_character_1();
        }
    if(display_state == 2)
        {
        display_character_2();
        }
    if(display_state == 3)
        {
         display_character_3();
        }
    if(display_state == 4)
        {
        display_character_4();
        }
    if(display_state == 5)
        {
        display_character_5();
        }
    if(display_state == 6)
        {
        display_character_6();
        }
    if(display_state == 7)
        {
        display_character_7();
        }
    if(display_state == 8)
        {
        display_character_8();
        }
    if (display_state == 9)
        {
        display_character_9();
        }
}
void seven_segment_display(void)
{
    if (timer1==0)
    {
        display_state=0;
    }
    else if (timer1<10)
    {
        display_state=1;
    }
    
    else if (timer1<20)
    {
        display_state=2;
    }   
    /*
    else if (timer1<30)
    {
        display_state=3;
    }
    else if (timer1<40)
    {
        display_state=4;
    } 
    else if (timer1<50)
    {
        display_state=5;
    }
     else if (timer1<60)
    {
        display_state=6;
    }
     else if (timer1<70)
    {
        display_state=7;
    }
     else if (timer1<80)
    {
        display_state=8;
    }
     else if (timer1<=90)
    {
        display_state=9;
    }
    */
    else
    timer1=0;
}
void digital_point_control(void)
{
    if (timer2==0)
    dp=1;
    else if (timer2<=5)
    dp=0;
    else
    timer2=0;
    }
void timers_control()
{
    timer1++;
    timer2++;
}