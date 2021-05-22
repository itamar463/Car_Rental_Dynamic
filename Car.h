//
// Created by Itamar on 17/05/2021.
//

#ifndef CAR_RENTAL_DYNAMIC_CAR_H
#define CAR_RENTAL_DYNAMIC_CAR_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ValidInput.h"
#include "matam.h"
#define LICENSE_NUM_LEN 7
#define CHASSIS_NUM_LEN 5

typedef struct Car{
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

typedef struct CarList{
    Car *data;
    struct CarList* next;
}CarList;
CarList *createCarList();

int addNewCar(CarList** head);

int carNumberWithGivenCapacity(CarList** head);

int carNumberWithGivenCapacity_REC(CarList* head, int* capacityCheck,CarList* baseHead);

int deleteCar(CarList** head);

int deleteAllCars(CarList** head);

int inverseCarList();
#endif
