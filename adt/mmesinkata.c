#include "mesinkata.c"

/* Kamus */
int NbKata, LTotal;

/* Algoritma */
int main () {
    LTotal = 0;
    NbKata = 0;
    STARTKATA();
    while (!EndKata) {
        LTotal++;
        NbKata++;
        ADVKATA();
    }
    if (NbKata != 0)
        printf("%d/%d\n",LTotal,NbKata);
    else
        printf("Pita tidak mengandung kata\n");
    return 0;
}
