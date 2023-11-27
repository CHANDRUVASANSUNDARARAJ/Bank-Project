#include<iostream>
#include<vector>
#include <cstdlib>
#include <time.h> 

using namespace std;

int createAccount();
string findCustomer(int accountNumber);
int checkBalance(int accountNumber);
int creditToAccount(int accountNumber);
int debitFromAccount(int accountNumber);
void transferAmount();

vector<pair<int, string> > customers;
vector<pair<int, int> > balance;

int main() 
{
	start:
	int functionality;
	cout<<"Enter the functionality :"<<"\n"<<"1.Create Account"<<"\n"<<"2.Find Customer"<<"\n"<<"3.Balance Enquiry"<<"\n"<<"4.Cash Deposit / Credit"<<"\n"<<"5.Cash WithDraw"<<"\n"<<"6.Amount Transfer"<<"\n"<<"7.Exit"<<"\n";
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
			cout<<"Enter Account Number: ";
			cin>>accountNumber;
			customerName = findCustomer(accountNumber);
			if(customerName != "false") {
			cout<<"Customer Name is : "<<customerName <<endl;
			cout<<"----------------------"<<endl;
			goto start;
			}
			else {
				cout<<"!!! Account Number Not Found !!!"<<endl;
				cout<<"----------------------"<<endl;
				goto start;
			}
		case 3:
			cout<<"---------------Balance Enquiry---------------"<<endl;
			cout<<"Enter Account Number: ";
			cin>>accountNumber;
			accountBalance = checkBalance(accountNumber);
			cout<<"Balance Amount :"<<accountBalance<<endl;
			cout<<"----------------------"<<endl;
			goto start;
		case 4:
			cout<<"---------------Amount Credit---------------"<<endl;
			cout<<"Enter Account Number: ";
			cin>>accountNumber;
			balanceAfterCredit = creditToAccount(accountNumber);
			cout<<"*****Amount Credited Successfully*****"<<endl;
			cout<<"Your New Balance is: "<<balanceAfterCredit<<endl;
			cout<<"----------------------"<<endl;
			goto start;
		case 5:
			cout<<"---------------Amount WithDraw---------------"<<endl;
			cout<<"Enter Account Number: ";
			cin>>accountNumber;
			balanceAfterDebit = debitFromAccount(accountNumber);
			cout<<"*****Amount Withdrawed Successfully*****"<<endl;
			cout<<"Your New Balance is: "<<balanceAfterDebit<<endl;
			cout<<"----------------------"<<endl;
			goto start;
		case 6:
			cout<<"---------------Amount Transfer---------------"<<endl;
			transferAmount();
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

string findCustomer(int accountNumber) {
	int customersSize = customers.size();
	for(int item=0;item<customersSize;item++) {
		if(customers[item].first == accountNumber) {
			return customers[item].second;
		}
	}
	return "false";
}

int creditToAccount(int accountNumber) {
	int amountToCredit;
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

int debitFromAccount(int accountNumber) {
	int debitAmount;
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

int checkBalance(int accountNumber) {
	for(int item = 0;item<balance.size();item++) {
		if(accountNumber == balance[item].first) {
			return balance[item].second;
		}
	}
	return 0;
}

void transferAmount() {
	int fromAccountNumber;
	int toAccountNumber;
	int amountToTransfer;
	cout<<"Enter the account Number of Sender: ";
	cin>>fromAccountNumber;
	cout<<"Enter Amount to transfer: ";
	cin>>amountToTransfer;
	int senderBalanceCheck = checkBalance(fromAccountNumber);
	if(amountToTransfer <= senderBalanceCheck) {
		cout<<"Enter the account Number of Receiver: ";
		cin>>toAccountNumber;
		for(int item = 0;item<balance.size();item++) {
			if(toAccountNumber == balance[item].first) {
				balance[item].second = balance[item].second+amountToTransfer;
			}
			if(fromAccountNumber == balance[item].first) {
				balance[item].second = balance[item].second-amountToTransfer;
			}
		}
		cout<<"*****Amount Transferred Successfully*****"<<endl;
	}
}
