                    // Bank Management System
                    //   State Bank of India
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


class Bank {
public:
	int con;
    int acc_number;
    string acc_holder_name; 
    string branch;
    double balance;
    double amount_dep;
    double amount_with;
    double amount_fd;
    double loan_amount;

// Initialize Default value
    Bank() {
        acc_number = 0;
        balance = 0;
        branch = "";
    }

//Service functions
    void branch_bank();
    void deposit();
    void withdraw();
    void start_FD();
    void loan();
    void display_balance();
    void Account_profile();
    void exit();
    void createacc();
    void display_trans();
};

//Defining functions
void Bank::branch_bank() {
    cout << "Branch bank function called." << endl;
    cout << "Showing branch details for " << branch << "..." << endl;
    cout << "Address: 123 Main Street, Springfield, IL 62701"<< endl;
    cout << "Hours: Mon-Fri: 9 AM - 5 PM, Sat: 9 AM - 1 PM, Sun: Closed" <<endl; 
    cout << "Contact no: (+91) 8457952612"<<endl;
}

void Bank::deposit() {

    cout << "Enter amount to deposit: ";
    cin >> amount_dep;
    if (amount_dep > 0) {
        balance += amount_dep;
    cout << "Amount deposited successfully. Current balance: Rs : " << balance << endl;
    } else {
        cout << "Invalid amount." << endl;
    }
}

void Bank::withdraw() {

    cout << "Enter amount to withdraw: ";
    cin >> amount_with;
    if (amount_with > 0 && amount_with <= balance) {
        balance -= amount_with;
        cout << "Amount withdrawn successfully. Current balance: Rs: " << balance << endl;
    } else {
        cout << "Invalid amount Withdrawal failed." << endl;
    }
}

void Bank::start_FD() {
 
    int duration;
    cout << "Welcome to phoenix Drone Fixed Deposites:"<<endl;
    cout << endl;
    cout << "Rate of intrest for 1 year = 5%"<<endl;
    cout << "Rate of intrest for more than 1 year = 7%"<<endl;
    cout << endl;
    jump:
    cout << "Enter amount to start F.D.: ";
    cin >> amount_fd;
    if(amount_fd>balance)
    {
    	cout<<"Account balance insuficient.Please enter amount lesser than "<<balance<<endl;
    	goto jump;
	}
    cout << "Enter duration (in years): ";
    cin >> duration;
    if (amount_fd > 0 && duration > 0) {
    	if(duration==1){
        double interest_rate = 0.05; //Intrest rate 5%
        double maturity_amount = amount_fd * pow((1 + interest_rate), duration);
        cout<<endl;
        cout << "FD started successfully. Maturity amount after " << duration << " years: Rs" << maturity_amount << endl;
        }
        else{
        double interest_rate = 0.07; //Intrest rate 7%
        double maturity_amount = amount_fd * pow((1 + interest_rate), duration);
        cout<<endl;
        cout << "FD started successfully. Maturity amount after " << duration << " years: Rs :" << maturity_amount << endl;
        cout<<endl;
        cout<<"You also grow with us!!"<<endl;;
		}
	} 
	else {
        cout << "Invalid amount,  F.D. creation failed." << endl;
    }
    balance-= amount_fd;
}

void Bank::loan() {
  
    cout << "Enter loan amount: ";
    cin >> loan_amount;
    if (loan_amount > 0) {
        cout << "Loan approved for amount: Rs : " << loan_amount << endl;
    } else {
        cout << "Invalid loan amount." << endl;
    }
    balance += loan_amount;
}

void Bank::display_balance() {
    cout << "Current balance: Rs : " << balance << endl;
}

void Bank::Account_profile() {
    cout << "Account Profile:" << endl;
    cout << "Account Number: " << acc_number << endl;
    cout << "Account Holder Name: " << acc_holder_name << endl;
    cout << "Branch: " << branch << endl;
    cout << "Current Balance: Rs : " << balance << endl;
}

void Bank::exit() {
    con=0;
    cout << "Thank you for using our services." << endl;
    cout << "*** Please Visit again!! *** " << endl;
}

void Bank::createacc() {
    
    cout << "Creating a new account..." << endl;
    cout << "Enter new account number: ";
    cin >> acc_number;
    cout << "Enter account holder full name: ";
    cin.ignore();
    getline(cin, acc_holder_name);
    cout << "Select branch (Surat/Delhi/Kanpur): ";
    getline(cin, branch);
    balance = 0;
    cout << "Account created successfully!" << endl;
    Account_profile();
}

void Bank::display_trans(){
	
	if(amount_dep!=0){
		cout<<"Total deposited amount is: "<<amount_dep<<endl;
		cout<<endl;
	}
	if(amount_with!=0){
		cout<<"Total Withdrawn amount is: "<<amount_with<<endl;
		cout<<endl;
	}
	if(loan_amount!=0){
		cout<<"Total loan amount taken is: "<<loan_amount<<endl;
		cout<<endl;
	}
	if(amount_fd!=0){
		cout<<"Total amount fixed deposited is: "<<amount_fd<<endl;
		cout<<endl;
	}
	display_balance();
}

int main() {
    int service;
    Bank acc1;
    
    cout << "****** WELCOME TO PHOENIX DRONE BANK ******" << endl;
    cout<<""<<endl;
    cout << " Enter your Account number: ";
    cin >> acc1.acc_number;
    acc1.con=1;
    
    //Taking input from user
    if (acc1.acc_number != 0) {
        cout << " Enter Account holder full name: ";
        cin.ignore(); // for consume any newline character left in the buffer
        getline(cin, acc1.acc_holder_name);
        cout << " Choose your branch (Surat/New Delhi/Kanpur/Patna/New York ): ";
        getline(cin, acc1.branch);
        cout<<endl;
        
        // Services 
        cout << "Services available: " << endl;
        cout << "1. Check account balance" << endl;
        cout << "2. Deposit amount" << endl;
        cout << "3. Start a fixed deposit (F.D.)" << endl;
        cout << "4. Get transaction details" << endl;
        cout << "5. Get a loan" << endl;
        cout << "6. Withdrawal Amount" << endl;
        cout << "7. Details of Branch " << endl;
        cout << "8. View Profile" << endl;
        cout << "9. Create Account" << endl;
        cout << "10. Exit" << endl;
        
        while(acc1.con!=0){
        cout << endl;
        cout << "Enter the number of the service to execute: ";
        cin >> service;
        cout<<endl;

        switch (service) {
            case 1:
                acc1.display_balance();//Display balance
                break;
            case 2:
                acc1.deposit();//Make a deposite
                break;
            case 3:
                acc1.start_FD();//Start a fd
                break;
            case 4:
                acc1.display_trans(); //display transaction details
                break;
            case 5:
                acc1.loan();//get a loan
                break;
            case 6:
                acc1.withdraw(); // withdraw balance
                break;
            case 7:
                acc1.branch_bank(); // Give address of your branch
                break;
            case 8:
                acc1.Account_profile(); // Show your details 
                break;
            case 9:
                acc1.createacc();// To create new account
                break;
            case 10:
                acc1.exit();//exit
                break;
            default:
                cout << "Invalid service number, Please try again." << endl;
                break;
        }
        }
    } 
    else {
        acc1.createacc();
    }
    return 0;
}
