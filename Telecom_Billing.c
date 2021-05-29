#include <stdio.h> 
#include <conio.h>
#include <string.h>
#include <stdlib.h>

char username[][20]={"faizal","kushagra","salman","nikita","pragya"};
char passwords[][20]={"123","123","123","123","123"};
char subs[][20]={"No subscription","Netflix","Disney+ Hotstar","Amazon prime video","ZEE5","SonyLIV"};

char name[20],password[20];
char admin_name[]={"xyz"};
char admin_pass[]={"123"};
long long int phone_no[10]={9899483922,8887122744,7291049064,3594695879,4387643986};
float data_used[]={39,40,20,33,10};
float call_time[]={23,24,45,64,23};
int user_sub[]={1,4,0,1,0}; // user subscription 
int user_tune[]={0,1,1,0,0};//caller tune
int id;
int discount=0;
int user_login();
int admin_login();
int admin_menu();
int user_menu();
void generate_bill(int);

int main()
{ 
  printf("\e[1;1H\e[2J");
  system("Color D");
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
        default: system("Color 4");printf("Wrong input enter correct input \n");
        goto a;
      }
  }
  printf("end of the program ");
}

void generate_bill(int id)
{ 
  printf("\e[1;1H\e[2J");
  system("Color A");
  float b_total,a_total,ott_charge;
  if(user_sub[id]==1)
  ott_charge=499;
  else if(user_sub[id]==2)
  {
    ott_charge=299;
  }
  else if(user_sub[id]==3)
  {
    ott_charge=129;
  }
  else if(user_sub[id]==4)
  {
    ott_charge=355;
  }
  else if(user_sub[id]==5)
  {
    ott_charge=180;
  }
  else
  ott_charge=0;
  b_total=(data_used[id]*16)+(call_time[id]*1.2)+(user_tune[id]*78)+(ott_charge);
  printf("\n");
  printf("--------------------------------------------Telecome Bill---------------------------------------------------\n");
  printf("     Name : %-20s                                                                                \n",username[id]);
  printf("     Mobile no: %-20lld                                                                            \n",phone_no[id]);
  printf("------------------------------------------------------------------------------------------------------------\n");
  printf("     * Data charges:                                                                      Rs %0.2f               \n",data_used[id]*16);
  printf("     * Call charges:                                                                      Rs %0.2f \n\n",(call_time[id]*1.2));
  printf("     * Subscriptions:-\n");
  printf("     --> Caller tune:                                                                     Rs %d\n",user_tune[id]*78);
  printf("     --> Add on charges(OTT):                                                             Rs %0.2f\n\n",ott_charge); 
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
 


}


int admin_menu()
{ 
   printf("this is a admin menu\n");
}


int user_menu()
 {
  printf("\e[1;1H\e[2J");
  int choice,choice_2;
  float up_data,up_call;
  system("Color 3");
  printf("*********************MAIN WINDOW********************                                                         logout(6)        exit(0)    \n");
  printf(" * Welcome Back %s \n",username[id]);
  printf(" * %lld\n",phone_no[id]);
  printf(" * Data consume(gb) :%.2f \n",data_used[id]);
  printf(" * Call time(min) :%.2f\n",call_time[id]);

  printf(" * Callertune :");
  {
    if(user_tune[id]==1)
      printf("Active\n");
    else 
      printf("Inactive\n");  
  }
  printf(" * Active subscription :%s\n\n",subs[user_sub[id]]);
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
    printf("Your current data consumption is :%.2f \n",data_used[id]);
    printf("How much you want to add data value : ");
    scanf("%f",&up_data);
    data_used[id]+=up_data;
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
    printf("Your current  call time is :%.2f \n",call_time[id]);
    printf("how much you want to add call time : ");
    scanf("%f",&up_call);
    call_time[id]+=up_call;
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
    if(user_tune[id]==1)
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
        user_tune[id]=1;
      else
        user_tune[id]=0;  

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
    printf("Your current  ott subscription :%s\n ",subs[user_sub[id]]);
    printf("Which ott subscription you want to take -->\n");
    for(int i=0;i<6;i++)
    { 
     printf("  * %s  press  %d\n",subs[i],i+1);
    }
    {
      int choice;
      scanf("%d",&choice);
      user_sub[id]=choice-1;
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










