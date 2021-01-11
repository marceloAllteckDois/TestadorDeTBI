
#include"adc_func_lib.h"
#include "pwm_lib.h"
#define TESTE 0x01
#define MANUAL 0X02
#define LIMPA  0x03
#define NADA   0xff
#define OK 0X04
#define CABO_ABERTO 0x05
#define SOBRECORRENTE 0X06
#define FALHA_TRILHAS 0X07
#define MOTOR_ABERTO 0X09
#define CORPO_OBSTRUIDO 0X0A

struct Analog Get_Valor(void);
struct NumChar Get_Char(long);
short Botao();
short Alarme(short,struct Analog,long);
struct Resultado Teste();
long Filtro();

long memoP1,memoP2;

struct Analog{
    long duty;
    long p1;
    long p2;
    long corrente;
}; 

struct NumChar{
    unsigned char u;
    unsigned char d;
    unsigned char c;
};

struct Resultado{
    short resultado;
    long maxCorrente;
    long p1Init;
    long p1Final;
    long p2Init;
    long p2Final;
};

struct Analog Get_Valor(){
    struct Analog a;
    a.duty=Adc_Read(DUTY);
    a.p1=Adc_Read(PISTA1);
    a.p2=Adc_Read(PISTA2);
    a.corrente=Filtro();
    a.duty=(a.duty*100)/1024;
    a.p1=(a.p1*500)/1023;
    a.p2=(a.p2*500)/1023;
    a.corrente=(a.corrente*520)/1023;
    return a;
}

struct NumChar Get_Char(long v){
    struct NumChar c;
    c.u=(((v%1000)%100)%10)+48;
    c.d=(((v%1000)%100)/10)+48;
    c.c=((v%1000)/100)+48;
    return c;
}
long Filtro(){
    long b=0;
    long ff=0;
    long f=0;
    int i,ii;
    for(ii=0;ii<10;ii++){
        for(i=0;i<10;i++){
            b=Adc_Read(CORRENTE);
            if(b>f)f=b;
        }
        ff=ff+f;
    }
    ff=ff/10;
    return ff;
}

short Alarme(short on, struct Analog a, long offset){
    long r;
    r=a.corrente-offset;
    if(r<0)r=r*(-1);
    if(r>30) return SOBRECORRENTE;
    else if(a.p1<100 && a.p2<100) return CABO_ABERTO;
    else if(on==1){
        if(a.duty>20 && a.corrente<2) return MOTOR_ABERTO;
        /*if(a.duty<=25){
            memoP1=a.p1;
            memoP2=a.p2;
        }
        if(a.duty>25){
            if(a.p1==memoP1 || a.p2==memoP2)
                return CORPO_OBSTRUIDO;
        }*/
    }
    else return OK;
}


short Botao(){
    short r=NADA;
    do{
        if(BT_TESTE==0 && BT_MANUAL==1){
            r=TESTE;
            __delay_ms(50);
        }
        else if(BT_TESTE==1 && BT_MANUAL==0){
            r=MANUAL;
            __delay_ms(50);
        }
        if(BT_TESTE==0 && BT_MANUAL==0){
            r=LIMPA;
            do{
               __delay_ms(50); 
            }while(BT_TESTE==0 || BT_MANUAL==0);
            break;
        }
        
    }while(BT_TESTE==0 || BT_MANUAL==0);

    return r;
}

struct Resultado Teste(){
    struct Resultado r;
    struct Analog a;
    int i,ii;
    long offset;
    short alarme;
    Pwm_Stop();
    a=Get_Valor();
    offset=a.corrente;
    r.p1Init=a.p1;
    r.p2Init=a.p2;
    for(i=0;i<3;i++){
        Pwm_Start();
        Pwm_Set_Duty(0);
        __delay_ms(600);
        for(ii=0;ii<=50;ii++){
            Pwm_Set_Duty(ii);
            a=Get_Valor();
            //alarme=Alarme(1,a,offset);
            if(alarme!=OK){
                r.resultado=alarme;
                return r;
            }
            if(a.p1<10 || a.p2<10){
                r.resultado=FALHA_TRILHAS;
                r.maxCorrente=a.corrente-offset;
                if(r.maxCorrente<0)r.maxCorrente=r.maxCorrente*(-1);
                return r;
            }
            __delay_ms(50);
            if(ii==50){
                r.maxCorrente=a.corrente-offset;
                if(r.maxCorrente<0)r.maxCorrente=r.maxCorrente*(-1);
                r.p2Final=a.p2;
                r.p1Final=a.p1;
                r.resultado=OK;
            }
        }
    }
    
    return r;
}