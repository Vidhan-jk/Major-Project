#ifndef UTC_H
#define UTC_H

/*
 * utc.h
 * 
 * Header file that contains declarations for functions used in the UTC project.
 * These functions handle time fetching, conversion, and input validation.
 */

// Shows the current system time in UTC
void showCurrentUTC();

// Converts Local Time (IST) to UTC
void convertLocalToUTC(int h, int m, int s, int *uh, int *um, int *us);

// Converts UTC time to Local Time (IST)
void convertUTCToLocal(int h, int m, int s, int *lh, int *lm, int *ls);

// Validates time values (returns 1 if valid, 0 if invalid)
int validate_time(int h, int m, int s);

#endif  // UTC_H
