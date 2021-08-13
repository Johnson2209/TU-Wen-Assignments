//#include <stdio.h>
//#include <stdlib.h>
#include "datum.h"
//#include <assert.h>

int isMeaningful(Date* date) {
  int d = getDateDay(date);
  int m = getDateMonth(date);
  int y = getDateYear(date);

  if (y < 1900) {
    return 0;
  }
  if (m < 1 || m > 12) {
    return 0;
  }
  if (d < 1) {
    return 0;
  }

  switch(m) {
    case (9 || 4 || 6 || 11) :
      if (d > 30) {
        return 0;
      }
    case (2) :
      if (y % 4 == 0 && d > 29) {
        return 0;
      }
      else if (d > 28) {
        return 0;
      }
    default :
      if (d > 31) {
        return 0;
      }
    }
    // if all tests are passed, then ...
    return 1;

  }


int main() {
  int day;
  int month;
  int year;
  Date* date;
  printf("Enter day : ");
  scanf("%d",&day);
  printf("Enter month : ");
  scanf("%d",&month);
  printf("Enter year : ");
  scanf("%d",&year);

  date =newDate(day, month, year);

  if (isMeaningful(date)==1) {
    printf("The date is %1d.%1d.%d \n", day, month, year);
  }
  else {
    printf("There's something wrong with the date \n");
  }
}

 // allocate and initialize new date
 Date* newDate(int d, int m, int y) {
   Date* date = malloc(sizeof(Date));
   assert(date != NULL);
   date->day = d;
   date->month = m;
   date->year = y;
   return date;
 }

// free memory allocation
 Date* delDate(Date* date) {
   assert(date != NULL);
   free(date);
   return NULL;
 }

 // set Day of a Date
 void setDateDay(Date* date, int d) {
   assert(date != NULL);
   date->day = d;
 }

 // set Month of a Date
 void setDateMonth(Date* date, int m) {
   assert(date != NULL);
   date->month = m;
 }

 // set Year of a Date
 void setDateYear(Date* date, int y) {
   assert(date != NULL);
   date->year = y;
 }

 // get Day of a Date
 int getDateDay(Date* date) {
   assert(date != NULL);
   return date->day;
 }

 // get Month of a Date
 int getDateMonth(Date* date) {
   assert(date != NULL);
   return date->month;
 }

 // get Year of a Date
 int getDateYear(Date* date) {
   assert(date != NULL);
   return date->year;
 }
