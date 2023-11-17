#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TRAINS 5
struct train {
    char name[50];
    char from_station[30];
    char to_station[30];
    char times[15];
    int num_passengers;
    int max_capacity;
    float ticket_price;
};
struct train trains[MAX_TRAINS];
int num_trains = 0;

void add_train() {
    if (num_trains >= MAX_TRAINS) {
        printf("Cannot add more trains, limit reached.\n");
        return;
    }
    struct train new_train;
    printf("Enter train name: ");
    scanf("%s", new_train.name);
    printf("Enter From Statiom: ");
    fflush(stdin);
    gets(new_train.from_station);
     printf("Enter To Statiom: ");
    fflush(stdin);
    gets(new_train.to_station);
    printf("Enter times: ");
    gets(new_train.times);
    printf("Enter maximum capacity: ");
    scanf("%d", &new_train.max_capacity);

    printf("Enter ticket price: ");
    scanf("%f", &new_train.ticket_price);
    new_train.num_passengers = 200;

    trains[num_trains] = new_train;
    num_trains++;
     printf("\n\n ");
    printf("**Train added successfully**\n");
}

void display_train(struct train t) {
    printf("Train Name: %s\n", t.name);
    printf("From Station:%s\n ",t.from_station);
    printf("To Station:%s\n ",t.to_station);
    printf("Times :%s\n ",t.times);
    printf("Number of passengers: %d\n", t.num_passengers);
    printf("Maximum capacity: %d\n", t.max_capacity);
    printf("Ticket price: %.2f\n", t.ticket_price);

}

void view_trains() {
    if (num_trains == 0) {
        printf("No trains added yet.\n");
        return;
    }

    printf("List of trains:\n");
    for (int i = 0; i < num_trains; i++) {
        printf("Train %d:\n", i+1);
        display_train(trains[i]);
        printf("\n");
    }
}

void book_ticket() {
    char pass_name[20];
    char mub_number[11];
    char identi_number[15];
    if (num_trains == 0) {
        printf("No trains added yet.\n");
        return;
    }
      printf("**Passenger Information:** \n\n");
      printf(" Name:");
      fflush(stdin);
      gets(&pass_name);
      printf(" Identification Number :");
      scanf("%s",&identi_number);
      printf("Mobile Number :");
      scanf("%s", &mub_number);
     printf("Enter train number to book ticket: ");
     int train_number;
    scanf("%d", &train_number);


   if (train_number < 1 || train_number > num_trains) {
        printf("Invalid train number.\n");
        return;
    }

    struct train *selected_train = &trains[train_number-1];

    if (selected_train->num_passengers >= selected_train->max_capacity) {

        printf("Train is full. Cannot book more tickets.\n");
        return;
    }

    selected_train->num_passengers++;
       printf(" Welcome Bangladesh Railway:\n\n");
        printf(" Name:%s\n",pass_name);
        printf(" Identification Number :%s\n",identi_number);
        printf("Mobile Number :%s\n",mub_number);
    printf("Ticket booked successfully.\n");
}

int main() {
    while (1) {
        printf("\t\t\tTrain Management System\n");
        printf("\t\t\t-----------------------\n");
        printf("1. Add Train\n");
        printf("2. View Trains\n");
        printf("3. Book Ticket\n");
        printf("4. Exit\n\n\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_train();
                break;
            case 2:
                view_trains();
                break;
            case 3:
                book_ticket();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}


