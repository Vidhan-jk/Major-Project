#include <stdio.h>
#include <stdlib.h>
#include "utc.h"

int main() {
    int choice;
    int hour, minute, second;
    int out_h, out_m, out_s;

    while (1) {
        printf("\n======= UNIVERSAL TIME CLOCK (UTC) =======\n");
        printf("1. Show Current System Time in UTC\n");
        printf("2. Convert Local Time (IST) to UTC\n");
        printf("3. Convert UTC to Local Time (IST)\n");
        printf("4. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showCurrentUTC();
                break;

            case 2:
                printf("Enter Local Time (HH MM SS): ");
                scanf("%d %d %d", &hour, &minute, &second);

                convertLocalToUTC(hour, minute, second, &out_h, &out_m, &out_s);

                printf("UTC Time: %02d:%02d:%02d\n", out_h, out_m, out_s);
                break;

            case 3:
                printf("Enter UTC Time (HH MM SS): ");
                scanf("%d %d %d", &hour, &minute, &second);

                convertUTCToLocal(hour, minute, second, &out_h, &out_m, &out_s);

                printf("Local Time (IST): %02d:%02d:%02d\n", out_h, out_m, out_s);
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);
                break;

            default:
                printf("Invalid option! Please enter 1–4.\n");
        }
    }

    return 0;
}
