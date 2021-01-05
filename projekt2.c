#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_L 50

struct Postac {
    char nazwisko[MAX_L];
    char imie[MAX_L];
    char data_urodzenia[MAX_L];
};

void wyc_dane(char *tab)
{
    char delim[] = "-";

	char *ptr = strtok(tab, delim);

	while(ptr != NULL)
	{
		printf("'%s'\n", ptr);
		ptr = strtok(NULL, delim);
	}
}

int main()
{
    char nazw[MAX_L], imie[MAX_L], data[MAX_L];
    struct Postac wszyscy[MAX_L];
    int ile = 0;

    for (int i = 0; i < 2; i++)
    {
        printf("Podaj nazwisko: ");
        fgets(nazw, sizeof(nazw), stdin);
        if (*nazw == '\n')
        {
            break;
        }
        printf("Podaj imie ");
        fgets(imie, sizeof(imie), stdin);
        printf("Podaj date ");
        fgets(data, sizeof(data), stdin);
        strcpy(wszyscy[i].nazwisko, nazw);
        strcpy(wszyscy[i].imie, imie);
        strcpy(wszyscy[i].data_urodzenia, data);
        ile++;
    }
    printf("--\n");

    for (int i = 0; i < ile; i++)
    {
        //printf("%s %s %s\n", wszyscy[i].nazwisko, wszyscy[i].imie, wszyscy[i].data_urodzenia);

        puts(wszyscy[i].nazwisko);
        puts(wszyscy[i].imie);
        puts(wszyscy[i].data_urodzenia);
        wyc_dane(wszyscy[i].data_urodzenia);
    }



    return 0;
}
