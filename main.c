#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int guess = rand() % 10000;

    int g[4];
    g[0] = guess / 1000;
    g[1] = (guess % 1000) / 100;
    g[2] = (guess % 100) / 10;
    g[3] = guess % 10;

    int ox, cow;
    do
    {
        ox = cow = 0;
        int user;
        printf("\nВведите любое число от 0 до 9999 включительно: ");

        if (!(scanf("%d", &user)))
        {
            printf("Некорретный ввод!");
            return -1;
        }
        if ((user < 0) || (user > 9999))
        {
            printf("Вне диапазона!");
            return 1;
        }
        int u[4];
        u[0] = user / 1000;
        u[1] = (user % 1000) / 100;
        u[2] = (user % 100) / 10;
        u[3] = user % 10;

        for (int i = 0; i < 4; i++)
        {
            char is_cow = 0;
            for (int j = 0; j < 4; j++)
            {
                if ((u[i] == g[j]) && (i == j))
                {
                    ox += 1;
                    break;
                }
                if ((u[i] == g[j]) && (i != j))
                {
                    is_cow = 1;
                }
            }
            cow += is_cow;
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
    } while (ox != 4);
    return 0;
}