#include <iostream>
#include "customer.hpp"

int main() {
  Customer cst;
  cst.setName("Nana");
  cst.setPIN(1234);
  cst.setBalance(100);
  cst.drawMoney(20);
  cst.printBalance();
  cst.drawMoney();
  cst.printBalance();

 return 0;
}
