/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

int export_bits(void)
{
    FILE *handle_export;
    
    int verif,i;
    char *bits[8]={"17","4","18","23","24","25","22","27"};
    
    for(i=0; i<8; i++)
    {
        if((handle_export = fopen("/sys/class/gpio/export","w")) == NULL);
        {
            printf("Cannot open EXPORT file.Try later\n");
            return (1);
        }
        verif=fputs(bits[i],handle_export);
        
        if (verif==-1)
        {
            printf("Cannot EXPORT PIN.Try again later.\n");
             return(1);
        }
        else{
            printf("EXPORT file opened succesfully \n");
        }
    }   
    
    fclose(handle_export);
}

int unexport_bits(void)
{
    FILE *handle_unexport;
    
    int verif,i;
    char *bits[8]={"17","4","18","23","24","25","22","27"};
    
    for(i=0; i<8; i++)
    {
        if((handle_unexport = fopen("/sys/class/gpio/unexport","w")) == NULL);
        {
            printf("Cannot open UNEXPORT file.Try later\n");
            return (1);
        }
        verif=fputs(bits[i],handle_unexport);
        
        if (verif==-1)
        {
            printf("Cannot UNEXPORT PIN.Try again later.\n");
             return(1);
        }
        else{
            printf("UNEXPORT file opened succesfully \n");
        }
    }   
    
    fclose(handle_unexport);
}

int valor_bit(int pos,int i){
    
    FILE *handle_value;
    int nWritten;
    const char *estado[2]={'0','1'},;
    
    
    if((handle_value = fopen(gpioxx[pos],"w")) == NULL){
        
            printf("Cannot open VALUE file.Try later\n");
            return (1);   
    }
    else{
    
            printf("Device successfully opened.Try again later.\n");
    }
    
    nWritten=fputc(estado[i],handle_value);
    
    if (nWritten==-1){
           
        printf("Cannot write to file.Try again later.\n");
            return(1);
    }
    else{
        
            printf("Write to file %s successfully done \n");
    }
    fclose(handle_value);

}