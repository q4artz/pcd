#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <math.h>
#pragma warning(disable:4996)

//Structure member
struct member {
    char memberId[6];
    char name[50];
    char gender[2];
    char ic[15];
    char contactNum[15];
    char upLine[10];
};

//Structure Sales
typedef struct {
    char SalesOrderID[5];
    char ItemCode[7];
    int QuantityOrdered;
    double Price;
    char MemberID[10];
}SalesOrder;

//Structure Staff
typedef struct {
    char StaffID[10];
    char StaffName[50];
    char StaffPassPhrase[20];
    char PasswordRecovery[20];
    char Position[30];
}StaffInfo;

//Function Declare Member
int memberfunctionSelect();  //Member Module Part
int memRegister();      //Member register
int memDelete();        //Member delete
void memSearchModify(); //Member search and modify
void memberList(); //Member listing
void memHistory(); //Member activity history
void readFile();   //Member read file
void writeFile();  //Member write file

//Function Declare Sales
void SalesModuleOptionSelect(); //Sales Module Part
int FilterOption(int* option); //Sales Filter Option
void AddModule();        //Sales Add Module
void ModifyModule();     //Sales Modify Module
void DisplayModule();    //Sales Display Module
void WriteToFile();      //Sales Write To File Module
void SearchModule();     //Sales Search Module
void ReadFromFile();     //Sales Read From File Module
void CountFileAccess(int* AccessCount); //Sales Count File Access Module
void ModuleSelect();    //Module Select
int AskForContinueation(); //Sales Ask For Continueation Module
void ReportModule(int* CozyReport); //Sales Report Module

//Function Declare Staff
void StaffModuleOptionSelect();
int StaffFilterOption(int* option);
void StaffAddModule();
void StaffModifyModule();
void StaffDisplayModule();
void StaffWriteToFile();
void StaffSearchModule();
void StaffReadFromFile();
void StaffLoginModule();
int StaffAskForContinueation();
void StaffReportModule(int* CozyReport);

//Global Variable (member)
int i; //count for display number in list, i for array in structure
struct member memList[100];

