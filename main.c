#include <stdio.h>
#include "Supplier.h"
#include "Client.h"
#include "Car.h"
#include "matam.h"
#include "Common.h"

char threeGreatSupplier[3][11];
int i = 0;

void client(ClientList **CList) {
    /* ask for how many clients would the user add for the list*/
    int n_client;
    int check = TRUE;
    printf("How many client you want to add ? : ");
    scanf("%d", &n_client);
    for (i = 0; i < n_client; ++i) {
        check = addNewClient(CList);
        if (check==FALSE){
            i--;
        }
    }
}

void supplier(SupplierList **list) {
    /* ask for how many suppliers would the user add for the list*/
    int n_supplier;
    int check = TRUE;
    printf("How many supplier you want to add ? : ");
    scanf("%d", &n_supplier);
    for (i = 0; i < n_supplier; ++i) {
        printf("\nSUPPLIER: \n");
        check = addNewSupplier(list);
        if (check==FALSE){
            i--;
        }
    }
}

void car(CarList **CarList) {
    /* ask for how many cars would the user add for the list*/
    int n_car;
    int check = TRUE;
    printf("How many cars you want to add ? : ");
    scanf("%d", &n_car);
    for (i = 0; i < n_car; ++i) {
        check = addNewCar(CarList);
        if (check==FALSE){
            i--;
        }
    }
}

void delete(SupplierList **SList, ClientList **CList, CarList **CarList) {
    /* menu for delete options*/
    int n_delete;
    printf("\n Enter your choice:\n"
           "1 - For delete supplier\n"
           "2 - For delete client\n"
           "3 - For delete car\n"
           "4 - For delete all suppliers\n"
           "5 - For delete all clients\n"
           "6 - For delete all cars\n"
           "7 - Return\n");
    scanf("%d", &n_delete);
    switch (n_delete) {
        case 1:
            deleteSupplier(SList);
            break;
        case 2:
            deleteClient(CList);
            break;
        case 3:
            deleteCar(CarList);
            break;
        case 4:
            deleteAllSuppliers(SList);
            break;
        case 5:
            deleteAllClients(CList);
            break;
        case 6:
            deleteAllCars(CarList);
            break;
        case 7:
            break;
        default:
            printf("Invalid option %d\n", n_delete);
            break;
    }
}

void menu(SupplierList **SList, ClientList **CList, CarList **CarList) {
    /* menu program for adding and getting details from all the structs*/
    int stop = 20;
    while (stop != 0) {
        printf("\nHello user \n"
               "Enter your choice :\n"
               "1  - For supplier\n"
               "2  - For client\n"
               "3  - For car\n"
               "4  - For client number with given car year\n"
               "5  - For car number with given capacity\n"
               "6  - For car number with given capacity REC\n"
               "7  - Three greatest supplier\n"
               "8  - Three greatest supplier REC\n"
               "9  - Print client cars for given rent date\n"
               "10 - Print Suppliers\n"
               "11 - For delete \n"
               "0 - For exit\n"
               " ---->");
        scanf("%d", &stop);
        switch (stop) {
            case 1:
                supplier(SList);
                break;
            case 2:
                client(CList);
                break;
            case 3:
                car(CarList);
                break;
            case 4:
                clientNumberWithGivenCarYear(CList, CarList);
                break;
            case 5:
                carNumberWithGivenCapacity(CarList);
                break;
            case 6:
                carNumberWithGivenCapacity_REC(*CarList, 0, *CarList);
                break;
            case 7:
                threeGreatestSuppliers(SList, threeGreatSupplier);
                break;
            case 8:
                threeGreatestSuppliers_REC(SList, threeGreatSupplier);
                break;
            case 9:
                printClientCarsForGivenRentDate(CList);
                break;
            case 10:
                printSuppliers(SList);
                break;
            case 11:
                delete(SList, CList, CarList);
                break;
            case 0:
                break;
            default:
                printf("Invalid option %d\n", stop);
                break;
        }
    }
}


int main() {
    ClientList *CList = createClientList();
    SupplierList *suppHead = createSupplierList();
    CarList *CarList = createCarList();
    menu(&suppHead, &CList, &CarList);
    deleteAllCars(&CarList);
    deleteAllClients(&CList);
    deleteAllSuppliers(&suppHead);
    check_for_exit();
    return 0;
}
