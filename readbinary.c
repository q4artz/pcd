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

    FILE *filePTR = fopen("SalesModuleFile.bin","rb+");

    int counter;

    if(filePTR == NULL){
        puts("There is nothing inside the file.");
        fclose(filePTR);
    };

    while(fread(&SalesDetail,sizeof(SalesDetail),1,filePTR) != 0){
       fwrite(&SalesDetail.SalesOrderID,sizeof(char),5,filePTR);
       fwrite(&SalesDetail.ItemCode,sizeof(char),7,filePTR);
       fwrite(&SalesDetail.QuantityOrdered,sizeof(int),1,filePTR);
       fwrite(&SalesDetail.Price,sizeof(double),1,filePTR);
       fwrite(&SalesDetail.MemberID,sizeof(char),10,filePTR);
    }
    printf("thing from bin file \n%s\n%s\n%d\n%.2lf\n%s\n"
    ,SalesDetail.SalesOrderID,SalesDetail.ItemCode,SalesDetail.QuantityOrdered,SalesDetail.Price,SalesDetail.MemberID);
}