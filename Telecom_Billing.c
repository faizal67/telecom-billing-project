#include <stdio.h> 
#include <conio.h>
#include <string.h>
#include <stdlib.h>
char username[][20]={"faizal","kushagra","salman","nikita","pragya"};
char passwords[][20]={"123","123","123","123","123"};
char name[20],password[20];
int id;
void clrscr(void);
int credential();
int main_menu();
int profile();
int data_used();
int call_time();
int generate_bill();
int main()
{ 
void clrscr();

printf("************please enter the username and password *************\n");
credential();
main_menu();
printf("End of the program");
return 0;
}


 int credential()
{
  
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
           id=i;
           printf("Welcome back %s\n",username[id]);
           break;
         }
         else
         { 
            if(snake==1)
             {
               exit(0);
               printf("please enter the username again\n");
               credential();
             }
             snake--;
             printf("Wrong password\nPlease enter the password again\nyou have only %d attempt left\n",snake);
              goto b;
         }    
        }
    }
  }
  if(flag==0)
  {
    printf("please enter the correct username\n");
    credential();
  }
}
int main_menu()
{
  int choice;
  printf("*********************MAIN WINDOW********************\n");
  printf(" * Profile                                                    press 1\n");
  printf(" * Data used                                                  press 2\n");
  printf(" * Voice call time                                            press 3\n");
  printf(" * Subscriptions                                              press 4\n");
  printf(" * Generate your Bill                                         press 5\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1: profile();
            break;
    case 2: data_used();
            break;
    case 3: call_time();
            break;
    case 4: generate_bill();
            break;
  }
return 0;
} 




int profile()
{
  int choice;
  printf("Name :%s\n",username[id]);
  printf("password :%s\n",passwords[id]);
  printf("Press 0 to back\n");
  scanf("%d",&choice);

  if (choice==0)
  {
   void clrscr();
  main_menu();
  }
}



int data_used()
{
return 0;
}





int call_time()
{
return 0;
}




int generate_bill()
{
  return 0;
} 