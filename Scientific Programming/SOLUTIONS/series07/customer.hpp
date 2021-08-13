#include <string>
#include <cassert>
#include <cstdio>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Customer {
  private:
    string name;
    double balance;
    int PIN;

  public:
    string getName();
    double getBalance();
    int getPIN();
    void setName(string);
    void setBalance(double);
    void setPIN(int);
    void printBalance();
    bool checkPIN();
    void drawMoney(double = 0);
};

string Customer::getName() {
   return name;
}

double Customer::getBalance() {
   return balance;
}

int Customer::getPIN() {
   return PIN;
}

void Customer::setName(string n) {
  name = n;
}

void Customer::setBalance(double b) {
  balance = b;
}

void Customer::setPIN(int pin) {
  PIN = pin;
}

void Customer::printBalance() {
  cout << "Current Balance: " << balance << endl;
}

bool Customer::checkPIN() {
  int chk;
  cout << "Enter PIN: ";
  cin >> chk;
  return (PIN == chk);
}

void Customer::drawMoney(double amount) {
  assert(checkPIN());
  if (amount == 0) {
    cout << "Enter Amount: ";
    cin >> amount;
  }
  assert(amount < balance);
  balance -= amount;
  if (balance < 10) {
    cout << "Warning: Balance is below 10 Euro" << endl;
  }

}
