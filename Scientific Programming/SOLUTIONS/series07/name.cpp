#include <iostream>
#include "name.hpp"


int main() {
 Name nm;
 nm.setFirstName("Johnson Olubori");
 nm.setSurName("Oyero");
 nm.printName();
 nm.setFullName("Nana Da Vinci");
 nm.printName();
 return 0;
}
