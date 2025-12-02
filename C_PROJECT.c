//......BUS TICKET BOOKING SYSTEM IN C......



// Including necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define maximum seats and name length
#define MAX_SEATS 30
#define MAX_NAME_LENGTH 50

// Structure to store booking details
struct Booking {
    char name[MAX_NAME_LENGTH];
    int seatNo;
    char source[MAX_NAME_LENGTH];
    char destination[MAX_NAME_LENGTH];
    char gender[10];
    int age;
    char phone[15];
    char date[15];
    float fare;
    char busType[20];
};

   // Array to store all bookings
   struct Booking bookings[MAX_SEATS];

   // Keeps count of how many seats have been booked
   int bookedSeats = 0;

   //BOOK SEAT FUNCTION
   void bookSeats() {
    if (bookedSeats >= MAX_SEATS) {
        printf("No more seats are available.\n");
        return;
    }

    struct Booking newBooking;

    //Take input from user
    printf("Enter name: ");
    scanf("%s", newBooking.name);

    printf("Enter seat number: ");
    scanf("%d", &newBooking.seatNo);

    printf("Enter source: ");
    scanf("%s", newBooking.source);
    
    printf("Enter destination: ");
    scanf("%s", newBooking.destination);
    
    printf("Enter gender: ");
    scanf("%s", newBooking.gender);
    
    printf("Enter age: ");
    scanf("%d", &newBooking.age);
    
    printf("Enter phone: ");
    scanf("%s", newBooking.phone);
    
    printf("Enter date (dd-mm-yyyy): ");
    scanf("%s", newBooking.date);

    printf("Enter bus type (AC / Non-AC / Sleeper): ");
    scanf("%s", newBooking.busType);
    
    float distance;
    printf("Enter the distance (in km): ");
    scanf("%f", &distance);
    
// Fare calculation
    if (strcmp(newBooking.busType, "AC") == 0) {
        newBooking.fare = distance * 8;
    } 
    else if (strcmp(newBooking.busType, "Non-AC") == 0) {
        newBooking.fare = distance * 5;
    } 
    else if (strcmp(newBooking.busType, "Sleeper") == 0) {
        newBooking.fare = distance * 10;
    } 
    else {
        printf("Unknown bus type! Using default rate.\n");
        newBooking.fare = distance * 6;
    }

    // Store booking in array
    bookings[bookedSeats++] = newBooking;

    printf("\nSeat booked successfully!\n");
}

   // VIEW ALL RESERVATIONS
   void viewReservations() {
    if (bookedSeats == 0) {
        printf("No reservations made yet.\n");
        return;
    }

    printf("\nAll reservations:\n ");
    printf("---------------------------------------------------------------------------------------------\n");
    printf(" SeatNo Name Source Destination Gender Age Phone Date Fare BusType\n");
    printf("---------------------------------------------------------------------------------------------\n");

    // Print all stored bookings
    for (int i = 0; i < bookedSeats; i++) {
        printf("%d %s %s %s %s %d %s %s %.2f %s\n", bookings[i].seatNo, bookings[i].name, bookings[i].source, 
            bookings[i].destination, bookings[i].gender, bookings[i].age, bookings[i].phone, bookings[i].date, bookings[i].fare, bookings[i].busType);
        }
    }

   // EDIT RESERVATION
   void editReservation() {
    
    int seat_To_Edit;
    printf("Enter seat number to edit: ");
    scanf("%d", &seat_To_Edit);

    int found = 0;

    // Search for seat
    for (int i = 0; i < bookedSeats; i++) {
       if (bookings[i].seatNo == seat_To_Edit) {

        found = 1;
        printf("\nEditing reservation for seat %d\n", seat_To_Edit);

            // Updating booking details
            printf("Enter new name: ");
            scanf("%s", bookings[i].name);

            printf("Enter new source: ");
            scanf("%s", bookings[i].source);

            printf("Enter new destination: ");
            scanf("%s", bookings[i].destination);

            printf("Enter new gender: ");
            scanf("%s", bookings[i].gender);

            printf("Enter new age: ");
            scanf("%d", &bookings[i].age);

            printf("Enter new phone: ");
            scanf("%s", bookings[i].phone);

            printf("Enter new date (dd-mm-yyyy): ");
            scanf("%s", bookings[i].date);

            printf("Enter new bus type (AC/Non-AC/Sleeper): ");
            scanf("%s", bookings[i].busType);

            float distance;
            printf("Enter new distance: ");
            scanf("%f", &distance);

            // Recalculate fare
            if (strcmp(bookings[i].busType, "AC") == 0)
                bookings[i].fare = distance * 8;
            else if (strcmp(bookings[i].busType, "Non-AC") == 0)
                bookings[i].fare = distance * 5;
            else if (strcmp(bookings[i].busType, "Sleeper") == 0)
                bookings[i].fare = distance * 10;
            else
                bookings[i].fare = distance * 6;
                        
            printf("\nReservation updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("No reservation found for seat number %d\n", seat_To_Edit);
    }
}

// PRINT TICKET
void printTicket() {
    int seat_To_Print;
    printf("Enter seat number to print ticket: ");
    scanf ("%d", &seat_To_Print);

    int found = 0;
     
    for (int i = 0; i < bookedSeats; i++) {
        if (bookings[i].seatNo == seat_To_Print) {
            found = 1;

            printf("\n=============================================\n");
            printf("              BUS TICKET DETAILS             \n");
            printf("=============================================\n");

            printf("Seat Number     : %d\n", bookings[i].seatNo);
            printf("Passenger Name  : %s\n", bookings[i].name);
            printf("Gender          : %s\n", bookings[i].gender);
            printf("Age             : %d\n", bookings[i].age);
            printf("Phone Number    : %s\n", bookings[i].phone);
            printf("Source          : %s\n", bookings[i].source);
            printf("Destination     : %s\n", bookings[i].destination);
            printf("Date of Journey : %s\n", bookings[i].date);
            printf("Bus Type        : %s\n", bookings[i].busType);
            printf("Fare            : %.2f\n", bookings[i].fare);

            printf("=============================================\n");
            printf("         Thank you for choosing us!          \n");
            printf("=============================================\n\n");

            break;
        }
    }

    if (!found) {
        printf("No reservation found for seat number %d\n", seat_To_Print);
    }
}

// MAIN FUNCTION
int main()
{
   int choice;
   do {
    printf("\nBUS TICKET BOOKING SYSTEM\n");
    printf("1. Book a seat\n");
    printf("2. View reservations\n");
    printf("3. Edit a reservation\n");
    printf("4. Print a ticket\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bookSeats();
            break;
        case 2:
            viewReservations();
            break;
        case 3:
            editReservation();
            break;
        case 4:
            printTicket();
            break;
        case 5:
            printf("exiting...");
            break;
        default:
            printf("Invalid choice. Please enter the valid option.");
    }
   } while (choice != 5);

   return 0;
}