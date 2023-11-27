#include<iostream>
#include<vector>
#include <cstdlib>
#include <time.h> 

using namespace std;

int createAccount();
string findCustomer();
int checkBalance();
int creditToAccount();
int debitFromAccount();

vector<pair<int, string> > customers;
vector<pair<int, int> > balance;

int main() 
{
	start:
	int functionality;
	cout<<"Enter the functionality :"<<"\n"<<"1.Create Account"<<"\n"<<"2.Find Customer"<<"\n"<<"3.Balance Enquiry"<<"\n"<<"4.Cash Deposit / Credit"<<"\n"<<"5.Cash WithDraw"<<"\n"<<"6.Exit"<<"\n";
	cout<<"----------------------"<<endl;
	cin>>functionality;
	int accountNumber;
	string customerName;
	int accountBalance;
	int balanceAfterCredit;
	int balanceAfterDebit;
	switch(functionality)
	{
		case 1: 
			cout<<"---------------Account Opening---------------"<<endl;
			accountNumber = createAccount();
			cout<<"Your Account Number is : "<<accountNumber <<endl;
			cout<<"----------------------"<<endl;
			goto start;
		case 2:
			cout<<"---------------Search Customer---------------"<<endl;
			customerName = findCustomer();
			cout<<"Customer Name is : "<<customerName <<endl;
			cout<<"----------------------"<<endl;
			goto start;
		case 3:
			cout<<"---------------Balance Enquiry---------------"<<endl;
			accountBalance = checkBalance();
			cout<<"Balance Amount :"<<accountBalance<<endl;
			cout<<"----------------------"<<endl;
			goto start;
		case 4:
			cout<<"---------------Amount Credit---------------"<<endl;
			balanceAfterCredit = creditToAccount();
			cout<<"*****Amount Credited Successfully*****"<<endl;
			cout<<"Your New Balance is: "<<balanceAfterCredit<<endl;
			cout<<"----------------------"<<endl;
			goto start;
		case 5:
			cout<<"---------------Amount WithDraw---------------"<<endl;
			balanceAfterDebit = debitFromAccount();
			cout<<"*****Amount Withdrawed Successfully*****"<<endl;
			cout<<"Your New Balance is: "<<balanceAfterDebit<<endl;
			cout<<"----------------------"<<endl;
			goto start;
		default:
			cout<<"Invalid Option!!!";
			cout<<"----------------------"<<endl;
			goto start;
	}
}

int createAccount()
{
	string firstName;
	string dOB;
	int accountNumber;
	srand(time(0));
	int initialBalnace;
	cout << "Enter first name: ";
	cin>>firstName;
	cout << "Date of Birth: ";
	cin>>dOB;
	cout<<"Enter Initial Balance: ";
	cin>>initialBalnace;
	accountNumber = rand();
	customers.push_back(make_pair(accountNumber, firstName));
	balance.push_back(make_pair(accountNumber, initialBalnace));
	return accountNumber;
}

string findCustomer() {
	int accountNumber;
	cout<<"Enter Account Number: ";
	cin>>accountNumber;
	int customersSize = customers.size();
	for(int item=0;item<customersSize;item++) {
		if(customers[item].first == accountNumber) {
			return customers[item].second;
		}
	}
	cout<<"!!! Account Number Not Found !!!";
}

int creditToAccount() {
	int accountNumber;
	int amountToCredit;
	cout<<"Enter Account Number: ";
	cin>>accountNumber;
	cout<<"Enter Amount to credit: ";
	cin>>amountToCredit;
	for(int item = 0;item<balance.size();item++) {
		if(accountNumber == balance[item].first) {
			balance[item].second  = balance[item].second + amountToCredit;
			return balance[item].second;
		}
	}
	return 0;
}

int debitFromAccount() {
	int accountNumber;
	int debitAmount;
	cout<<"Enter Account Number: ";
	cin>>accountNumber;
	cout<<"Enter Amount you want: ";
	cin>>debitAmount;
	for(int item = 0;item<balance.size();item++) {
		if(accountNumber == balance[item].first) {
			if(balance[item].second>=debitAmount) {
			balance[item].second  = balance[item].second - debitAmount;
			return balance[item].second;
			} else {
				cout<<"Your Balance is low !!!"<<endl;
				return balance[item].second;
			}
		}
	}
	return 0;
}

int checkBalance() {
	int accountNumber;
	cout<<"Enter Account Number: ";
	cin>>accountNumber;
	for(int item = 0;item<balance.size();item++) {
		if(accountNumber == balance[item].first) {
			return balance[item].second;
		}
	}
	return 0;
}




