#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void masolas(const char *forrasfajl, const char *celfajl) {
    FILE *fp1 = fopen(forrasfajl, "r");
    if(fp1 == NULL) {
        printf("Hiba: A forrasfajl megnyitasa sikertelen.\n");
        return;
    }
    FILE *fp2 = fopen(celfajl, "w");
    if(fp2 == NULL) {
        printf("Hiba: A celfajl megnyitasa sikertelen.\n");
        fclose(fp1);
        return;
    }
    char buffer[256];
    while(fgets(buffer, sizeof(buffer), fp1) != NULL) {
        fputs(buffer, fp2);
    }
    fclose(fp1);
    fclose(fp2);
}

int main(void) {
    char fajlnev[100], sor[256];
    
    if(fgets(fajlnev, sizeof(fajlnev), stdin) == NULL) {
        printf("Hiba a fajlnev beolvasasakor.\n");
        return 1;
    }
    fajlnev[strcspn(fajlnev, "\n")] = '\0';
    
    FILE *fp = fopen(fajlnev, "w");
    if(fp == NULL) {
        printf("Hiba: A fajl megnyitasa irasra sikertelen.\n");
        return 1;
    }
    
    while(fgets(sor, sizeof(sor), stdin) != NULL) {
        sor[strcspn(sor, "\n")] = '\0';
        if(strcmp(sor, "#") == 0) {
            break;
        }
        printf(fp, "%s\n", sor);
    }
    fclose(fp);
     
    char forrasFajl[100], celFajl[100];
    
    printf("\nAdja meg a forrasfajl nevet: ");
    if(fgets(forrasFajl, sizeof(forrasFajl), stdin) == NULL) {
        printf("Hiba a forras fajl nevenek beolvasásakor.\n");
        return 1;
    }
    forrasFajl[strcspn(forrasFajl, "\n")] = '\0';
    
    printf("Adja meg a cel fajl nevet: ");
    if(fgets(celFajl, sizeof(celFajl), stdin) == NULL) {
        printf("Hiba a cel fajl nevenek beolvasasakor.\n");
        return 1;
    }
    celFajl[strcspn(celFajl, "\n")] = '\0';
    
    masolas(forrasFajl, celFajl);
    printf("A fajl masolasa kesz.\n");
    
    system("pause");
    return 0;
}
