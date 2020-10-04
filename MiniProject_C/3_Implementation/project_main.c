
/**
* project_main.c
*@brief Main file for Customer Management System
*/
#include "manage.h"


/** @brief count value gives the no:of persons inside the shop */
static int count=0;
static int option_flag=0;

void new_customer();
void view();
void count_check();
void anyone_left();
void customer_mgmt();
void options();

/** @brief function to login using username and password for the employee
 *
 * \param
 * \param
 * \return 1 if login is successful
 *
 */
int LoginCheck(struct Employee e)          //Employee login function
{
    FILE *fptr;
    int a=0;
    do                                      // Finite attempts to login (3)...
    {
        int i=0;
        char c=' ';
        printf("\n\t\tCUSTOMER DATA MANAGEMENT DURING COVID-19\n\n");
        printf("\n\t\t\tUsername : ");
        gets(e.user);
        printf("\t\t\tPassword : ");
        while(i<20)
	    {
            e.pass[i]=getch();
            c=e.pass[i];
            if(c=='\r')               // Checking if enter is pressed
                break;
            else if (c=='\b' && i>=1 ) // checking if backspace is pressed.
            {
                printf("\b\b");
                --i;
            }
            else
            {
                printf("*");
                i++;
            }
	    }

         e.pass[i]='\0';

	char ch,buffer[40];
        strcat(e.user,e.pass);
        fptr=fopen("emp_cred.txt","r");
        while((ch = fgetc(fptr)) != EOF)
        {
        fscanf(fptr, "%[^\n]", buffer);
        if(strcmp(e.user,buffer)==0)
        {
            printf("\n\n\n\t\t\tLogin Successful");
            fclose(fptr);
            //a=1;
            return 1;
        }
        }
        printf("\n\n\t Invalid login, Press any key to try again...");

        getch();
        system("cls");                  //used to clr screen
        a++;
    }while (a<=2);

    fclose(fptr);

}


/**< function to go back to options in between entering new customer details */

int go_back()
{
    if(count!=0)
    {
        char ch1;
        printf("\nDo you want to go back to options menu? (y/n) :");
        scanf("%s",&ch1);
        if(ch1=='Y' || ch1=='y')
            return 1;
    }
    return 0;
}

/** checks the no:of persons inside the shop is less than or equal to 5
 *
 */

void count_check()
{
    anyone_left();
    if (count<5)
    {
        if(option_flag==0)
        {
            printf("You can enter \n");
            count++;
        }
        else
            option_flag=0;
        printf("Count %d\n", count);
        int f=go_back();
        if(f==1)
            options();
        else
            new_customer();
    }
    else
    {
        printf("Entry restricted\n");
        while(count==5)
        {
            count_check();
        }
    }
}

/** The function to check whether any  of the customers has left the shop */

void anyone_left()
{
    char ch='y';
    while((ch=='y' || ch=='Y') && count!=0)
    {
        printf("Has anyone left?");
        scanf("%s", &ch);
        if(ch=='Y'||ch=='y')
            if(count!=0)
                count--;
        printf("count %d\n", count);
    }
}

/** List of options */
void options()
{   system("cls");
    int n;
    option_flag=1;
    printf("\n\t\t\t Select option ");
    printf("\n\n\t 1.New Customer details entry");
    printf("\n\t 2.View Customer details");
    printf("\n\t 3.Exit");
    printf("\n\n\t Enter an option: ");
    scanf("%d", &n);
    system("cls");

    switch(n)
    {
        case 1:
        {
           customer_mgmt();
           break;
        }
         case 2:
         {
             view();
             break;
         }
         case 3:
         {
            system("cls");
         }
    }
}


void customer_mgmt()             /**< option 1 */
{
    if (count<1)
        new_customer();
    else
        count_check();
}

/** the function to enter new customer details */

void new_customer()
{
    if(count<=5)
    {
        struct Customer c;
        printf("Enter name:");
        //getchar();
        scanf("%s",&c.name);
        printf("Enter phone number:");
        scanf("%s",&c.phone);
        while(!phone_check(c))
        {
            printf("Enter a valid phone number:");
            scanf("%s",&c.phone);
        }
        c.date=local_time();
        FILE *fptr;
        fptr = fopen ("Customer_details.csv", "a+");
        if (fptr == NULL)
        {
            fprintf(stderr, "\nError in opening file\n");
        }

        fprintf(fptr,"%s%s,%s,%s%s","",c.date,c.name,c.phone,"\n");

        fclose(fptr);
        if(!temp_check())
            customer_mgmt();
    }
    option_flag=0;
    count_check();

}

/** function to view the details of customers - option 2 */

void view()
{
    FILE *fptr;
    fptr=fopen("Customer_details.csv","r");
    char buffer[100];
    if(fptr==NULL)
    {
        printf("Error in opening file");
        exit(1);
    }
    while(fgets(buffer, 100, fptr))
    {
        printf("%s\n",buffer);
    }
    fclose(fptr);
    printf("Press any key to go back.....");
    getchar();
    system("cls");
    options();
}

/** @brief main function
 *
 * @param void
 * \return 0
 *
 */


int main()
{
	//test_main();

	struct Employee e={0};
    int x;
    x=LoginCheck(e);
    if(x==1)
        options();

    return 0;
}

