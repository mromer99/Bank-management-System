#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main_exit;
void menu();
void close_and_exit();

void fordelay(int j)
{
    int i, k;
    for (i= 0; i < j; i++)
    {
        k = i;
    }
    
}

float interest(float timee, float amount, int rate) {
    double SI;
    SI = (timee*amount*rate) / 100.0;
    return(SI);
}

struct date{
    int month, day, year;       

};

struct {
    char name[60];
    int acc_nr, age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amount;
    struct date dob;
    struct date deposit;
    struct date withdraw;
    
} add, upd, check, rem, transaction;



void new_acc() 
{
    int choice;
    
    FILE *ptr;
    ptr = fopen("record.dat", "a+");

    account_nr:
    system("clear");
    printf("\t\t\t\xB2\xB2\xB2 ADD RECORD \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(dd/mm/yyyy):");
    scanf("%d/%d/%d", &add.deposit.day, &add.deposit.month, &add.deposit.year);
   
    printf("\nEnter the account number:");
    scanf("%d", &check.acc_nr);
    
    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_nr, add.name, &add.dob.day, 
    &add.dob.month, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, 
    &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        if (check.acc_nr == add.acc_nr)
        {
            printf("Account nr. already in use!");
            fordelay(1000000000);
            goto account_nr;
        }
    }
    add.acc_nr = check.acc_nr;
    printf("\nEnter the name:");
    scanf("%s", add.name);

    printf("\nEnter the date of birth(dd/mm/yyyy):");
    scanf("%d/%d/%d", &add.dob.day, &add.dob.month, &add.dob.year);

    printf("\nEnter the age:");
    scanf("%d", &add.age);

    printf("\nEnter the address:");
    scanf("%s", add.address);

    printf("\nEnter the citizenship number:");
    scanf("%s", add.citizenship);

    printf("\nEnter the phone number: ");
    scanf("%lf", &add.phone);

    printf("\nEnter the amount to the deposit:$");
    scanf("%f", &add.amount);

    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s", add.acc_type);

    fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_nr, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);

    fclose(ptr);
    printf("\nAccount created successfully!");

    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    if (main_exit == 1)
    {
        menu();
    } 
    else if (main_exit == 0)
    {
        close_and_exit();
    } 
    else 
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}


void edit(void) 
{
    int choice, test = 0;

    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("record.dat", "w");

    printf("\nEnter the account nr. of the customer whose info you want to change: ");
    scanf("%d", &upd.acc_nr);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_nr, add.name, &add.dob.day, 
    &add.dob.month, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, 
    &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        if (add.acc_nr == upd.acc_nr)
        {
            test = 1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\nEnter your choice(1 for address and 2 for the phone): ");
            scanf("%d", &choice);
            system("clear");

            if (choice == 1)
            {
                printf("Enter the new address: ");
                scanf("%s", upd.address);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_nr, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, upd.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
                system("clear");
                printf("changes saved!");
            }
            else if (choice == 2)
            {
                printf("Enter the new phone number");
                scanf("%lf", &upd.phone);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_nr, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, upd.phone, add.acc_type, add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
                system("clear");
                printf("changes saved!");
            }
        }
        else
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_nr, add.name, add.dob.day, 
            add.dob.month, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, 
            add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
        }
    }

    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if (test != 1)
    {
        system("clear");
        printf("\nRecord not found!!\a\a");
        
        edit_invalid:
        printf("\nEnter 0 to try again, 1 to return to main menu and 2 to exit: ");
        scanf("%d", &main_exit);
        system("clear");
        if (main_exit == 1)
        {
            menu();
        }
        else if (main_exit == 2)
        {
            close_and_exit();
        }
        else if (main_exit == 0)
        {
            edit();
        }
        else 
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d", &main_exit);
        system("clear");
        if (main_exit == 1)
        {
            menu();
        }
        else
        {
            close_and_exit();
        }
        
    }
    
    
}

