#define _POSIX_C_SOURCE 200809L  /* for getline on some systems (not used here, but fine) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#include "utc.h"

/*
 * main.c
 *
 * Menu-driven interface for the Universal Time Clock project.
 * This version uses robust input handling to avoid scanf() problems:
 *  - read_int_in_range(): reads a single integer from stdin reliably.
 *  - read_time_triple(): reads three integers (HH MM SS) and validates them.
 *
 * All input is obtained using fgets() + strtol()/sscanf() checks so the program
 * will not crash or behave unpredictably on bad input (like letters or extra characters).
 */

/* Read a single integer from stdin safely, requiring the value to be in [min,max].
 * The function prints prompt and repeats until a valid number is entered.
 * Returns the validated integer.
 */
int read_int_in_range(const char *prompt, int min, int max) {
    char buf[128];
    char *endptr;
    long val;

    while (1) {
        /* Prompt */
        printf("%s", prompt);

        /* Read a line from stdin; fgets returns NULL on EOF/error */
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* Input error - clear error and try again */
            clearerr(stdin);
            printf("Input error. Please try again.\n");
            continue;
        }

        /* Remove leading spaces */
        char *p = buf;
        while (isspace((unsigned char)*p)) p++;

        /* Use strtol to parse integer and detect non-numeric input */
        errno = 0;
        val = strtol(p, &endptr, 10);

        /* If no digits were found */
        if (endptr == p) {
            printf("Invalid input; please enter a number.\n");
            continue;
        }

        /* Skip trailing spaces */
        while (isspace((unsigned char)*endptr)) endptr++;

        /* If there are extra characters left (not newline or NUL), reject */
        if (*endptr != '\0' && *endptr != '\n') {
            printf("Unexpected characters after number. Please enter only a number.\n");
            continue;
        }

        /* Check for range errors / overflow */
        if (errno == ERANGE || val < min || val > max) {
            printf("Please enter a number between %d and %d.\n", min, max);
            continue;
        }

        /* Successful parse and in range */
        return (int)val;
    }
}

/* Read a time triple (HH MM SS) from stdin safely and validate ranges.
 * On success, fills h,m,s and returns 1. Otherwise repeats prompt until valid.
 */
int read_time_triple(int *h, int *m, int *s, const char *prompt) {
    char buf[256];
    int n;
    while (1) {
        printf("%s", prompt);

        if (!fgets(buf, sizeof(buf), stdin)) {
            clearerr(stdin);
            printf("Input error. Please try again.\n");
            continue;
        }

        /* Try to parse exactly three integers. The fourth "%c" helps detect extra junk. */
        char extra;
        n = sscanf(buf, " %d %d %d %c", h, m, s, &extra);

        if (n < 3) {
            printf("Invalid format. Please enter three integers: HH MM SS\n");
            continue;
        }
        /* If sscanf parsed a fourth item, there was extra junk after the three numbers */
        if (n > 3) {
            printf("Extra characters detected after time. Please enter only HH MM SS.\n");
            continue;
        }

        /* Validate numeric ranges using validate_time (from utc.c) */
        if (!validate_time(*h, *m, *s)) {
            printf("Invalid time values. Hours: 0-23, Minutes: 0-59, Seconds: 0-59.\n");
            continue;
        }

        /* All good */
        return 1;
    }
}

int main(void) {
    int choice;
    int hour, minute, second;
    int out_h, out_m, out_s;

    /* Main menu loop */
    while (1) {
        printf("\n======= UNIVERSAL TIME CLOCK (UTC) =======\n");
        printf("1. Show Current System Time in UTC\n");
        printf("2. Convert Local Time (IST) to UTC\n");
        printf("3. Convert UTC to Local Time (IST)\n");
        printf("4. Exit\n");
        printf("-----------------------------------------\n");

        /* Read menu choice safely (only accept 1..4) */
        choice = read_int_in_range("Enter your choice (1-4): ", 1, 4);

        switch (choice) {
            case 1:
                /* Display current system UTC */
                showCurrentUTC();
                break;

            case 2:
                /* Read a valid local time triple from user */
                if (!read_time_triple(&hour, &minute, &second, "Enter Local Time (HH MM SS): "))
                    break; /* should not happen; read_time_triple loops until valid */

                /* Convert IST -> UTC */
                convertLocalToUTC(hour, minute, second, &out_h, &out_m, &out_s);

                printf("UTC Time: %02d:%02d:%02d\n", out_h, out_m, out_s);
                break;

            case 3:
                /* Read a valid UTC time triple from user */
                if (!read_time_triple(&hour, &minute, &second, "Enter UTC Time (HH MM SS): "))
                    break;

                /* Convert UTC -> IST */
                convertUTCToLocal(hour, minute, second, &out_h, &out_m, &out_s);

                printf("Local Time (IST): %02d:%02d:%02d\n", out_h, out_m, out_s);
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                /* Should never reach here because read_int_in_range enforces 1-4 */
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    /* Unreachable, but good style */
    return 0;
}
