#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

struct CustomerDetails{
    char Name[40];
    char email[30];
    char password[15];
    char confirmpassword[15];
    char mobile[10];
    int age;
    char tracking_number[11];
    char *trackin_num;
};
void blue()
{
    printf("\033[0;34m");
}
void purple()
{
    printf("\033[0;35m");
}
void red()
{
    printf("\033[0;31m");
}
void green()
{
    printf("\033[0;32m");
}
void yellow()
{
    printf("\033[0;33m");
}
void reset()
{
    printf("\033[0m");
}
void highlight()
{
    printf("\033[0;41m");
}
char* random_number_function(char *x)
{
    char rstring[11];
    srand(time(NULL));  
    //This is required so that each time a new random value is generated
    for(int i=0;i<10;i++)
    {
        rstring[i]='0'+(rand()%10);
    }
    rstring[10]='\0';
    char *randomptr=rstring;
    return randomptr;
}
void displayFrontPage() {
    system("cls"); 
    yellow();
    printf("\n\n\n\n\n\n\n\n\n");
    printf("   \t\t\t\t\t --------------------------------------------- \n");
    printf("   \t\t\t\t\t|                                             | \n");
    printf("   \t\t\t\t\t|   ---------------------------------------   |\n");
    printf("   \t\t\t\t\t|  |                                       |  |\n");
    printf("   \t\t\t\t\t|  |              WELCOME TO               |  |\n");
    printf("   \t\t\t\t\t|  |              Delivr.io                |  |\n");
    printf("   \t\t\t\t\t|  |                                       |  |\n");
    printf("   \t\t\t\t\t|   ---------------------------------------   |\n");
    printf("   \t\t\t\t\t|                                             |\n");
    printf("   \t\t\t\t\t --------------------------------------------- \n");
    printf("\n");
    printf("   \t\t\t\t\tPress any key to proceed to login: ");
    reset();
    getchar();
}
void Cleardisplay() {
    system("cls"); // Clear the console screen
}
bool validateit(struct CustomerDetails Cust)
{
    bool flag;int count=0,success=0;
    for(int i=0;Cust.Name[i]!='\0';i++)
    {
        if (!((Cust.Name[i]>= 'a' && Cust.Name[i] <= 'z')
        || (Cust.Name[i]>='A' && Cust.Name[i]<= 'Z'))) {

			printf("\nPlease enter the valid Name!\n");
			flag = 0;
			return flag;
    }
    if (flag==1)
    {
        for(int i=0;Cust.email[i]!='\0';i++){
            if(Cust.Name[i]== '&'||Cust.Name[i]== '&')
                count++;
        }
        if(count>=2 && strlen(Cust.email)>8)
        {
            //strcmp --> gives (0) when both string are equal
            if(!strcmp(Cust.password,Cust.confirmpassword))
            {
                if(strlen(Cust.password)>=8 && strlen(Cust.password)<15)
                {
                    int caps = 0,small = 0,numbers = 0,special = 0;
                    for (i = 0; Cust.password[i] != '\0'; i++) {   
                        if (Cust.password[i]>= 'A'&& Cust.password[i]<= 'Z')
							caps++;
						else if (Cust.password[i]>= 'a'&& Cust.password[i] <= 'z')
							small++;
						else if (Cust.password[i]>= '0'&& Cust.password[i] <= '9')
							numbers++;
						else if (Cust.password[i] == '@'|| Cust.password[i] == '&'||Cust.password[i] == '#'||       Cust.password[i] == '*'||Cust.password[i]=='$')
							special++;
                    }
                    if (caps >= 1 && small >= 1&& numbers >= 1 && special >= 1) {
                        if(Cust.age>0)
                        {
                            if(strlen(Cust.mobile)==10)
                            {
                                for(i = 0; i < 10; i++) {
                                    if (Cust.mobile[i] >= '0'&& Cust.mobile[i] <= '9'){
										success = 1;
								    }
								    else {
										printf("\n\nPlease Enter valid mobile number\n\n");
										SignUp_Customer(Cust);
										break;
                                    }
                                }
                                if(success==1)
                                    return 1;
                                }
                            }
                            else{
                                printf("Enter valid age\n");
                                SignUp_Customer(Cust);
                            }   
                        }

                    }
                    else{
                        
                    }
                }
            }
        }
    }
}
void SignUp_Customer(struct CustomerDetails Cust)
{
    yellow();
    printf("Welcome to Delivr.io, Please Enter your Details for Signing Up:\n");
    printtf("Enter your Name: ");
    fgets(Cust.Name,sizeof(Cust.Name),stdin);
    printtf("Enter your Age: ");
    fgets(Cust.age,sizeof(Cust.age),stdin);
    printtf("Enter your Mobile Number wihtoud country code: ");
    fgets(Cust.mobile,sizeof(Cust.mobile),stdin);
    printtf("Enter your Email: ");
    fgets(Cust.email,sizeof(Cust.email),stdin);
    printtf("Enter your Password: ");
    fgets(Cust.password,sizeof(Cust.password),stdin);
    printtf("Confirm your Password: ");
    fgets(Cust.confirmpassword,sizeof(Cust.confirmpassword),stdin);
    bool check=validateit(Cust);

}
void SignIn_Customer()
{}
void Login_Admin()
{}
int main()
{
    displayFrontPage();
    Cleardisplay();
    int ch=0;   //Choice
    choice:
    green();
    printf("Press 1 to use Customer SignUp Page\nPress 2 to use Customer SignIn Page\nPress 3 to use Admin Login Page\n");
    reset();
    blue();
    scanf("%d",&ch);
    reset();
    struct CustomerDetails Customer;
    switch(ch)
    {
        case 1:
            Cleardisplay();
            SignUp_Customer(Customer);
            break;
        case 2:
            Cleardisplay();
            SignIn_Customer();
            break;
        case 3:
            Cleardisplay();
            Login_Admin();
            break;
        default:
            yellow();
            printf("Wrong choice!Enter 1 to choose again or any other key to quit: ");
            reset();
            int ch2;
            blue();
            scanf("%d",&ch2);
            reset();
            if(ch2==1){
                Cleardisplay();
                goto choice;
            }
            else
            {
                Cleardisplay();
                blue();
                printf("Thankyou for using Delivr.io");
                reset();
                return 0;
            }
            break;
    }
    return 0;
}