
#include "Client.h"
Date create_date(int year, int month, int day) {
    /*Creating a date by given details*/
    Date today;
    if (date_valid(year, month, day) == 0) {
        today.year = -1;
        today.month = -1;
        today.day = -1;
    } else {
        today.year = year;
        today.month = month;
        today.day = day;
    }
    return today;
}

void print_date(Date d) {
    /*printing format for Date*/
    smaller_than_ten(d.day);
    printf("%d/", d.day);
    smaller_than_ten(d.month);
    printf("%d/%d\n", d.month, d.year);
}

Time create_time(int hour, int minute) {
    /* create Time struct by given details*/
    Time current_hour;
    if (time_valid(hour, minute) == 0) {
        current_hour.hour = -1;
        current_hour.minute = -1;
    } else {
        current_hour.hour = hour;
        current_hour.minute = minute;
    }
    return current_hour;
}

void print_time(Time t) {
    /* print Time format*/
    smaller_than_ten(t.hour);
    printf("%d:", t.hour);
    smaller_than_ten(t.minute);
    printf("%d\n", t.minute);
}

int client_valid(char *first_name, char *last_name, char *id, char *license_number, int price_per_rent, Date date,
                 Time time) {
    /* check for Client validation using functions from ValueChecker*/
    if (valid_char_check(first_name) == 0){
        printf("Name not valid\n");
        return 0;
    }
    if (valid_char_check(last_name) == 0){
        printf("Last name not valid\n");
        return 0;
    }
    if (valid_digit_check(id) == 0 || check_equal_size(id,ID_LEN)==0){
        printf("ID not valid\n");
        return 0;
    }
    if (valid_digit_check(license_number) == 0 || check_equal_size(license_number,LICENSE_LEN)==0){
        printf("License number not valid\n");
        return 0;
    }
    if (date.year == -1){
        printf("Date not valid\n");
        return 0;
    }
    if (time.hour == -1){
        printf("Time not valid\n");
        return 0;
    }
    if (valid_int(price_per_rent, 100, 999) == 0){
        printf("Price not valid\n");
        return 0;
    }
    return 1;
}

Client init_client() {
    /*init Client by given details and using of client_valid func*/
    Client client;
    char id[ID_LEN * 3];
    char license_num[LICENSE_LEN * 3];
    char *first_name = (char *) checked_malloc(sizeof(char) * 1024);
    char *last_name = (char *) checked_malloc(sizeof(char) * 1024);
    Date date_of_rent;
    int year, month, day, hour, minute;
    Time time_of_rent;
    int price_per_rent;
    printf("Enter ID (9 digits): \n");
    scanf("%s", id);
    printf("Enter first name: \n");
    scanf("%s", first_name);
    printf("Enter last name: \n");
    scanf("%s", last_name);
    printf("Enter license number (7 digits): \n");
    scanf("%s", license_num);
    printf("Enter date: year , month , day\n");
    scanf("%d %d %d", &year, &month, &day);
    printf("Enter time: hour , minute\n");
    scanf("%d %d", &hour, &minute);
    printf("Enter price per rent for 24 hours (number of 3 digits): \n");
    scanf("%d", &price_per_rent);
//    if (strlen(id) != ID_LEN)strcpy(client.id, "");
//    else strcpy(client.id, id);
//    if (strlen(first_name) > FIRST_NAME_LEN)strcpy(client.first_name, "");
//    else strcpy(client.first_name, first_name);
//    if (strlen(last_name) > LAST_NAME_LEN)strcpy(client.last_name, "");
//    else strcpy(client.last_name, last_name);
//    if (strlen(license_num) > LICENSE_LEN)strcpy(client.license_number, "");
//    else strcpy(client.license_number, license_num);
//    client.price_per_rent = price_per_rent;
    date_of_rent = create_date(year, month, day);
    time_of_rent = create_time(hour, minute);
    client.date_of_rent = date_of_rent;
    client.hour_of_rent = time_of_rent;
    if (client_valid(first_name,last_name,id,license_num,
                     price_per_rent, date_of_rent, time_of_rent) == 0){
        client.price_per_rent = -1;
        return client;
    }
    client.first_name = dupstr(first_name);
    client.last_name = dupstr(last_name);
    strcpy(client.id,id);
    strcpy(client.license_number,license_num);
    client.date_of_rent = date_of_rent;
    client.hour_of_rent = time_of_rent;
    client.price_per_rent = price_per_rent;
    return client;

}
int addNewClient() {
    /* add a new Client to the clientList by using helper functions*/
    Client check = init_client();
    return 1;

}