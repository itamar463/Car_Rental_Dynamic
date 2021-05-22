//
// Created by Itamar on 17/05/2021.
//

#ifndef CAR_RENTAL_DYNAMIC_VALIDINPUT_H
#define CAR_RENTAL_DYNAMIC_VALIDINPUT_H
#include <string.h>
#include <stdio.h>
#include "stdlib.h"

int isLetter(char letter);
int isDigit(char isNum);
int valid_char_check(char *str);
int valid_digit_check(char *str);
int date_valid(int year, int month, int day);
void smaller_than_ten(int num);
int time_valid(int hour, int minute);
int check_value_size(char* str,int size);
int check_equal_size(char* str,int size);
int valid_int(int num,int min,int max);
int valid_long(long num,long min,long max);
char *dupstr(const char *str);


#endif
