#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxNext 4
#define maxJoint 2
#define maxLine 6
#define startBL 1
#define endBL 23
#define startBR 1
#define endBR 24
#define startG 1
#define endG 19
#define startO1 1
#define endO1 21
#define startO2 50
#define endO2 54
#define startR 2
#define endR 28
#define startY 7
#define endY 20

typedef struct Station{
    char line[10];
    char id[maxJoint][10];
    char name[100];
    int number;
    int d;
    struct Station *next[maxNext];
    struct Station *trans;
}Station;

void genStation(Station *station, char line[10], char id[10], char name[100], int number, Station *left, Station *right);

void stationID(Station *stations[]);

void doWeb(Station *R[endR + 1], Station *O[endO2 + 1], Station *Y[endY + 1], Station *G[endG + 1], Station *BL[endBL + 1], Station *BR[endBR + 1]);