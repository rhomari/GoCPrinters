
#include <windows.h>
#include "cprinters.h"
#include <stdio.h>
#include <stdlib.h>
#include <winspool.h>

#include <string.h>


void listPrinters()
{
   
    DWORD Needed, Returned;
    PRINTER_INFO_5 * printerInformations;
   
    
    EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS , NULL, 5, NULL, 0, &Needed, &Returned);
    LPBYTE buffer = (LPBYTE)malloc(Needed);
    
   
    if (EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS,NULL,5, buffer,Needed,&Needed,&Returned)){
        printerInformations = (PRINTER_INFO_5*) buffer;
        int counter = 0;
        for (int i=0; i< Returned;i++, printerInformations++ ){
            counter++;
            printf("%s \n",printerInformations->pPrinterName);
     
        }
 
    }
    else{
        printf("ERROR");
    }
    free(buffer);
    

}
