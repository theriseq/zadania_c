#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_L 50
#define MAX_POST 40

typedef struct Postac{
    char nazwisko[MAX_L];
    char imie[MAX_L];
    char data_urodzenia[MAX_L];
    int data_uro_int;
} postac;

postac wszyscy[MAX_POST];
char nazwisko[MAX_L];
char imie[MAX_L];
char data_urodzenia[MAX_L];
int ile = 0;

char data[MAX_L];
char sep[] = "-"; // separuje date
char *ptr;


void pobierz_dane() {
    for (int i = 0; i < 39; i++) {
        //pobierz dane
        printf("Podaj nazwisko: ");
        gets(nazwisko);
        if (strlen(nazwisko) == 0) {
            //jesli endl to koncz
            printf("\n--\nPusty wiersz\n--\n");
            break;
        }
        printf("\nPodaj imie: ");
        gets(imie);
        printf("\nPodaj date: ");
        gets(data_urodzenia);

        //przypisz dane do struktury
        strcpy(wszyscy[i].nazwisko, nazwisko);
        strcpy(wszyscy[i].imie, imie);
        strcpy(wszyscy[i].data_urodzenia, data_urodzenia);

        ptr = strtok(wszyscy[i].data_urodzenia, sep);
        memset(data, 0, sizeof(data));
        while (ptr != NULL) {
            strcat(data, ptr);
            //printf("data ptr\n: %s\n", data);
            ptr = strtok(NULL, sep);
        }
        wszyscy[i].data_uro_int = atoi(data);
        memset(data, 0, sizeof(data));

        ile++;
    }
}
void posortuj_dane() {
    for (int j=0;j<ile-1;j++) {
        for (int i=j+1;i<ile;i++) {
            if (wszyscy[i].data_uro_int<wszyscy[j].data_uro_int) {
                postac temp = wszyscy[j];
                wszyscy[j]=wszyscy[i];
                wszyscy[i]=temp;
            }

        }
    }
}
void wypisz_dane() {
    if (ile > 0) {
        system("cls");
        printf("\n---- POSORTOWANE DANE----\n");
        for (int i = 0; i < ile; i++) {
            printf("%i. %s %s\n", i+1, wszyscy[i].nazwisko, wszyscy[i].imie);
        }
    } else {
        system("cls");
        printf("Nie wprowadzono zadnych danych. Zamykam aplikacje.");
    }

}
int main()
{
    pobierz_dane();
    posortuj_dane();
    wypisz_dane();

    return 0;
}
