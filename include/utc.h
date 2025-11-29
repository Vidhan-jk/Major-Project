#ifndef UTC_H
#define UTC_H

/*
 * utc.h
 *
 * Declarations for UTC helper functions and a time validator.
 * Place this file in the `include/` folder and include it in your sources:
 *   #include "utc.h"
 */

/* Show the current system time in UTC (prints to stdout). */
void showCurrentUTC(void);

/* Convert Local Time (IST) to UTC.
 * Inputs: h,m,s (0<=h<24, 0<=m<60, 0<=s<60)
 * Outputs: uh,um,us pointers receive converted UTC time components.
 */
void convertLocalToUTC(int h, int m, int s, int *uh, int *um, int *us);

/* Convert UTC to Local Time (IST).
 * Inputs: h,m,s (UTC time)
 * Outputs: lh,lm,ls pointers receive converted local time components.
 */
void convertUTCToLocal(int h, int m, int s, int *lh, int *lm, int *ls);

/* Validate a time triple. Returns 1 if valid, 0 otherwise.
 * Valid when: 0 <= h < 24, 0 <= m < 60, 0 <= s < 60.
 */
int validate_time(int h, int m, int s);

#endif /* UTC_H */
