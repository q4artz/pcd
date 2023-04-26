#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996);
typedef struct{
    char StaffID[10];
    char StaffName[50];
    char StaffPassPhrase[20];
    char PasswordRecovery[20];
    char Position[30];
}StaffInfo;

void MemberModuleOptionSelect();
int FilterOption(int *option);
void AddModule();
void ModifyModule();
void DisplayModule();
void WriteToFile();
void SearchModule();
void ReadFromFile();
void LoginModule();
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


    MemberModuleOptionSelect();
};
void MemberModuleOptionSelect(){
    // Job (Let user input what they want to do. then pass to FilterOption(); );
    
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
    else if(*option== 3){
        SearchModule();
    }
    else if(*option == 4){
        DisplayModule();
    }
    else{
    puts("\n\nPlease Select A Valid Option\n");
    MemberModuleOptionSelect();
    };
};
void LoginModule(){
    StaffInfo StaffDetail;
    char UserInputStaffID[20];
    char UserInputPassphrase[20];
    int Loginsuccess =0;
    FILE *filePTR = fopen("StaffModuleFile.txt","w+");
    puts("Please Enter your Credentials!\n");
    puts("Please Enter Your Staff ID > eg.STF001");
    scanf(" %s",UserInputStaffID);
    puts("Please Enter Your Staff Passphrase");
    scanf(" %s",UserInputPassphrase);

    if(strcmp(StaffDetail.StaffID,UserInputStaffID) == 0 && strcmp(StaffDetail.StaffPassPhrase,UserInputPassphrase) == 0){
        Loginsuccess =1;
    }
    else{
        Loginsuccess =0;
        puts("Login Fail");
        MemberModuleOptionSelect();
    }

    fclose(filePTR);
}
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
void modifyModule(){
    LoginModule();
    puts("In Modify Module\n");

    StaffInfo StaffDetail;
    char NewCharValue;
    char NewValue[30];
    char UserInputStaffID[6];
    char UserInputPassphrase[20];
    char field[20];
    int modified =0;
    int IDfound =0;
     FILE *filePTR = fopen("StaffModuleFile.txt","w+");

     puts("Enter Staff id > eg.STF001");
     scanf(" %s",UserInputStaffID);
     puts("Enter Passphrase.");
     scanf(" %s",UserInputPassphrase);

     while (fscanf(filePTR, "%[^\n]-%[^\n]-%[^\n]-%[^\n]-%[^\n]",
                   StaffDetail.StaffID, StaffDetail.StaffName,StaffDetail.StaffPassPhrase,StaffDetail.PasswordRecovery,StaffDetail.Position) != EOF) {
        if(strcmp(StaffDetail.StaffID,UserInputStaffID) == 0 && strcmp(StaffDetail.StaffPassPhrase,UserInputPassphrase) == 0){
             fprintf(filePTR,"\n\nStaff ID > %s\nStaff Name > %s\nPassPhrase > %s\nPassword Recovery > %s\nStaff Position > %s\n"
        ,StaffDetail.StaffID,StaffDetail.StaffName,StaffDetail.StaffPassPhrase,StaffDetail.PasswordRecovery,StaffDetail.Position);
            IDfound =1;
            printf("\nEnter field to modify: (Format:\nstaffid\nname\npassphrase\npasswordrecovery\npostion\n)");
            scanf(" %s", field);
            printf("Enter new value: ");
            scanf(" %s", NewValue);
            if (strcmp(field, "staffid") == 0) {
                    strcpy(StaffDetail.StaffID,NewValue);
                    modified = 1;
                    printf("%s",StaffDetail.StaffID);
                }
            else if (strcmp(field,"passphrase") == 0) {
                    strcpy(StaffDetail.StaffPassPhrase,NewValue);
                    modified = 1;
                    printf("%s",StaffDetail.StaffPassPhrase);
                }
            else if (strcmp(field, "name") == 0) {
                    strcpy(StaffDetail.StaffName,NewValue);
                    modified = 1;
                    printf("%s",StaffDetail.StaffName);
            }
            else if (strcmp(field, "passwordrecovery") == 0) {
                    strcpy(StaffDetail.PasswordRecovery,NewValue);
                    modified = 1;
                    printf("%s",StaffDetail.PasswordRecovery);
            }
            else if (strcmp(field, "position") == 0) {
                    strcpy(StaffDetail.Position,NewValue);
                    modified = 1;
                    printf("%s",StaffDetail.Position);
            }
            if(modified == 1){
                fprintf(filePTR,"\n\nStaff ID > %s\nStaff Name > %s\nPassPhrase > %s\nPassword Recovery > %s\nStaff Position > %s\n"
        ,StaffDetail.StaffID,StaffDetail.StaffName,StaffDetail.StaffPassPhrase,StaffDetail.PasswordRecovery,StaffDetail.Position);
                printf("\nStaff information modified successfully.\n");
            }
        }
        else{
             fprintf(filePTR,"\n\nStaff ID > %s\nStaff Name > %s\nPassPhrase > %s\nPassword Recovery > %s\nStaff Position > %s\n"
        ,StaffDetail.StaffID,StaffDetail.StaffName,StaffDetail.StaffPassPhrase,StaffDetail.PasswordRecovery,StaffDetail.Position);
            printf("\nInvalid field name.\n");
        }
    }
    if(!IDfound){
        puts("Staff Does not exist.");
    }
    fclose(filePTR);

    AskForContinueation();
}void SearchModule(){
    LoginModule();
    puts("Activating Search Module");
    StaffInfo StaffDetail;
    char UserInputStaffID[20];
    char UserInputPassphrase[20];
    char confirmation = 'n';
    int Choice;
    int IDfound =0;
    FILE *filePTR = fopen("StaffModuleFile.txt","w+");

    puts("Enter Member id > eg.MEM001");
    scanf(" %s",UserInputStaffID);
    puts("Enter Passphrase.");
    scanf(" %s",UserInputPassphrase);

    while(fscanf(filePTR, "%[^\n]-%[^\n]-%[^\n]-%[^\n]-%[^\n]",StaffDetail.StaffID, StaffDetail.StaffName,StaffDetail.StaffPassPhrase,StaffDetail.PasswordRecovery,StaffDetail.Position) != EOF) {
        if(strcmp(StaffDetail.StaffID,UserInputStaffID) == 0 && strcmp(StaffDetail.StaffPassPhrase,UserInputPassphrase) == 0){
             fprintf(filePTR,"\n\nStaff ID > %s\nStaff Name > %s\nPassPhrase > %s\nPassword Recovery > %s\nStaff Position > %s\n"
        ,StaffDetail.StaffID,StaffDetail.StaffName,StaffDetail.StaffPassPhrase,StaffDetail.PasswordRecovery,StaffDetail.Position);
            IDfound =1;
        }
    }
    if(!IDfound){
        puts("Sales ID not found");
    };

    fclose(filePTR);
    

    AskForContinueation();

};
void DisplayModule(){
    LoginModule();
    puts("\nActivating Display Module... \n");
    
    int ReportSelection;
    puts("Would you like to Look at a Compact Report or Cozy Report?");
    puts("\n1 > Compact Report(no fancy formatting)\n2 > Cozy Report(Fancy Formatting)\n");
    scanf("%d",&ReportSelection);
    

    if(ReportSelection == 1)
        ReadFromFile();

    ReportModule(&ReportSelection);

   int AskForContinueation();
}
void ReportModule(int *CozyReport){
    puts("Printing cozy report");

    FILE *filePTR = fopen("StaffModuleFile.txt","r");
    StaffInfo StaffDetail;
    int counter;


     if(filePTR == NULL){
        puts("There is nothing inside the file.");
        fclose(filePTR);
    };

    // Research Read from text

    while(fread(&StaffDetail,sizeof(StaffInfo),1,filePTR) != 0){
        puts("------------------------------------------------------------");
        puts("||\tAnchor Company Cozy Staff Report\t\t ||");
        puts("------------------------------------------------------------");
        printf("|| \nStaff ID \t\t>> \t%s\t\t ||\n",StaffDetail.StaffID);
        printf("|| \tStaff Password \t\t>> \t%s\t\t ||\n",StaffDetail.StaffPassPhrase);
        printf("|| \tStaff Name \t\t>> \t%s\t ||\n",StaffDetail.StaffName);
        printf("|| \tStaff Password Recovery \t\t>> \t%s\t ||\n",StaffDetail.PasswordRecovery);
        printf("|| \tStaff Position \t\t>> \t%s\t ||\n",StaffDetail.Position);
        puts("------------------------------------------------------------");

    }
    fclose(filePTR);

}
void ReadFromFile(){
    puts("\nAccessing Read Module... \n");

    FILE *filePTR = fopen("StaffModuleFile.txt","r");
    StaffInfo StaffDetail;
    int counter;


     if(filePTR == NULL){
        puts("There is nothing inside the file.");
        fclose(filePTR);
    };

    // Research Read from text

    while(fread(&StaffDetail,sizeof(StaffInfo),1,filePTR) != 0){   

        fprintf(filePTR,"\n\nStaff ID > %s\nStaff Name > %s\nPassPhrase > %s\nPassword Recovery > %s\nStaff Position > %s\n"
        ,StaffDetail.StaffID,StaffDetail.StaffName,StaffDetail.StaffPassPhrase,StaffDetail.PasswordRecovery,StaffDetail.Position);
    }
    fclose(filePTR);
    puts("\n\nExiting Read Module... \n");
}
void WriteToFile(){
    
    puts("Accessing Writing Module... \n");

    StaffInfo StaffDetail;
    char confirmation;

    FILE *filePTR = fopen("StaffModuleFile.txt","w");
    
    if(filePTR == NULL){
        printf("Error!");   
        exit(1); 
    };

    do{
        puts("Format: \nStaff ID (eg. STF001)\nStaff Name (eg. Twikipedia)\nStaff PassPhrase (eg.securepassword123)\nPassword Recovery (eg.dog)\nStaff Position (eg.Cachier)");
    
        scanf(" %s",StaffDetail.StaffName);
        scanf(" %s",StaffDetail.StaffPassPhrase);
        scanf(" %s",StaffDetail.StaffPassPhrase);
        scanf(" %s",StaffDetail.PasswordRecovery);
        scanf(" %s",StaffDetail.Position);

        puts("\nCurrently Writting to file... \n");
        fwrite(&StaffDetail,sizeof(StaffInfo),1,filePTR);

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