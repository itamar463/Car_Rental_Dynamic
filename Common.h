
#ifndef CAR_RENTAL_DYNAMIC_COMMON_H
#define CAR_RENTAL_DYNAMIC_COMMON_H
#define DAVIS
#include <stdio.h>
#include "Car.h"
#include "Supplier.h"
#include "Client.h"
int compareCharacters(char a,char b) ;
int clientNumberWithGivenCarYear(ClientList **ClientHead  , CarList **CarList1);
#ifdef DAVIS
int printSuppliers(SupplierList** head);
int printClientCarsForGivenRentDate(ClientList** head);
#endif
#endif //CAR_RENTAL_DYNAMIC_COMMON_H
