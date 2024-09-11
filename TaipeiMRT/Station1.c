#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Station.h"

void genStation(Station *station, char line[10], char id[10], char name[100], Station *left, Station *right){
    strcpy(station->line, line);
    strcpy(station->id[0], id);
    strcpy(station->name, name);
    station->number = 1;
    station->next[0] = left;
    if(right == NULL)station->next[station->number] = right, station->number++;
}

void stationID(Station *stations[]){
    int BL0 = 0;
    int BR0 = BL0 + endBL - startBL + 1;
    int G0 = BR0 + endBR - startBR + 1;
    int O0 = G0 + endG - startG + 1;
    int O50 = O0 + endO1 - startO1;
    int R0 = O0 + endO2 - startO2 + 1;
    int Y0 = R0 + endR - startR + 1;
    
}