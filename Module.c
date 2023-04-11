#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996);
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
void ModifyModule();
void DisplayModule();
void WriteToFile();
void SearchModule();
void ReadFromFile();
void CountFileAccess(int *AccessCount);
void ModuleSelect();
int AskForContinueation();
void ReportModule(int *CozyReport);

int main(int argc, char *argv[]){

    puts("                   '                   ");
    puts("                  'o'                  ");  
    puts("                 'ooo'                 ");   
    puts("                'ooxoo'                ");  
    puts("               'ooxxxoo'               ");   
    puts("              'oookkxxoo'              "); 
    puts("             'oiioxkkxxoo'             ");   
    puts("            ':;:iiiioxxxoo'            ");  
    puts("               `'.;::ioxxoo'           ");  
    puts("          '-.      `':;jiooo'          "); 
    puts("         'oooio-..     `'i:io'         ");  
    puts("        'ooooxxxxoio:,.   `'-;'        ");  
    puts("       'ooooxxxxxkkxoooIi:-.  `'       "); 
    puts("      'ooooxxxxxkkkkxoiiiiiji'         ");   
    puts("     'ooooxxxxxkxxoiiii:'`     .i'     ");
    puts("   'ooooxxxxxoi:::'`       .;ioxo'     "); 
    puts("   'ooooxooi::'`         .:iiixkxxo'   ");
    puts("  'ooooi:'`                `'';ioxxo'  ");
    puts(" 'i:'`                          '':io' ");
    puts("'`                                   `'");

    puts("\t---------------------------------------------------");
    puts("|\tWelcome to Anchor Company Module Management Program\t|");

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
        puts("3 > Search");
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
    else if(*option == 3){
       SearchModule();
    }
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

    AskForContinueation();
};

void SearchModule(){
    puts("Activating Search Module");
    SalesOrder SalesDetail;
    char UserInputSalesOrderID[20];
    char confirmation = 'n';
    int Choice;
    int IDfound =0;
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
    }
    if(!IDfound){
        puts("Sales ID not found");
    };

    fclose(filePTR);
    

    AskForContinueation();

};
void DisplayModule(){
    puts("\nActivating Display Module... \n");
    
    int ReportSelection;
    puts("Would you like to Look at a Compact Report or Cozy Report?");
    puts("\n1 > Compact Report(no fancy formatting)\n2 > Cozy Report(Fancy Formatting)\n");
    scanf("%d",&ReportSelection);
    
    if(ReportSelection == 1)
        ReadFromFile();

    ReportModule(&ReportSelection);

    AskForContinueation();
};
void ReportModule(int *CozyReport){
       puts("You had chosen Cozy Report format.. good choice..\n");

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

    puts("------------------------------------------------------------");
    puts("||\tAnchor Company Cozy Sales Report\t\t ||");
    puts("------------------------------------------------------------");
    printf("|| \tSales Order ID \t\t>> \t%s\t\t ||\n",SalesDetail.SalesOrderID);
    printf("|| \tSales Item Code \t\t>> \t%s\t ||\n",SalesDetail.ItemCode);
    printf("|| \tQuantity Ordered \t\t>> \t%d\t ||\n",SalesDetail.QuantityOrdered);
    printf("|| \tSales Item Price \t\t>> \t%.2lf\t ||\n",SalesDetail.Price);
    printf("|| \tMember ID \t\t>> \t%s\t\t ||\n",SalesDetail.MemberID);
    puts("------------------------------------------------------------");

    fclose(filePTR);
}
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
        puts("\ny > Continue \nn > no continue \n(Pease only enter lower case)\n");
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