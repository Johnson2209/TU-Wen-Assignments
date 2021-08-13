#include <stdio.h>
#include "person.h"
#include "datum.h"

struct _Address_{
    char* street;
    char* number;
    char* city;
    char* zip;
};
typedef struct _Address_ Address;
typedef struct _Date_ Date;
struct _Person_{
    char* firstname;
    char* surname;
    Address* address;
    Date* birthday;
};
typedef struct _Person_ Person;

int main(){
    Address* addr1;
    addr1->street = "xyz";
    addr1->number = "220";
    addr1->city = "wien";
    addr1->zip = "1110";
    Address* addr2;
    addr2->street = "abc";
    addr2->number = "002";
    addr2->city = "wien";
    addr2->zip = "1010";
    Date* d1 = newDate(23,6,1995);
    Date* d2 = newDate(16,10,1987);
    Person* p1;
    p1->firstname = "J";
    p1->surname = "Bond";
    p1->birthday = d1;
    p1->address = addr1;

    Person* p2;
    p2->firstname = "M";
    p2->surname = "Corleone";
    p2->birthday = d2;
    p2->address = addr2;

    Person* p = whoIsOlder(p1, p2);

    printf(" %c is older", p->firstname);

}

Person* whoIsOlder(Person* a, Person* b){
    Date* d1 = getBirthday(a);
    Date* d2 = getBirthday(b);

    if((2019 - d1->year) > (2019 - d2->year)){
        return a;
    }
}

void setFirstName(Person* person, char* fName){
    person->firstname = fName;
}
void setSurName(Person* person, char* sName){
    person->surname = sName;
}
void setAddress(Person* person, Address* addr){
    person->address = addr;
}
void setBirthday(Person* person, Date* date){
    date->birthday = date;
}

char* getFirstName(Person* person){
    return person->firstname;
}
char* getSurName(Person* person){
    return person->surname;
}
Address* getAddress(Person* person){
    return person->address;
}
Date* getBirthday(Person* person){
    return person->birthday;
}
