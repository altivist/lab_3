#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int guess = rand() % 10000;

    int g[4] = {guess / 1000, (guess / 100) % 10, (guess / 10) % 10, guess % 10};
    printf("debug: %d\n", guess);

    int ox, cow;
    do
    {
        ox = cow = 0;

        int user;
        printf("\nВведите любое число от 0 до 9999 включительно: ");
        if (scanf("%d", &user) != 1)
        {
            printf("Некорректный ввод!\n");
            return 1;
        }
        if (user < 0 || user > 9999)
        {
            printf("Вне диапазона!\n");
            return -1;
        }

        int u[4] = {user / 1000, (user / 100) % 10, (user / 10) % 10, user % 10};

        int freq_g[10] = {0}, freq_u[10] = {0};

        for (int i = 0; i < 4; i++)
        {
            if (g[i] == u[i])
            {
                ox++;
            }
            else
            {
                freq_g[g[i]]++;
                freq_u[u[i]]++;
            }
        }

        for (int d = 0; d < 10; d++)
        {
            if (freq_g[d] < freq_u[d])
            {
                cow += freq_g[d];
            }
            else
            {
                cow += freq_u[d];
            }
        }

        printf("%d бык", ox);
        if (ox != 1)
        {
            if (ox == 0)
                printf("ов");
            else
                printf("а");
        }
        if (cow != 0)
        {
            printf(" и %d коров", cow);
            if (ox == 1)
                printf("a");
            else
                printf("ы");
        }
        printf("\n");

        printf("\n");
    } while (ox != 4);

    printf("Поздравляю! Вы угадали число!\n");
    return 0;
}
