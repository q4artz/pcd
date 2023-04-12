#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996);
typedef struct{
    char MemberID[10];
    char MemberPassPhrase[20];
    char Name[50];
    char gender[2];
    char IC[15];
    char ContactNumber[12];
    char UpLineID[5];
}MemberInfo;

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
    MemberInfo MemberDetail;
    char UserInputMemberID[20];
    char UserInputPassphrase[20];
    int Loginsuccess =0;
    FILE *filePTR = fopen("MemberModuleFile.txt","w+");
    puts("Please Enter your Credentials!\n");
    puts("Please Enter Your Member ID > eg.MEM001");
    scanf(" %s",UserInputMemberID);
    puts("Please Enter Your Member Passphrase");
    scanf(" %s",UserInputPassphrase);

    if(strcmp(MemberDetail.MemberID,UserInputMemberID) == 0 && strcmp(MemberDetail.MemberPassPhrase,UserInputPassphrase) == 0){
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

    MemberInfo MemberDetail;
    char NewCharValue;
    char NewValue[30];
    char UserInputMemberID[6];
    char UserInputPassphrase[20];
    char field[20];
    int modified =0;
    int IDfound =0;
     FILE *filePTR = fopen("MemberModuleFile.txt","w+");

     puts("Enter Member id > eg.MEM001");
     scanf(" %s",UserInputMemberID);
     puts("Enter Passphrase.");
     scanf(" %s",UserInputPassphrase);

     while (fscanf(filePTR, "%[^\n]-%[^\n]-%c-%[^\n]-%[^\n]-%[^\n]",
                   MemberDetail.MemberID, MemberDetail.Name,
                   MemberDetail.gender, MemberDetail.IC,
                   MemberDetail.ContactNumber, MemberDetail.UpLineID) != EOF) {
        if(strcmp(MemberDetail.MemberID,UserInputMemberID) == 0 && strcmp(MemberDetail.MemberPassPhrase,UserInputPassphrase) == 0){
             fprintf(filePTR,"\n\nMember ID > %s\nMember Name > %s\nMember Gender > %s\nMember IC > %s\nMember Contact Number > %s\nMember Up Line ID %s\n"
        ,MemberDetail.MemberID,MemberDetail.Name,MemberDetail.gender,MemberDetail.IC,MemberDetail.ContactNumber,MemberDetail.UpLineID);
            IDfound =1;
            printf("\nEnter field to modify: (Format:\nmemberid\npassphrase\ngender\nic\ncontactnumber\nuplineid)");
            scanf(" %s", field);
            printf("Enter new value: ");
            scanf(" %s", NewValue);
            if (strcmp(field, "memberid") == 0) {
                    strcpy(MemberDetail.MemberID,NewValue);
                    modified = 1;
                    printf("%s",MemberDetail.MemberID);
                }
            else if (strcmp(field,"passphrase") == 0) {
                    strcpy(MemberDetail.MemberPassPhrase,NewValue);
                    modified = 1;
                    printf("%s",MemberDetail.MemberPassPhrase);
                }
            else if (strcmp(field, "gender") == 0) {
                    strcpy(MemberDetail.gender,NewValue);
                    modified = 1;
                    printf("%s",MemberDetail.gender);
            }
            else if (strcmp(field, "ic") == 0) {
                    strcpy(MemberDetail.IC,NewValue);
                    modified = 1;
                    printf("%s",MemberDetail.IC);
            }
            else if (strcmp(field, "contactnumber") == 0) {
                    strcpy(MemberDetail.ContactNumber,NewValue);
                    modified = 1;
            }
            else if (strcmp(field, "uplineid") == 0) {
                    strcpy(MemberDetail.UpLineID,NewValue);
                    modified = 1;
            }
            if(modified == 1){
                fprintf(filePTR,"\n\nMember ID > %s\nMember Name > %s\nMember Gender > %s\nMember IC > %s\nMember Contact Number > %s\nMember Up Line ID %s\n"
        ,MemberDetail.MemberID,MemberDetail.Name,MemberDetail.gender,MemberDetail.IC,MemberDetail.ContactNumber,MemberDetail.UpLineID);
                printf("\nSales information modified successfully.\n");
            }
        }
        else{
             fprintf(filePTR,"\n\nMember ID > %s\nMember Name > %s\nMember Gender > %s\nMember IC > %s\nMember Contact Number > %s\nMember Up Line ID %s\n"
        ,MemberDetail.MemberID,MemberDetail.Name,MemberDetail.gender,MemberDetail.IC,MemberDetail.ContactNumber,MemberDetail.UpLineID);
            printf("\nInvalid field name.\n");
        }
    }
    if(!IDfound){
        puts("Member Does not exist.");
    }
    fclose(filePTR);

    AskForContinueation();
}void SearchModule(){
    LoginModule();
    puts("Activating Search Module");
    MemberInfo MemberDetail;
    char UserInputMemberID[20];
    char UserInputPassphrase[20];
    char confirmation = 'n';
    int Choice;
    int IDfound =0;
    FILE *filePTR = fopen("MemberModuleFile.txt","w+");

    puts("Enter Member id > eg.MEM001");
    scanf(" %s",UserInputMemberID);
    puts("Enter Passphrase.");
    scanf(" %s",UserInputPassphrase);

    while (fscanf(filePTR, "%[^\n]-%[^\n]-%c-%[^\n]-%[^\n]-%[^\n]",MemberDetail.MemberID, MemberDetail.Name,MemberDetail.gender, MemberDetail.IC,MemberDetail.ContactNumber, MemberDetail.UpLineID) != EOF) {
        if(strcmp(MemberDetail.MemberID,UserInputMemberID) == 0 && strcmp(MemberDetail.MemberPassPhrase,UserInputPassphrase) == 0){
             fprintf(filePTR,"\n\nMember ID > %s\nMember Name > %s\nMember Gender > %s\nMember IC > %s\nMember Contact Number > %s\nMember Up Line ID %s\n"
        ,MemberDetail.MemberID,MemberDetail.Name,MemberDetail.gender,MemberDetail.IC,MemberDetail.ContactNumber,MemberDetail.UpLineID);
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

    FILE *filePTR = fopen("MemberModuleFile.txt","r");
    MemberInfo MemberDetail;
    int counter;


     if(filePTR == NULL){
        puts("There is nothing inside the file.");
        fclose(filePTR);
    };

    // Research Read from text

    while(fread(&MemberDetail,sizeof(MemberInfo),1,filePTR) != 0){
//       fwrite(&MemberDetail.MemberID,sizeof(char),10,filePTR);
//       fwrite(&MemberDetail.Name,sizeof(char),50,filePTR);
//       fwrite(&MemberDetail.gender,sizeof(char),1,filePTR);
//       fwrite(&MemberDetail.IC,sizeof(char),15,filePTR);
//       fwrite(&MemberDetail.ContactNumber,sizeof(char),12,filePTR);
//       fwrite(&MemberDetail.UpLineID,sizeof(char),5,filePTR);
        puts("------------------------------------------------------------");
        puts("||\tAnchor Company Cozy Member Report\t\t ||");
        puts("------------------------------------------------------------");
        printf("|| \tMember ID \t\t>> \t%s\t\t ||\n",MemberDetail.MemberID);
        puts("|| \tMember Password \t\t>> \t%s (Joking, not going to print it out lol)\t ||\n");
        printf("|| \tMember Name \t\t>> \t%s\t ||\n",MemberDetail.Name);
        printf("|| \tMember Gender \t\t>> \t%s\t ||\n",MemberDetail.gender);
        printf("|| \tMember IC \t\t>> \t%s\t ||\n",MemberDetail.IC);
        printf("|| \tMember Contact Number \t\t>> \t%s\t\t ||\n",MemberDetail.ContactNumber);
        printf("|| \tMember Up Line Number \t\t>> \t%s\t ||\n",MemberDetail.UpLineID);
        puts("------------------------------------------------------------");

    }
    fclose(filePTR);

}
void ReadFromFile(){
    puts("\nAccessing Read Module... \n");

    FILE *filePTR = fopen("MemberModuleFile.txt","r");
    MemberInfo MemberDetail;
    int counter;


     if(filePTR == NULL){
        puts("There is nothing inside the file.");
        fclose(filePTR);
    };

    // Research Read from text

    while(fread(&MemberDetail,sizeof(MemberInfo),1,filePTR) != 0){   

        printf("\n\nMember ID > %s\nMember Name > %s\nMember Gender > %s\nMember IC > %s\nMember Contact Number > %s\nMember Up Line ID %s\n"
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
        scanf(" %s",MemberDetail.gender);
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