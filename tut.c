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
    int modified = 0;
    int IDfound =0;
    int NewIntValue;
    double NewDoubleValue;
    char UserInputSalesOrderID[5];
    char field[20];
    char NewValue[20];
    FILE *filePTR = fopen("SalesModuleFile.bin","rb+");

    puts("Enter Sales Order id > eg.S001");
    scanf("%s",UserInputSalesOrderID);

    while(fscanf(filePTR,"%[^\n]-%[^\n]-%d-%lf-%[^\n]",SalesDetail.SalesOrderID,SalesDetail.ItemCode,&SalesDetail.QuantityOrdered,&SalesDetail.Price,SalesDetail.MemberID) != EOF){
        if(strcmp(SalesDetail.SalesOrderID,UserInputSalesOrderID)==0){
            puts("Sales Module Found");
             printf("\n\nSales Order ID > %s\nItem Code > %s\nQuantity Ordered > %d\nPrice > %.2lf\nMember ID > %s\n"
            ,SalesDetail.SalesOrderID,SalesDetail.ItemCode,SalesDetail.QuantityOrdered,SalesDetail.Price,SalesDetail.MemberID);
            IDfound = 1;
        }

        printf("\nEnter field to modify: ");
        scanf("%s", field);

        if(strcmp(field,"quantity") == 0){
            puts("Enter new integer Value");
            scanf("%d",&NewIntValue);
        }
        else if(strcmp(field,"price") == 0){
            puts("Enter new Double Value");
            scanf("%lf",&NewDoubleValue);
        }
        else{
        printf("Enter new value: ");
        scanf("%s", NewValue);
        }
        if (strcmp(field, "salesorderid") == 0) {
                strcpy(SalesDetail.SalesOrderID, NewValue);
                modified = 1;
                printf("%s",SalesDetail.SalesOrderID);
            }
        else if (strcmp(field,"itemcode") == 0) {
                strcpy(SalesDetail.ItemCode,NewValue);
                modified = 1;
                printf("%s",SalesDetail.ItemCode);
            }
        else if (strcmp(field, "quantity") == 0) {
            SalesDetail.QuantityOrdered = NewIntValue;
            modified = 1;
        }
        else if (strcmp(field, "price") == 0) {
            SalesDetail.Price = NewDoubleValue;
            modified = 1;
        }
        else if (strcmp(field, "gender") == 0) {
            strcpy(SalesDetail.MemberID,NewValue);
            modified = 1;
        }
        if(modified == 1){
            fprintf(filePTR,"%s\n%s\n%d\n%lf\n%s",SalesDetail.SalesOrderID,SalesDetail.ItemCode,SalesDetail.QuantityOrdered,SalesDetail.Price,SalesDetail.MemberID);
            printf("\nSales information modified successfully.\n");
        }
        else{
            fprintf(filePTR,"%s\n%s\n%d\n%lf\n%s",SalesDetail.SalesOrderID,SalesDetail.ItemCode,SalesDetail.QuantityOrdered,SalesDetail.Price,SalesDetail.MemberID);
            printf("\nInvalid field name.\n");
        }
    }
    if(!IDfound){
        puts("Sales Does not exist.");
    }
    fclose(filePTR);
}