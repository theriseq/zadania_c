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

void pobierz_dane() {
    char data[MAX_L];
    char sep[] = "-"; //separator
    char *ptr;

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
        //strlen(data_urodzenia) < 10 ||
        //        data_urodzenia[4] != '-' ||
        //        data_urodzenia[7] != '-' ||
        //        data_urodzenia[6] - '0' > 2 ||
        //        (data_urodzenia[8] - '0' >= 3  && data_urodzenia[9] >= 2)
        if (czy_wprowadzone_dane_ok(data_urodzenia) == false) {
            printf("\nNie podano prawidlowej daty. Nie dodaje postaci do struktury.\n");
            if ( data_urodzenia[6] - '0' > 2) {
                printf("Bledny miesiac\n");
            }
            if (data_urodzenia[8] - '0' >= 3  && data_urodzenia[9] >= 2) {
                printf("bledny dzien\n");
            }
        } else {
            printf("Dodaje %s %s %s..\n", nazwisko, imie, data_urodzenia);
            //przypisz dane do struktury
            strcpy(wszyscy[ile].nazwisko, nazwisko);
            strcpy(wszyscy[ile].imie, imie);
            strcpy(wszyscy[ile].data_urodzenia, data_urodzenia);

            ptr = strtok(wszyscy[ile].data_urodzenia, sep);
            memset(data, 0, sizeof(data));
            while (ptr != NULL) {
                strcat(data, ptr);
                ptr = strtok(NULL, sep);
            }
            wszyscy[ile].data_uro_int = atoi(data);
            memset(data, 0, sizeof(data));

            ile++;
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
