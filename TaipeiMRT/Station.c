#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Station.h"

void doWeb(Station *R[endR + 1], Station *O[endO2 + 1], Station *Y[endY + 1], Station *G[endG + 1], Station *BL[endBL + 1], Station *BR[endBR + 1]){
    for(int i = startR; i <= endR; i++){//Red Line
        R[i] = (Station *)malloc(sizeof(Station));
        strcpy(R[i]->line, "R");
        R[i]->name[0] = 'R';
        R[i]->name[1] = '0' + i/10;
        R[i]->name[2] = '0' + i%10;
        R[i]->name[3] = '\0';
        R[i]->number = 0;
        R[i]->trans = NULL;
        for(int j = 0; j < maxNext; j++) R[i]->next[j] = NULL;
        if(i != startR) R[i - 1]->next[R[i - 1]->number] = R[i], R[i - 1]->number++, R[i]->next[R[i]->number] = R[i - 1], R[i]->number++;
    }
    for(int i = startO1; i <= endO1; i++){//Orange Line
        O[i] = (Station *)malloc(sizeof(Station));
        strcpy(O[i]->line, "O");
        O[i]->name[0] = 'O';
        O[i]->name[1] = '0' + i/10;
        O[i]->name[2] = '0' + i%10;
        O[i]->name[3] = '\0';
        O[i]->number = 0;
        O[i]->trans = NULL;
        for(int j = 0; j < maxNext; j++) O[i]->next[j] = NULL;
        if(i != startO1) O[i - 1]->next[O[i - 1]->number] = O[i], O[i - 1]->number++, O[i]->next[O[i]->number] = O[i - 1], O[i]->number++;
    }
    for(int i = startO2; i <= endO2; i++){//Orange Line
        O[i] = (Station *)malloc(sizeof(Station));
        strcpy(O[i]->line, "O");
        O[i]->name[0] = 'O';
        O[i]->name[1] = '0' + i/10;
        O[i]->name[2] = '0' + i%10;
        O[i]->name[3] = '\0';
        O[i]->number = 0;
        O[i]->trans = NULL;
        for(int j = 0; j < maxNext; j++) O[i]->next[j] = NULL;
        if(i != startO2) O[i - 1]->next[O[i - 1]->number] = O[i], O[i - 1]->number++, O[i]->next[O[i]->number] = O[i - 1], O[i]->number++;
    }
    for(int i = startY; i <= endY; i++){//Yellow Line
        Y[i] = (Station *)malloc(sizeof(Station));
        strcpy(Y[i]->line, "Y");
        Y[i]->name[0] = 'Y';
        Y[i]->name[1] = '0' + i/10;
        Y[i]->name[2] = '0' + i%10;
        Y[i]->name[3] = '\0';
        Y[i]->number = 0;
        Y[i]->trans = NULL;
        for(int j = 0; j < maxNext; j++) Y[i]->next[j] = NULL;
        if(i != startY) Y[i - 1]->next[Y[i - 1]->number] = Y[i], Y[i - 1]->number++, Y[i]->next[Y[i]->number] = Y[i - 1], Y[i]->number++;
    }
    for(int i = startG; i <= endG; i++){//Green Line
        G[i] = (Station *)malloc(sizeof(Station));
        strcpy(G[i]->line, "G");
        G[i]->name[0] = 'G';
        G[i]->name[1] = '0' + i/10;
        G[i]->name[2] = '0' + i%10;
        G[i]->name[3] = '\0';
        G[i]->number = 0;
        G[i]->trans = NULL;
        for(int j = 0; j < maxNext; j++) G[i]->next[j] = NULL;
        if(i != startG) G[i - 1]->next[G[i - 1]->number] = G[i], G[i - 1]->number++, G[i]->next[G[i]->number] = G[i - 1], G[i]->number++;
    }
    for(int i = startBL; i <= endBL; i++){//Blue Line
        BL[i] = (Station *)malloc(sizeof(Station));
        strcpy(BL[i]->line, "BL");
        BL[i]->name[0] = 'B';
        BL[i]->name[1] = 'L';
        BL[i]->name[2] = '0' + i/10;
        BL[i]->name[3] = '0' + i%10;
        BL[i]->name[4] = '\0';
        BL[i]->number = 0;
        BL[i]->trans = NULL;
        for(int j = 0; j < maxNext; j++) BL[i]->next[j] = NULL;
        if(i != startBL) BL[i - 1]->next[BL[i - 1]->number] = BL[i], BL[i - 1]->number++, BL[i]->next[BL[i]->number] = BL[i - 1], BL[i]->number++;
    }
    for(int i = startBR; i <= endBR; i++){//Brown Line
        BR[i] = (Station *)malloc(sizeof(Station));
        strcpy(BR[i]->line, "BR");
        BR[i]->name[0] = 'B';
        BR[i]->name[1] = 'R';
        BR[i]->name[2] = '0' + i/10;
        BR[i]->name[3] = '0' + i%10;
        BR[i]->name[4] = '\0';
        BR[i]->number = 0;
        BR[i]->trans = NULL;
        for(int j = 0; j < maxNext; j++) BR[i]->next[j] = NULL;
        if(i != startBR) BR[i - 1]->next[BR[i - 1]->number] = BR[i], BR[i - 1]->number++, BR[i]->next[BR[i]->number] = BR[i - 1], BR[i]->number++;
    }
    {//trans
        R[5]->trans = BR[9];
        R[7]->trans = O[6];
        R[8]->trans = G[10];
        R[10]->trans = BL[12];
        R[11]->trans = G[14];
        R[13]->trans = O[11];
        O[2]->trans = Y[11];
        O[5]->trans = G[9];
        O[6]->trans = R[7];
        O[7]->trans = BL[14];
        O[8]->trans = G[15];
        O[11]->trans = R[13];
        O[12]->next[O[12]->number] = O[50], O[12]->number++;
        O[17]->trans = Y[18];
        O[50]->next[O[50]->number] = O[12], O[50]->number++;
        Y[7]->trans = G[4];
        Y[11]->trans = O[2];
        Y[16]->trans = BL[7];
        Y[17]->trans = BL[8];
        Y[18]->trans = O[17];
        G[4]->trans = Y[7];
        G[9]->trans = O[5];
        G[10]->trans = R[8];
        G[12]->trans = BL[11];
        G[14]->trans = R[11];
        G[15]->trans = O[8];
        G[16]->trans = BR[11];
        BL[7]->trans = Y[16];
        BL[8]->trans = Y[17];
        BL[11]->trans = G[12];
        BL[12]->trans = R[10];
        BL[14]->trans = O[7];
        BL[15]->trans = BR[10];
        BL[23]->trans = BR[24];
        BR[9]->trans = R[5];
        BR[10]->trans = BL[15];
        BR[11]->trans = G[16];
        BR[24]->trans = BL[23];
    }
}