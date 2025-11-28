#include <stdio.h>
#include <time.h>
#include "utc.h"

// Function 1: Show current system time in UTC
void showCurrentUTC() {
    time_t now;
    struct tm *utc_time;

    time(&now);                  // get system time
    utc_time = gmtime(&now);     // convert to UTC

    printf("\nCurrent UTC Time: %02d:%02d:%02d\n",
           utc_time->tm_hour,
           utc_time->tm_min,
           utc_time->tm_sec);
}

// Function 2: Convert Local Time → UTC
void convertLocalToUTC(int h, int m, int s, int *uh, int *um, int *us) {

    // India Standard Time (IST) = UTC + 5:30
    // So UTC = Local − 5:30  

    int total_seconds = h*3600 + m*60 + s;
    int offset_seconds = 5*3600 + 30*60;  // 5 hours 30 minutes

    total_seconds -= offset_seconds;

    if (total_seconds < 0)
        total_seconds += 24*3600;

    *uh = (total_seconds / 3600) % 24;
    *um = (total_seconds / 60) % 60;
    *us = total_seconds % 60;
}

// Function 3: Convert UTC → Local (India)
void convertUTCToLocal(int h, int m, int s, int *lh, int *lm, int *ls) {

    // Local = UTC + 5:30

    int total_seconds = h*3600 + m*60 + s;
    int offset_seconds = 5*3600 + 30*60;

    total_seconds += offset_seconds;

    if (total_seconds >= 24*3600)
        total_seconds -= 24*3600;

    *lh = (total_seconds / 3600) % 24;
    *lm = (total_seconds / 60) % 60;
    *ls = total_seconds % 60;
}
