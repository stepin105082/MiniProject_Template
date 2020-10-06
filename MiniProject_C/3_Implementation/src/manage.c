/**  manage.c
 * @brief functions mostly involved in the project
 *
 *
 */

#include "manage.h"

int LoginCheck(char user[], char pass[])          //Employee login function
{
    FILE *fptr;
	char ch,buffer[40];
        strcat(user,pass);
        fptr=fopen("emp_cred.txt","r");
        while(ch = fgetc(fptr) != EOF)
        {
        fscanf(fptr, "%[^\n]", buffer);
        if(strcmp(user,buffer)==0)
        {
            printf("\n\n\n\t\t\tLogin Successful");
            fclose(fptr);
            return 1;
        }
	}    
    fclose(fptr);
    return 0;
}


char* local_time()
{
    struct tm* local;
    time_t t = time(NULL);
    local = localtime(&t);      // Get the local time
    char *a= asctime(local);
    *(a+24)=' ';
    return a;
}

int phone_check(struct Customer c)  // to check the digits in the phone number
{
    if(strlen(c.phone)!=10)
        return 0;
    return 1;
}

int sanitize()                  //sanitization check
{
    int s=rand() % 2;
    //printf("Sanitize %d\n",s);
    if(s==1)
        return 1;
    else
        sanitize();

}

int temp_check()                    //temperature check
{
    int temp=(rand() % 12)+30;
   // printf("Temp %d\n",temp);

    if(temp<=40)
    {
        if(sanitize())
            return 1;
    }
    else
    {
        printf("\n Temperature is high !.. Kindly don't enter the shop.\n");
        return 0;
    }

}


