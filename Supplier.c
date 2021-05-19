//
// Created by Itamar on 17/05/2021.
//

#include "Supplier.h"

int createSupplierList(){}

int checkValues(char *authorized_dealer_num, char *supplier_name, char *supplier_phone_num ,
                long sum_of_general_deals_withSupp, int number_of_deals_withSupp) {
    /*check if the values input is according the legality*/
    /*LEN CHECK*/
    if(valid_long(sum_of_general_deals_withSupp , MIN_SUM_DEALS , MAX_SUM_DEALS) == 0) return 0;
    if(valid_int(number_of_deals_withSupp , MIN_NUM_DEALS  ,MAX_NUM_DEALS) == 0 ) return 0;

    if(check_equal_size(authorized_dealer_num , AUTH_DEALER_NUM_LEN) == 0 ) return  0 ;
    if(check_equal_size(supplier_phone_num , SUPP_PHONE_LEN) == 0 ) return  0 ;

    if(valid_digit_check(supplier_phone_num ) == 0 ) return  0 ;
    if(valid_digit_check(authorized_dealer_num) == 0 ) return  0 ;

    if(valid_char_check(supplier_name) == 0 ) return  0 ;

    return 1;
}


int initSupplier(){
    char authorized_dealer_num[AUTH_DEALER_NUM_LEN + 1];
    char* supplier_name;
    char supplier_phone_num[SUPP_PHONE_LEN + 1];
    long sum_of_general_deals_withSupp;
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

if( checkValues(authorized_dealer_num, supplier_name, supplier_phone_num ,
                   sum_of_general_deals_withSupp,  number_of_deals_withSupp) == 0){
    return 0;
}
    return 1;
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