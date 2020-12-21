/*
Patryk Orlowski
19.12.2020

Dla n-elementowego ciagu liczb rzeczywistych obliczyc wartosc srednia i odchylenie standardowe
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double oblicz_srednia(int liczby[], int rozm) {
    double suma = 0;
    double srednia = 0;

    for (int i = 0; i < rozm; i++) {
        suma += liczby[i];
    }
    return srednia = suma / rozm;
}

double oblicz_odchylenie(int liczby[], int rozm, double srednia) {

    double odchylenie = 0;

    for (int i = 0; i < rozm; i++) {
        odchylenie += pow((liczby[i] - srednia), 2.0);
    }

    return sqrt(odchylenie / rozm);

}

double zaokraglij(double wartosc) {
    return round(10 * wartosc) / 10;
}

int main() {

    int liczby[] = {6,3,5,5,6};
    int rozm = (sizeof(liczby) / sizeof(liczby[0]));

    double srednia = oblicz_srednia(liczby, rozm);
    double odchylenie = oblicz_odchylenie(liczby, rozm, srednia);

    printf("Wartosc srednia = %.2f\n", zaokraglij(srednia));
    printf("Odchylenie standardowe = %f = ~%.2f", odchylenie, zaokraglij(odchylenie));


    return 0;
}
