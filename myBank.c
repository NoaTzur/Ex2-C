#include "banksStatus.c"
#include <stdio.h>
#define first_account 901
#define total_num_of_accounts 50

int static curr_num_of_account = first_account; //901 is the first bank number
int static arrayIndex = 0;

void openBank(double amount){

    if(curr_num_of_account <= 950){ //950 is the last bank number that can be opened.
        banks_status[arrayIndex][0] = curr_num_of_account;
        banks_status[arrayIndex][1] = amount;

        printf("Bank acount successfully opened! your acount number is: %d", curr_num_of_account );
        curr_num_of_account++;
        arrayIndex++;
    }
    else
    {
        printf("We have 50 bank acount at this moment, cant open new one");
    }
}

void printBalance(int accountNumber){

    int index_in_arr = accountNumber-first_account; //account 950-901 == index 49 in array
    //if it is close so bank_status[index_in_arr] == 0 (false) and the index is 0-49
    if(banks_status[index_in_arr] && index_in_arr>=0 && index_in_arr<50)  
    {  
        double balance = banks_status[index_in_arr][1];
        printf("the balance in account number %d, is %.2f", accountNumber, balance);
    }
    else
    {
        printf("This account is closed, no action can be performed");
    }

}

void printAfterDeposit(int accountNumber, double amount) { 

    int index_in_arr = accountNumber-first_account; //account 950-901 == index 49 in array
    //if it is close so bank_status[index_in_arr] == 0 (false) and the index is 0-49
    if(banks_status[index_in_arr] && index_in_arr>=0 && index_in_arr<50 && amount >0)  
    {  
        banks_status[index_in_arr][1] += amount;
        double balance = banks_status[index_in_arr][1];
        printf("the balance after depositing in account number %d, is %.2f", accountNumber, balance);
    }
    else
    {
        printf("This account is closed, no action can be performed");
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
            printf("The new balance is %.2f", *p);
        }
        else
        {
            printf("There is not enough cash in this account to perform a withdrawal");
        }
    }
    else
    {
        printf("This account is closed, no action can be performed");
    }
}

void closeAccount(int accountNumber){

    int index_in_arr = accountNumber-first_account; //account 950-901 == index 49 in array
    //if it is close so bank_status[index_in_arr] == 0 (false) and the index is 0-49
    if(banks_status[index_in_arr] && index_in_arr>=0 && index_in_arr<50)  
    {  
        banks_status[index_in_arr][0] = 0;
        printf("Account number %d closed successfully", accountNumber);
    }
    else
    {
        printf("This account is already closed");
    }
}

void addingInterest(double interest_rate){

    for(int i=0; i<total_num_of_accounts; i++){
        if(banks_status[i][0]!=0){ // banks_status[i][0] == 0 means the account is closed
            banks_status[i][1] = banks_status[i][1] + banks_status[i][1]*(interest_rate/100.0);
        }
    }
}

void printAll(){

    for(int i=0; i<total_num_of_accounts; i++){
        if(banks_status[i][0]!=0){ // banks_status[i][0] == 0 means the account is closed
            printf("Account number: %d, the balance is: %.2f", banks_status[i][0], banks_status[i][1]);
        }
    }
}

void closeAll(){

    for(int i=0; i<total_num_of_accounts; i++){
        banks_status[i][0] = 0; //account is closed no
    }
}