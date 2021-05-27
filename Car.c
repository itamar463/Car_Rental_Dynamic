
#include "Car.h"

static unsigned int carCounter = 0;

CarList *createCarList() {
    /*init empty list */
    CarList *list = NULL;
    return list;
}

int valid_car(char *license_num, char *chassis_number, char *maker, char *model, char *color, int year_manufacture,
              int year_get_on_road,
              int price_that_paid, int present_car_price, int engine_cap) {
    /* check for car validation details by using functions from ValueChecker*/
    if ((check_equal_size(license_num, LICENSE_NUM_LEN) == 0) || (valid_digit_check(license_num) == 0)) {
        return 0;
    }
    if ((check_equal_size(chassis_number, CHASSIS_NUM_LEN) == 0) || (valid_digit_check(chassis_number) == 0)) {
        return 0;
    }
    if (valid_char_check(maker) == 0) {
        return 0;
    }
    if (valid_char_check(model) == 0) {
        return 0;
    }
    if (valid_char_check(maker) == 0) {
        return 0;
    }
    if (valid_char_check(color) == 0) {
        return 0;
    }

    if (valid_int(year_manufacture, 1930, 2022) == 0)return 0;
    if (valid_int(year_get_on_road, year_manufacture - 1, 2022) == 0)return 0;
    if (valid_int(price_that_paid, 0, 1000000) == 0)return 0;
    if (valid_int(present_car_price, 0, 1000000) == 0)return 0;
    if (valid_int(engine_cap, 1000, 10000) == 0)return 0;
    return 1;
}

Car *init_car() {
    /* init a Vehicle struct by given details*/
    Car *car = (Car *) checked_malloc(sizeof(Car));
    char license_number[LICENSE_NUM_LEN * 3];
    char chassis_number[CHASSIS_NUM_LEN * 3];
    char *maker = (char *) checked_malloc(sizeof(char) * 1024);
    char *model = (char *) checked_malloc(sizeof(char) * 1024);
    char *color = (char *) checked_malloc(sizeof(char) * 1024);
    int year_manufacture;
    int year_get_on_road;
    int price_that_paid;
    int present_car_price;
    int engine_cap;
    printf("Enter license number (7 digits) : \n");
    scanf("%s", license_number);
    printf("Enter chassis number (5 digits) : \n");
    scanf("%s", chassis_number);
    printf("Enter maker : \n");
    scanf("%s", maker);
    printf("Enter model : \n");
    scanf("%s", model);
    printf("Enter color :\n");
    scanf("%s", color);
    printf("Enter year of manufacture (number of 4 digits):\n");
    scanf("%d", &year_manufacture);
    printf("Enter price that paid for the car:\n");
    scanf("%d", &price_that_paid);
    printf("Enter year that car get on road (number of 4 digits):\n");
    scanf("%d", &year_get_on_road);
    printf("Enter present car price :\n");
    scanf("%d", &present_car_price);
    printf("Enter engine capacity (number of 4 digits):\n");
    scanf("%d", &engine_cap);
    if (valid_car(license_number, chassis_number, maker, model, color, year_manufacture, year_get_on_road,
                  price_that_paid,
                  present_car_price, engine_cap) == 0) {
        checked_free(model);
        checked_free(maker);
        checked_free(color);
        car = NULL;
        return car;
    }
    strcpy(car->license_number, license_number);
    strcpy(car->chassis_number, chassis_number);
    car->model = dupstr(model);
    car->maker = dupstr(maker);
    car->color = dupstr(color);
    car->year_manufacture = year_manufacture;
    car->year_get_on_road = year_get_on_road;
    car->present_car_price = present_car_price;
    car->price_that_paid = price_that_paid;
    car->engine_cap = engine_cap;
    return car;
}

int addCarToList(CarList **head) {
    /* add new car to list*/
    CarList *temp = (*head);
    CarList *prev;
    CarList *new = (CarList *) checked_malloc(sizeof(CarList));
    new->data = init_car();

    if (new->data == NULL) {
        checked_free(new->data);
        checked_free(new);
        return 0;
    }
    if (temp == NULL || new->data->year_manufacture < temp->data->year_manufacture) {
        new->next = (*head);
        (*head) = new;
        return 1;
    }
    while (temp != NULL && new->data->year_manufacture >= temp->data->year_manufacture) {
        prev = temp;
        temp = temp->next;
    }
    new->next = temp;
    prev->next = new;
    return 1;
}

int addNewCar(CarList **head) {
    /* if car is valid add new car to the list*/
    int check = addCarToList(head);
    if (check != 1) {
        printf("car not added\n");
        return FALSE;
    }
    carCounter++;
    return 1;
}


int deleteCar(CarList **head) {
    /*delete car from list by given license number */
    CarList *temp = (*head);
    CarList *prev;
    char deleteCarCheck[LICENSE_NUM_LEN + 1];
    printf("enter license number : \n");
    scanf("%s", deleteCarCheck);
    if (temp != NULL && strcmp(temp->data->license_number, deleteCarCheck) == 0) {
        (*head) = temp->next;
        checked_free(temp->data->model);
        checked_free(temp->data->maker);
        checked_free(temp->data->color);
        checked_free(temp->data);
        checked_free(temp);
    }
    while (temp != NULL && strcmp(temp->data->license_number, deleteCarCheck) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return 0;
    prev->next = temp->next;
    checked_free(temp->data->model);
    checked_free(temp->data->maker);
    checked_free(temp->data->color);
    checked_free(temp->data);
    checked_free(temp);
    return 1;
}

void remove_first_from_list(CarList **head) {
    /*delete first car from list */
    CarList *temp;
    CarList *prev = (*head);
    temp = (*head)->next;
    checked_free(prev->data->model);
    checked_free(prev->data->maker);
    checked_free(prev->data->color);
    checked_free(prev->data);
    checked_free(prev);
    *head = temp;
}

int deleteAllCars(CarList **head) {
    /* delete all cars */
    while (*head != NULL) {
        remove_first_from_list(head);
    }
    return 1;
}

int inverseCarList(CarList **head) {
    /*inverse the sort of the list */
    CarList *prev = NULL;
    CarList *current = *head;
    CarList *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    return 1;
}

int carNumberWithGivenCapacity(CarList **head) {
    /*return the number of cars with the same capacity */
    int capacityCheck;
    int counter = 0;
    CarList *temp = (*head);
    printf("Enter engine capacity: \n");
    scanf("%d", &capacityCheck);
    while (temp != NULL) {
        if (temp->data->engine_cap == capacityCheck) {
            counter++;
        }
        temp = temp->next;
    }
    printf("The number of cars with the same capacity : %d\n", counter);
    return counter;
}

int carNumberWithGivenCapacity_REC(CarList *head, int *capacityCheck, CarList *baseHead) {
    /*return number of cars with the same capacity */
    if (head == baseHead) {
        printf("Enter engine capacity: \n");
        scanf("%d", capacityCheck);
    }
    if (head == NULL) {
        return 0;
    }
    if (head->data->engine_cap == (*capacityCheck)) {
        return 1 + carNumberWithGivenCapacity_REC(head->next, capacityCheck, baseHead);
    } else return 0 + carNumberWithGivenCapacity_REC(head->next, capacityCheck, baseHead);

}
