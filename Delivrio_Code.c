#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

struct CustomerDetails{
    char Name[30];
    char email[40];
    char password[15];
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
    rstring[10]='/0';
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
void SignUp_Customer()
{}
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
    switch(ch)
    {
        case 1:
            Cleardisplay();
            SignUp_Customer();
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