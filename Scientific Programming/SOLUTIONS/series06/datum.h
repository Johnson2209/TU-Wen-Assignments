#ifndef _STRUCT_DATE_
#define _STRUCT_DATE_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Declaration of structure
struct _Date_ {
  int day; // Day
  int month; // Month
  int year; // Year
 };

 // Declaration of corresponding data type
 typedef struct _Date_ Date;
 Date* newDate(int d, int m, int y);
 Date* delDate(Date* date);
 void setDateDay(Date* date, int d);
 void setDateMonth(Date* date, int m);
 void setDateYear(Date* date, int y);
 int getDateDay(Date* date);
 int getDateMonth(Date* date);
 int getDateYear(Date* date);

#endif
