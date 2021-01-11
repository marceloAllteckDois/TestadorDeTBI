/*
 * File:   main.c
 * Author: eu
 *
 * Created on October 8, 2020, 5:33 AM
 */

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF         // Data EEPROM Memory Code Protection bit (Data EEPROM code-protected)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF          // Flash Program Memory Code Protection bit (All program memory code-protected)
#define _XTAL_FREQ 20000000
#define TMR2PRESCALE 16
#define BT_TESTE  PORTCbits.RC6
#define BT_MANUAL PORTCbits.RC7
#define LED_OK    PORTCbits.RC4
#define LED_MANUAL PORTCbits.RC5
#define LED_ERRO  PORTCbits.RC3
#include <xc.h>
#include "lcd_txt_lib.h"
void setup(void);
void run(void);

void main(void) {
    setup();
    run();
}

void setup(){
    TRISA=0X0F;
    TRISB=0;
    TRISC=0XC0;
    Adc_Init();
    Pwm_Init();
    Pwm_Set_Duty(0);
    Pwm_Stop();
    INTCON=0;
    PORTA=0;
    PORTB=0;
    PORTC=0;
    Lcd_Init();
    
    Lcd_Cmd(LCD_CURSOR_OFF);
    Lcd_Cmd(LCD_CLEAR);
    TelaIntro();
    __delay_ms(1000);
}

void run(){
   struct Resultado r;
   struct Analog a;
   long offset;
   short bt;
   short alarme=OK;
    do{
      a=Get_Valor();
      Pwm_Set_Duty(a.duty);
      bt=Botao();
      if(bt==MANUAL)LED_MANUAL=~LED_MANUAL;
      else if(bt==TESTE){
          TelaTeste();
          r=Teste();
          alarme=r.resultado;
      }
      else if(bt==LIMPA){
          TelaReset();
          alarme=OK;
          LED_ERRO=0;
      }
      if(LED_MANUAL==1 && alarme==OK){
          Pwm_Start();
      }
      else {
          Pwm_Stop();
          offset=a.corrente;
      }
      //if(alarme==OK)alarme=Alarme(LED_MANUAL,a,offset);
      if(alarme!=OK){
          LED_MANUAL=0;
          LED_OK=0;
          LED_ERRO=1;
          Pwm_Stop();
          //TelaAlarme(alarme);
         
      }
      TelaPrincipal(&a,&offset);
    }while(1);
}