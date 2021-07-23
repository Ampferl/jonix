#ifndef _CTYPE_H_
#define _CTYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

int isspace(int c);
int isblank(int c);
int isdigit(int c);
int isalpha(int c);
int isalnum(int c);
int isxdigit(int c);
int isupper(int c);
int islower(int c);

int tolower(int c);
int toupper(int c);

#ifdef __cplusplus
};
#endif

#endif
