#include <stdio.h>
#include <stdlib.h>
#include "utc.h"   // Header file containing function declarations

int main() {
    int choice;
    int hour, minute, second;
    int out_h, out_m, out_s;   // Variables for converted output time

    while (1) {  // Infinite loop for continuous menu display
        printf("\n======= UNIVERSAL TIME CLOCK (UTC) =======\n");
        printf("1. Show Current System Time in UTC\n");
        printf("2. Convert Local Time (IST) to UTC\n");
        printf("3. Convert UTC to Local Time (IST)\n");
        printf("4. Exit\n");
        printf("-----------------------------------------\n");

        // Taking user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Checking user choice using switch-case
        switch (choice) {

            case 1:
                // Function to display current system time in UTC
                showCurrentUTC();
                break;

            case 2:
                // Taking Local Time input from user
                printf("Enter Local Time (HH MM SS): ");
                scanf("%d %d %d", &hour, &minute, &second);

                // Converting Local Time (IST) to UTC 
                convertLocalToUTC(hour, minute, second, &out_h, &out_m, &out_s);

                // Displaying converted time
                printf("UTC Time: %02d:%02d:%02d\n", out_h, out_m, out_s);
                break;

            case 3:
                // Taking UTC input from user
                printf("Enter UTC Time (HH MM SS): ");
                scanf("%d %d %d", &hour, &minute, &second);

                // Converting UTC to Local Time (IST)
                convertUTCToLocal(hour, minute, second, &out_h, &out_m, &out_s);

                // Displaying converted time
                printf("Local Time (IST): %02d:%02d:%02d\n", out_h, out_m, out_s);
                break;

            case 4:
                // Exit the program
                printf("Exiting program...\n");
                exit(0);

            default:
                // Handling invalid menu input
                printf("Invalid option! Please enter 1–4.\n");
        }
    }

    return 0;   // Program exit point
}
