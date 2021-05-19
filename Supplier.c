//
// Created by Itamar on 17/05/2021.
//

#include "Supplier.h"

int createSupplierList(){}

int initSupplier(){
    char authorized_dealer_num[AUTH_DEALER_NUM_LEN + 1];
    char* supplier_name;
    char supplier_phone_num[SUPP_PHONE_LEN + 1];
    int sum_of_general_deals_withSupp;
    int number_of_deals_withSupp;
    Supplier temporarySupp;

    printf("enter authorized_dealer_num : ");
    scanf("%s", authorized_dealer_num);
    printf("enter supplier_name : ");
    scanf("%s", supplier_name);
    printf("enter  supplier_phone_num : ");
    scanf("%s", supplier_phone_num);
    printf("enter  number_of_deals_withSupp : ");
    scanf("%d", &number_of_deals_withSupp);
    printf("enter  sum_of_general_deals_withSupp : ");
    scanf("%d", &sum_of_general_deals_withSupp);


}

int addNewSupplier(){
    Supplier *tmp;
    Supplier *list1;
    if(list.head == NULL){
        tmp =  initSupplier();
        tmp->left = NULL;
        tmp->right = NULL;
        list.head = tmp;
        Supplier *list1 = tmp;
    }
    else {
        tmp = initSupplier();
        list.head->right = tmp;

    }




}