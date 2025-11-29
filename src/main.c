#include <stdio.h>
#include <stdlib.h>
#include "utc.h"   // Include header file for UTC function declarations

/*
 * main.c
 * 
 * This file contains the menu-driven interface for the Universal Time Clock project.
 * It interacts with the user, accepts input, and calls the appropriate functions
 * from utc.c to perform time conversions or display the system's current UTC time.
 */

int main() {
    int choice;                    // Stores user menu choice
    int hour, minute, second;      // Stores input time from user
    int out_h, out_m, out_s;       // Stores converted output time

    while (1) {  // Infinite loop so the menu keeps showing until user exits
        printf("\n======= UNIVERSAL TIME CLOCK (UTC) =======\n");
        printf("1. Show Current System Time in UTC\n");
        printf("2. Convert Local Time (IST) to UTC\n");
        printf("3. Convert UTC to Local Time (IST)\n");
        printf("4. Exit\n");
        printf("-----------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            // Option 1: Display system time in UTC
            case 1:
                showCurrentUTC();
                break;

            // Option 2: Convert Local IST to UTC
            case 2:
                printf("Enter Local Time (HH MM SS): ");
                scanf("%d %d %d", &hour, &minute, &second);

                // Validate the time input
                if (!validate_time(hour, minute, second)) {
                    printf("Invalid time format! Please enter a valid HH MM SS.\n");
                    break;
                }

                convertLocalToUTC(hour, minute, second, &out_h, &out_m, &out_s);

                printf("UTC Time: %02d:%02d:%02d\n", out_h, out_m, out_s);
                break;

            // Option 3: Convert UTC to IST
            case 3:
                printf("Enter UTC Time (HH MM SS): ");
                scanf("%d %d %d", &hour, &minute, &second);

                // Validate the time input
                if (!validate_time(hour, minute, second)) {
                    printf("Invalid time format! Please enter a valid HH MM SS.\n");
                    break;
                }

                convertUTCToLocal(hour, minute, second, &out_h, &out_m, &out_s);

                printf("Local Time (IST): %02d:%02d:%02d\n", out_h, out_m, out_s);
                break;

            // Option 4: Exit program
            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid option! Please enter 1–4.\n");
        }
    }

    return 0;   // Program ends (although logically never reached due to infinite loop)
}