int main(int argc, char* argv[]) {

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

//Module Select
void ModuleSelect() {
    // 1 == SalesModule 2 == Staff Module 3 == Stockmodule
    int ModuleSelect;
    puts("Which Module would you like to access? ");
    puts("0 > Exit");
    puts("1 > Sales System Module");
    puts("2 > Staff Module");
    puts("3 > Member Module");
    scanf("%d", &ModuleSelect);

    if (ModuleSelect == 0) {
        puts("Exiting.. ");
        exit(0);
    }
    else if (ModuleSelect == 1) {
        SalesModuleOptionSelect();
    }
    else if (ModuleSelect == 2) {
        StaffModuleOptionSelect();
    }
    else if (ModuleSelect == 3) {
        memberfunctionSelect();
    }
    else {
        puts("You did not select a Valid Module\n");
    }
};

//Member Module Part

int memberfunctionSelect() {
    int choice;
    system("cls");
    do {
        readFile();
        printf("Member Module Menu\n");
        printf("--------------------\n");
        printf("1 > Add New Member\n");
        printf("2 > Delete Existing Member\n");
        printf("3 > Search or Modify Member Information\n");
        printf("4 > Member List\n");
        printf("5 > Activity History\n");
        printf("0 > Exit Member Module Menu\n");
        printf("Choice: ");
        scanf("%d", &choice);
        rewind(stdin);

        if (choice == 0) {
            printf("See you next time...\n");
            system("pause");
            ModuleSelect();
        }
        else if (choice == 1) {
            memRegister();
        }
        else if (choice == 2) {
            memDelete();
        }
        else if (choice == 3) {
            memSearchModify();
        }
        else if (choice == 4) {
            memberList();
        }
        else if (choice == 5) {
            memHistory();
        }
        else {
            printf("\n\nInvalid Choice, Please try again\n");
            memberfunctionSelect();
        }
    } while (choice != 6);
    return 0;
}

//Member register
int memRegister() {
    char cont;
    int idValid = 0, a = 0, count = 0;
    system("cls");
    printf("New Member Register\n");
    printf("--------------------\n");

    //structure variable
    struct member newMem;

    //file
    FILE* mem;
    mem = fopen("member.txt", "a");
    if (mem == NULL) {
        printf("Unable to open file\n");
        exit(-1);
    }
    FILE* history;
    history = fopen("history.txt", "a");
    if (history == NULL) {
        printf("Unable to open file\n");
        exit(-1);
    }
    //get new member information
    do {
        //get user member id and validation
        while (!idValid) {     //get id
            printf("Member ID (e.g:M1001): ");
            scanf("%s", &newMem.memberId);
            rewind(stdin);
            //check length
            if (strlen(newMem.memberId) != 5) {
                printf("Invalid format.Please enter in the correct format (e.g.M1001).\n\n");
                continue;
            }
            //check first letter is alphabet M
            if (newMem.memberId[0] != 'M') {
                printf("Invalid format.Please enter in the correct format (e.g.M1001).\n\n");
                continue;
            }
            //check left character is digit
            for (a = 1; a < 4; a++) {
                if (!isdigit(newMem.memberId[a])) {
                    printf("Invalid format.Please enter in the correct format (e.g.M1001).\n\n");
                    continue;
                }
            }

            if (strcmp(memList[count].memberId, newMem.memberId) == 0) {
                printf("Sorry,this Member ID already registered.~_~\n\n");
                continue;
            }
            idValid = 1;

        }

        printf("Name: ");
        scanf("%[^\n]", &newMem.name);
        rewind(stdin);

        printf("Gender (M/F): ");
        scanf("%1s", &newMem.gender);
        rewind(stdin);

        printf("IC Num (e.g:xxxxxx-xx-xxxx): ");
        scanf("%14s", &newMem.ic);
        rewind(stdin);

        printf("Contact Num (e.g:01x-xxxxxxxx): ");
        scanf("%12s", &newMem.contactNum);
        rewind(stdin);

        printf("Up Line ID (e.g:U1001): ");
        scanf("%5s", &newMem.upLine);
        rewind(stdin);

        //write into file and printf sucessfully message
        fprintf(mem, "%s|%s|%s|%s|%s|%s|\n", newMem.memberId, newMem.name, newMem.gender, newMem.ic, newMem.contactNum, newMem.upLine);
        i++;
        printf("Member has sucessfully added!!\n\n");

        fprintf(history, "Added a new member:%s\n", newMem.memberId);
        //continuous

        printf("Add another New Member? (Y/N): ");
        scanf("%c", &cont);
        rewind(stdin);

        if (cont == 'n' || cont == 'N') {
            printf("\n\n");
            fclose(mem);
            fclose(history);
            memberfunctionSelect();
        }
        else if (cont != 'n' && cont != 'N' && cont != 'y' && cont != 'Y') {
            printf("Invalid choice!!\n");
            continue;
        }
    } while (cont == 'y' || cont == 'Y');
}

//Member read file
void readFile() {
    //this function read all the data from file to array for process
    struct member store;
    i = 0;

    FILE* list;
    list = fopen("member.txt", "r");
    if (list == NULL) {
        printf("Unable to open file\n");
        exit(-1);
    }
    while (!feof(list))
    {
        fscanf(list, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|\n", memList[i].memberId, memList[i].name, memList[i].gender, memList[i].ic, memList[i].contactNum, memList[i].upLine);
        i++;
    }
    fclose(list);
}

//Member write file
void writeFile() {
    int count;
    FILE* write;
    write = fopen("member.txt", "w");
    if (write == NULL) {
        printf("Unable to open file\n");
        exit(-1);
    }
    for (count = 0; count < i; count++) {
        fprintf(write, "%s|%s|%s|%s|%s|%s|\n", memList[count].memberId, memList[count].name, memList[count].gender, &memList[count].ic, memList[count].contactNum, memList[count].upLine);
    }
    fclose(write);
    system("pause");
    system("cls");
    memberfunctionSelect();
}

//Member delete 
int memDelete() {
    int count, forward, found = 0;
    char deleteId[6], cont;

    FILE* history;
    history = fopen("history.txt", "a");
    if (history == NULL) {
        printf("Unable to open file.\n");
        exit(-1);
    }

    system("cls");
    printf("Delete Function\n\n");
    printf("Key in the Member ID need to delete (exit to exit): ");
    scanf("%5s", &deleteId);
    rewind(stdin);

    if (strcmp(deleteId, "exit") == 0) {
        printf("Exiting program..\n");
        memberfunctionSelect();
    }

    for (count = 0; count < i; count++) {

        if (strcmp(memList[count].memberId, deleteId) == 0) {
            printf("ID\tName\t\t\t      Gender\t No.IC\t\t   No.Contact\t    Up Line\n");
            printf("===================================================================================================\n");
            printf("%-6s\t%-30s\t%1s\t%-15s\t%15s\t%10s\n", memList[count].memberId, memList[count].name, memList[count].gender, memList[count].ic, memList[count].contactNum, memList[count].upLine);
            found = 1;
            printf("\n\nDo you sure want to delete this record? (Y/N): ");
            scanf("%c", &cont);
            rewind(stdin);

            if (cont == 'y' || cont == 'Y') {
                printf("Record have been deleted!\n");
                fprintf(history, "%s have been deleted.\n", deleteId);
                fclose(history);
                for (count = 0; count < i; count++) {
                    if (strcmp(memList[count].memberId, deleteId) == 0) {
                        for (forward = count + 1; forward < i; forward++) {
                            memList[forward - 1] = memList[forward];          //move forward all the array behind the selected to replace the selected array
                        }
                    }
                }i--;     //deleted the last array because all array move forward one step
            }
            else if (cont == 'n' || cont == 'N') {
                memberfunctionSelect();
            }
            else
            {
                printf("Invalid choice!!\n");
                continue;
            }
        }
    }
    if (!found) {
        printf("Record not found!!\n");
        system("pause");
        return 0;
    }
    writeFile();
    system("pause");
}

//Member search and modify
void memSearchModify() {
    char cont, other;
    char search[51];
    int count = 0, choose;

    //file open
    FILE* history;
    history = fopen("history.txt", "a");
    if (history == NULL) {
        printf("Unable to open file\n");
        exit(-1);
    }

    system("cls");
    printf("Searching and Modify\n\n");
    rewind(stdin);
    printf("Member's ID to Search >");
    scanf("%[^\n]", &search);
    rewind(stdin);
    printf("---------------------------------------------------------------------------------------\n");
    for (count = 0; count < i; count++) {
        if (strcmp(memList[count].memberId, search) == 0) {
            fprintf(history, "Searching member :%s.\n", search);
            printf("ID\tName\t\t\t      Gender\t No.IC\t\t   No.Contact\t    Up Line\n");
            printf("===================================================================================================\n");
            printf("%-6s\t%-30s\t%1s\t%-15s\t%15s\t%10s\n", memList[count].memberId, memList[count].name, memList[count].gender, memList[count].ic, memList[count].contactNum, memList[count].upLine);
            printf("\n\nWould you like to make any changes (Y/N): ");
            scanf("%c", &cont);
            rewind(stdin);
            do {
                if (cont == 'y' || cont == 'Y') {
                    do {
                        printf("\n\nNeed to changes what information for Member ID(%s)?\n", memList[count].memberId);
                        printf("1 > Member Name (%s)\n", &memList[count].name);
                        printf("2 > Gender (%s) \n", &memList[count].gender);
                        printf("3 > IC Num (%s) \n", &memList[count].ic);
                        printf("4 > Contact Num (%s) \n", &memList[count].contactNum);
                        printf("5 > Upline ID (%s) \n", &memList[count].upLine);
                        printf("0 > Cancel \n", &memList[count].memberId);
                        printf("Choose > ");
                        scanf("%d", &choose);
                        rewind(stdin);

                        switch (choose) {
                        case 0:
                            printf("Quitting Modify Module...\n");
                            system("pause");
                            system("cls");
                            memberfunctionSelect();
                        case 1:
                            printf("Enter new Name: ");
                            scanf("%[^\n]", &memList[count].name);
                            fprintf(history, "%s Name has been modified to %s.\n", memList[count].memberId, memList[count].name);
                            rewind(stdin);
                            break;
                        case 2:
                            printf("Enter new Gender: ");
                            scanf("%1s", &memList[count].gender);
                            fprintf(history, "%s Gender has been modified to %s.\n", memList[count].memberId, memList[count].gender);
                            rewind(stdin);
                            break;
                        case 3:
                            printf("Enter new IC NUM (e.g:xxxxxx-xx-xxxx): ");
                            scanf("%14s", &memList[count].ic);
                            fprintf(history, "%s IC Num has been modified to %s.\n", memList[count].memberId, memList[count].ic);
                            rewind(stdin);
                            break;
                        case 4:
                            printf("Enter new Contact Num (e.g:01x-xxxxxxxx): ");
                            scanf("%12s", &memList[count].contactNum);
                            fprintf(history, "%s Contact Number has been modified to %s.\n", memList[count].memberId, memList[count].contactNum);
                            rewind(stdin);
                            break;
                        case 5:
                            printf("Enter new Upline ID: ");
                            scanf("%5s", &memList[count].upLine);
                            fprintf(history, "%s Up Line has been modified to %s.\n", memList[count].memberId, memList[count].upLine);
                            rewind(stdin);
                            break;
                        default:
                            printf("Invalid Choice!");
                            printf("Choose > ");
                            scanf("%d", &choose);
                        }
                        printf("Changes making...\n\n1..2...Proof!!\n\nChanges Completely!!\n");
                        printf("Edit other infomation? (Y/N): ");
                        scanf("%c", &other);
                        rewind(stdin);
                        if (other != 'y' && other != 'Y' && other != 'n' && other != 'N') {
                            printf("Invalid choice!\n");
                            printf("Edit other infomation? (Y/N): ");
                            scanf("%c", &other);
                            rewind(stdin);
                        }
                    } while (other == 'y' || other == 'Y');
                }
                else if (cont == 'n' || cont == 'N') {

                    fclose(history);
                    system("cls");
                    writeFile();
                    memberfunctionSelect();
                }
                else if (cont != 'n' || cont != 'N' || cont != 'y' || cont != 'Y') {
                    printf("Invalid choice!!\n");
                    printf("Would you like to make any changes (Y/N):\n");
                    scanf("%c", &cont);
                    rewind(stdin);
                }
            } while (cont != 'n' && cont != 'N' && cont != 'y' && cont != 'Y');
        }
    }

    fclose(history);
    writeFile();

}
//Member listing
void memberList() {

    int count = 0, num = 1;
    system("cls");
    printf("No.\tID\tName\t\t\t      Gender\t No.IC\t\t   No.Contact\t    Up Line\n");
    printf("===================================================================================================\n");
    for (count = 0; count < i; count++) {
        printf("%-2d.      %-6s\t%-30s\t%1s\t%15s\t%15s\t%10s\n", num, memList[count].memberId, memList[count].name, memList[count].gender, memList[count].ic, memList[count].contactNum, memList[count].upLine);
        num++;
    }

    system("pause");
    system("cls");
    memberfunctionSelect();
}

//Member activity history
void memHistory() {
    system("cls");
    char activity[50];

    FILE* history;
    history = fopen("history.txt", "r");
    if (history == NULL) {
        printf("Unable to open file\n");
        exit(-1);
    }

    printf("Activity History\n");
    printf("========================\n");
    while (!feof(history))
    {
        fscanf(history, "%[^\n]\n", &activity);
        printf("%s\n", activity);

    }

    fclose(history);

    system("pause");
    system("cls");
    memberfunctionSelect();
}

//Sales Module Part
void SalesModuleOptionSelect() {

    // Job (Let user input what they want to do. then pass to FilterOption(); );

    // 0 == exit 1 == add 2 == modify 3 == delete

    int* option;
    char confirmation = 'N';

    while (confirmation != 'y') {
        puts("\nWhat would you like to do?\n");
        puts("0 > Exit");
        puts("1 > Add");
        puts("2 > Modify");
        puts("3 > Search");
        puts("4 > Display");
       
        scanf("%d", &option);

        printf("\n\nConfirm option \t%d ??\n", option);
        puts("y > proceed \nn > no proceed \n(Pease only enter lower case)");
        scanf(" %c", &confirmation);
        puts("\n");
    }
    FilterOption(&option);
}

//Sales Filter Option
int FilterOption(int* option) {

    // Job (Filter out User option, throw them to the place they want);

    printf("\nUser selected option >\t%d\n", *option);

    if (*option == 0) {
        puts("\nExiting Program... ");
        return 0;
    }
    else if (*option == 1) {
        AddModule();
    }
    else if (*option == 2) {
        ModifyModule();
    }
    else if (*option == 3) {
        SearchModule();
    }
    else if (*option == 4) {
        DisplayModule();
    }
    else {
        puts("\n\nPlease Select A Valid Option\n");
        SalesModuleOptionSelect();
    };
};

//Sales Add Module
void AddModule() {
    //Job Write to file, ask User if they want to see file content. Yes throw to DisplayModule(). No go back OptionSelect();
    char confirmation;
    puts("Activating Add Module... \n");

    WriteToFile();

    puts("Would You Like to View Contents within the file?\n");
    puts("\ny > proceed \nn > no proceed \n(Pease only enter lower case)\n");
    scanf(" %c", &confirmation);

    if (confirmation == 'y') {
        DisplayModule();
    }

    AskForContinueation();

};

//Sales Modify Module
void ModifyModule() {
    puts("Activating Modify Module... \n");

    SalesOrder SalesDetail;
    int modified = 0;
    int IDfound = 0;
    int NewIntValue;
    double NewDoubleValue;
    char UserInputSalesOrderID[5];
    char field[20];
    char NewValue[20];
    FILE* filePTR = fopen("SalesModuleFile.bin", "rb+");
    int i = 0;

    puts("Enter Sales Order id > eg.S001");
    scanf(" %s", UserInputSalesOrderID);


    while (fread(&SalesDetail, sizeof(SalesOrder), 1, filePTR) != EOF) {
        if (strcmp(SalesDetail.SalesOrderID, UserInputSalesOrderID) == 0) {
            puts("Sales Module Found");
            printf("\n\nSales Order ID > %s\nItem Code > %s\nQuantity Ordered > %d\nPrice > %.2lf\nMember ID > %s\n"
                , SalesDetail.SalesOrderID, SalesDetail.ItemCode, SalesDetail.QuantityOrdered, SalesDetail.Price, SalesDetail.MemberID);
            IDfound = 1;

            puts("\nEnter field to modify: (Format:\n\nmsalesorderid\nitemcode\nquantity\nprice\nmemberid)\n\n");
            scanf(" %s", field);

            if (strcmp(field, "quantity") == 0) {
                puts("Enter new integer Value");
                scanf("%d", &NewIntValue);
            }
            else if (strcmp(field, "price") == 0) {
                puts("Enter new Double Value");
                scanf("%lf", &NewDoubleValue);
            }
            else {
                printf("Enter new value: ");
                scanf(" %s", NewValue);
            }
            if (strcmp(field, "salesorderid") == 0) {
                strcpy(SalesDetail.SalesOrderID, NewValue);
                modified = 1;
                printf("%s", SalesDetail.SalesOrderID);
            }
            else if (strcmp(field, "itemcode") == 0) {
                strcpy(SalesDetail.ItemCode, NewValue);
                modified = 1;
                printf("%s", SalesDetail.ItemCode);
            }
            else if (strcmp(field, "quantity") == 0) {
                SalesDetail.QuantityOrdered = NewIntValue;
                modified = 1;
            }
            else if (strcmp(field, "price") == 0) {
                SalesDetail.Price = NewDoubleValue;
                modified = 1;
            }
            else if (strcmp(field, "memberid") == 0) {
                strcpy(SalesDetail.MemberID, NewValue);
                modified = 1;
            }
            if (modified == 1) {
                printf("\n\n%s\n%s\n%d\n%lf\n%s", SalesDetail.SalesOrderID, SalesDetail.ItemCode, SalesDetail.QuantityOrdered, SalesDetail.Price, SalesDetail.MemberID);
                printf("\nSales information modified successfully.\n");

                fclose(filePTR);

                AskForContinueation();
            }
        }
        
    }
    if (!IDfound) {
        puts("Sales Does not exist.");
    }
    
};

//Sales Search Module
void SearchModule() {
    puts("Activating Search Module");
    SalesOrder SalesDetail;
    char UserInputSalesOrderID[20];
    char confirmation = 'n';
    int Choice;
    int IDfound = 0;
    FILE* filePTR = fopen("SalesModuleFile.bin", "rb+");

    puts("Enter Sales Order id > eg.S001");
    scanf(" %s", UserInputSalesOrderID);

    while (fread(&SalesDetail, sizeof(SalesOrder), 1, filePTR) != 0) {
        if (strcmp(SalesDetail.SalesOrderID, UserInputSalesOrderID) == 0) {
            puts("Sales Module Found");

            printf("\n\nSales Order ID > %s\nItem Code > %s\nQuantity Ordered > %d\nPrice > %.2lf\nMember ID > %s\n"
                , SalesDetail.SalesOrderID, SalesDetail.ItemCode, SalesDetail.QuantityOrdered, SalesDetail.Price, SalesDetail.MemberID);

            IDfound = 1;
        }
    }
    if (!IDfound) {
        puts("Sales ID not found");
    };

    fclose(filePTR);


    AskForContinueation();

};

//Sales Display Module
void DisplayModule() {
    puts("\nActivating Display Module... \n");

    int ReportSelection;
    puts("Would you like to Look at a Compact Report or Cozy Report?");
    puts("\n1 > Compact Report(no fancy formatting)\n2 > Cozy Report(Fancy Formatting)\n");
    scanf("%d", &ReportSelection);

    if (ReportSelection == 1)
        ReadFromFile();
    else
    ReportModule(&ReportSelection);

    AskForContinueation();
};

//Sales Report Module
void ReportModule(int* CozyReport) {
    puts("You had chosen Cozy Report format.. good choice..\n");

    FILE* filePTR = fopen("SalesModuleFile.bin", "rb+");
    SalesOrder *SalesDetail = malloc(sizeof(SalesOrder));
    int i = 1;

    if (filePTR == NULL) {
        puts("There is nothing inside the file.");
        fclose(filePTR);
    };

        fread(&SalesDetail->SalesOrderID, sizeof(SalesDetail->SalesOrderID), 1, filePTR);
        fread(&SalesDetail->ItemCode, sizeof(SalesDetail->ItemCode), 1, filePTR);
        fread(&SalesDetail->QuantityOrdered, sizeof(SalesDetail->QuantityOrdered), 1, filePTR);
        fread(&SalesDetail->Price, sizeof(SalesDetail->Price), 1, filePTR);
        fread(&SalesDetail->MemberID, sizeof(SalesDetail->MemberID), 1, filePTR);

        puts("------------------------------------------------------------");
        puts("||\tAnchor Company Cozy Sales Report\t\t ||");
        puts("------------------------------------------------------------");
        printf("|| \tSales Order ID \t\t\t>> \t%s\t\t ||\n", SalesDetail->SalesOrderID);
        printf("|| \tSales Item Code \t\t>> \t%s\t ||\n", SalesDetail->ItemCode);
        printf("|| \tQuantity Ordered \t\t>> \t%d\t ||\n", SalesDetail->QuantityOrdered);
        printf("|| \tSales Item Price \t\t>> \t%.2lf\t ||\n", SalesDetail->Price);
        printf("|| \tMember ID \t\t\t>> \t%s\t\t ||\n", SalesDetail->MemberID);
        puts("------------------------------------------------------------");
    free(SalesDetail);
    fclose(filePTR);
    
}

//Sales Write to File Module
void WriteToFile() {

    puts("Accessing Writing Module... \n");

    SalesOrder *SalesDetail;
    double TotalPrice;
    char confirmation;
    int num_points = 50;
    SalesDetail = malloc(num_points * sizeof(SalesOrder));

    FILE* filePTR = fopen("SalesModuleFile.bin", "wb");

    if (filePTR == NULL) {
        printf("Error!");
        exit(1);
    };

    do {
        puts("Format: \nSales Order ID (eg. S001)\nItem Code (eg. ITM001)\nQuantity Ordered (eg. 10)\nPrice (eg. RM 250k)\nMember ID (eg. M0001)\n");

        scanf(" %s", SalesDetail->SalesOrderID);
        scanf(" %s", SalesDetail->ItemCode);
        scanf("%d", &SalesDetail->QuantityOrdered);
        scanf("%lf", &SalesDetail->Price);
        scanf(" %s", SalesDetail->MemberID);

        puts("\nCurrently Writting to file... \n");
        fwrite(SalesDetail, sizeof(SalesOrder), num_points, filePTR);

        i++;
        puts("\nDo you Want to Continue? \n");
        puts("\ny > proceed \nn > no proceed \n(Pease only enter lower case)\n");
        scanf(" %c", &confirmation);
        puts("\n");

    } while (confirmation != 'n');
    free(SalesDetail);

    fclose(filePTR);

    puts("Exiting Write Module... \n");
}

//Sales Read From File Module
void ReadFromFile() {

    puts("\nAccessing Read Module... \n");

    FILE* filePTR = fopen("SalesModuleFile.bin", "rb");
    SalesOrder* SalesDetail = malloc(sizeof(SalesOrder));
    int i = 0;

    if (filePTR == NULL) {
        puts("There is nothing inside the file.");
        fclose(filePTR);
    };

        fread(&SalesDetail->SalesOrderID, sizeof(SalesDetail->SalesOrderID), 1, filePTR);
        fread(&SalesDetail->ItemCode, sizeof(SalesDetail->ItemCode), 1, filePTR);
        fread(&SalesDetail->QuantityOrdered, sizeof(SalesDetail->QuantityOrdered), 1, filePTR);
        fread(&SalesDetail->Price, sizeof(SalesDetail->Price), 1, filePTR);
        fread(&SalesDetail->MemberID, sizeof(SalesDetail->MemberID), 1, filePTR);

        printf("\n\nSales Order ID > %s\nItem Code > %s\nQuantity Ordered > %d\nPrice > %.2lf\nMember ID > %s\n"
        ,SalesDetail->SalesOrderID, SalesDetail->ItemCode, SalesDetail->QuantityOrdered, SalesDetail->Price, SalesDetail->MemberID);

    fclose(filePTR);
    puts("\n\nExiting Read Module... \n");
};

//Sales Ask For Continueation Module
int AskForContinueation() {
    char confirmation = 'n';
    while (confirmation != 'y') {
        puts("Would you like to continue?");
        puts("\ny > Continue \nn > no continue \n(Pease only enter lower case)\n");
        scanf(" %c", &confirmation);

    }
    if (confirmation == 'n') {
        exit (0);
    }
    ModuleSelect();
};

//Staff Module Part
void StaffModuleOptionSelect() {
    // Job (Let user input what they want to do. then pass to FilterOption(); );

    int* option;
    char confirmation = 'N';

    while (confirmation != 'y') {
        puts("\nWhat would you like to do?\n");
        puts("0 > Exit");
        puts("1 > Add");
        puts("2 > Modify");
        puts("3 > Search");
        puts("4 > Display");
        scanf("%d", &option);

        printf("\n\nConfirm option \t%d ??\n", option);
        puts("y > proceed \nn > no proceed \n(Pease only enter lower case)");
        scanf(" %c", &confirmation);
        puts("\n");
    }
    StaffFilterOption(&option);
}

//Staff Filter Option
int StaffFilterOption(int* option) {

    // Job (Filter out User option, throw them to the place they want);

    printf("\nUser selected option >\t%d\n", *option);

    if (*option == 0) {
        puts("\nExiting Program... ");
        return 0;
    }
    else if (*option == 1) {
        StaffAddModule();
    }
    else if (*option == 2) {
        StaffModifyModule();
    }
    else if (*option == 3) {
        StaffSearchModule();
    }
    else if (*option == 4) {
        StaffDisplayModule();
    }
    else {
        puts("\n\nPlease Select A Valid Option\n");
        StaffModuleOptionSelect();
    };
};

//Staff Login Module
void StaffLoginModule() {
    StaffInfo StaffDetail;
    char UserInputStaffID[10];
    char UserInputPassphrase[20];
    int Loginsuccess = 0;
    FILE* filePTR = fopen("StaffModuleFile.txt", "a");
    puts("Please Enter your Credentials!\n");
    puts("Please Enter Your Staff ID > eg.STF001");
    scanf(" %s", UserInputStaffID);
    puts("Please Enter Your Staff Passphrase");
    scanf(" %s", UserInputPassphrase);

    if (strcmp(UserInputStaffID, "STF001") == 0 && strcmp(UserInputPassphrase, "123") == 0) {
        Loginsuccess = 1;
    }
    else {
        Loginsuccess = 0;
        puts("Login Fail");
        StaffModuleOptionSelect();
    }

    fclose(filePTR);
}

//Staff Add Module
void StaffAddModule() {
    //Job Write to file, ask User if they want to see file content. Yes throw to DisplayModule(). No go back OptionSelect();
    char confirmation;
    puts("Activating Add Module... \n");

    StaffWriteToFile();

    puts("Would You Like to View Contents within the file?\n");
    puts("\ny > proceed \nn > no proceed \n(Pease only enter lower case)\n");
    scanf(" %c", &confirmation);

    if (confirmation == 'y') {
        StaffDisplayModule();
    }

    StaffAskForContinueation();

};

//Staff Modify Module
void StaffModifyModule() {
    StaffLoginModule();
    puts("In Modify Module\n");

    StaffInfo StaffDetail;
    char NewCharValue;
    char NewValue[30];
    char UserInputStaffID[6];
    char UserInputPassphrase[20];
    char field[20];
    int modified = 0;
    int IDfound = 0;
    FILE* filePTR = fopen("StaffModuleFile.txt", "w+");

    puts("Enter Staff id > eg.STF001");
    scanf(" %s", UserInputStaffID);
    puts("Enter Passphrase.");
    scanf(" %s", UserInputPassphrase);

    while (fscanf(filePTR, "%[^\n]-%[^\n]-%[^\n]-%[^\n]-%[^\n]",
        StaffDetail.StaffID, StaffDetail.StaffName, StaffDetail.StaffPassPhrase, StaffDetail.PasswordRecovery, StaffDetail.Position) != EOF) {
        if (strcmp(UserInputStaffID, "STF001") == 0 && strcmp(UserInputPassphrase, "123") == 0) {
            fprintf(filePTR, "\n\nStaff ID > %s\nStaff Name > %s\nPassPhrase > %s\nPassword Recovery > %s\nStaff Position > %s\n"
                , StaffDetail.StaffID, StaffDetail.StaffName, StaffDetail.StaffPassPhrase, StaffDetail.PasswordRecovery, StaffDetail.Position);
            IDfound = 1;
            printf("\nEnter field to modify: (Format:\nstaffid\nname\npassphrase\npasswordrecovery\npostion\n)");
            scanf(" %s", field);
            printf("Enter new value: ");
            scanf(" %s", NewValue);
            if (strcmp(field, "staffid") == 0) {
                strcpy(StaffDetail.StaffID, NewValue);
                modified = 1;
                printf("%s", StaffDetail.StaffID);
            }
            else if (strcmp(field, "passphrase") == 0) {
                strcpy(StaffDetail.StaffPassPhrase, NewValue);
                modified = 1;
                printf("%s", StaffDetail.StaffPassPhrase);
            }
            else if (strcmp(field, "name") == 0) {
                strcpy(StaffDetail.StaffName, NewValue);
                modified = 1;
                printf("%s", StaffDetail.StaffName);
            }
            else if (strcmp(field, "passwordrecovery") == 0) {
                strcpy(StaffDetail.PasswordRecovery, NewValue);
                modified = 1;
                printf("%s", StaffDetail.PasswordRecovery);
            }
            else if (strcmp(field, "position") == 0) {
                strcpy(StaffDetail.Position, NewValue);
                modified = 1;
                printf("%s", StaffDetail.Position);
            }
            if (modified == 1) {
                fprintf(filePTR, "\n\nStaff ID > %s\nStaff Name > %s\nPassPhrase > %s\nPassword Recovery > %s\nStaff Position > %s\n"
                    , StaffDetail.StaffID, StaffDetail.StaffName, StaffDetail.StaffPassPhrase, StaffDetail.PasswordRecovery, StaffDetail.Position);
                printf("\nStaff information modified successfully.\n");
            }
        }
        else {
            fprintf(filePTR, "\n\nStaff ID > %s\nStaff Name > %s\nPassPhrase > %s\nPassword Recovery > %s\nStaff Position > %s\n"
                , StaffDetail.StaffID, StaffDetail.StaffName, StaffDetail.StaffPassPhrase, StaffDetail.PasswordRecovery, StaffDetail.Position);
            printf("\nInvalid field name.\n");
        }
    }
    if (!IDfound) {
        puts("Staff Does not exist.");
    }
    fclose(filePTR);

    StaffAskForContinueation();
}

//Staff Search Module
void StaffSearchModule() {
    StaffLoginModule();
    puts("Activating Search Module");
    StaffInfo StaffDetail;
    char UserInputStaffID[20];
    char UserInputPassphrase[20];
    char confirmation = 'n';
    int Choice;
    int IDfound = 0;
    FILE* filePTR = fopen("StaffModuleFile.txt", "w+");

    puts("Enter Member id > eg.MEM001");
    scanf(" %s", UserInputStaffID);
    puts("Enter Passphrase.");
    scanf(" %s", UserInputPassphrase);

    while (fscanf(filePTR, "%[^\n]-%[^\n]-%[^\n]-%[^\n]-%[^\n]", StaffDetail.StaffID, StaffDetail.StaffName, StaffDetail.StaffPassPhrase, StaffDetail.PasswordRecovery, StaffDetail.Position) != EOF) {
        if (strcmp(UserInputStaffID, "STF001") == 0 && strcmp(UserInputPassphrase, "123") == 0) {
            fprintf(filePTR, "\n\nStaff ID > %s\nStaff Name > %s\nPassPhrase > %s\nPassword Recovery > %s\nStaff Position > %s\n"
                , StaffDetail.StaffID, StaffDetail.StaffName, StaffDetail.StaffPassPhrase, StaffDetail.PasswordRecovery, StaffDetail.Position);
            IDfound = 1;
        }
    }
    if (!IDfound) {
        puts("Sales ID not found");
    };

    fclose(filePTR);


    StaffAskForContinueation();

};

//Staff Display Module
void StaffDisplayModule() {
    StaffLoginModule();
    puts("\nActivating Display Module... \n");

    int ReportSelection;
    puts("Would you like to Look at a Compact Report or Cozy Report?");
    puts("\n1 > Compact Report(no fancy formatting)\n2 > Cozy Report(Fancy Formatting)\n");
    scanf("%d", &ReportSelection);


    if (ReportSelection == 1)
        StaffReadFromFile();
    else
    StaffReportModule(&ReportSelection);

    int AskForContinueation();
}

//Staff Report Module
void StaffReportModule(int* CozyReport) {
    puts("Printing cozy report");

    FILE* filePTR = fopen("StaffModuleFile.txt", "a");
    StaffInfo StaffDetail;
    int counter;


    if (filePTR == NULL) {
        puts("There is nothing inside the file.");
        fclose(filePTR);
    };

    // Research Read from text

    while (fread(&StaffDetail, sizeof(StaffInfo), 1, filePTR) != 0) {
        puts("------------------------------------------------------------");
        puts("||\tAnchor Company Cozy Staff Report\t\t ||");
        puts("------------------------------------------------------------");
        printf("|| \nStaff ID \t\t>> \t%s\t\t ||\n", StaffDetail.StaffID);
        printf("|| \tStaff Password \t\t>> \t%s\t\t ||\n", StaffDetail.StaffPassPhrase);
        printf("|| \tStaff Name \t\t>> \t%s\t ||\n", StaffDetail.StaffName);
        printf("|| \tStaff Password Recovery \t\t>> \t%s\t ||\n", StaffDetail.PasswordRecovery);
        printf("|| \tStaff Position \t\t>> \t%s\t ||\n", StaffDetail.Position);
        puts("------------------------------------------------------------");

    }
    fclose(filePTR);

}

//Staff Read From File
void StaffReadFromFile() {
    puts("\nAccessing Read Module... \n");

    FILE* filePTR = fopen("StaffModuleFile.txt", "a");
    StaffInfo StaffDetail;
    int counter;


    if (filePTR == NULL) {
        puts("There is nothing inside the file.");
        fclose(filePTR);
    };

    // Research Read from text

    while (fread(&StaffDetail, sizeof(StaffInfo), 1, filePTR) != 0) {

        fprintf(filePTR, "\n\nStaff ID > %s\nStaff Name > %s\nPassPhrase > %s\nPassword Recovery > %s\nStaff Position > %s\n"
            , StaffDetail.StaffID, StaffDetail.StaffName, StaffDetail.StaffPassPhrase, StaffDetail.PasswordRecovery, StaffDetail.Position);
    }
    fclose(filePTR);
    puts("\n\nExiting Read Module... \n");
}

//Staff Write to File
void StaffWriteToFile() {

    puts("Accessing Writing Module... \n");

    StaffInfo StaffDetail;
    char confirmation;

    FILE* filePTR = fopen("StaffModuleFile.txt", "w");

    if (filePTR == NULL) {
        printf("Error!");
        exit(1);
    };

    do {
        puts("Format: \nStaff ID (eg. STF001)\nStaff Name (eg. Twikipedia)\nStaff PassPhrase (eg.securepassword123)\nPassword Recovery (eg.dog)\nStaff Position (eg.Cachier)");

        scanf(" %s", StaffDetail.StaffID);
        scanf(" %s", StaffDetail.StaffName);
        scanf(" %s", StaffDetail.StaffPassPhrase);
        scanf(" %s", StaffDetail.PasswordRecovery);
        scanf(" %s", StaffDetail.Position);

        puts("\nCurrently Writting to file... \n");
        fwrite(&StaffDetail, sizeof(StaffInfo), 1, filePTR);

        puts("\nDo you Want to Continue? \n");
        puts("\ny > proceed \nn > no proceed \n(Pease only enter lower case)\n");
        scanf(" %c", &confirmation);
        puts("\n");
    } while (confirmation != 'n');

    fclose(filePTR);

    puts("Exiting Write Module... \n");
};

//Staff Ask for Continueation
int StaffAskForContinueation() {
    char confirmation = 'n';
    while (confirmation != 'y') {
        puts("Would you like to continue?");
        puts("\ny > Continue \nn > no continue \n(Pease only enter lower case)\n");
        scanf(" %c", &confirmation);
    }

    if (confirmation == 'n') {
        return 0;
    }
    ModuleSelect();
};