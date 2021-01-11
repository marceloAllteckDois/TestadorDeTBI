#include "lcd_func.h"
#include "prg_func_lib.h"

void TelaPrincipal(struct Analog*,long*);
void TelaIntro(void);
void TelaTeste(void);
void TelaReset(void);
void TelaAlarme(short);
void TelaResultado(struct Resultado);

unsigned char l;

void TelaPrincipal(struct Analog *a,long *offset){
    struct NumChar c;
    (*a).corrente=(*a).corrente-*offset;
    if((*a).corrente<0)(*a).corrente=(*a).corrente*(-1);
    Lcd_Cmd(LCD_RETURN_HOME);
    Lcd_Cmd(LCD_FIRST_ROW);
    // DUTY=XX%P1=XX.XV
    l='D';Lcd_Chr_CP(l);
    l='U';Lcd_Chr_CP(l);
    l='T';Lcd_Chr_CP(l);
    l='Y';Lcd_Chr_CP(l);
    l='=';Lcd_Chr_CP(l);
    c=Get_Char((*a).duty);
    Lcd_Chr_CP(c.d);
    Lcd_Chr_CP(c.u);
    l='%';Lcd_Chr_CP(l);
    l='P';Lcd_Chr_CP(l);
    l='1';Lcd_Chr_CP(l);
    l='=';Lcd_Chr_CP(l);
    c=Get_Char((*a).p1);
    Lcd_Chr_CP(c.c);
    l='.';Lcd_Chr_CP(l);
    Lcd_Chr_CP(c.d);
    Lcd_Chr_CP(c.u);
    l='v';Lcd_Chr_CP(l);
    //I=X.XXA_P2=X.XXV
    Lcd_Cmd(LCD_SECOND_ROW);
    l='I';Lcd_Chr_CP(l);
    l='=';Lcd_Chr_CP(l);
    c=Get_Char((*a).corrente);
    Lcd_Chr_CP(c.c);
    Lcd_Chr_CP(c.d);
    l='.';Lcd_Chr_CP(l);
    Lcd_Chr_CP(c.u);
    l='A';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l='P';Lcd_Chr_CP(l);
    l='2';Lcd_Chr_CP(l);
    l='=';Lcd_Chr_CP(l);
    c=Get_Char((*a).p2);
    Lcd_Chr_CP(c.c);
    l='.';Lcd_Chr_CP(l);
    Lcd_Chr_CP(c.d);
    Lcd_Chr_CP(c.u);
    l='V';Lcd_Chr_CP(l);
    
}

void TelaIntro(){
    Lcd_Cmd(LCD_RETURN_HOME);
    Lcd_Cmd(LCD_FIRST_ROW);
    //TESTADOR 
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l='T';Lcd_Chr_CP(l);
    l='E';Lcd_Chr_CP(l);
    l='S';Lcd_Chr_CP(l);
    l='T';Lcd_Chr_CP(l);
    l='A';Lcd_Chr_CP(l);
    l='D';Lcd_Chr_CP(l);
    l='O';Lcd_Chr_CP(l);
    l='R';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    //BORBOLETA
    Lcd_Cmd(LCD_SECOND_ROW);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l='B';Lcd_Chr_CP(l);
    l='O';Lcd_Chr_CP(l);
    l='R';Lcd_Chr_CP(l);
    l='B';Lcd_Chr_CP(l);
    l='O';Lcd_Chr_CP(l);
    l='L';Lcd_Chr_CP(l);
    l='E';Lcd_Chr_CP(l);
    l='T';Lcd_Chr_CP(l);
    l='A';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    
}

void TelaTeste(){
    Lcd_Cmd(LCD_RETURN_HOME);
    Lcd_Cmd(LCD_FIRST_ROW);
    //TESTANDO
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l='T';Lcd_Chr_CP(l);
    l='E';Lcd_Chr_CP(l);
    l='S';Lcd_Chr_CP(l);
    l='T';Lcd_Chr_CP(l);
    l='A';Lcd_Chr_CP(l);
    l='N';Lcd_Chr_CP(l);
    l='D';Lcd_Chr_CP(l);
    l='O';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    //AGUARDE:
    Lcd_Cmd(LCD_SECOND_ROW);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l='A';Lcd_Chr_CP(l);
    l='G';Lcd_Chr_CP(l);
    l='U';Lcd_Chr_CP(l);
    l='A';Lcd_Chr_CP(l);
    l='R';Lcd_Chr_CP(l);
    l='D';Lcd_Chr_CP(l);
    l='E';Lcd_Chr_CP(l);
    l=':';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    __delay_ms(1000);
}

void TelaReset(){
    Lcd_Cmd(LCD_RETURN_HOME);
    Lcd_Cmd(LCD_FIRST_ROW);
    //LIMPANDO
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l='L';Lcd_Chr_CP(l);
    l='I';Lcd_Chr_CP(l);
    l='M';Lcd_Chr_CP(l);
    l='P';Lcd_Chr_CP(l);
    l='A';Lcd_Chr_CP(l);
    l='N';Lcd_Chr_CP(l);
    l='D';Lcd_Chr_CP(l);
    l='O';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    //ALARMES
    Lcd_Cmd(LCD_SECOND_ROW);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l='A';Lcd_Chr_CP(l);
    l='L';Lcd_Chr_CP(l);
    l='A';Lcd_Chr_CP(l);
    l='R';Lcd_Chr_CP(l);
    l='M';Lcd_Chr_CP(l);
    l='E';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    l=' ';Lcd_Chr_CP(l);
    __delay_ms(1000);
}

void TelaResultado(struct Resultado r){
    Lcd_Cmd(LCD_RETURN_HOME);
    Lcd_Cmd(LCD_FIRST_ROW);
    int i;
    l='R';Lcd_Chr_CP(l);
    l=':';Lcd_Chr_CP(l);
    switch (r.resultado){
        case OK:
            l='O';Lcd_Chr_CP(l);
            l='K';Lcd_Chr_CP(l);
            for(i=0;i<13;i++){
                l=' ';
                Lcd_Chr_CP(l);
            }
            break;
        case SOBRECORRENTE:
            l='S';Lcd_Chr_CP(l);
            l='O';Lcd_Chr_CP(l);
            l='B';Lcd_Chr_CP(l);
            l='R';Lcd_Chr_CP(l);
            l='E';Lcd_Chr_CP(l);
            l='C';Lcd_Chr_CP(l);
            l='O';Lcd_Chr_CP(l);
            l='R';Lcd_Chr_CP(l);
            l='R';Lcd_Chr_CP(l);
            l='E';Lcd_Chr_CP(l);
            l='N';Lcd_Chr_CP(l);
            l='T';Lcd_Chr_CP(l);
            l='E';Lcd_Chr_CP(l);
            l=' ';Lcd_Chr_CP(l);
            break;
        case FALHA_TRILHAS:
            l='E';Lcd_Chr_CP(l);
            l='R';Lcd_Chr_CP(l);
            l='R';Lcd_Chr_CP(l);
            l='O';Lcd_Chr_CP(l);
            l=' ';Lcd_Chr_CP(l);
            l='T';Lcd_Chr_CP(l);
            l='R';Lcd_Chr_CP(l);
            l='I';Lcd_Chr_CP(l);
            l='L';Lcd_Chr_CP(l);
            l='H';Lcd_Chr_CP(l);
            l='A';Lcd_Chr_CP(l);
            l='S';Lcd_Chr_CP(l);
            l=' ';Lcd_Chr_CP(l);
            l=' ';Lcd_Chr_CP(l);
            break;
            default:
                
    }
}

void TelaAlarme(short v){
    
}