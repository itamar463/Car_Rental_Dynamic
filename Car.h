//
// Created by Itamar on 17/05/2021.
//

#ifndef CAR_RENTAL_DYNAMIC_CAR_H
#define CAR_RENTAL_DYNAMIC_CAR_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ValidInput.h"
#define LICENSE_NUM_LEN 7
#define CHASSIS_NUM_LEN 5

typedef struct {
    char license_number[LICENSE_NUM_LEN + 1];
    char chassis_number[CHASSIS_NUM_LEN + 1];
    char* maker;
    char* model;
    char* color;
    int year_manufacture;
    int year_get_on_road;
    int price_that_paid;
    int present_car_price;
    int engine_cap;
}Car;
int createCarList();

int
addNewCar();

int carNumberWithGivenCapacity();

int carNumberWithGivenCapacity_REC();

int deleteCar();

int deleteAllCars();

int inverseCarList();
#endif
