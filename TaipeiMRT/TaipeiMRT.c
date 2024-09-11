#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Station.h"
#define XD "中"

typedef struct Route{
    int trans;
    Station *route[100];
}Route;

void minD(Station *start, Station *end, int d){
    if(end->d == -1 || end->d > d){
        end->d = d;
        for(int i = 0; i < end->number; i++) minD(start, end->next[i], d + 1);
        if(end->trans != NULL) minD(start, end->trans, d);
    }
}

int findTrans(Station *route[]){
    int ans = 0;
    int p = 0;
    while(route[p + 2] != NULL){
        if(strcmp(route[p]->line, route[p + 1]->line) != 0) ans++;
        p++;
    }
    return ans;
}

void printRoute(Station *start, Station *end, Station *route[], Route *sol[10]){
    route[start->d] = start;
    if(start->d == 0){
        int trans = findTrans(route);
        int n = 0;
        while(sol[n] != NULL){
            n++;
        }
        sol[n] = (Route *)malloc(sizeof(Route));
        sol[n]->trans = trans;
        for(int i = 0; i < 100; i++) sol[n]->route[i] = route[i];
    }
    if(start->d != 0){
        for(int i = 0; i < start->number; i++){
            if(start->next[i]->d == start->d - 1){
                printRoute(start->next[i], end, route, sol);
            }
        }
        if(start->trans != NULL){
            for(int i = 0; i < start->trans->number; i++){
                if(start->trans->next[i]->d == start->d - 1){
                    printRoute(start->trans->next[i], end, route, sol);
                }
            }
        }
    }
}

int findMinTrans(Route *sol[10]){
    int n = 0;
    int ans = 100;
    while(sol[n] != NULL){
        if(sol[n]->trans < ans) ans = sol[n]->trans;
        n++;
    }
    return ans;
}

Station *R[endR + 1], *O[endO2 + 1], *Y[endY + 1], *G[endG + 1], *BL[endBL + 1], *BR[endBR + 1];

int main(){
    int whole = endBL - startBL + 1 + 
                endBR - startBR + 1 + 
                endG - startG + 1 + 
                endO1 - startO1 + 1 + 
                endO2 - startO2 + 1 + 
                endR - startR + 1 + 
                endY - startY + 1;
    //Station *stations[whole];
    //stationID(stations);
    doWeb(R, O, Y, G, BL, BR);
    char station[10];
    while(scanf("%s", station) != EOF){
        for(int i = 2; i <= 28; i++) R[i]->d = -1;
        for(int i = 1; i <= 21; i++) O[i]->d = -1;
        for(int i = 50; i <= 54; i++) O[i]->d = -1;
        for(int i = 7; i <= 20; i++) Y[i]->d = -1;
        for(int i = 1; i <= 19; i++) G[i]->d = -1;
        for(int i = 1; i <= 23; i++) BL[i]->d = -1;
        for(int i = 1; i <= 24; i++) BR[i]->d = -1;
        Station *start;
        if(station[0] == 'R'){
            int startNum = (station[1] - '0') * 10 + station[2] - '0';
            start = R[startNum];
        }
        else if(station[0] == 'O'){
            int startNum = (station[1] - '0') * 10 + station[2] - '0';
            start = O[startNum];
        }
        else if(station[0] == 'Y'){
            int startNum = (station[1] - '0') * 10 + station[2] - '0';
            start = Y[startNum];
        }
        else if(station[0] == 'G'){
            int startNum = (station[1] - '0') * 10 + station[2] - '0';
            start = G[startNum];
        }
        else if(station[0] == 'B' && station[1] == 'L'){
            int startNum = (station[2] - '0') * 10 + station[3] - '0';
            start = BL[startNum];
        }
        else{
            int startNum = (station[2] - '0') * 10 + station[3] - '0';
            start = BR[startNum];
        }
        scanf("%s", station);
        Station *end;
        if(station[0] == 'R'){
            int startNum = (station[1] - '0') * 10 + station[2] - '0';
            end = R[startNum];
        }
        else if(station[0] == 'O'){
            int startNum = (station[1] - '0') * 10 + station[2] - '0';
            end = O[startNum];
        }
        else if(station[0] == 'Y'){
            int startNum = (station[1] - '0') * 10 + station[2] - '0';
            end = Y[startNum];
        }
        else if(station[0] == 'G'){
            int startNum = (station[1] - '0') * 10 + station[2] - '0';
            end = G[startNum];
        }
        else if(station[0] == 'B' && station[1] == 'L'){
            int startNum = (station[2] - '0') * 10 + station[3] - '0';
            end = BL[startNum];
        }
        else{
            int startNum = (station[2] - '0') * 10 + station[3] - '0';
            end = BR[startNum];
        }
        minD(start, end, 0);
        Station *route[100];
        Route *sol[10];
        for(int i = 0; i < 10; i++) sol[i] = NULL;
        for(int i = 0; i < 100; i++) route[i] = NULL;
        printRoute(start, end, route, sol);
        int ways = 0;
        int way = 1;
        int minTrans = findMinTrans(sol);
        for(int i = 0; sol[i] != NULL; i++) if(sol[i]->trans == minTrans) ways++;
        if(ways == 1) printf("There is a way from %s to %s with", start->name, end->name);
        else printf("There are %d ways from %s to %s with", ways, start->name, end->name);
        if(minTrans == 1) printf(" a transfer station.\n");
        else printf(" %d transfer stations.\n", minTrans);
        for(int i = 0; sol[i] != NULL; i++){
            if(sol[i]->trans == minTrans){
                printf("Way %d\n", way);
                way++;
                for(int j = start->d; j > 0; j--){
                    printf("%s", sol[i]->route[j]->name);
                    if(strcmp(sol[i]->route[j - 1]->line, sol[i]->route[j]->line) != 0) printf("->%s\n", sol[i]->route[j]->trans->name);
                    else printf(" ");
                }
                printf("%s", sol[i]->route[0]->name);
                if(strcmp(sol[i]->route[0]->line, end->line) != 0) printf("->%s", end->name);
                printf("\n");
            }
        }
    }
    return 0;
}
