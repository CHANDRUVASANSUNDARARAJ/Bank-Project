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
void atmFunction();
int applyATM(int accountNumber);
void atmWithDraw(int cardNumber);
void atmPinGeneration();
bool existsCard(int cardNumber);
bool validatePIN(int PIN,int cardNumber);
int fetchAccountNumber(int cardNumber);
void atmCredit(int cardNumber);
void atmPINChange(int cardNumber);

vector<pair<int, string>> customers;// account Number  + Name
vector<pair<int, int>> balance;// Account number + Balance
vector<pair<int,int>> ATMCardDetails; //Account  Number + Card Number
vector<pair<int,int>> ATMPin; //Card Number + PIN
vector<vector<string>> customerDetails;

int main()
{
	start:
	int functionality;
	cout<<"Enter the functionality :"<<"\n"<<"1.Create Account"<<"\n"<<"2.Find Customer"<<"\n"<<"3.Balance Enquiry"<<"\n"<<"4.Cash Deposit / Credit"<<"\n"<<"5.Cash WithDraw"<<"\n"<<"6.Amount Transfer"<<"\n"<<"7.ATM Services"<<"\n"<<"8.Exit"<<"\n";
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
			cout<<"----------------------"<<endl;
			goto start;
        case 7:
            cout<<"---------------Welcome to ATM---------------"<<endl;
            atmFunction();
            goto start;
		default:
			cout<<"Invalid Option!!!";
			cout<<"----------------------"<<endl;
			goto start;
	}
}

