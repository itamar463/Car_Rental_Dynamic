

#ifndef CAR_RENTAL_DYNAMIC_COMMON_H
#define CAR_RENTAL_DYNAMIC_COMMON_H

#include <stdio.h>
#include "Car.h"
#include "Supplier.h"
#include "Client.h"
#define DAVIS
int clientNumberWithGivenCarYear(ClientList **ClientHead  , CarList **CarList1);
#ifdef DAVIS
int printClientCarsForGivenRentDate(ClientList** ClientHead);
int printSuppliers(SupplierList** head);
#endif


#endif /*CAR_RENTAL_DYNAMIC_COMMON_H*/
