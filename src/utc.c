#include <stdio.h>
#include <time.h>
#include "utc.h"

/*
 * utc.c
 *
 * Contains the implementation for:
 *  ✔ Fetching system UTC time
 *  ✔ Converting Local Time (IST) to UTC
 *  ✔ Converting UTC to Local Time (IST)
 *  ✔ Validating time input
 *
 * NOTE:
 *     IST = UTC + 5 hours 30 minutes
 *     So for conversion we use:
 *         UTC = IST - 5:30
 *         IST = UTC + 5:30
 */

// Function to show current system time in UTC
void showCurrentUTC() {
    time_t now;               // Holds current system time
    struct tm *utc_time;      // Struct to hold broken-down UTC time

    time(&now);               // Get current time
    utc_time = gmtime(&now);  // Convert to UTC

    if (utc_time != NULL) {
        printf("\nCurrent UTC Time: %02d:%02d:%02d\n",
               utc_time->tm_hour,
               utc_time->tm_min,
               utc_time->tm_sec);
    } else {
        printf("Error retrieving UTC time!\n");
    }
}

// Convert Local Time (IST) to UTC
void convertLocalToUTC(int h, int m, int s, int *uh, int *um, int *us) {
    int total_seconds = h * 3600 + m * 60 + s;

    // IST offset from UTC = +5 hours 30 minutes
    const int offset_seconds = 5 * 3600 + 30 * 60;

    total_seconds -= offset_seconds;

    // If negative, wrap around 24 hours
    if (total_seconds < 0)
        total_seconds += 24 * 3600;

    // Store result in output pointers
    *uh = (total_seconds / 3600) % 24;
    *um = (total_seconds / 60) % 60;
    *us = total_seconds % 60;
}

// Convert UTC to Local Time (IST)
void convertUTCToLocal(int h, int m, int s, int *lh, int *lm, int *ls) {
    int total_seconds = h * 3600 + m * 60 + s;

    // IST = UTC + 5:30
    const int offset_seconds = 5 * 3600 + 30 * 60;

    total_seconds += offset_seconds;

    // Wrap around after 24 hours
    if (total_seconds >= 24 * 3600)
        total_seconds -= 24 * 3600;

    *lh = (total_seconds / 3600) % 24;
    *lm = (total_seconds / 60) % 60;
    *ls = total_seconds % 60;
}

// Validate time input
int validate_time(int h, int m, int s) {
    if (h < 0 || h >= 24) return 0;   // Hour must be 0–23
    if (m < 0 || m >= 60) return 0;   // Minute must be 0–59
    if (s < 0 || s >= 60) return 0;   // Second must be 0–59
    return 1;                         // Time is valid
}
