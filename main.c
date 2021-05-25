#include <stdio.h>
#include "Car.h"
#include "Client.h"
#include "Supplier.h"
int main() {
    int  num;
    SupplierList* suppHead = createSupplierList();
    CarList* head = createCarList();
    //addNewCar(&head);
    //addNewCar(&head);
    //addNewCar(&head);
    //int x = carNumberWithGivenCapacity_REC(head,&num,head);
    //printf("%d",x);
//    deleteCar(&head);
//    deleteAllCars(&head);
//    List* head = createSupplierList();3
//    addNewSupplier(&head);
//    addNewSupplier(&head);
//    deleteAllSuppliers(&head);
    addNewSupplier(&suppHead);
    addNewSupplier(&suppHead);
    threeGreatestSuppliers(&suppHead);
    //deleteSupplier(&head);
    //addNewCar();
//    print1(&head);
    //addNewClient();
    return 0;
}
