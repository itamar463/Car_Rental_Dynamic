#include <stdio.h>
#include "Car.h"
#include "Client.h"
#include "Supplier.h"
int main() {
    List* head = createSupplierList();
    addNewSupplier(&head);
    addNewSupplier(&head);
    printf("%s",head->data->supplier_name);
    //addNewCar();
    //addNewClient();
    return 0;
}
