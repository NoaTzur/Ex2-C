
#include <stdio.h>
#include "banksStatus.c"
#define first_account 901
#define total_num_of_accounts 50

int static curr_num_of_account = first_account; //901 is the first bank number
int static arrayIndex = 0;


int checkForSpcaesInArray(){
	
	for(int i=0; i<50; i++){
		if(banks_status[i][0] == 0){
			curr_num_of_account = 901+i;
			arrayIndex =i;
			return 0;	
		}
	}
	return 0;

}

void openBank(double amount){

	checkForSpcaesInArray(); //checks if there is any spaces in the array

    if(curr_num_of_account <= 950){ //950 is the last bank number that can be opened.
        banks_status[arrayIndex][0] = curr_num_of_account;
        banks_status[arrayIndex][1] = amount;

        printf("New account number is: %d\n", curr_num_of_account );
        curr_num_of_account++;
        arrayIndex++;
    }
    else
    {
        printf("We have 50 bank acount at this moment, cant open new one\n");
    }
}

void printBalance(int accountNumber){

    int index_in_arr = accountNumber-first_account; //account 950-901 == index 49 in array
    //if it is close so bank_status[index_in_arr][0] == 0 (false) and the index is 0-49
    if(banks_status[index_in_arr][0] && index_in_arr>=0 && index_in_arr<50)  
    {  
        double balance = banks_status[index_in_arr][1];
        printf("The balance of account number %d is: %.2f\n", accountNumber, balance);
    }
    else
    {
        printf("This account is closed\n");
    }

}

void printAfterDeposit(int accountNumber, double amount) { 

    int index_in_arr = accountNumber-first_account; //account 950-901 == index 49 in array
    //if it is close so bank_status[index_in_arr] == 0 (false) and the index is 0-49
    if(index_in_arr>=0 && banks_status[index_in_arr][0] && index_in_arr<50 && amount >0)  
    {  
        banks_status[index_in_arr][1] += amount;
        double balance = banks_status[index_in_arr][1];
        printf("the balance after depositing in account number %d, is %.2f\n", accountNumber, balance);
    }
    else if(amount < 0)
    { 
    	printf("Cannot deposit a negative amount");
    }
    else
    {
        printf("This account is closed\n");
    }
}

void withdrawal(int accountNumber, double amount){

    int index_in_arr = accountNumber-first_account; //account 950-901 == index 49 in array
    //if it is close so bank_status[index_in_arr] == 0 (false) and the index is 0-49
    if(banks_status[index_in_arr] && index_in_arr>=0 && index_in_arr<50)  
    {  
        double newAmount = banks_status[index_in_arr][1] - amount;
        double *p = &newAmount;
        if(newAmount > 0)
        {
            banks_status[index_in_arr][1] = *p;
            printf("The new balance is: %.2f\n", *p);
        }
        else
        {
            printf("Cannot withdraw more than the balance\n");
        }
    }
    else
    {
        printf("This account is closed, no action can be performed\n");
    }
}

void closeAccount(int accountNumber){

    int index_in_arr = accountNumber-first_account; //account 950-901 == index 49 in array
    //if it is close so bank_status[index_in_arr] == 0 (false) and the index is 0-49
    if(banks_status[index_in_arr] && index_in_arr>=0 && index_in_arr<50)  
    {  
        banks_status[index_in_arr][0] = 0;
        printf("Closed account number %d\n", accountNumber);
        curr_num_of_account--;
        
        
    }
    else
    {
        printf("This account is already closed\n");
    }
}

void addingInterest(int interest_rate){

    for(int i=0; i<total_num_of_accounts; i++){
        if(banks_status[i][0]!=0){ // banks_status[i][0] == 0 means the account is closed
            banks_status[i][1] = banks_status[i][1] + banks_status[i][1]*(interest_rate/100.0);
         
        }
    }
}

void printAll(){

    for(int i=0; i<total_num_of_accounts; i++){
        if(banks_status[i][0]!=0){ // banks_status[i][0] == 0 means the account is closed
            printf("The balance of account number %.2f is: %.2f\n", banks_status[i][0], banks_status[i][1]);
        }
    }
}

void closeAll(){

    for(int i=0; i<total_num_of_accounts; i++){
        banks_status[i][0] = 0; //account is closed no
    }
}
