#include <stdio.h> 
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct client                                                                       //declaration of structure
{
 char username[20];
 char passwords[20];
 long long int phone_no;
 float data_used;                                                                   //structure variables
 float call_time;
 int user_sub;                                                                      //for store user subscription code
 int user_tune;                                                                     //for store user callertune  0--->deactive    1---->active
};

struct client c[5]={{"faizal","123",9899483922,39,23,1,0},                          //(name,password,phone no,data,calltime,subscription code,callertune)
                      {"pragya","123",0001010101,23,6,3,1},
                      {"salman","123",7291049064,20,45,0,0},                        //initialisation of structure fuction
                      {"kushagra","123",8887122744,40,24,4,1},
                      {"nikita","123",3594695879,33,63,1,0}};
char subs[][20]={"No subscription","Netflix","Disney+ Hotstar","Amazon prime video","ZEE5","SonyLIV"};    //defination of subscription code
float subs_charge[]={000,499,299,129,355,180,299};                                   //subscription charges
char admin_name[]={"xyz"};
char admin_pass[]={"123"};

int id;                                                                              //uniqe id for all user
int discount=0;
int user_login();   
int admin_login();
int admin_menu();
int user_menu();
void generate_bill(int);

int main()
{ 
  
  printf("\e[1;1H\e[2J");   //to clear the screen
  system("Color D");        //to change the font color
  int choice;

  printf("***************************************************************\n");
  printf("--------------------------WELCOME TO THE TELECOME BILLING SYSTEM----------------------------\n");
  printf("                         ******************************************************************\n\n");
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
        default: system("Color C");printf("Hey!!! Type the correct input. \n\n");
        goto a;
      }
  }
  printf("end of the program ");
}

void generate_bill(int id)
{ 
  printf("\e[1;1H\e[2J");
  system("Color A");
  int choice;
  float b_total;       //b=befor adding gst    
  b_total=(c[id].data_used*16)+(c[id].call_time*1.2)+(c[id].user_tune*78)+(subs_charge[c[id].user_sub]);
  printf("\n");
  printf("--------------------------------------------Telecome Bill---------------------------------------------------\n");
  printf("     Name : %s\n",c[id].username);
  printf("     Mobile no: %lld\n",c[id].phone_no);
  printf("------------------------------------------------------------------------------------------------------------\n");
  printf("     * Data charges:                                                                      Rs %0.2f               \n",c[id].data_used*16);
  printf("     * Call charges:                                                                      Rs %0.2f \n\n",(c[id].call_time*1.2));
  printf("     * Subscriptions:-\n");
  printf("     --> Caller tune:                                                                     Rs %d\n",c[id].user_tune*78);
  printf("     --> Add on charges(OTT):                                                             Rs %0.2f\n\n",subs_charge[c[id].user_sub]); 
  printf("     * Additional Charges:-\n");
  printf("     --> One time charges:                                                                Rs 0.00\n");
  printf("     --> International Roaming charges:                                                   Rs 0.00\n\n");
  printf("     * Texable Values\n");
  printf("     -->Central GST @18% :                                                                  Rs %-0.2f\n",(b_total/100)*18);
  printf("------------------------------------------------------------------------------------------------------------\n");
  printf("     * Total Current amount :                                                             Rs %0.2f\n",b_total+((b_total/100)*18));
  printf("     * Discount :                                                                         Rs %d\n\n",discount);
  printf("     * Total Payable amount :                                                             Rs %0.2f\n",(b_total+((b_total/100)*18))-discount);
  printf("------------------------------------------------------------------------------------------------------------\n");
  while(1)
  {
  printf("press 0 to exit  ");
  scanf("%d",&choice);
  if (choice==0)
   exit(0);
  }
}


int admin_menu()
{ 
  int choice;
  printf("\e[1;1H\e[2J");
  system("Color 9");
   printf("admin menu is not yet complete\n");
   printf("Work in progress...\n It will complete soon...\n");
   a:
   printf("\n\nPress zero to back  ");
   scanf("%d",&choice);
   switch(choice)
   {
     case 0:
     {
       main();
     break;
     }
     default: 
     goto a;
   }
  
}


