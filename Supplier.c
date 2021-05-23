//
// Created by Itamar on 17/05/2021.
//

#include "Supplier.h"

void printSuppliers(SupplierList** head){
    /*PRINTS ALL THE SUPPLIERS*/
    SupplierList* tmp = *head;
    while (tmp!=NULL){
        printf("%s\n%s\n%s\n%d\n%ld\n" , tmp->data->supplier_name, tmp->data->authorized_dealer_num , tmp->data->supplier_phone_num , tmp->data->number_of_deals_withSupp ,tmp->data->sum_of_general_deals_withSupp);
        tmp=tmp->next;
    }
}

SupplierList *createSupplierList(){
    /*CRATE SUPPLIER LIST*/
    SupplierList *list = NULL;
    return list;
}

int checkValues(char *authorized_dealer_num, char *supplier_name, char *supplier_phone_num,
                long sum_of_general_deals_withSupp, int number_of_deals_withSupp) {
    /*CHECK IF THE VALUES INPUT IS ACCORDING THE LEGALITY*/
    /*LEN CHECK*/
    if (valid_long(sum_of_general_deals_withSupp, MIN_SUM_DEALS, MAX_SUM_DEALS) == 0) return FALSE;
    if (valid_int(number_of_deals_withSupp, MIN_NUM_DEALS, MAX_NUM_DEALS) == 0) return FALSE;

    if (check_equal_size(authorized_dealer_num, AUTH_DEALER_NUM_LEN) == 0) return FALSE;
    if (check_equal_size(supplier_phone_num, SUPP_PHONE_LEN) == 0) return FALSE;

    if (valid_digit_check(supplier_phone_num) == 0) return FALSE;
    if (valid_digit_check(authorized_dealer_num) == 0) return FALSE;

    if (valid_char_check(supplier_name) == 0) return FALSE;

    return TRUE;
}

Supplier *initSupplier() {
    /*INITIALIZING THE SUPPLIER*/
    char authorized_dealer_num[AUTH_DEALER_NUM_LEN + 1];
    char *supplier_name = (char *) checked_malloc(sizeof(char) * 1024);
    char supplier_phone_num[SUPP_PHONE_LEN + 1];
    long sum_of_general_deals_withSupp;
    int number_of_deals_withSupp;
    Supplier *temporarySupp = (Supplier *) checked_malloc(sizeof(Supplier));

    printf("enter authorized_dealer_num (10 DIGITS): ");
    scanf("%s", authorized_dealer_num);
    printf("enter supplier_name : ");
    scanf("%s", supplier_name);
    printf("enter  supplier_phone_num (10 DIGITS): ");
    scanf("%s", supplier_phone_num);
    printf("enter  number_of_deals_withSupp (5 DIGITS): ");
    scanf("%d", &number_of_deals_withSupp);
    printf("enter  sum_of_general_deals_withSupp (10 DIGITS): ");
    scanf("%ld", &sum_of_general_deals_withSupp);

    if (checkValues(authorized_dealer_num, supplier_name, supplier_phone_num,
                    sum_of_general_deals_withSupp, number_of_deals_withSupp) == 1) {

        strcpy(temporarySupp->supplier_phone_num, supplier_phone_num);
        temporarySupp->supplier_name = dupstr(supplier_name);
        strcpy(temporarySupp->authorized_dealer_num, authorized_dealer_num);
        temporarySupp->sum_of_general_deals_withSupp = sum_of_general_deals_withSupp;
        temporarySupp->number_of_deals_withSupp = number_of_deals_withSupp;
    } else strcpy( temporarySupp->authorized_dealer_num  , "-1");
    return temporarySupp;
}

int addToList(SupplierList **head) {
    /*CRATE THE SUPPLIER AND PUT IN THE LIST*/
    SupplierList *new;
    new = (SupplierList *) checked_malloc(sizeof(SupplierList));
    new->data = initSupplier();

    if (strcmp(new->data->authorized_dealer_num ,"-1") == TRUE) {
        checked_free(new->data->supplier_name);
        checked_free(new->data);
        checked_free(new);
        return FALSE;
    }
    new->next = *head;
    *head = new;
    return TRUE;
}
int addNewSupplier(SupplierList **head) {
    /*CRATE NEW SUPPLIER*/
    int check = addToList(head);
    if (check != TRUE) {
        printf("Supplier not added\n");
        return FALSE;
    }
    return TRUE;
}

int deleteSupplier(SupplierList** head){
    /*DELETE SUPPLIER WITH GIVEN AUTHORIZED DEALER NUM*/
    SupplierList* temp = (*head);
    SupplierList* prev;
    char deleteSupplier[AUTH_DEALER_NUM_LEN+1];
    printf("enter the authorized dealer num to remove (10 DIGITS): ");
    scanf("%s" ,deleteSupplier);
    if (temp != NULL && strcmp(temp->data->authorized_dealer_num,deleteSupplier)==0){
        (*head) = temp->next;
        checked_free(temp->data->supplier_name);
        checked_free(temp->data);
        checked_free(temp);
        printf("supplier removed\n");
        return TRUE;
    }
    while (temp != NULL && strcmp(temp->data->authorized_dealer_num,deleteSupplier) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        printf("supplier doesnt found\n");
        return FALSE;}
    prev->next = temp->next;
    checked_free(temp->data->supplier_name);
    checked_free(temp->data);
    checked_free(temp);
    printf("supplier removed\n");
    return TRUE;
}
int deleteAllSuppliers(SupplierList** head){
    /*DELETING ALL SUPPLIERS*/
    SupplierList *temp = (*head);
    SupplierList *curr = *head;
    while(curr != NULL){
        curr = temp->next;
        checked_free(temp->data->supplier_name);
        checked_free(temp->data);
        checked_free(temp);
    }
    printf("ALL SUPPLIER REMOVED\n");
    return TRUE;
}

char **threeGreatestSuppliers(SupplierList** head) {
    /*PRINT AND RETURN THE 3 GREATEST SUPPLIERS*/
    char auth_num[AUTH_DEALER_NUM_LEN+1] ;
    char *three_great_supp[3][AUTH_DEALER_NUM_LEN + 1];
    *three_great_supp[0]="0";
    *three_great_supp[0]="0";
    *three_great_supp[0]="0";
    int index =0;
    int count_down = 3;
    long big_check = 0;
    while (count_down > 0) {
        SupplierList *tmp = (*head);
        while (tmp != NULL) {
            if ((strcmp(tmp->data->authorized_dealer_num, three_great_supp[0]) != FALSE) &&
                (strcmp(tmp->data->authorized_dealer_num, three_great_supp[1]) != FALSE) &&
                (tmp->data->sum_of_general_deals_withSupp > big_check)) {
                big_check = tmp->data->sum_of_general_deals_withSupp;
                strcpy(auth_num , tmp->data->authorized_dealer_num);
                 tmp=tmp->next;
            }
             else tmp=tmp->next;}
        if(strcmp(auth_num ,three_great_supp[0]) !=FALSE && strcmp(auth_num ,three_great_supp[1]) !=FALSE){
        strcpy(three_great_supp[index]  , auth_num );}
        index++;
        big_check = 0;
        count_down--;
    }
    for (index=0 ; index<3 ; index++){
        if(three_great_supp[index]!="0") {
            printf("%s\n", three_great_supp[index]);
        }}
    return (char **) three_great_supp;
}
//char *threeGreatestSupplier_REC(SupplierList** head , long* sum){
//    char authorized_dealer_num[AUTH_DEALER_NUM_LEN + 1];
//    SupplierList *tmp = (*head);
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


