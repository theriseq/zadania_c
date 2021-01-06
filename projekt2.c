#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
int ile = 0; //zmienna przechowuje ilosc poprawnie wpisanych danych

bool czy_wprowadzone_dane_ok (char *data) {
    char miesiac[50];
    char dzien[50];
    memset(miesiac, 0, sizeof(miesiac));
    if (strlen(data) == 10 && data_urodzenia[4] == '-' && data_urodzenia[7] == '-') {
        strncat(miesiac, &data[5], 1);
        strncat(miesiac, &data[6], 1);
        strncat(dzien, &data[8], 1);
        strncat(dzien, &data[9], 1);
        if (atoi(miesiac) < 13 && atoi(dzien) < 32) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
bool sprawdz_czy_urodzony (int data_u) {
    int akt_data = 20210106;
    if (data_u > akt_data) {
        return false;
    } else {
        return true;
    }
}

void pobierz_dane() {
    char data[MAX_L];
    char sep[] = "-"; //separator
    char *ptr;

    for (int i = 0; i < 39; i++) {
        //pobierz dane
        printf("Podaj nazwisko: ");
        gets(nazwisko);
        if (strlen(nazwisko) == 0) {
            break;
        }
        printf("\nPodaj imie: ");
        gets(imie);
        printf("\nPodaj date: ");
        gets(data_urodzenia);
        if (czy_wprowadzone_dane_ok(data_urodzenia) == false) {
            printf("\nNie podano prawidlowej daty. Nie dodaje postaci do struktury.\n");
        } else {

            ptr = strtok(data_urodzenia, sep);
            memset(data, 0, sizeof(data));
            while (ptr != NULL) {
                strcat(data, ptr);
                ptr = strtok(NULL, sep);
            }
            if (sprawdz_czy_urodzony(atoi(data)) == true) {
                printf("Dodaje %s %s %s..\n", nazwisko, imie, data_urodzenia);
                strcpy(wszyscy[ile].nazwisko, nazwisko);
                strcpy(wszyscy[ile].imie, imie);
                strcpy(wszyscy[ile].data_urodzenia, data_urodzenia);
                wszyscy[ile].data_uro_int = atoi(data);
                memset(data, 0, sizeof(data));
                ile++;
            } else {
                printf("Data urodzenia nie moze byc wieksza niz aktualna data!\n");
            }
        }
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
        printf("\n---- POSORTOWANE DANE ----\n");
        for (int i = 0; i < ile; i++) {
            printf("%i. %s %s %s\n", i+1, wszyscy[i].nazwisko, wszyscy[i].imie, wszyscy[i].data_urodzenia);
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
