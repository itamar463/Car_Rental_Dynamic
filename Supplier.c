//
// Created by Itamar on 17/05/2021.
//

#include "Supplier.h"

int printSuppliers(List** head){
    List* tmp = *head;
    while (tmp!=NULL){
        printf("%s\n%s\n%s\n%d\n%ld\n" , tmp->data->supplier_name, tmp->data->authorized_dealer_num , tmp->data->supplier_phone_num , tmp->data->number_of_deals_withSupp ,tmp->data->sum_of_general_deals_withSupp);
        tmp=tmp->next;
    }
}


List *createSupplierList() {
    List *list = NULL;
    return list;
}

int checkValues(char *authorized_dealer_num, char *supplier_name, char *supplier_phone_num,
                long sum_of_general_deals_withSupp, int number_of_deals_withSupp) {
    /*check if the values input is according the legality*/
    /*LEN CHECK*/
    if (valid_long(sum_of_general_deals_withSupp, MIN_SUM_DEALS, MAX_SUM_DEALS) == 0) return 0;
    if (valid_int(number_of_deals_withSupp, MIN_NUM_DEALS, MAX_NUM_DEALS) == 0) return 0;

    if (check_equal_size(authorized_dealer_num, AUTH_DEALER_NUM_LEN) == 0) return 0;
    if (check_equal_size(supplier_phone_num, SUPP_PHONE_LEN) == 0) return 0;

    if (valid_digit_check(supplier_phone_num) == 0) return 0;
    if (valid_digit_check(authorized_dealer_num) == 0) return 0;

    if (valid_char_check(supplier_name) == 0) return 0;

    return 1;
}

Supplier *initSupplier() {
    char authorized_dealer_num[AUTH_DEALER_NUM_LEN + 1];
    char *supplier_name = (char *) checked_malloc(sizeof(char) * 1024);
    char supplier_phone_num[SUPP_PHONE_LEN + 1];
    long sum_of_general_deals_withSupp;
    int number_of_deals_withSupp;
    Supplier *temporarySupp = (Supplier *) checked_malloc(sizeof(Supplier));

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
                    sum_of_general_deals_withSupp, number_of_deals_withSupp) == 1) {

        strcpy(temporarySupp->supplier_phone_num, supplier_phone_num);
        temporarySupp->supplier_name = dupstr(supplier_name);
        strcpy(temporarySupp->authorized_dealer_num, authorized_dealer_num);
        temporarySupp->sum_of_general_deals_withSupp = sum_of_general_deals_withSupp;
        temporarySupp->number_of_deals_withSupp = number_of_deals_withSupp;
    } else temporarySupp = NULL;
    return temporarySupp;
}

int deleteSupplier(List** head){
    List* temp = (*head);
    List* prev;
    char deleteSupplier[AUTH_DEALER_NUM_LEN+1];
    printf("enter the authorized dealer num to remove: ");
    scanf("%s" ,deleteSupplier);
    if (temp != NULL && strcmp(temp->data->authorized_dealer_num,deleteSupplier)==0){
        (*head) = temp->next;
        checked_free(temp->data->supplier_name);
        checked_free(temp->data);
        checked_free(temp);
        printf("supplier removed\n");
        return 1;
    }
    while (temp != NULL && strcmp(temp->data->authorized_dealer_num,deleteSupplier) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        printf("supplier doesnt found\n");
        return 0;}
    prev->next = temp->next;
    checked_free(temp->data->supplier_name);
    checked_free(temp->data);
    checked_free(temp);
    printf("supplier removed\n");
    return 1;
}

int addToList(List **head) {
    List *new;
    new = (List *) checked_malloc(sizeof(List));
    new->data = initSupplier();
    if (new->data == NULL) {
        checked_free(new);
        return 0;
    }
    new->next = *head;
    *head = new;
    return 1;
}

int addNewSupplier(List **head) {
    int check = addToList(head);
    if (check != 1) {
        printf("Supplier not added\n");
        return 0;
    }
    return 1;
}

int deleteAllSuppliers(List** head){
    List *temp = (*head);
    while (head != NULL){
        (*head) = temp->next;
        checked_free(temp->data->supplier_name);
        checked_free(temp->data);
        checked_free(temp);
    }
    return 1;
}

//char **threeGreatestSuppliers(List** head) {
//    char auth_num[AUTH_DEALER_NUM_LEN+1];
//    char *three_great_supp[3][AUTH_DEALER_NUM_LEN + 1];
//    int index =0;
//    int count_down = 3;
//    long big_check = 0;
//    while (count_down > 0) {
//        List *tmp = (*head);
//        while (tmp != NULL) {
//            if ((strcmp(tmp->data->authorized_dealer_num, *three_great_supp[0]) != 0) &&
//                (strcmp(tmp->data->authorized_dealer_num, *three_great_supp[1]) != 0) &&
//                (tmp->data->sum_of_general_deals_withSupp > big_check)) {
//                big_check = tmp->data->sum_of_general_deals_withSupp;
//                strcpy(auth_num , tmp->data->authorized_dealer_num);
//                 tmp=tmp->next;
//            }
//             else tmp=tmp->next;}
//        if(strcmp(auth_num ,*three_great_supp[0]) !=0 && strcmp(auth_num ,*three_great_supp[1]) !=0){
//        strcpy(*three_great_supp[index]  , auth_num );}
//        index++;
//        big_check = 0;
//        count_down--;
//    }
//    printf("%s\n", three_great_supp[0]);
//    printf("%s\n", three_great_supp[1]);
//    printf("%s\n" , three_great_supp[2]);
//    return (char **) three_great_supp;
//}
//char *threeGreatestSupplier_REC(List** head , long* sum){
//    char authorized_dealer_num[AUTH_DEALER_NUM_LEN + 1];
//    List *tmp = (*head);
//    if(tmp==NULL)return NULL;
//    if(tmp->data->sum_of_general_deals_withSupp > *sum){
//        *sum = tmp->data->sum_of_general_deals_withSupp;
//    }
//    name = threeGreatestSupplier_REC( tmp->next , &sum);
//
//
//
//
//}


