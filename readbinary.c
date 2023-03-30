#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
typedef struct{
    char SalesOrderID[5];
    char ItemCode[7];
    int QuantityOrdered;
    double Price;
    char MemberID[10];
}SalesOrder;


int main(){
    SalesOrder SalesDetail;
    puts("Accessing Reading Module... \n");

    FILE *filePTR = fopen("SalesModuleFile.bin","rb");

    int counter;

    if(filePTR == NULL){
        puts("There is nothing inside the file.");
        fclose(filePTR);
    };
    while(!EOF){
        char buffer[256];
        fread(&SalesDetail,sizeof(SalesOrder),256,filePTR);
    };
    printf("thing from bin file \n%s\n%s\n%d\n%lf\n%s\n",SalesDetail.SalesOrderID,SalesDetail.ItemCode,SalesDetail.QuantityOrdered,SalesDetail.Price,SalesDetail.MemberID);
}