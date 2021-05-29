#include "Common.h"
#include <stdio.h>

int clientNumberWithGivenCarYear(ClientList **ClientHead, CarList **CarList1) {
    /*RETURN THE NUMBER OF CLIENTS WITH THE SAME CAR YEAR*/
    CarList *tmpCar = *CarList1;
    int car_manu;
    int num_of_car_same_year = 0;
    printf("Enter year of car manufacture: \n");
    scanf("%d", &car_manu);
    while (tmpCar != NULL) {
        if (tmpCar->data->year_manufacture == car_manu) {
            ClientList *tmpClient = *ClientHead;
            while (tmpClient != NULL) {
                if (strcmp(tmpClient->data->license_number, tmpCar->data->license_number) == 0) {
                    num_of_car_same_year++;
                }
                tmpClient = tmpClient->next;
            }
        }
        tmpCar = tmpCar->next;
    }
    printf("The number of clients with cars that have the same year is: %d\n", num_of_car_same_year);
    return num_of_car_same_year;
}

int printClientCarsForGivenRentDate(ClientList **ClientHead) {
    /*PRINT CLIENTS WITH THE SAME RENT DATE*/
    ClientList *temp = *ClientHead;
    int check = 0;
    int year;
    int month;
    int day;
    if (temp == NULL) {
        printf("THERE NO CLIENTS\n");
        return 0;
    }

    printf("Enter date: year , month , day\n");
    scanf("%d %d %d", &year, &month, &day);
    if (date_valid(year, month, day) == 0) {
        printf("date not valid \n");
        return 0;
    }

    while (temp != NULL) {
        if (temp->data->date_of_rent.day == day && temp->data->date_of_rent.year == year &&
            temp->data->date_of_rent.month == month) {
            check++;
            printf("CLIENT :\n"
                   "first name : %s\n"
                   "last name : %s\n"
                   "id : %s\n"
                   "car licence number : %s\n"
                   "rent price for 24 hours : %d \n", temp->data->first_name, temp->data->last_name, temp->data->id,
                   temp->data->license_number, temp->data->price_per_rent);
            printf("rent date : ");
            print_date(temp->data->date_of_rent);
            printf("rent time : ");
            print_time(temp->data->hour_of_rent);

        }
        temp = temp->next;

    }
    if(check== 0) printf("No clients for the given date \n");
    return 1;
}

int printSuppliers(SupplierList **head) {
    /*PRINTS ALL THE SUPPLIERS*/
    SupplierList *tmp = *head;
    if(tmp == NULL){
        printf("No suppliers\n");
        return FALSE;}
    while (tmp != NULL) {
        printf("Supplier name: %s\nDealer number: %s\nSupplier phone number: %s\nNumber of deals: %d\n"
               "Sum of deals in general: %ld\n\n",
               tmp->data->supplier_name,
               tmp->data->authorized_dealer_num,
               tmp->data->supplier_phone_num, tmp->data->number_of_deals_withSupp,
               tmp->data->sum_of_general_deals_withSupp);
        tmp = tmp->next;
    }
    return 1;
}