void transact(void)
{
    int choice, test = 0;
    FILE *old, *newRec;
    old = fopen("record.dat", "r");
    newRec= fopen("new.dat", "w");

    printf("Enter the account nr of the Customer: ");
    scanf("%d", &transaction.acc_nr);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_nr, add.name, 
    &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.address, add.citizenship, 
    &add.phone, add.acc_type, &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year) !=EOF)
    {
        if (add.acc_nr == transaction.acc_nr) 
        {
            test = 1;
            if (strcmp(add.acc_type, "fixed1") == 0 || strcmp(add.acc_type, "fixed")== 0 || strcmp(add.acc_type, "fixed3")== 0)
            {
                printf("\a\a\a\n\n YOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                fordelay(1000000000);
                system("clear");
                menu();
            }
            printf("\n\nDo you want to \n1.Deposit\n2.Withdraw?\n\nEnter your Choice(1 for deposit and 2 for withdraw):");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("Enter the amount you want to deposit:$ ");
                scanf("%f", &transaction.amount);
                add.amount += transaction.amount;
                fprintf(newRec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_nr, add.name, 
    add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, 
    add.phone, add.acc_type, add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
                printf("\n\nDeposited successfully");
            }
            else
            {
                printf("Enter the amount you want to withdraw:$ ");
                scanf("%f", &transaction.amount);
                add.amount -= transaction.amount;
                fprintf(newRec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_nr, add.name, 
    add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, 
    add.phone, add.acc_type, add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
                printf("\n\nWithdrawn successfully");
            }
        }
      /*  else if (add.acc_nr != transaction.acc_nr)
        {
            printf("\n\nAccount was not Found!");

        }
        */
        else
        {
            fprintf(newRec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_nr, add.name, 
    add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, 
    add.phone, add.acc_type, add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
        }

    }
    
    fclose(old);
    fclose(newRec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test != 1)
    {
        printf("\n\nRecord not found!!");

        transaction_invalid:
        printf("\n\n\nEnter '0' to try again, '1' to return to main Menu and '2' to exit ");
        scanf("%d", &main_exit);
        system("clear");

        if (main_exit == 0)
        {
            transact();
        } 
        else if (main_exit == 1)
        {
            menu();    
        }
        else if (main_exit == 2)
        {
            close_and_exit();
        }
        else {
            printf("\nInvalid!");
            goto transaction_invalid;
        }
    }
    else 
    {
        printf("\nEnter '0' to exit and '1' to go to the main Menu: ");
        scanf("%d", &main_exit);
        system("clear");

        if (main_exit == 1)
        {
            menu();
        } else
            close_and_exit();
        
    }
    
}

void see(void)
{
    FILE *ptr;
    int test = 0, rate, choice;
    float time, intrst;

    ptr = fopen("record.dat", "r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter the account number:");
        scanf("%d", &check.acc_nr);

        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", 
        &add.acc_nr, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.address, add.citizenship,
        &add.phone, add.acc_type, &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year) !=EOF)
        {
            if (add.acc_nr == check.acc_nr)
            {
                system("clear");
                test = 1;

                printf("\nAccount Nr.:%d \nName:%s \nDate Of Birth: %d/%d/%d \nAge: %d \nAdress: %s \nCitizenship Nr.: %s \nPhone Nr.: %.0lf \nType of Account: %s \nAmount Deposited: $%.2f \nDate Of Deposit: %d/%d/%d", add.acc_nr, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
                if (strcmp(add.acc_type, "Fixed1")== 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get $%.2f as interest on %d/%d/%d.", intrst, add.deposit.day, add.deposit.month, add.deposit.year+1);
                }
                else if (strcmp(add.acc_type, "fixed2")== 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get $%.2f as interest on %d/%d/%d.", intrst, add.deposit.day, add.deposit.month, add.deposit.year+2);
                }
                else if (strcmp(add.acc_type, "fixed3")== 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get $%.2f as interest on %d/%d/%d.", intrst, add.deposit.day, add.deposit.month, add.deposit.year+3);
                }
                else if (strcmp(add.acc_type, "saving")== 0)
                {
                    time = 1.0/12.0;
                    rate = 8;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get $%.2f as interest on %d of every month", intrst, add.deposit.day);
                }
                else if (strcmp(add.acc_type, "current")== 0)
                {
                    printf("\n\nYou will get no interest \a\a");
                }
            }          
        }
    }
    else if (choice == 2)
    {
        printf("Enter the Name:");
        scanf("%s", check.name);

        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", 
        &add.acc_nr, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.address, add.citizenship,
        &add.phone, add.acc_type, &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year) !=EOF)
        {
            if (add.name == check.name)
            {
                system("clear");
                test = 1;

                printf("\nAccount Nr.:%d \nName:%s \nDate Of Birth: %d/%d/%d \nAge: %d \nAdress: %s \nCitizenship Nr.: %s \nPhone Nr.: %.0lf \nType of Account: %s \nAmount Deposited: $%.2f \nDate Of Deposit: %d/%d/%d", add.acc_nr, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
                if (strcmp(add.acc_type, "Fixed1")== 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get $%.2f as interest on %d/%d/%d.", intrst, add.deposit.day, add.deposit.month, add.deposit.year+1);
                }
                else if (strcmp(add.acc_type, "fixed2")== 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get $%.2f as interest on %d/%d/%d.", intrst, add.deposit.day, add.deposit.month, add.deposit.year+2);
                }
                else if (strcmp(add.acc_type, "fixed3")== 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get $%.2f as interest on %d/%d/%d.", intrst, add.deposit.day, add.deposit.month, add.deposit.year+3);
                }
                else if (strcmp(add.acc_type, "saving")== 0)
                {
                    time = 1.0/12.0;
                    rate = 8;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get $%.2f as interest on %d of every month", intrst, add.deposit.day);
                }
                else if (strcmp(add.acc_type, "current")== 0)
                {
                    printf("\n\nYou will get no interest \a\a");
                }
            }          
        }
    }

    fclose(ptr);
    if (test !=1)
    {
        system("clear");
        printf("\nRecord not found!!\a\a\a");
        
        see_invalid:
            printf("\nEnter 0 to try again, 1 to return to main menu and 2 to exit: ");
            scanf("%d", &main_exit);
            system("clear");
                if (main_exit == 0)
                {
                    see();
                }
                else if (main_exit == 1)
                {
                    menu();
                }
                else if (main_exit == 2)
                {
                    close_and_exit();
                }
                else
                {
                    system("clear");
                    printf("\nInvalid!!\a");
                    goto see_invalid;
                }
    }
    else {
        printf("\nEnter 0 to go to exit and 1 to return to main menu: ");
        scanf("%d", &main_exit);
        if (main_exit == 0)
        {
            system("clear");
            close_and_exit();
        }
        else if (main_exit == 1)
        {
            system("clear");
            menu();
        }
        
    }

}

void erase(void)
{

}

void view_list(void)
{

}

void close_and_exit() {
    printf("\n\n\n\t\tSee you again!");
}

void menu(void) 
{
    int choice;

    system("clear");
    system("color 9");
    
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create  new account\n\t\t2.Update information of exixting account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d", &choice);

    system("clear");
    switch (choice)
    {
    case 1:new_acc();
    break;
    case 2:edit();
    break;
    case 3:transact();
    break;
    case 4:see();
    break;
    case 5:erase();
    break;
    case 6:view_list();
    break;
    case 7:close_and_exit();
    break;
    }

}


int main() 
{
    menu();
}