#include <stdio.h>
#include "Supplier.h"
#include "Client.h"
#include "Car.h"
#include "Common.h"

void client(ClientList **CList) {
    /* ask for how many clients would the user add for the list*/
    int check;
    int i;
    int n_supplier;
    printf("How many clients you want to add ? : ");
    scanf("%d", &n_supplier);
    for (i = 0; i < n_supplier; ++i) {
        printf("\nCLIENT: \n");
        check = addNewClient(CList);
        if (check == 0) i--;
    }
}

void supplier(SupplierList **list) {
    /* ask for how many suppliers would the user add for the list*/
    int n_supplier;
    int i;
    int check;
    printf("How many supplier you want to add ? : ");
    scanf("%d", &n_supplier);
    for (i = 0; i < n_supplier; ++i) {
        printf("\nSUPPLIER: \n");
        check = addNewSupplier(list);
        if (check == 0)i--;
    }
}

void car(CarList **CarList) {
    /* ask for how many cars would the user add for the list*/
    int n_car;
    int check;
    int i;
    printf("How many cars you want to add ? : ");
    scanf("%d", &n_car);
    for (i = 0; i < n_car; ++i) {
        printf("\nCAR: \n");
        check = addNewCar(CarList);
        if (check == 0) { i--; }
    }
}

void delete(SupplierList **SList, ClientList **CList, CarList **CarList) {
    /* menu for delete options*/
    int n_delete = 9;
    while (n_delete != 0) {
        printf("\n Enter your choice:\n"
               "1 - For delete supplier\n"
               "2 - For delete client\n"
               "3 - For delete car\n"
               "4 - For delete all suppliers\n"
               "5 - For delete all clients\n"
               "6 - For delete all cars\n"
               "0 - Return\n");
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
            case 0:
                break;
            default:
                printf("Invalid option %d\n", n_delete);
                break;
        }
    }
}

void menu(SupplierList **SList, ClientList **CList, CarList **CarList) {
    /* menu program for adding and getting details from all the structs*/
    char threeGreatSupplier[3][11];
    int counter = 0;
    int stop = 20;
    while (stop != 0) {
        printf("----------------------------------");
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
                counter = carNumberWithGivenCapacity_REC(*CarList, &counter, *CarList);
                printf("The number of cars with the same capacity : %d\n", counter);
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
    /* FOR SAFETY*/
    deleteAllCars(&CarList);
    deleteAllClients(&CList);
    deleteAllSuppliers(&suppHead);
    check_for_exit();
    return 0;
}

