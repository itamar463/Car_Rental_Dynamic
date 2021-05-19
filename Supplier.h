//
// Created by Itamar on 17/05/2021.
//

#ifndef CAR_RENTAL_DYNAMIC_SUPPLIER_H
#define CAR_RENTAL_DYNAMIC_SUPPLIER_H

#include <stdio.h>
#include <string.h>
#include "ValidInput.h"

#define AUTH_DEALER_NUM_LEN 10
#define SUPP_PHONE_LEN 10

typedef struct supplier {
    char authorized_dealer_num[AUTH_DEALER_NUM_LEN + 1];
    char *supplier_name;
    char supplier_phone_num[SUPP_PHONE_LEN + 1];
    int number_of_deals_withSupp;
    long sum_of_general_deals_withSupp;
    struct supplier *right ;
    struct supplier *left;
} Supplier;

struct List{
    Supplier *head;
    Supplier *tail;
};


void print1();

int createSupplierList();

struct Supplier getSupplierDetails();

void addToList(struct Supplier s);

int addNewSupplier();

int deleteSupplier();

int deleteAllSuppliers();

char **threeGreatestSuppliers_REC();

char **threeGreatestSuppliers();

int printSuppliers();
#endif
