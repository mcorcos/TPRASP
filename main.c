/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: jucardozo
 *
 * Created on 26 de octubre de 2019, 15:03
 */

#include <stdio.h>
#include <stdlib.h>
#include "registros.h"

#define ltrT(i) ((i)=='t' || (i)=='T')  //cambia todos los bits del puerto por el opuesto
#define ltrQ(i) ((i)=='q' || (i)=='Q')  //letra q me permite salir del programa
#define ltrC(i) ((i)=='c' || (i)=='C')  //letra c me permite apagar todos los bits
#define ltrS(i) ((i)=='s' || (i)=='S')  //letra s me permite prender todos los bits
#define numvalido(i)    ((i)>='0' && (i)<='7')
#define MaskT      0xFF//mascara que sirve para manipular los bits del puerto A
#define MaskC      0x00

#define PRENDER 1
#define APAGAR  0
/*
 */



/*
 * 
 */

int main() {
    int entrada,loop=1,verif;    //entrada es una variable que me permite almacenar el dato aportado por el usuario, loop, me permite permanecer en el ciclo
    extern registros_t *puertos;
    char portA='A';     //solo se desea modificar el puerto A
    printf ("Ingrese numero de bit o letra correspondiente\n");
    
    
    if ((export_bits())==1 || (direction_bits())==1 ){
        
        loop=0;
    }
    
    
    do{
    while (kbhit()){
        
        entrada=getchar ();
        
        if (numvalido(entrada)) {   //usar macro de libreria
            bitSet(portA, entrada);
            printf (" El valor del puerto A es: 0x%x\n", (*puertos).px.a);
            valor_bit(entrada,PRENDER);
        }
        else if (ltrT(entrada)){
            MaskToggle(MaskT,portA);
            printf (" El valor del puerto A es: 0x%x\n", (*puertos).px.a);
        }
        else if (ltrC(entrada)){
            MaskOff(MaskC,portA);
            printf (" El valor del puerto A es: 0x%x\n", (*puertos).px.a);
            
            valor_bit(0,APAGAR);
            valor_bit(1,APAGAR);
            valor_bit(2,APAGAR);
            valor_bit(3,APAGAR);
            valor_bit(4,APAGAR);
            valor_bit(5,APAGAR);
            valor_bit(6,APAGAR);
            valor_bit(7,APAGAR);
            
        
        }
        else if (ltrS(entrada)){
            MaskOn(MaskT,portA);
            printf (" el valor del puerto A es: 0x%x\n", (*puertos).px.a);
        
            valor_bit(0,PRENDER);
            valor_bit(1,PRENDER);
            valor_bit(2,PRENDER);
            valor_bit(3,PRENDER);
            valor_bit(4,PRENDER);
            valor_bit(5,PRENDER);
            valor_bit(6,PRENDER);
            valor_bit(7,PRENDER);
        
        }
        else if (ltrQ(entrada)){
            loop=0;
        }
       
        
    }
    }while(loop);
    
    unexport_bits();
    
    printf ("bye\n");
    return (EXIT_SUCCESS);
}
        
   