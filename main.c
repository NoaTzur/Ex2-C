#include <stdio.h>
#include "myBank.h"
//here i will put the main prog that will call the function from mainFunc and use the array from banksStatus


int main(){

    char userChoice='l';
    double amount = 0;
    int accountNumber= -1;

    while(userChoice != 'E'){
        
        printf("please choose one of the actions from the list:\t"
                    "O - open new account\t"
                    "B - checking what is the balance in the given account\t"
                    "D - make a deposit to the given account\t"
                    "W - withdrawal from the given account\t"
                    "C - closing the given account\t"
                    "I - adding an interest to all the accounts in the bank that open\t"
                    "P - print all the account and the balance of each account in the bank (just accounts that open)\t"
                    "E - Exit\n");

        int check = scanf("%c", &userChoice);

        if(userChoice == 'O' && check == 1)
        {
            printf("Please enter the initial amount you want to deposit to your new account");
            if(((scanf("%ld", &amount)) == 1) && amount > 0)
            {
                openBank(amount);
            }
            else
            {
                printf("you didnt enter valid amount. please enter a number bigger then 0");
            }
        }
        else if (userChoice == 'B' && check == 1)
        {
            printf("what is you account number?");
            if((scanf("%d", &accountNumber)) ==1)
            {
                printBalance(accountNumber);
            }
            else
            {
                printf("The account number you have entered is not valid, or the account is closed at this moment");
            }
            
        }
        else if (userChoice == 'D' && check == 1)
        {
            printf("Enter the account number, and then the amount you want to deposit");
            if((scanf("%d%lf", &accountNumber, &amount)) ==1)
            {
                printAfterDeposit(accountNumber, amount);
            }
            else
            {
                printf("you have entered invalid values");
            }
        }

        else if (userChoice == 'W' && check == 1)
        {
            printf("Enter the account number, and then the amount you want to withdraw");
            if((scanf("%d%lf", &accountNumber, &amount)) ==1)
            {
                withdrawal(accountNumber, amount);
            }
            else
            {
                printf("you have entered invalid values");
            }
            

        }
        else if (userChoice == 'C' && check == 1)
        {
            printf("Please enter the account number you want to close");
            if((scanf("%d", &accountNumber)) ==1)
            {
                closeAccount(accountNumber);
            }
            else
            {
                printf("The account number you have entered is not valid, or the account is already closed");
            }
        }
        else if (userChoice == 'I' && check == 1)
        {
            double interest = 0;
            int checks = scanf("%.2lf", &interest);
            if(checks == 1 && interest > 0)
            {
               addingInterest(interest);         
            }
            else
            {
                printf("invalid interest");
            }
            
        }
        else if (userChoice == 'P' && check == 1)
        {
            printAll();
        }
        else if (userChoice == 'E' && check == 1)
        {
            printf("Bye-Bye!");
        } 
    }

    return 0;
}