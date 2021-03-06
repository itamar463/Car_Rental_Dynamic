
#include "Client.h"

Date create_date(int year, int month, int day) {
    /*CREATING A DATE BY GIVEN DETAILS RETURN TRUE IF SUCCEED ELSE FALSE*/
    Date today = {0, 0, 0};
    if (date_valid(year, month, day) == FALSE) {
        printf("date not valid \n");
        return today;
    } else {
        today.year = year;
        today.month = month;
        today.day = day;
    }
    return today;
}

Time create_time(int hour, int minute) {
    /*CREATING A TIME STRUCT BY GIVEN DETAILS RETURN TRUE IF SUCCEED ELSE FALSE*/
    Time current_hour = {0, 0};
    if (time_valid(hour, minute) == FALSE) {
        printf("time not valid \n");
        return current_hour;
    } else {
        current_hour.hour = hour;
        current_hour.minute = minute;
    }
    return current_hour;
}

void print_date(Date d) {
    /*PRINTING DATE FORMAT*/
    smaller_than_ten(d.day);
    printf("%d/", d.day);
    smaller_than_ten(d.month);
    printf("%d/%d\n", d.month, d.year);
}

void print_time(Time t) {
    /*PRINTING TIME FORMAT*/
    smaller_than_ten(t.hour);
    printf("%d:", t.hour);
    smaller_than_ten(t.minute);
    printf("%d\n", t.minute);
}

int client_valid(char *first_name, char *last_name, char *id, char *license_number, int price_per_rent) {
    /*CHECK FOR CLIENT VALIDATION USING FUNCTION FROM ValueChecker*/
    if (valid_char_check(first_name) == FALSE) {
        return FALSE;
    }
    if (valid_char_check(last_name) == FALSE) {
        return FALSE;
    }
    if (valid_digit_check(id) == FALSE || check_equal_size(id, ID_LEN) == FALSE) {
        return FALSE;
    }
    if (valid_digit_check(license_number) == FALSE || check_equal_size(license_number, LICENSE_LEN) == FALSE) {
        return FALSE;
    }
    if (valid_int(price_per_rent, 100, 999) == FALSE) {
        return FALSE;
    }
    return TRUE;
}

ClientList *createClientList() {
    /*CREATE CLIENT LIST*/
    ClientList *ClientList = NULL;
    return ClientList;
}

Client *initClient() {
    /*INIT CLIENT BY GIVEN DETAILS AND USING client_valid func*/
    Client *client = (Client *) checked_malloc(sizeof(Client));
    char id[ID_LEN * 3];
    char license_num[LICENSE_LEN * 3];
    char *first_name = (char *) checked_malloc(sizeof(char) * 1024);
    char *last_name = (char *) checked_malloc(sizeof(char) * 1024);
    Date date_of_rent;
    int year, month, day, hour, minute;
    Time time_of_rent;
    int price_per_rent;
    printf("NEW CLIENT : \n");
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
    date_of_rent = create_date(year, month, day);
    time_of_rent = create_time(hour, minute);

    if (client_valid(first_name, last_name, id, license_num,
                     price_per_rent) == TRUE && date_of_rent.day != 0 && time_of_rent.hour != 0) {
        strcpy(client->id, id);
        strcpy(client->license_number, license_num);
        client->first_name = dupstr(first_name);
        client->last_name = dupstr(last_name);
        client->date_of_rent = date_of_rent;
        client->hour_of_rent = time_of_rent;
        client->price_per_rent = price_per_rent;
        return client;
    } else {
        strcpy(client->id, "-1");
        checked_free(first_name);
        checked_free(last_name);

    }
    return client;


}

int addToListC(ClientList **ClientHead) {
    /*CREATE CLIENT LIST AND CLIENT STRUCT AND ADD TO THE LINKED LIST */
    ClientList *new;
    new = (ClientList *) checked_malloc(sizeof(ClientList));
    new->data = initClient();
    if (strcmp(new->data->id, "-1") == 0) {
        checked_free(new->data);
        checked_free(new);
        return FALSE;
    }
    new->next = *ClientHead;
    *ClientHead = new;
    return TRUE;
}

int addNewClient(ClientList **ClientHead) {
    /*ADD A NEW CLIENT TO CLIENT LIST BY HELPER FUNCTIONS*/
    int check = addToListC(ClientHead);
    if (check == FALSE) {
        printf("client not added\n");
        return FALSE;
    }
    return TRUE;
}

int deleteAllClients(ClientList **ClientHead) {
    /*REMOVE ALL THE CLIENTS*/
    ClientList *temp = (*ClientHead);
    while (*ClientHead != NULL) {
        temp = *ClientHead;
        *ClientHead = temp->next;
        checked_free(temp->data->last_name);
        checked_free(temp->data->first_name);
        checked_free(temp->data);
        checked_free(temp);
    }
    printf("ALL CLIENTS REMOVED\n");
    return TRUE;
}

int deleteClient(ClientList **ClientHead) {
    /*REMOVE CLIENT BY GIVEN ID CLIENT*/
    ClientList *temp = (*ClientHead);
    ClientList *prev;
    char deleteClient[ID_LEN + 1];
    printf("Enter id client to remove : ");
    scanf("%s", deleteClient);
    if (temp != NULL && strcmp(temp->data->id, deleteClient) == 0) {
        (*ClientHead) = temp->next;
        checked_free(temp->data->last_name);
        checked_free(temp->data->first_name);
        checked_free(temp->data);
        checked_free(temp);
        printf("CLIENT REMOVED\n");
        return 1;
    }
    while (temp != NULL && (strcmp(deleteClient, temp->data->id) != 0)) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("CLIENT NOT FOUND\n");
        return FALSE;
    }
    prev->next = temp->next;
    checked_free(temp->data->last_name);
    checked_free(temp->data->first_name);
    checked_free(temp->data);
    checked_free(temp);
    printf("CLIENT REMOVED\n");
    return TRUE;
}
