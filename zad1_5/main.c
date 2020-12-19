#include <stdio.h>
#include <math.h>

double oblicz_srednia(int liczby[], int rozm) {
    double suma = 0;
    double srednia = 0;

    for (int i = 0; i < rozm; i++) {
        suma += liczby[i];
    }
    return srednia = suma / rozm;
}

double oblicz_wariacje(int liczby[], int rozm, double srednia) {

    double wariacja = 0;

    for (int i = 0; i < rozm; i++) {
        wariacja += pow((liczby[i] - srednia), 2.0);
    }

    return wariacja / rozm;

}
double oblicz_odchylenie(double wariacja) {
    return sqrt(wariacja);
}

double zaokraglij(double wartosc) {
    return round(10 * wartosc) / 10;
}

int main() {

    int liczby[] = {2,5,1,3};
    int rozm = (sizeof(liczby) / sizeof(liczby[0]));

    double srednia = oblicz_srednia(liczby, rozm);
    double wariacja = oblicz_wariacje(liczby, rozm, srednia);
    double odchylenie = oblicz_odchylenie(wariacja);

    printf("Wartosc srednia: ~%.2f\n", zaokraglij(srednia));
    printf("wariacja ~%.2f\n", zaokraglij(wariacja));
    printf("Odchylenie standardowe: ~%.2f", zaokraglij(odchylenie));


    return 0;
}