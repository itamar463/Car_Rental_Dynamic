//
// Created by Itamar on 17/05/2021.
//

#include "Supplier.h"

List* createSupplierList() {
    List * list = NULL;
    return list;
}

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
//    if (checkValues(authorized_dealer_num, supplier_name, supplier_phone_num, number_of_deals_withSupp,
//                    sum_of_general_deals_withSupp) == 0) {
//        temporarySupp.sum_of_general_deals_withSupp = -1;
//        return 0;
//    }
//    return 1;
//int checkValues(char *authorized_dealer_num, char *supplier_name, char *supplier_phone_num, int number_of_deals,
//                long sum_of_general) {
//    /*check if the values input is according the legality*/
//    /*LEN CHECK*/
//    /*DIGIT-CHAR CHEK*/
//    if (valid_digit_check(authorized_dealer_num) == 0 ||
//        check_equal_size(authorized_dealer_num, AUTH_DEALER_NUM_LEN) == 0) {
//        printf("Authorized_dealer_num not right\n");
//        return 0;
//    }
//    if (valid_digit_check(supplier_phone_num) == 0 || check_equal_size(supplier_phone_num, SUPP_PHONE_LEN) == 0) {
//        printf("Supplier_phone_num not right\n");
//        return 0;
//    }
//    /*LETTER CHECK*/
//    if (valid_char_check(supplier_name) == 0) {
//        printf("Supplier name not right\n");
//        return 0;
//    }
//    if (valid_int(number_of_deals, 10000, 100000) == 0) {
//        printf("Number of deals not right\n");
//        return 0;
//    }
//    if (valid_long(sum_of_general, 1000000000, 9999999999) == 0) {
//        printf("Sum of general not right\n");
//        return 0;
//    }
//    return 1;
//}

Supplier* initSupplier() {
    char authorized_dealer_num[AUTH_DEALER_NUM_LEN + 1];
    char *supplier_name = (char *) checked_malloc(sizeof(char) * 1024);
    char supplier_phone_num[SUPP_PHONE_LEN + 1];
    long sum_of_general_deals_withSupp;
    int number_of_deals_withSupp;
    Supplier* temporarySupp = (Supplier*) checked_malloc(sizeof(Supplier));

    printf("enter authorized_dealer_num : ");
    scanf("%s", authorized_dealer_num);
    printf("enter supplier_name : ");
    scanf("%s", supplier_name);
    printf("enter  supplier_phone_num : ");
    scanf("%s", supplier_phone_num);
    printf("enter  number_of_deals_withSupp : ");
    scanf("%d", &number_of_deals_withSupp);
    printf("enter  sum_of_general_deals_withSupp : ");
    scanf("%ld", &sum_of_general_deals_withSupp);

    if (checkValues(authorized_dealer_num, supplier_name, supplier_phone_num,
                    sum_of_general_deals_withSupp,number_of_deals_withSupp) == 1) {

        strcpy(temporarySupp->supplier_phone_num, supplier_phone_num);
        temporarySupp->supplier_name = dupstr(supplier_name);
        strcpy(temporarySupp->authorized_dealer_num, authorized_dealer_num);
        temporarySupp->sum_of_general_deals_withSupp = sum_of_general_deals_withSupp;
        temporarySupp->number_of_deals_withSupp = number_of_deals_withSupp;
    } else temporarySupp = NULL;
    return temporarySupp;

}



int addToList(List** head) {
    List * new;
    new = (List *) checked_malloc(sizeof(List));
    new->data = initSupplier();
    if (new->data==NULL){
        checked_free(new);
        return 0;
    }
    new->next = *head;
    *head = new;
    return 1;
}
int addNewSupplier(List** head) {
    int check = addToList(head);
    if(check!=1){
        printf("Supplier not added\n");
        return 0;
    }
    return 1;
    }


