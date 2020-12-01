#include <stdio.h>
#include "myBank.h"

//void clearBuffer(void){

//	int ch;
//	while(((ch = getchar()) != '\n') && (ch!=EOF));
//	}


int main(){

    char userChoice='l';
    double amount = 0;
    int accountNumber= -1;

    while(userChoice != 'E'){
      
        printf("\nplease choose one of the actions from the list:\n"
                    "O - open new account\n"
                    "B - checking what is the balance in the given account\n"
                    "D - make a deposit to the given account\n"
                    "W - withdrawal from the given account\n"
                    "C - closing the given account\n"
                    "I - adding an interest to all the accounts in the bank that open\n"
                    "P - print all the account and the balance of each account in the bank (just accounts that open)\n"
                    "E - Exit\n");

        int check = scanf("%c", &userChoice);	
	
		if(userChoice == 'O' && check == 1)
		{
		    printf("Please enter amount for deposit:");
		    int check = (scanf("%lf", &amount));
		    if((check == 1) && amount > 0)
		    {
		        openBank(amount);
		    }
		    else if ((check == 1) && amount<0)
		    {
		    	printf("Invalid Amount\n");
		    }
		    else 
		    {
		        printf("Failed to read the amount\n");
		    }
		}
		else if (userChoice == 'B' && check == 1)
		{
		    printf("Please enter account number:");
		    if((scanf("%d", &accountNumber)) ==1)
		    {
		        printBalance(accountNumber);
		    }
		    else
		    {
		        printf("Failed to read the account number");
		    }
		    
		}
		else if (userChoice == 'D' && check == 1)
		{
		    printf("Please enter account number:");
		    int check1 = scanf("%d", &accountNumber);
		    if(accountNumber>64 && accountNumber <128)
		    {
		    	printf("Failed to read the account number");
		    }
		    else if(accountNumber<901 || accountNumber >950)
		    {
		    	printf("Invalid account number");
		    }
		    else if(banks_status[accountNumber-901][0] == 0) 
		    {
		    	printf("This account is closed");
		    }
		    else
		    {
		    	printf("Please enter the amount to deposit:");
		    	int check2 = scanf("%lf", &amount);
			
		    	if(check1 ==1 && check2 == 1)
		    	{
		      	  printAfterDeposit(accountNumber, amount);
		    	}
		    	else
		    	{
		    	printf("Failed to read the amount");
		    	}
		}
		}

		else if (userChoice == 'W' && check == 1)
		{
		    printf("Please enter account number: ");
		    int check1 = scanf("%d", &accountNumber);
		    if(banks_status[accountNumber-901][0] == 0) 
		    {
		    	printf("This account is closed");
		    }
		    else
		    {
		    	printf("Please enter the amount to withdraw:");
		    	int check2 = scanf("%lf", &amount);
		    
		    	if(check1 ==1 && check2 == 1)
		    	{
		        	withdrawal(accountNumber, amount);
		    	}
		    	else
		    	{
		        	printf("Failed to read the account number");
		    	}
		    }

		}
		else if (userChoice == 'C' && check == 1)
		{
		    printf("Please enter account number:");
		    if((scanf("%d", &accountNumber)) ==1 && banks_status[accountNumber-901][0])
		    {
		        closeAccount(accountNumber);
		    }
		    else if(banks_status[accountNumber-901][0] == 0)
		    {
		    	printf("This account is already closed");
		    }
		    else
		    {
		        printf("Invalid info");
		    }
		}
		else if (userChoice == 'I' && check == 1)
		{
		    int interest = 0;
		    printf("Please enter interest rate:" );
		    int checks = scanf("%d", &interest);

		    if(checks == 1 && interest > 0)
		    {
		       addingInterest(interest);         
		    }
		    else if(interest<0)
		    {
		        printf("Invalid interest rate");
		    }
		    else
		    {
		    	printf("Failed to read the interest rate");
		    }
		    
		}
		else if (userChoice == 'P' && check == 1)
		{
		    printAll();
		}
		
		else if (userChoice == 'E' && check == 1)
		{
		    
		}
		else
		{
			printf("Invalid transaction type\n");
		}
		
		//clearBuffer();		
	    }

	return 0;
}

