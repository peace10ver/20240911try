#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Station{
    char line[10];
    char name[100];
    int number;
    int d;
    struct Station *next[4];
    struct Station *trans;
}Station;