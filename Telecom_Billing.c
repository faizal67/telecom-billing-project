#include <stdio.h> 
#include <conio.h>
#include <string.h>
#include <stdlib.h>
char username[][20]={"faizal","kushagra","salman","nikita","pragya"};
char passwords[][20]={"123","123","123","123","123"};
char name[20],password[20];
char admin_name[]={"xyz"};
char admin_pass[]={"123"};
long long  phone_no[]={9899483922,8887122744,7291049064,3594695879,4387643986};
float data_used[]={39,40,20,33,10};
float call_time[]={23,24,45,64,23};
int id;
void clrscr(void);
int user_login();
int admin_login();
int admin_menu();
int user_menu();
//faizal


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
  printf(" * Welcome Back %s \n",username[id]);
  printf(" * %lld\n",phone_no[id]);
  printf(" * Data consume(gb) :%f \n",data_used[id]);
  printf(" * Call time(min) :%f\n",call_time[id]);
  printf(" *  update data consume       update call time       \n");
 
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
  int flag=0,snake=3;
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
                if(snake==0)
                 {
                  printf("please enter the username again\n");
                  user_login();
                 }
                
                printf("Wrong password\n");
                printf("Please enter the password again\nyou have only %d attempt left\n",snake);
                snake--;
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










