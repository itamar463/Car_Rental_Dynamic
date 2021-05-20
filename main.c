#include <stdio.h>
#include "Car.h"
#include "Client.h"
#include "Supplier.h"
int main() {
    List* head = createSupplierList();
    addNewSupplier(&head);
    addNewSupplier(&head);
    deleteSupplier(&head);


    deleteSupplier(&head);

    //addNewCar();

    print1(&head);
    //addNewClient();
    return 0;
}
