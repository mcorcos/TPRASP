


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "registros.h"
#include "hardware.h"


int prendo_bits (void){
	
    FILE *bit0;
    int nwrite;
    bit0=fopen("/sys/class/gpio/export","w");
    nwrite=fputs("17",bit0);
    fclose(bit0);
    bit0=fopen("/sys/class/gpio/gpio17/direction","w");
    nwrite=fputs("out",bit0);
    fclose(bit0);
    bit0=fopen("/sys/class/gpio/gpio17/value","w");
    nwrite=fputs("1",bit0);
    fclose(bit0);
}

int prendo_bits (void){
	
    FILE *handle_export;
    int nWritten;
    if((hanfle_export = fopen("/sys/class/gpio/export","w")) == NULL);{
        printf("Cannot open EXPORT file.Try later\n");
        return (1);
        
    }
    nWritten=fputs("xx",handle_export);
    if (nWritten==-1){
        printf("Cannot EXPORT PIN.Try again later.\n");
        return(1);
    }
    else{
        printf("EXPORT file opened succesfully \n");
    }
    fclose(handle_export);
    
       if((hanfle_export = fopen("/sys/class/gpio/gpioxx/direction","w")) == NULL);{
        printf("Cannot open DIRECTIN file.Try later\n");
        return (1);
        
    }
    nWritten=fputs("out/in",handle_export);
    if (nWritten==-1){
        printf("Cannot DIRECTION PIN.Try again later.\n");
        return(1);
    }
    else{
        printf("DIRECTION file for PIN opened succesfully \n");
    }
    fclose(handle_export);
    
    if((hanfle_export = fopen("/sys/class/gpio/gpioxx/value","w")) == NULL);{
     
     printf("Cannot open VALUE file.Try later\n");
     return (1);   
    }
    else{
     printf("Device succesfully opened");
    }
    nWritten=fputs("xx",handle_export);
    if (nWritten==-1){
        printf("Cannot open device.Try again later.\n");
        return(1);
    }
    else{
        printf("Device succesfully opened \n");
    }
    fclose(handle_export);
}