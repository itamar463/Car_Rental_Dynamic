//
// Created by Itamar on 17/05/2021.
//

#ifndef CAR_RENTAL_DYNAMIC_SUPPLIER_H
#define CAR_RENTAL_DYNAMIC_SUPPLIER_H
#include "matam.h"
#include <stdio.h>
#include <string.h>
#include "ValidInput.h"

#define AUTH_DEALER_NUM_LEN 10
#define SUPP_PHONE_LEN 10
#define MIN_NUM_DEALS 9999
#define MAX_NUM_DEALS 100000
#define MIN_SUM_DEALS 999999999
#define MAX_SUM_DEALS 10000000000
typedef struct {
    char authorized_dealer_num[AUTH_DEALER_NUM_LEN + 1];
    char *supplier_name;
    char supplier_phone_num[SUPP_PHONE_LEN + 1];
    int number_of_deals_withSupp;
    long sum_of_general_deals_withSupp;
} Supplier;

typedef struct List{
    Supplier *data;
    struct List* next;
}List;


void print1();

List* createSupplierList();

struct Supplier getSupplierDetails();

int addNewSupplier(List** head);

int deleteSupplier(List** head);

int deleteAllSuppliers(List** head);

char **threeGreatestSuppliers_REC();

char **threeGreatestSuppliers();

int printSuppliers();
#endif
