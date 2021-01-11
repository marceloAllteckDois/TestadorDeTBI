#define PWM PORTCbits.RC2

void Pwm_Init();//2kHz
void Pwm_Set_Duty(long);
void Pwm_Start(void);
void Pwm_Stop(void);
void Pwm_Init(){
    PR2 = 128;//(_XTAL_FREQ/(freq*4*TMR2PRESCALE)) - 1; 
    //CCP1M3 = 1; CCP1M2 = 1;  //Configure the CCP1 module 
    T2CKPS0 = 1;T2CKPS1 = 1; TMR2ON = 1; //Configure the Timer module
    //TRISC2 = 0; // make port pin on C as output
}

void Pwm_Set_Duty(long d){
    long duty=(d*512)/100;
    if(duty<520)
  {

    //duty = (duty/1023)*(_XTAL_FREQ/(PWM_freq*TMR2PRESCALE)); // On reducing //duty = (((float)duty/1023)*(1/PWM_freq)) / ((1/_XTAL_FREQ) * TMR2PRESCALE);
    CCP1X =(__bit)duty >> 10; //Store the 1st bit
    CCP1Y =(__bit)duty >> 9; //Store the 0th bit
    CCPR1L =duty>>2;// Store the remining 8 bit
  }
}

void Pwm_Start(){
    CCP1M3 = 1; CCP1M2 = 1;
    T2CONbits.TMR2ON=1;
}

void Pwm_Stop(){
   CCP1M3 = 0; CCP1M2 = 0;
   T2CONbits.TMR2ON=0;
   TMR2=0;
   PWM=0;
}