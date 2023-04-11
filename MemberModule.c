#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
typedef struct{
    char MemberID[10];
    char Name[50];
    char gender;
    char IC[15];
    char ContactNumber[12];
    char UpLineID[5];
}MemberInfo;

void SalesModuleOptionSelect(){
    // Job (Let user input what they want to do. then pass to FilterOption(); );

    // 0 == exit 1 == add 2 == modify 3 == delete
    
    int *option;
    char confirmation = 'N';
    
    while(confirmation != 'y'){
        puts("\nWhat would you like to do?\n");
        puts("0 > Exit");
        puts("1 > Login");
        puts("2 > Register");
        puts("3 > Add");
        puts("4 > Modify");
        puts("5 > Search");
        puts("6 > Display");
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
        //LoginModule()
    }
    else if(*option == 2){
        //RegisterModule()
    }
    else if(*option == 3){
       void AddModule();
    }
    else if(*option == 4){
        //ModifyModule();
    }
    else if(*option== 5){
        //SearchModule();
    }
    else if(*option == 6){
        void DisplayModule();
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

    void WriteToFile();

    puts("Would You Like to View Contents within the file?\n");
    puts("\ny > proceed \nn > no proceed \n(Pease only enter lower case)\n");
    scanf(" %c",&confirmation);
    
    if(confirmation == 'y'){
        DisplayModule();
    }

    int AskForContinueation();

};
void modifyModule(){
    puts("In Modify Module\n");

    MemberInfo MemberDetail;
    char NewCharValue;
    char NewValue[30];
    char UserInputMemberID[6];
     FILE *filePTR = fopen("MemberModuleFile.txt","w+");

     puts("Enter Member id > eg.MEM001");
     scanf("%s",UserInputMemberID);

     while(fscanf(filePTR,"%[^\n]-%[^\n]-%c-%[^\n]-%[^\n]-%[^\n]",MemberDetail.MemberID,MemberDetail.Name,MemberDetail.gender,MemberDetail.IC,MemberDetail.ContactNumber,MemberDetail.UpLineID){
        if(strcmp(MemberDetail.MemberID,))
     }
     
}
void DisplayModule(){
    puts("\nActivating Display Module... \n");
    
    int ReportSelection;
    puts("Would you like to Look at a Compact Report or Cozy Report?");
    puts("\n1 > Compact Report(no fancy formatting)\n2 > Cozy Report(Fancy Formatting)\n");
    scanf("%d",&ReportSelection);
    

    if(ReportSelection == 1)
        void ReadFromFile();

   int AskForContinueation();
}
void ReadFromFile(){
    puts("\nAccessing Read Module... \n");

    FILE *filePTR = fopen("MemberModuleFile.txt","r");
    MemberInfo MemberDetail;
    int counter;

/*
typedef struct{
    char MemberID[10];
    char Name[50];
    char gender;
    char IC[15];
    char ContactNumber[12];
    char UpLineID[5];
}MemberInfo;
*/
     if(filePTR == NULL){
        puts("There is nothing inside the file.");
        fclose(filePTR);
    };

    // Research Read from text

    while(fread(&MemberDetail,sizeof(MemberInfo),1,filePTR) != 0{
//       fwrite(&MemberDetail.MemberID,sizeof(char),10,filePTR);
//       fwrite(&MemberDetail.Name,sizeof(char),50,filePTR);
//       fwrite(&MemberDetail.gender,sizeof(char),1,filePTR);
//       fwrite(&MemberDetail.IC,sizeof(char),15,filePTR);
//       fwrite(&MemberDetail.ContactNumber,sizeof(char),12,filePTR);
//       fwrite(&MemberDetail.UpLineID,sizeof(char),5,filePTR);
//    

    printf("\n\nMember ID > %s\nMember Name > %s\nMember Gender > %c\nMember IC > %s\nMember Contact Number > %s\nMember Up Line ID %s\n"
    ,MemberDetail.MemberID,MemberDetail.Name,MemberDetail.gender,MemberDetail.IC,MemberDetail.ContactNumber,MemberDetail.UpLineID);
    }

    fclose(filePTR);
    puts("\n\nExiting Read Module... \n");
}
void WriteToFile(){
    
    puts("Accessing Writing Module... \n");

    MemberInfo MemberDetail;
    char confirmation;

    FILE *filePTR = fopen("MemberModuleFile.txt","w");
    
    if(filePTR == NULL){
        printf("Error!");   
        exit(1); 
    };

    do{
        puts("Format: \nMember ID (eg. MEM001)\nContact Number (eg. 012-123123123)\nGender (eg. M)\nIC (eg. 0343120912312)\n Name (eg. Lim Yong Hao)\nUp Line ID (eg. ID001)");
    
        scanf(" %s",MemberDetail.MemberID);
        scanf(" %s",MemberDetail.ContactNumber);
        scanf(" %c",&MemberDetail.gender);
        scanf(" %s",MemberDetail.IC);
        scanf(" %s",MemberDetail.Name);
        scanf(" %s",MemberDetail.UpLineID);

        puts("\nCurrently Writting to file... \n");
        fwrite(&MemberDetail,sizeof(MemberInfo),1,filePTR);

        puts("\nDo you Want to Continue? \n");
        puts("\ny > proceed \nn > no proceed \n(Pease only enter lower case)\n");
        scanf(" %c",&confirmation);
        puts("\n");
    }while(confirmation != 'n');

    fclose(filePTR);

    puts("Exiting Write Module... \n");
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
