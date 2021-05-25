//
// Created by Itamar on 17/05/2021.
//

#include "Common.h"
#include <stdio.h>

int clientNumberWithGivenCarYear(ClientList **ClientHead  , CarList **CarList1) {
    CarList *tmpCar = *CarList1;
    int car_manu;
    int num_of_car_same_year = 0;
    printf("Enter year of car manufacture: \n");
    scanf("%d",&car_manu);
    while (tmpCar !=NULL){
        if(tmpCar->data->year_manufacture == car_manu){
            ClientList* tmpClient = *ClientHead;
            while (tmpClient !=NULL){
                if(strcmp(tmpClient->data->license_number , tmpCar->data->license_number)==0){
                    num_of_car_same_year++;}
                tmpClient= tmpClient->next;
            }
        }
        tmpCar=tmpCar->next;
    }
    return num_of_car_same_year;
}

int compareCharacters(char a,char b) {
    if (a == b) {
        printf("good\n");
        return 0;
    } else {
        printf("bad\n");
        return -1;
    }
}
int printClientCarsForGivenRentDate(ClientList** ClientHead){
    ClientList *temp = *ClientHead;
    if(temp == NULL){
        printf("THERE NO CLIENTS\n");
        return 0;
    }
    int year, month, day;
    printf("Enter date: year , month , day\n");
    scanf("%d %d %d", &year, &month, &day);
    if (date_valid(year, month, day) == 0) {
        printf("date not valid \n");
        return 0;}

    while(temp != NULL){
        if(temp->data->date_of_rent.day == day && temp->data->date_of_rent.year == year &&
           temp->data->date_of_rent.month == month ){
            printf("CLIENT :\n"
                   "first name : %s\n"
                   "last name : %s\n"
                   "id : %s\n"
                   "car licence nuber : %s\n"
                   "rent price for 24 hours : %d \n",temp->data->first_name , temp->data->last_name
                    , temp->data->id , temp->data->license_number , temp->data->price_per_rent);
            printf("rent date : ");
            print_date(temp->data->date_of_rent);
            printf("rent time : ");
            print_time(temp->data->hour_of_rent);
            temp =  temp->next;
        }
    }
    return 1;
}
int printSuppliers(SupplierList** head){
    /*PRINTS ALL THE SUPPLIERS*/
    SupplierList* tmp = *head;
    while (tmp!=NULL){
        printf("%s\n%s\n%s\n%d\n%ld\n" , tmp->data->supplier_name, tmp->data->authorized_dealer_num , tmp->data->supplier_phone_num , tmp->data->number_of_deals_withSupp ,tmp->data->sum_of_general_deals_withSupp);
        tmp=tmp->next;
    }
    return 1;
}