int createAccount() {
	string firstName;
	int age;
	int accountNumber;
	srand(time(0));
	int initialBalnace;
	cout << "Enter first name: ";
	cin>>firstName;
	cout << "Enter Your AGE: ";
	cin>>age;
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

bool isCustomerExists(int accountNumber) {
    int customersSize = customers.size();
	for(int item=0;item<customersSize;item++) {
		if(customers[item].first == accountNumber) {
			return true;
		}
	}
	return false;
}

void atmFunction() {
    int functionalityOfAtm;
    int accountNumber;
    int cardNumber;
    int accountBalance;
    int balanceAfterDebit;
    int PIN;
    cout<<"Choose your Option :"<<endl;
    cout<<"1.Apply ATM Card"<<endl;
    cout<<"2.Withdraw"<<endl;
    cout<<"3.Balance Enquiry"<<endl;
    cout<<"4.PIN Generation"<<endl;
    cout<<"5.Amount Credit"<<endl;
    cout<<"6.PIN Change"<<endl;
    cout<<"7.Goto Banking"<<endl;
    cout<<"----------------------"<<endl;
    cin>>functionalityOfAtm;
    switch(functionalityOfAtm) {
    case 1:
        cout<<"---------------Application For ATM Card---------------"<<endl;
        cout<<"Enter Account Number :";
        cin>>accountNumber;
        if(isCustomerExists(accountNumber)) {
            cout<<"Customer Name is :"<<findCustomer(accountNumber)<<endl;
            int atmCardNumber = applyATM(accountNumber);
            cout<<"*****Applied Successfully*****"<<endl;
            cout<<"Please Note Your Card Number :"<<atmCardNumber<<endl;;
            cout<<"Thank You"<<endl;
            cout<<"----------------------"<<endl;
        }
        break;
    case 2:
        cout<<"---------------Withdraw from Atm---------------"<<endl;
        cout<<"Enter card Number :";
        cin>>cardNumber;
        atmWithDraw(cardNumber);
        cout<<"----------------------"<<endl;
        break;
    case 3:
        cout<<"---------------Check Balance---------------"<<endl;
        cout<<"Enter Card Number :";
        cin>>cardNumber;
        cout<<"Enter Your PIN :";
        cin>>PIN;
        if(validatePIN(PIN,cardNumber)) {
            accountNumber = fetchAccountNumber(cardNumber);
            accountBalance = checkBalance(accountNumber);
            cout<<"Balance Amount :"<<accountBalance<<endl;
        } else {
            cout<<"The PIN you Entered is wrong"<<endl;
        }
        cout<<"----------------------"<<endl;
        break;
    case 4:
        cout<<"---------------PIN Generation---------------"<<endl;
        atmPinGeneration();
        cout<<"----------------------"<<endl;
        break;
    case 5:
        cout<<"---------------Amount Credit---------------"<<endl;
        cout<<"Enter Your card Number";
        cin>>cardNumber;
        atmCredit(cardNumber);
        cout<<"----------------------"<<endl;
        break;
    case 6:
        cout<<"---------------PIN Change---------------"<<endl;
        cout<<"Enter Your Card Number :";
        cin>>cardNumber;
        atmPINChange(cardNumber);
        cout<<"----------------------"<<endl;
        break;
    default:
        cout<<"Invalid Option !!!"<<endl;
        cout<<"----------------------"<<endl;
        break;
    }
}

int applyATM(int accountNumber) {
    int cardNumber;
    srand(time(0));
    cardNumber = rand();
    ATMCardDetails.push_back(make_pair(accountNumber, cardNumber));
    return cardNumber;
}

void atmWithDraw(int cardNumber) {
    if(existsCard(cardNumber)) {
        for(int item = 0;item<=ATMCardDetails.size();item++) {
            if(cardNumber == ATMCardDetails[item].second) {
                int PIN;
                cout<<"Enter Your PIN :";
                cin>>PIN;
                bool pinValidation = validatePIN(PIN,cardNumber);
                if(pinValidation) {
                int viewBalance;
                int currentBalance = debitFromAccount(ATMCardDetails[item].first);
                cout<<"*****Amount Withdrawed Successfully*****"<<endl;
                cout<<"Do you Want to See Your Balance ?"<<endl;

                cout<<"1.Yes"<<endl;
                cout<<"2.No"<<endl;
                cin>>viewBalance;
                if(viewBalance == 1) {
                    cout<<"Your Balance is :"<<currentBalance<<endl;
                }
                }
                else {
                    return;
                }
            }
        }
    }
    else {
        cout<<"Invalid Card Number !!!"<<endl;
    }
    return;
}

void atmCredit(int cardNumber) {
    if(existsCard(cardNumber)) {
        for(int item = 0;item<=ATMCardDetails.size();item++) {
            if(cardNumber == ATMCardDetails[item].second) {
                int PIN;
                cout<<"Enter Your PIN :";
                cin>>PIN;
                bool pinValidation = validatePIN(PIN,cardNumber);
                if(pinValidation) {
                    int viewBalance;
                    int currentBalance = creditToAccount(ATMCardDetails[item].first);
                    cout<<"*****Amount Credited Successfully*****"<<endl;
                    cout<<"Do you Want to See Your Balance ?"<<endl;
                    cout<<"----------------------"<<endl;
                    cout<<"1.Yes"<<endl;
                    cout<<"2.No"<<endl;
                    cin>>viewBalance;
                    if(viewBalance == 1) {
                        cout<<"Your Balance is :"<<currentBalance<<endl;
                    }
                }
                else {
                    return;
                }
            }
        }
    }
    else {
        cout<<"Invalid Card Number !!!"<<endl;
    }
}
void atmPinGeneration() {
    int accountNumber;
    int cardNumber;
    int PIN;
    cout<<"Enter Account Number :";
    cin>>accountNumber;
    cout<<"Enter card Number :";
    cin>>cardNumber;
    if(existsCard(cardNumber)) {
        cout<<"Enter Your Four Digits PIN :";
        cin>>PIN;
        ATMPin.push_back(make_pair(cardNumber, PIN));
        cout<<"*****Successfully PIN Generated*****"<<endl;
    }
}

void atmPINChange(int cardNumber) {
    int oldPIN;
    int newPIN;
    if(existsCard(cardNumber)) {
        cout<<"Enter Your Old PIN :";
        cin>>oldPIN;
        if(validatePIN(oldPIN,cardNumber)) {
            for(int item = 0;item < ATMPin.size();item++) {
                if(ATMPin[item].first == cardNumber) {
                    cout<<"Enter Your PIN :";
                    cin>>newPIN;
                    ATMPin[item].second = newPIN;
                    cout<<"PIN Changed Successfully"<<endl;
                }
            }
       }
    }
}

bool existsCard(int cardNumber) {
    for(int item = 0;item<=ATMCardDetails.size();item++) {
        if(cardNumber == ATMCardDetails[item].second) {
            return true;
        }
    }
    cout<<"Card Not Exist!!!"<<endl;
    cout<<"----------------------"<<endl;
    return false;
}

bool validatePIN(int PIN,int cardNumber) {
    for(int item = 0;item < ATMPin.size();item++) {
        if(ATMPin[item].first == cardNumber) {
            if(ATMPin[item].second == PIN) {
                return true;
            }
        }
    }
    cout<<"Wrong PIN !!!";
    return false;
}

int fetchAccountNumber(int cardNumber) {
    for(int item = 0;item<=ATMCardDetails.size();item++) {
        int accountNumber;
        if(existsCard(cardNumber)) {
            if(cardNumber == ATMCardDetails[item].second) {
                return ATMCardDetails[item].first;
            }
        } else {
            cout<<"Card Number Invalid !!!"<<endl;
            cout<<"----------------------"<<endl;
            return 0;
        }
    }
}


