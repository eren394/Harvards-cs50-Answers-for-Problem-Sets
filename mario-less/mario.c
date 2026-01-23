#include <stdio.h>

int main(void)
{
    int height;

    do {
        printf("Height: ");
        if (scanf("%d", &height) != 1) {
            while (getchar() != '\n');
            height = 0;
        }
    } while (height < 2 || height > 8);

    for (int i = 1; i <= height; i++) {
        for (int s = 0; s < height - i; s++) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
