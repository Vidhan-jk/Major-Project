#include <stdio.h>
#include <time.h>
#include "utc.h"

/*
 * utc.c
 *
 * Implements:
 *  - showCurrentUTC(): prints current system time in UTC.
 *  - convertLocalToUTC(): converts IST -> UTC by subtracting 5:30.
 *  - convertUTCToLocal(): converts UTC -> IST by adding 5:30.
 *  - validate_time(): checks bounds of hh:mm:ss.
 *
 * Conversions use total seconds and wrap around 24*3600 to handle day boundaries.
 */

/* Print current UTC time in HH:MM:SS format. */
void showCurrentUTC(void) {
    time_t now;
    struct tm *utc_time;

    /* Get current time (seconds since epoch) */
    time(&now);

    /* Convert to UTC broken-down time */
    utc_time = gmtime(&now);

    if (utc_time != NULL) {
        printf("\nCurrent UTC Time: %02d:%02d:%02d\n",
               utc_time->tm_hour,
               utc_time->tm_min,
               utc_time->tm_sec);
    } else {
        /* Very rare; handle gracefully */
        fprintf(stderr, "Error: unable to obtain UTC time.\n");
    }
}

/* Convert Local Time (IST) to UTC.
 * IST = UTC + 5:30  =>  UTC = IST - 5:30
 */
void convertLocalToUTC(int h, int m, int s, int *uh, int *um, int *us) {
    int total_seconds = h * 3600 + m * 60 + s;
    const int offset_seconds = 5 * 3600 + 30 * 60; /* 19800 seconds */

    total_seconds -= offset_seconds;

    /* Wrap to previous day if negative */
    if (total_seconds < 0)
        total_seconds += 24 * 3600;

    if (uh) *uh = (total_seconds / 3600) % 24;
    if (um) *um = (total_seconds / 60) % 60;
    if (us) *us = total_seconds % 60;
}

/* Convert UTC to Local Time (IST).
 * IST = UTC + 5:30
 */
void convertUTCToLocal(int h, int m, int s, int *lh, int *lm, int *ls) {
    int total_seconds = h * 3600 + m * 60 + s;
    const int offset_seconds = 5 * 3600 + 30 * 60;

    total_seconds += offset_seconds;

    /* Wrap to next day if >= 24h */
    if (total_seconds >= 24 * 3600)
        total_seconds -= 24 * 3600;

    if (lh) *lh = (total_seconds / 3600) % 24;
    if (lm) *lm = (total_seconds / 60) % 60;
    if (ls) *ls = total_seconds % 60;
}

/* Validate time triple: hours 0..23, minutes 0..59, seconds 0..59 */
int validate_time(int h, int m, int s) {
    if (h < 0 || h >= 24) return 0;
    if (m < 0 || m >= 60) return 0;
    if (s < 0 || s >= 60) return 0;
    return 1;
}
