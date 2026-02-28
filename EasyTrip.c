#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 3
#define MAX_PASSENGERS 50
#define MAX_USERS 2

struct Bus {
    int busNumber;
    char source[50];
    char destination[50];
    int totalSeats;
    int availableSeats;
    float fare;
};

struct Passenger {
    char name[50];
    int age;
    int seatNumber;
    int busNumber;
};

struct User {
    char username[50];
    char password[50];
};

/* Function Prototypes */
void displayMainMenu();
void displayUserMenu();
int loginUser(struct User users[], int numUsers, char username[], char password[]);
void bookTicket(struct Bus buses[], int numBuses, struct Passenger passengers[], int *numPassengers);
void cancelTicket(struct Bus buses[], int numBuses, struct Passenger passengers[], int *numPassengers);
void checkBusStatus(struct Bus buses[], int numBuses);

int main() {
    struct User users[MAX_USERS] = {
        {"admin", "1234"},
        {"user", "1111"}
    };

    struct Bus buses[MAX_BUSES] = {
        {101, "Chennai", "Trichy", 40, 40, 350.0},
        {102, "Madurai", "Coimbatore", 30, 30, 300.0},
        {103, "Salem", "Bangalore", 35, 35, 450.0}
    };

    struct Passenger passengers[MAX_PASSENGERS];
    int numPassengers = 0;
    int loggedIn = -1;
    int choice;

    while (1) {
        if (loggedIn == -1) {
            displayMainMenu();
            scanf("%d", &choice);

            if (choice == 1) {
                char username[50], password[50];
                printf("Enter Username: ");
                scanf("%s", username);
                printf("Enter Password: ");
                scanf("%s", password);

                loggedIn = loginUser(users, MAX_USERS, username, password);

                if (loggedIn == -1)
                    printf("Login Failed!\n");
                else
                    printf("Login Successful!\n");
            } 
            else if (choice == 2) {
                printf("Exiting Program...\n");
                break;
            } 
            else {
                printf("Invalid Choice!\n");
            }
        } 
        else {
            displayUserMenu();
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    bookTicket(buses, MAX_BUSES, passengers, &numPassengers);
                    break;
                case 2:
                    cancelTicket(buses, MAX_BUSES, passengers, &numPassengers);
                    break;
                case 3:
                    checkBusStatus(buses, MAX_BUSES);
                    break;
                case 4:
                    printf("Logged out successfully.\n");
                    loggedIn = -1;
                    break;
                default:
                    printf("Invalid Choice!\n");
            }
        }
    }

    return 0;
}

/* Functions */

void displayMainMenu() {
    printf("\n=== Bus Reservation System ===\n");
    printf("1. Login\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
}

void displayUserMenu() {
    printf("\n=== User Menu ===\n");
    printf("1. Book Ticket\n");
    printf("2. Cancel Ticket\n");
    printf("3. Check Bus Status\n");
    printf("4. Logout\n");
    printf("Enter your choice: ");
}

int loginUser(struct User users[], int numUsers, char username[], char password[]) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            return i;
        }
    }
    return -1;
}

void bookTicket(struct Bus buses[], int numBuses, struct Passenger passengers[], int *numPassengers) {
    int busNumber;
    printf("Enter Bus Number: ");
    scanf("%d", &busNumber);

    int busIndex = -1;
    for (int i = 0; i < numBuses; i++) {
        if (buses[i].busNumber == busNumber) {
            busIndex = i;
            break;
        }
    }

    if (busIndex == -1) {
        printf("Bus not found!\n");
        return;
    }

    if (buses[busIndex].availableSeats == 0) {
        printf("No seats available!\n");
        return;
    }

    printf("Enter Passenger Name: ");
    scanf("%s", passengers[*numPassengers].name);

    printf("Enter Passenger Age: ");
    scanf("%d", &passengers[*numPassengers].age);

    passengers[*numPassengers].seatNumber =
        buses[busIndex].totalSeats - buses[busIndex].availableSeats + 1;
    passengers[*numPassengers].busNumber = busNumber;

    buses[busIndex].availableSeats--;

    printf("Ticket Booked Successfully!\n");
    printf("Seat Number: %d\n", passengers[*numPassengers].seatNumber);

    (*numPassengers)++;
}

void cancelTicket(struct Bus buses[], int numBuses, struct Passenger passengers[], int *numPassengers) {
    char name[50];
    printf("Enter Passenger Name to Cancel Ticket: ");
    scanf("%s", name);

    int found = 0;

    for (int i = 0; i < *numPassengers; i++) {
        if (strcmp(passengers[i].name, name) == 0) {
            for (int j = 0; j < numBuses; j++) {
                if (buses[j].busNumber == passengers[i].busNumber) {
                    buses[j].availableSeats++;
                    break;
                }
            }

            for (int k = i; k < (*numPassengers) - 1; k++) {
                passengers[k] = passengers[k + 1];
            }

            (*numPassengers)--;
            found = 1;
            printf("Ticket Cancelled Successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Passenger not found!\n");
    }
}

void checkBusStatus(struct Bus buses[], int numBuses) {
    for (int i = 0; i < numBuses; i++) {
        printf("\nBus Number: %d", buses[i].busNumber);
        printf("\nSource: %s", buses[i].source);
        printf("\nDestination: %s", buses[i].destination);
        printf("\nTotal Seats: %d", buses[i].totalSeats);
        printf("\nAvailable Seats: %d", buses[i].availableSeats);
        printf("\nFare: %.2f\n", buses[i].fare);
    }
}
