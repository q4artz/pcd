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

void StaffModuleOptionSelect();
int StaffFilterOption(int *option);
void StaffAddModule();
void StaffModifyModule();
void StaffDisplayModule();
void StaffWriteToFile();
void StaffSearchModule();
void StaffReadFromFile();
void StaffLoginModule();
int StaffAskForContinueation();
void StaffReportModule(int *CozyReport);


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


    StaffModuleOptionSelect();
};
void StaffModuleOptionSelect(){
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
    StaffFilterOption(&option);
}
int StaffFilterOption(int *option){

    // Job (Filter out User option, throw them to the place they want);

    printf("\nUser selected option >\t%d\n",*option);
    
    if(*option == 0){
        puts("\nExiting Program... ");
        return 0;
    }
    else if(*option == 1){
        StaffAddModule();
    }
    else if(*option == 2){
        StaffModifyModule();
    }
    else if(*option== 3){
        StaffSearchModule();
    }
    else if(*option == 4){
        StaffDisplayModule();
    }
    else{
    puts("\n\nPlease Select A Valid Option\n");
    StaffModuleOptionSelect();
    };
};
void StaffLoginModule(){
    StaffInfo StaffDetail;
    char UserInputStaffID[10];
    char UserInputPassphrase[20];
    int Loginsuccess =0;
    FILE *filePTR = fopen("StaffModuleFile.txt","r");
    puts("Please Enter your Credentials!\n");
    puts("Please Enter Your Staff ID > eg.STF001");
    scanf(" %s",UserInputStaffID);
    puts("Please Enter Your Staff Passphrase");
    scanf(" %s",UserInputPassphrase);

    if(strcmp(UserInputStaffID,"STF001") == 0 && strcmp(UserInputPassphrase,"123") == 0){
        Loginsuccess =1;
    }
    else{
        Loginsuccess =0;
        puts("Login Fail");
        fprintf(filePTR,"%s %s",StaffDetail.StaffID,StaffDetail.StaffPassPhrase);
        printf("user input %s %s",UserInputStaffID,UserInputPassphrase);
        StaffModuleOptionSelect();
    }

    fclose(filePTR);
}
void StaffAddModule(){
    //Job Write to file, ask User if they want to see file content. Yes throw to DisplayModule(). No go back OptionSelect();
    char confirmation;
    puts("Activating Add Module... \n");

    StaffWriteToFile();

    puts("Would You Like to View Contents within the file?\n");
    puts("\ny > proceed \nn > no proceed \n(Pease only enter lower case)\n");
    scanf(" %c",&confirmation);
    
    if(confirmation == 'y'){
        StaffDisplayModule();
    }

    StaffAskForContinueation();

};
void StaffModifyModule(){
    StaffLoginModule();
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
        if(strcmp(UserInputStaffID,"STF001") == 0 && strcmp(UserInputPassphrase,"123") == 0){
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

    StaffAskForContinueation();
}void StaffSearchModule(){
    StaffLoginModule();
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
        if(strcmp(UserInputStaffID,"STF001") == 0 && strcmp(UserInputPassphrase,"123") == 0){
             fprintf(filePTR,"\n\nStaff ID > %s\nStaff Name > %s\nPassPhrase > %s\nPassword Recovery > %s\nStaff Position > %s\n"
        ,StaffDetail.StaffID,StaffDetail.StaffName,StaffDetail.StaffPassPhrase,StaffDetail.PasswordRecovery,StaffDetail.Position);
            IDfound =1;
        }
    }
    if(!IDfound){
        puts("Sales ID not found");
    };

    fclose(filePTR);
    

    StaffAskForContinueation();

};
void StaffDisplayModule(){
    StaffLoginModule();
    puts("\nActivating Display Module... \n");
    
    int ReportSelection;
    puts("Would you like to Look at a Compact Report or Cozy Report?");
    puts("\n1 > Compact Report(no fancy formatting)\n2 > Cozy Report(Fancy Formatting)\n");
    scanf("%d",&ReportSelection);
    

    if(ReportSelection == 1)
        StaffReadFromFile();

    StaffReportModule(&ReportSelection);

   int AskForContinueation();
}
void StaffReportModule(int *CozyReport){
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
void StaffReadFromFile(){
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
void StaffWriteToFile(){
    
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
    
        scanf(" %s",StaffDetail.StaffID);
        scanf(" %s",StaffDetail.StaffName);
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
int StaffAskForContinueation(){
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