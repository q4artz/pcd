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
void OptionSelect(){
    
    // Job (Let user input what they want to do. then pass to FilterOption(); );

    // 0 == exit 1 == add 2 == modify 3 == delete
    
    int *option;
    char confirmation = 'N';
    
    while(confirmation != 'y'){
        puts("\nWhat would you like to do?\n");
        puts("0 > Exit");
        puts("1 > Add");
        puts("2 > Modify");
        puts("3 > Delete");
        scanf("%d",&option);
        
        printf("\n\nConfirm option \t%d ??\n",option);
        puts("\ny > proceed \nn > no proceed \n(Pease only enter lower case)\n");
        scanf(" %c",&confirmation);
        puts("\n");
    }
    FilterOption(&option);
}
int FilterOption(int *option){

    // Job (Filter out User option, throw them to the place they want);

    printf("\nUser selected option \t%d\n",*option);
    
    if(*option == 0){
        puts("\nExiting Program... \n");
        return 0;
    }
    else if(*option == 1){
        AddModule();
    }
    else if(*option == 2){
        ModifyModule();
    }
    else if(*option == 3){
        DeleteModule();
    }
    else{
        puts("\nPlease Select A Valid Option\n");
        OptionSelect();
    }
}
void AddModule(){
    char confirmation; 
    int Error = 0;
    puts("Activating Add Module... \n");

    WriteToFile();


};
ModifyModule(){
    puts("Activating Modify Module... \n");

    SearchModule();
};
DeleteModule(){
    puts("Activating Delete Module... \n");

    SearchModule();
};
SearchModule(){
    puts("Activating Search Module");
};
void DisplayModule(){
    puts("Activating Display Module... \n");

    ReadFromFile();
};
void WriteToFile(){
    
    puts("Accessing Writing Module... \n");

    SalesOrder SalesDetail;
    double TotalPrice;
    char confirmation;

    FILE *filePTR = fopen("SalesModuleFile.bin","wb+");
    
    if(filePTR == NULL){
        printf("Error!");   
        exit(1); 
    };

    do{
    puts("Format: \nSales Order ID (eg. S001)\nItem Code (eg. ITM001)\nQuantity Ordered (eg. 10)\nPrice (eg. RM 250k)\nMember ID (eg. MEM001)\n");

    scanf(" %s",&SalesDetail.SalesOrderID);
    scanf("%s",&SalesDetail.ItemCode);
    scanf("%d",&SalesDetail.QuantityOrdered);
    scanf("%lf",&SalesDetail.Price);
    scanf(" %s",&SalesDetail.SalesOrderID);
  
    puts("Currently Writting to file... \n");
    fwrite(&SalesDetail,sizeof(SalesDetail),1,filePTR);

    puts("\nDo you Want to Continue? \n");
    puts("\ny > proceed \nn > no proceed \n(Pease only enter lower case)\n");
    scanf(" %c",&confirmation);
    puts("\n");
    
    }while(confirmation != 'n');

    puts("Exiting Writing Module... \n");
}
void ReadFromFile(){

    puts("Accessing Reading Module... \n");

    FILE *filePTR = fopen("SalesModuleFile.bin","rb");

    int counter;

    if(filePTR == NULL){
        puts("There is nothing inside the file.");
        fclose(filePTR);
    };
    while(!EOF){
        char buffer[256];
        fread(&buffer,sizeof(buffer),1,filePTR);
        printf("%s",buffer);
    };
};
CountFileAccess(int *AccessCount){};
int main(){
    
    DisplayModule();

    OptionSelect();

    puts("back at main");
}