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

//int display_state = 0;

int display_state=0;

int timer1=0;
int timer2=0;

void init_function(void);
void seven_segment_control(void);
void set_seven_segment_display(void);
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
    
    if(display_state == 0)
    {
      display_character_0();
      }
    else if(display_state == 1)
        {display_character_1();
        }
    else if(display_state == 2)
        {
        display_character_2();
        }
    else if(display_state == 3)
        {
         display_character_3();
      }
    else if(display_state == 4)
        {
        display_character_4();
        }
    else if(display_state == 5)
        {
        display_character_5();
      }
    else if(display_state == 6)
    {
        display_character_6();
        }
    else if(display_state == 7)
        {
        display_character_7();
        }
    else if(display_state == 8)
        {
        display_character_8();
        }
    else if (display_state == 9)
        {
        display_character_9();
        }
}
void set_seven_segment_display(void)
{
    if (timer1==0)
    seven_segment_control=1;
    else if (timer1<=9)
    seven_segment_control=0;
    else 
    timer1=0;

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