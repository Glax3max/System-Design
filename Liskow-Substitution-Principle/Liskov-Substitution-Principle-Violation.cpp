#include<bits/stdc++.h>
using namespace std;

class Account{
public: 
    virtual void deposit(double amount) = 0; //pure virtual function
    virtual void withdraw(double amount) = 0; //pure virtual function
};

class SavingAccount:public Account{
private:
    double balance;
public:
    SavingAccount() {
        balance = 0;
    }
    void deposit(double amount) {
        balance += amount;
        cout<<"Diposited: "<<amount<<" in Saving Account. New Balance: "<<balance<<endl;
    }

    void withdraw(double amount) {
        if(balance >= amount) {
            balance-=amount;
            cout<<"Withdrawn: "<<amount<<" from Saving Account.New Balance: "<<balance<<endl;
        }else{
            cout<<"InSufficient funds in Saving Account!\n";
        }
    }
};

class CurrentAccount:public Account{
private:
    double balance;
public:
    CurrentAccount() {
        balance = 0;
    }
    void deposit(double amount) {
        balance += amount;
        cout<<"Diposited: "<<amount<<" in Current Account. New Balance: "<<balance<<endl;
    }

    void withdraw(double amount) {
        if(balance >= amount) {
            balance-=amount;
            cout<<"Withdrawn: "<<amount<<" from Current Account.New Balance: "<<balance<<endl;
        }else{
            cout<<"InSufficient funds in Current Account!\n";
        }
    }
};

class FixedTermAccount:public Account{
private:
    double balance;
public:
    FixedTermAccount() {
        balance = 0;
    }
    void deposit(double amount) {
        balance += amount;
        cout<<"Diposited: "<<amount<<" in Fixed Term Account. New Balance: "<<balance<<endl;
    }
    
    void withdraw(double amount) {
        throw logic_error("Withdrawal not allowed in Fixed Term Account!");
    }
};


class BankClient{
private:
    vector<Account*> accounts;
public:
    BankClient(vector<Account*> accounts) {
        this->accounts = accounts;
    }    

    void processTransactions() {
        for(Account* acc : accounts) {
            acc->deposit(1000); //All accounts allow deposits 

            // Assuming all accounts support withdrawal (LSP Violation)
            try{
                acc->withdraw(500);
            }catch (const logic_error& e){
                cout<<"Exception: "<<e.what()<<endl;
            }
        }
    }
};

int main() {
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient(accounts);
    client->processTransactions(); //Throws exeception when withdrawing from FixedTermAccount
    
    return 0;
}