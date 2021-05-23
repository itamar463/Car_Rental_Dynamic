//
// Created by Itamar on 17/05/2021.
//

#include "Common.h"
#include <stdio.h>
#include "Car.h"
#include "Client.h"

int clientNumberWithGivenCarYear(ClientList **ClientHead  , CarList **CarList1) {
    /*RETURN THE NUMBER OF CLIENTS WITH THE SAME CAR YEAR*/
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