int user_menu()
 {
  printf("\e[1;1H\e[2J");
  int choice,choice_2;           
  float up_data,up_call;
  system("Color 9");
  printf("*********************MAIN WINDOW********************                                                         logout(6)        exit(0)    \n");
  printf(" * Welcome Back %s \n",c[id].username);
  printf(" * %lld\n",c[id].phone_no);
  printf(" * Data consume(gb) :%.2f \n",c[id].data_used);
  printf(" * Call time(min) :%.2f\n",c[id].call_time);

  printf(" * Callertune :");
  {
    if(c[id].user_tune==1)
      printf("Active\n");
    else 
      printf("Inactive\n");  
  }
  printf(" * Active OTT subscription :%s\n\n",subs[c[id].user_sub]);
  printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
  printf("  Update data consume     update call time     Activate/Deactivate caller tune      Change OTT subscription      Generate Bill\n");
  printf("       Press 1                Press 2                     Press 3                           Press 4                  press 5  \n ");
  printf("----------------------------------------------------------------------------------------------------------------------------------------\n"); 
  printf("Enter the choice :"); 
  a:
  scanf("%d",&choice);
  switch(choice)
  {
  case 1:
    system("Color A");
    printf("Your current data consumption is :%.2f \n",c[id].data_used);
    printf("How much you want to add data value : ");
    scanf("%f",&up_data);
    c[id].data_used+=up_data;
    printf(" successfully data updated \n\n");

    while(1)
    {
      printf("Press zero to back :");
      scanf("%d",&choice_2);
      if (choice_2==0)
      {
        user_menu();
        break;
      }  
      else 
      printf("Please Enter correct value\n");
    }choice_2=1;
  break;
  
  case 2:
    system("Color C");
    printf("Your current  call time is :%.2f \n",c[id].call_time);
    printf("how much you want to add call time : ");
    scanf("%f",&up_call);
    c[id].call_time+=up_call;
    printf(" successfully call time  updated \n");

    while(1)
    {
      printf("Press zero to back :");
      scanf("%d",&choice_2);
      if (choice_2==0)
      {
        user_menu();
        break;
      }  
      else 
      printf("Please Enter correct value\n");
    }choice_2=1; 
  break;

  case 3:
    printf("Your current  caller tune status : ");
    {
    if(c[id].user_tune==1)
      printf("Active\n");
    else 
      printf("Inactive\n");  
    }
    printf("What you want  (Activate or Deactivate) \n");
    printf("                 press 1      press 2\n");
    {
      int choice;
      scanf("%d",&choice);
      if(choice==1)
        c[id].user_tune=1;
      else
        c[id].user_tune=0;  

    }
    
    printf(" Update  successfull  \n");

    while(1)
    {
      printf("Press zero to back :");
      scanf("%d",&choice_2);
      if (choice_2==0)
      {
        user_menu();
        break;
      }  
      else 
      printf("Please Enter correct value\n");
    }choice_2=1; 
  break;

  case 4:
    printf("Your current  ott subscription :%s\n ",subs[c[id].user_sub]);
    printf("Which ott subscription you want to take -->\n");
    for(int i=0;i<6;i++)
    { 
     printf("  * %-30s                   Rs %0.2f           press  %d\n",subs[i],subs_charge[i],i+1);
    }
    {
      int choice;
      c:
      scanf("%d",&choice);
      if(choice<=0||choice>=7)
      {
        goto c;
      }
      c[id].user_sub=choice-1;
    }
    
    printf(" Update  successfull  \n");

    while(1)
    {
      printf("Press zero to back :");
      scanf("%d",&choice_2);
      if (choice_2==0)
      {
        user_menu();
        break;
      }  
      else 
      printf("Please Enter correct value\n");
    }choice_2=1; 
  break;

  case 5:
   generate_bill(id);
  break;

  case 6:
   main();
   break;

  case 0:
   exit(0);


  default: 
  printf("Enter the correct choice");
  goto a;
    break;
  }

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
   char name[20],password[20];
  int flag=0,snake=3;
    printf("Username-->");
    scanf("%s",&name);
      for (int i=0;i<5;i++)
       {
         if(strcmp(name,c[i].username)==0)
         {
          flag++;
          {
            a:
            printf("Password--");
            scanf("%s",&password);
            if(strcmp(password, c[i].passwords)==0)
              {
                id=i;
                user_menu();
                break;
              }
            else
              { 
                if(snake==0)
                 {
                   main();
                  // printf("\n\nyou have used all attempts!!!!! \n");
                  // system("Color A");
                  // printf("Please enter the username again\n");
                  // user_login();
                 }
                
                  system("Color C");
                printf("\n\n");  
                printf("Wrong password!!!\n");
                printf("Please enter the password again\nyou have only %d attempt left\n",snake);
                snake--;
                goto a;
              }  
          }
         }
          
        }
   if(flag==0)
   {
     printf("You typed wrong username please try again\n");
     user_login(c);
   }      

return 0;   
}










