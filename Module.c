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

void SalesModuleOptionSelect();
int FilterOption(int *option);
void AddModule();
//void DeleteModule();
void ModifyModule();
void DisplayModule();
void WriteToFile();
void SearchModule();
void ReadFromFile();
void CountFileAccess(int *AccessCount);
void ModuleSelect();
int AskForContinueation();

int main(int argc, char *argv[]){

    ModuleSelect();
};
void SalesModuleOptionSelect(){
    
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
        puts("4 > Display");
        scanf("%d",&option);
        
        printf("\n\nConfirm option \t%d ??\n",option);
        puts("y > proceed \nn > no proceed \n(Pease only enter lower case)");
        scanf(" %c",&confirmation);
        puts("\n");
    }
    FilterOption(&option);
}
int FilterOption(int *option){

    // Job (Filter out User option, throw them to the place they want);

    printf("\nUser selected option >\t%d\n",*option);
    
    if(*option == 0){
        puts("\nExiting Program... ");
        return 0;
    }
    else if(*option == 1){
        AddModule();
    }
    else if(*option == 2){
        ModifyModule();
    }
//    else if(*option == 3){
//        DeleteModule();
//    }
    else if(*option == 4){
        DisplayModule();
    }
    else{
    puts("\n\nPlease Select A Valid Option\n");
    SalesModuleOptionSelect();
    };
};
void AddModule(){
    //Job Write to file, ask User if they want to see file content. Yes throw to DisplayModule(). No go back OptionSelect();
    char confirmation;
    puts("Activating Add Module... \n");

    WriteToFile();

    puts("Would You Like to View Contents within the file?\n");
    puts("\ny > proceed \nn > no proceed \n(Pease only enter lower case)\n");
    scanf(" %c",&confirmation);
    
    if(confirmation == 'y'){
        DisplayModule();
    }

    AskForContinueation();

};
void ModifyModule(){
    puts("Activating Modify Module... \n");

    SearchModule();

    AskForContinueation();
};
//void DeleteModule(){
//    puts("Activating Delete Module... \n");
//
//    SearchModule();
//
//    AskForContinueation();
//};
void SearchModule(){
    puts("Activating Search Module");
    SalesOrder SalesDetail;
    char UserSearchString[20];
    char confirmation = 'n';
    FILE *filePTR = fopen("SalesModuleFile.bin","wb");

    while(confirmation != 'y'){
        puts("Enter the Category You wanted to find\n1. salesorderid \n2. itemcode\n 3. quantityordered\n 4. price \n 5. memberid \n");
        puts("!!! Please only enter Lower Case !!!");
        scanf("%s",UserSearchString);
        printf("You Written %s , Are you sure this is the one? \n",UserSearchString);
        puts("\ny > proceed \nn > no proceed \n(Pease only enter lower case)\n");
        scanf("%c",&confirmation);
    }

    if(strcmp(UserSearchString,"salesorderid")== 0){
         while(fread(&SalesDetail,sizeof(SalesDetail),1,filePTR) != 0){
           fwrite(&SalesDetail.SalesOrderID,sizeof(char),5,filePTR);
        }
    }
    else if(strcmp(UserSearchString,"itemcode")== 0){
         while(fread(&SalesDetail,sizeof(SalesDetail),1,filePTR) != 0){
           fwrite(&SalesDetail.ItemCode,sizeof(char),7,filePTR);
        }
    }
    else if(strcmp(UserSearchString,"quantityordered")== 0){
        while(fread(&SalesDetail,sizeof(SalesDetail),1,filePTR) != 0){
           fwrite(&SalesDetail.QuantityOrdered,sizeof(int),1,filePTR);
        }
    }
    else if(strcmp(UserSearchString,"price")== 0){
         while(fread(&SalesDetail,sizeof(SalesDetail),1,filePTR) != 0){
           fwrite(&SalesDetail.Price,sizeof(double),1,filePTR);
        }
    }
    else if(strcmp(UserSearchString,"memberid")== 0){
         while(fread(&SalesDetail,sizeof(SalesDetail),1,filePTR) != 0){
           fwrite(&SalesDetail.MemberID,sizeof(char),10,filePTR);
        }
    }
    else{
        puts("Please Enter Valid Category Stupid");
    }

    // display everything from UserSearchString
    AskForContinueation();

};
void DisplayModule(){
    puts("\nActivating Display Module... \n");

    ReadFromFile();

    AskForContinueation();
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
 
    scanf(" %s",SalesDetail.SalesOrderID);
    scanf(" %s",SalesDetail.ItemCode);
    scanf("%d",&SalesDetail.QuantityOrdered);
    scanf("%lf",&SalesDetail.Price);
    scanf(" %s",SalesDetail.MemberID);

    puts("\nCurrently Writting to file... \n");
    fwrite(&SalesDetail,sizeof(SalesDetail),1,filePTR);

    puts("\nDo you Want to Continue? \n");
    puts("\ny > proceed \nn > no proceed \n(Pease only enter lower case)\n");
    scanf(" %c",&confirmation);
    puts("\n");
    
    }while(confirmation != 'n');

    fclose(filePTR);

    puts("Exiting Write Module... \n");
}
void ReadFromFile(){

    puts("\nAccessing Read Module... \n");

    FILE *filePTR = fopen("SalesModuleFile.bin","rb");
    SalesOrder SalesDetail;
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

    printf("\n\nSales Order ID > %s\nItem Code > %s\nQuantity Ordered > %d\nPrice > %.2lf\nMember ID > %s\n"
    ,SalesDetail.SalesOrderID,SalesDetail.ItemCode,SalesDetail.QuantityOrdered,SalesDetail.Price,SalesDetail.MemberID);

    fclose(filePTR);
    puts("\n\nExiting Read Module... \n");
};
int AskForContinueation(){
    char confirmation = 'n';
    char DoubleConfirm = 'n';
    while(DoubleConfirm != 'y'){
        puts("Would you like to continue?");
        puts("\ny > proceed \nn > no proceed \n(Pease only enter lower case)\n");
        scanf(" %c",&confirmation);

        printf("You had choosen %c , Are You Sure?\n",confirmation);
        puts("\ny > Yes i Confirm \nn > no I no Confirm \n(Pease only enter lower case)\n");
        scanf(" %c",&DoubleConfirm);
    }
    if(confirmation == 'n'){
        return 0;
    }
    ModuleSelect();
};
void ModuleSelect(){
    // 1 == SalesModule 2 == Staff Module 3 == Stockmodule
    int ModuleSelect;
    puts("Which Module would you like to access? ");
    puts("0 > Exit");
    puts("1 > Sales System Module");
    puts("2 > Staff Module");
    puts("3 > Member Module");
    scanf("%d",&ModuleSelect);

    if(ModuleSelect == 0){
        puts("Exiting.. ");
        exit(0);
    }
    else if(ModuleSelect == 1){
        SalesModuleOptionSelect();    
    }
    else if(ModuleSelect == 2){
        // SatffModule();
    }
    else if(ModuleSelect == 3){
        // MemberModule();
    }
    else{
        puts("You did not select a Valid Module\n");
    }
};
void CountFileAccess(int *AccessCount){};