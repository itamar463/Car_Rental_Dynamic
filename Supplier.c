
#include "Supplier.h"



SupplierList *createSupplierList(){
    /*CRATE SUPPLIER LIST*/
    SupplierList *list = NULL;
    return list;
}

int checkValues(char *authorized_dealer_num, char *supplier_name, char *supplier_phone_num,
                long sum_of_general_deals_withSupp, int number_of_deals_withSupp) {
    /*CHECK IF THE VALUES INPUT IS ACCORDING THE LEGALITY*/
    /*LEN CHECK*/
    if (valid_long(sum_of_general_deals_withSupp, MIN_SUM_DEALS, MAX_SUM_DEALS) == 0){
        printf("sum of general deals not valid\n");
        return FALSE;}
    if (valid_int(number_of_deals_withSupp, MIN_NUM_DEALS, MAX_NUM_DEALS) == 0){
        printf("number of deals not valid\n");
        return FALSE;
    }

    if (check_equal_size(authorized_dealer_num, AUTH_DEALER_NUM_LEN) == 0) {
        printf("authorized dealer number not valid\n");
        return FALSE;
    }
    if (check_equal_size(supplier_phone_num, SUPP_PHONE_LEN) == 0) {
        printf("supplier phone number not valid\n");
        return FALSE;
    }

    if (valid_digit_check(supplier_phone_num) == 0) {
        printf("supplier phone number not valid\n");
        return FALSE;
    }
    if (valid_digit_check(authorized_dealer_num) == 0){
        printf("authorized dealer number not valid\n");
     return FALSE;
    }

    if (valid_char_check(supplier_name) == 0){
        printf("supplier name not valid\n");
        return FALSE;
    }

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
    }
    else{
        strcpy( temporarySupp->authorized_dealer_num  , "-1");
        checked_free(supplier_name);
    }
    return temporarySupp;
}

int addToList(SupplierList **head) {
    /*CRATE THE SUPPLIER AND PUT IN THE LIST*/
    SupplierList *new;
    new = (SupplierList *) checked_malloc(sizeof(SupplierList));
    new->data = initSupplier();

    if (strcmp(new->data->authorized_dealer_num ,"-1") == 0) {
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
    SupplierList *curr = *head;
    while(*head != NULL){
        curr = *head;
        *head = curr->next;
        checked_free(curr->data->supplier_name);
        checked_free(curr->data);
        checked_free(curr);
    }
    printf("ALL SUPPLIER REMOVED\n");
    return TRUE;
}

char **threeGreatestSuppliers(SupplierList** head , char threeGreatSupplier[3][11] ) {
    /*PRINT AND RETURN THE 3 GREATEST SUPPLIERS*/
    int index =0;
    int count_down = 3;
    long big_check = 0;
    char auth_num[AUTH_DEALER_NUM_LEN+1] ;
    if(head == NULL) return NULL;
    strcpy(threeGreatSupplier[0],"0");
    strcpy(threeGreatSupplier[1],"0");
    strcpy(threeGreatSupplier[2],"0");
    while (count_down > 0) {
        SupplierList *tmp = (*head);
        while (tmp != NULL) {
            if ((strcmp(tmp->data->authorized_dealer_num, threeGreatSupplier[0]) != FALSE) &&
                (strcmp(tmp->data->authorized_dealer_num, threeGreatSupplier[1]) != FALSE) &&
                (tmp->data->sum_of_general_deals_withSupp > big_check)) {
                big_check = tmp->data->sum_of_general_deals_withSupp;
                strcpy(auth_num , tmp->data->authorized_dealer_num);
                 tmp=tmp->next;
            }
             else tmp=tmp->next;}
        if(strcmp(auth_num ,threeGreatSupplier[0]) !=FALSE && strcmp(auth_num ,threeGreatSupplier[1]) !=FALSE){
        strcpy(threeGreatSupplier[index]  , auth_num );}
        index++;
        big_check = 0;
        count_down--;
    }
    for (index=0 ; index<3 ; index++){
        if(strcmp(threeGreatSupplier[index],"0")!=0) {
            printf("%s\n", threeGreatSupplier[index]);
        }}
    return (char **) *threeGreatSupplier;
}

void threeGreatSuppliersHelper(SupplierList **head, long check, char biggestSupplier[AUTH_DEALER_NUM_LEN + 1],
                               char threeGreatSupp[3][11]) {
    SupplierList *temp = (*head);
    if (temp == NULL) {
        return;
    }
    if ((temp->data->sum_of_general_deals_withSupp > check) &&
        (strcmp(temp->data->authorized_dealer_num, threeGreatSupp[0]) != 0) &&
        (strcmp(temp->data->authorized_dealer_num, threeGreatSupp[1]) != 0)) {
        check = temp->data->sum_of_general_deals_withSupp;
        strcpy(biggestSupplier, temp->data->authorized_dealer_num);
    }
    threeGreatSuppliersHelper(&temp->next, check, biggestSupplier, threeGreatSupp);
}

char **threeGreatestSuppliers_REC(SupplierList **head, char threeGreatSupp[3][11]) {
    SupplierList *temp = *head;
    int i = 0;
    int countDown = 3;
    long check = 0;
    int index = 0;
    char biggestSupplier[AUTH_DEALER_NUM_LEN + 1];
    while (countDown > 0) {
        strcpy(biggestSupplier, "0");
        threeGreatSuppliersHelper(&temp, check, biggestSupplier, threeGreatSupp);
        strcpy(threeGreatSupp[index], biggestSupplier);
        countDown--;
        index++;
    }
    printf("Three great suppliers are: \n");
    printf("[ ");
    for (i; i < 3; i++){
        if (i<2){
            printf(" %s |",threeGreatSupp[i]);
        } else printf(" %s ",threeGreatSupp[i]);
    }
    printf("]");
    return (char **) threeGreatSupp;
}
