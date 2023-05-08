// Βιβλιοθήκη με τις συναρτήσεις του αρχείου minmax_funcs.c

#include <string.h>

// Μια πίο εύκολη γραφή για διευκόλυνση στη χρήση
typedef void* Pointer;
typedef char* String;
typedef int (*function)(Pointer a, Pointer b);

int compare_int(Pointer a, Pointer b);
int compare_float(Pointer a, Pointer b);
int compare_double(Pointer a, Pointer b);