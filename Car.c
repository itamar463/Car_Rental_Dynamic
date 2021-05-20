
#include "Car.h"

int valid_car(char *license_num, char *chassis_number, char *maker, char *model, char *color, int year_manufacture,
              int year_get_on_road,
              int price_that_paid, int present_car_price, int engine_cap) {
    /* check for car validation details by using functions from ValueChecker*/
    if ((check_equal_size(license_num, LICENSE_NUM_LEN) == 0) || (valid_digit_check(license_num) == 0)) {
        printf("License number is not valid!\n");
        return 0;
    }
    if ((check_equal_size(chassis_number, CHASSIS_NUM_LEN) == 0) || (valid_digit_check(chassis_number) == 0)) {
        printf("Chassis number is not valid!\n");
        return 0;
    }
    if (valid_char_check(maker) == 0) {
        printf("Maker not valid\n");
        return 0;
    }
    if (valid_char_check(model) == 0) {
        return 0;
    }
    if (valid_char_check(maker) == 0) {
        return 0;
    }
    if (valid_char_check(color) == 0) {
        printf("Color not valid\n");
        return 0;
    }

    if (valid_int(year_manufacture, 1930, 2022) == 0)return 0;
    if (valid_int(year_get_on_road, year_manufacture - 1, 2022) == 0)return 0;
    if (valid_int(price_that_paid, 0, 1000000) == 0)return 0;
    if (valid_int(present_car_price, 0, 1000000) == 0)return 0;
    if (valid_int(engine_cap, 1000, 10000) == 0)return 0;
    return 1;
}

Car init_car() {
    /* init a Vehicle struct by given details*/
    Car car;
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
        car.year_manufacture = -1;
        return car;
    }
    strcpy(car.license_number, license_number);
    strcpy(car.chassis_number, chassis_number);
    car.model = dupstr(model);
    car.maker = dupstr(maker);
    car.color = dupstr(color);
    car.year_manufacture = year_manufacture;
    car.year_get_on_road = year_get_on_road;
    car.present_car_price = present_car_price;
    car.price_that_paid = price_that_paid;
    car.engine_cap = engine_cap;
    return car;
}

int addNewCar() {
    /* add new car to the list*/
    Car car = init_car();

    return 1;
}