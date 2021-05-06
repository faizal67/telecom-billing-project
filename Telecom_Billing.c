#include <stdio.h> 
#include <conio.h>
#include <string.h>
char username[][20]={"faizal","kushagra","salman","nikita","pragya"};
char passwords[][20]={"123","123","123","123","123"};
void clrscr(void);
int credential();
int main()
{ 
void clrscr();
printf("************please enter the username and password *************\n");
credential();
printf("End of the program");
return 0;
}
 int credential()
{
  char name[20],password[20];
  int flag=0,snake=4;
  printf("Username--");
  scanf("%s",&name);
  {
   for (int i=0;i<5;i++)
    {
        if(strcmp(name, username[i])==0)
        {
          flag++;
          b:
          printf("Password--");
          scanf("%s",&password);
         if(strcmp(password, passwords[i])==0)
         {
           printf("Welcome back %s\n",name);
           break;
         }
         else 
         if(snake==1)
         {
          printf("please enter the username again\n");
          credential();
         }
         snake--;
         printf("Wrong password\nPlease enter the password again\nyou have only %d attempt left\n",snake);
         goto b;
        }
    }
  }
  if(flag==0)
  {
    printf("please enter the correct username\n");
    credential();
  }
}  