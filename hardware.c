


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "registros.h"
#include "hardware.h"

static char gpioxx[8]={"/sys/class/gpio/gpio17/direction","/sys/class/gpio/gpio4/direction","/sys/class/gpio/gpio18/direction","/sys/class/gpio/gpio23/direction","/sys/class/gpio/gpio24/direction","/sys/class/gpio/gpio25/direction","/sys/class/gpio/gpio22/direction","/sys/class/gpio/gpio27/direction"};


int Direction_bits (void){
    
    FILE *handle_export;
    int nWritten,i;
    
    for(i=0;i<8;i++){
        
        if((handle_export = fopen(gpioxx[i],"w")) == NULL){
        printf("Cannot open DIRECTIN file.Try later\n");
        return (1);
        }
        nWritten=fputs("out",handle_export);
        if (nWritten==-1){
            printf("Cannot DIRECTION PIN.Try again later.\n");
            return(1);
        }
        else{
            printf("DIRECTION file for PIN opened successfully \n");
        }
        fclose(handle_export);
    }
    
    
    
    
    
    
    
}
