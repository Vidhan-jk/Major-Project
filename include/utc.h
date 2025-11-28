#ifndef UTC_H
#define UTC_H

void showCurrentUTC();
void convertLocalToUTC(int h, int m, int s, int *uh, int *um, int *us);
void convertUTCToLocal(int h, int m, int s, int *lh, int *lm, int *ls);

#endif
