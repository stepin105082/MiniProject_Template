/**  manage.c
 * @brief functions mostly involved in the project
 *
 *
 */

#include "manage.h"

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

int sanitize()
{
    int s=rand() % 2;
    //printf("Sanitize %d\n",s);
    if(s==1)
        return 1;
    else
        sanitize();

}

int temp_check()
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
        printf("\n Temperature is high !.. Kindly don't enter the shop.");
        return 0;
    }

}


