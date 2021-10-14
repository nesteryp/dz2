#include <stdio.h>

#include <stdlib.h>

#define max(x, y)((x) > (y) ? (x) : (y))

int main(void) {
    FILE * file;
    int a = 0, b = 0, c, k = 0, d = 0;
    char is = 'T';

    file = fopen("dz2.gv", "w");
    fputs("graph{\n", file);

    c = scanf("%d-%d\n", & a, & b);

    if (c != 0) {
        while (c != 0) {
            d = max(d, max(a, b));
            k++;

            if (c == 1) {
                is = 'F';
                fprintf(file, "\t%d\n", a);
            }

            if (c == 2) fprintf(file, "\t%d--%d\n", a, b);
            c = scanf("%d-%d\n", & a, & b);
        }

        if ((is == 'T') && (d == k + 1))
            printf("Является деревом");

        else printf("Не является деревом");

        fputc('}', file);
        fclose(file);
        system("dot -Tpng dz2.gv -o dz2.png");
        return 0;
    } else {
        printf("Неверные данные");
        return 1;
    }
}