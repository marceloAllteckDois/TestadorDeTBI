#define DUTY 0x01
#define PISTA1 0x02
#define PISTA2 0x03
#define CORRENTE 0x04

void Adc_Init(void);
long Adc_Read(short);

void Adc_Init(){
   ADCON1=0xC2;
   ADCON0bits.ADCS1=1;
   ADCON0bits.ADCS0=0;
}
long Adc_Read(short porta){
    long r;
    switch (porta){
        case DUTY:
            ADCON0bits.CHS2=0;
            ADCON0bits.CHS1=0;
            ADCON0bits.CHS0=0;
            break;
        case PISTA1:
            ADCON0bits.CHS2=0;
            ADCON0bits.CHS1=0;
            ADCON0bits.CHS0=1;
            break;
        case PISTA2:
            ADCON0bits.CHS2=0;
            ADCON0bits.CHS1=1;
            ADCON0bits.CHS0=0;
            break;
        case CORRENTE:
            ADCON0bits.CHS2=0;
            ADCON0bits.CHS1=1;
            ADCON0bits.CHS0=1;
            break;
    }
    ADCON0bits.ADON=1;
    __delay_us(50);
    ADCON0bits.GO_DONE=1;
    do{
        __delay_us(50);
    }while(ADCON0bits.GO_DONE==1);
    r= ADRESH;
    r= r << 8;
    r= r+ADRESL;
    
    return r;
}