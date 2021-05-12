#include <stdio.h> 
#include <conio.h>
#include <string.h>
#include <stdlib.h>
char username[][20]={"faizal","kushagra","salman","nikita","pragya"};
char passwords[][20]={"123","123","123","123","123"};
char name[20],password[20];
char admin_name[]={"xyz"};
char admin_pass[]={"123"};
int id;
void clrscr(void);
int user_login();
int admin_login();
int admin_menu();
int user_menu();



int main()
{ 
  void clrscr();
  int choice;
  printf("***************************************************************\n");
  printf("--------------------------WELCOME TO THE TELECOME BILLING SYSTEM----------------------------\n");
  printf("                          ******************************************************************\n\n");
  a:
  {
    printf("\t\t\t LOGIN WINDOW\n");
    printf("------------->USER<-----------*------------->ADMIN<-----------\n");
    printf("             press 1                        press 2\n");
    scanf("%d",&choice);
    switch (choice)
      {
        case 1:user_login();
        break;
        case 2:admin_login();
        break;
        default: printf("Wrong input enter correct input \n");
        goto a;
      }
  }
  printf("end of the program");
}


int admin_menu()
{
   printf("this is a admin menu\n");
}


int user_menu()
 {
  int choice;
  printf("*********************MAIN WINDOW********************\n");
  printf(" * Profile                                                    press 1\n");
  printf(" * Data used                                                  press 2\n");
  printf(" * Voice call time                                            press 3\n");
  printf(" * Subscriptions                                              press 4\n");
  printf(" * Generate your Bill                                         press 5\n");
 
 } 

int admin_login()
{
 char name[20],password[20];
 while(1)
 {
   printf("Please enter the admin name--->");
   scanf("%s",&name);
   if(strcmp(name, admin_name)==0)
    {
      while(1)
      {
        printf("\nEnter the password---->");
        scanf("%s",&password);
        if(strcmp(password, admin_pass)==0)
        {
          printf(" YOU HAVE ENTERED INTO A ADMIN SECTION \n");
          admin_menu();
          break;
        }
        else 
        {
          printf("Please enter the correct password\n");
        }
      }
    break;  
    }    
   else
   {
      printf("Please Enter the correct admin name\n");
   }    
 }  
return 0;
}

int user_login()
 {
  int flag=0,snake=4;
    printf("Username--");
    scanf("%s",&name);
      for (int i=0;i<5;i++)
       {
         if(strcmp(name, username[i])==0)
         {
          flag++;
          {
            a:
            printf("Password--");
            scanf("%s",&password);
            if(strcmp(password, passwords[i])==0)
              {
                id=i;
                printf("Welcome back %s\n",username[id]);
                user_menu();
                break;
              }
            else
              { 
                if(snake==1)
                 {
                  printf("please enter the username again\n");
                  user_login();
                 }
                snake--;
                printf("Wrong password\n");
                printf("Please enter the password again\nyou have only %d attempt left\n",snake);
                goto a;
              }  
          }
         }
          
        }
   if(flag==0)
   {
     user_login();
   }      

return 0;   
}










