
#include "Client.h"
Date create_date(int year, int month, int day) {
    /*CREATING A DATE BY GIVEN DETAILS RETURN TRUE IF SUCCEED ELSE FALSE*/
    Date today = { 0 , 0 , 0};
    if (date_valid(year, month, day) == 0) {
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
    /* create Time struct by given details*/
    Time current_hour = { 0 , 0};
    if (time_valid(hour, minute) == 0) {
        printf("time not valid \n");
        return current_hour;
    }
    else {
        current_hour.hour = hour;
        current_hour.minute = minute;
    }
    return current_hour;
}

void print_date(Date d) {
    /*printing format for Date*/
    smaller_than_ten(d.day);
    printf("%d/", d.day);
    smaller_than_ten(d.month);
    printf("%d/%d\n", d.month, d.year);
}
void print_time(Time t) {
    /* print Time format*/
    smaller_than_ten(t.hour);
    printf("%d:", t.hour);
    smaller_than_ten(t.minute);
    printf("%d\n", t.minute);
}
int printClientCarsForGivenRentDate(ClientList** ClientHead){
    ClientList *temp = *ClientHead;
    if(temp == NULL){
        printf("THERE NO CLIENTS\n");
        return 0;
    }
    int year, month, day;
    printf("Enter date: year , month , day\n");
    scanf("%d %d %d", &year, &month, &day);
    if (date_valid(year, month, day) == 0) {
        printf("date not valid \n");
        return 0;}

    while(temp != NULL){
        if(temp->data->date_of_rent.day == day && temp->data->date_of_rent.year == year &&
           temp->data->date_of_rent.month == month ){
            printf("CLIENT :\n"
                   "first name : %s\n"
                   "last name : %s\n"
                   "id : %s\n"
                   "car licence nuber : %s\n"
                   "rent price for 24 hours : %d \n",temp->data->first_name , temp->data->last_name
                    , temp->data->id , temp->data->license_number , temp->data->price_per_rent);
            printf("rent date : ");
            print_date(temp->data->date_of_rent);
            printf("rent time : ");
            print_time(temp->data->hour_of_rent);
            temp =  temp->next;
        }
    }
    return 1;
}

int client_valid(char *first_name, char *last_name, char *id, char *license_number, int price_per_rent) {
    /* check for Client validation using functions from ValueChecker*/
    if (valid_char_check(first_name) == 0){
        return 0;
    }
    if (valid_char_check(last_name) == 0){
        return 0;
    }
    if (valid_digit_check(id) == 0 || check_equal_size(id,ID_LEN)==0){
        return 0;
    }
    if (valid_digit_check(license_number) == 0 || check_equal_size(license_number,LICENSE_LEN)==0){
        return 0;
    }
    if (valid_int(price_per_rent, 100, 999) == 0){
        return 0;
    }
    return 1;
}

ClientList *createClientList() {
    ClientList *ClientList = NULL;
    return ClientList;
}

Client *initClient() {
    /*init Client by given details and using of client_valid func*/
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

    if (client_valid(first_name,last_name,id,license_num,
                     price_per_rent) == 1 && date_of_rent.day !=0 && time_of_rent.hour!= 0){
        strcpy(client->id,id);
        strcpy(client->license_number,license_num);
        client->first_name = dupstr(first_name);
        client->last_name = dupstr(last_name);
        client->date_of_rent = date_of_rent;
        client->hour_of_rent = time_of_rent;
        client->price_per_rent = price_per_rent;
        return  client;}
    strcpy( client->id  , "-1");
    return client;


}
int addToListC(ClientList **ClientHead) {
    ClientList *new;
    new = (ClientList *) checked_malloc(sizeof(ClientList));
    new->data = initClient();
    if (strcmp(new->data->id ,"-1") ==0) {
        checked_free(new->data->first_name);
        checked_free(new->data->last_name);
        checked_free(new);
        return 0;
    }
    new->next = *ClientHead;
    *ClientHead = new;
    return 1;
}
int addNewClient(ClientList** ClientHead) {
    /* add a new Client to the clientList by using helper functions*/
    int check = addToListC(ClientHead);
    if(check!= 1){
        printf("client not added\n");
    }
    return 1;
}

int deleteAllClients(ClientList** ClientHead){
    ClientList *curr = (*ClientHead);
    ClientList *temp = (*ClientHead);
    while(curr != NULL){
        temp=curr;
        curr = curr->next;
        checked_free(temp->data->last_name);
        checked_free(temp->data->first_name);
        checked_free(temp->data);
        checked_free(temp);}
    printf("ALL CLIENTS REMOVED\n");
    return 1;
}
int deleteClient(ClientList** ClientHead){
    ClientList* temp = (*ClientHead);
    ClientList* prev;
    char deleteClient[ID_LEN+1];
    printf("Enter id client to remove : ");
    scanf("%s" , deleteClient);
    if (temp != NULL && strcmp(temp->data->id,deleteClient)==0){
        (*ClientHead) = temp->next;
        checked_free(temp->data->last_name);
        checked_free(temp->data->first_name);
        checked_free(temp->data);
        checked_free(temp);
        printf("CLIENT REMOVED\n");
        return 1;
    }
    while (temp != NULL && (strcmp(deleteClient , temp->data->id) != 0)) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        printf("CLIENT NOT FOUND\n");
        return 0;
    }
    prev->next = temp->next;
    checked_free(temp->data->last_name);
    checked_free(temp->data->first_name);
    checked_free(temp->data);
    checked_free(temp);
    printf("CLIENT REMOVED\n");
    return 1;
}
