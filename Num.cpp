```cpp

#include <stdio.h>

const int N = 8;
const int MAX_NUM = N * N - 1;

int origArray[N * N];
int matrix[N][N];

void printMatrix()
{
    int j = 1;
    int x = 0;
    int y = 0;
    int width = N;
    int height = N;
    bool posX = true;
    bool inc = true;

    for (int i = 0; i <= MAX_NUM; i++) {
        origArray[i] = i;
    }

    for (int num = 0; num <= MAX_NUM; num++  ) {
        matrix[y][x] = num;

        if (origArray[MAX_NUM] == num) { // last one
            break;
        }

        if (posX) { // coordinate x
            if (j % width == 0) {
                posX = false;
                j = 1;
                height--;
                inc ? y++ : y--;
            } else {
                j++;
                inc ? x++ : x--;
            }

        } else { // coordinate y
            if (j % height == 0) {
                posX = true;
                j = 1;
                width--;
                inc ? x-- : x++;
                inc = !inc;
            } else {
                j++;
                inc ? y++ : y--;
            }
        }
    }

    for (int mx = 0; mx < N; mx++) {
        for (int my = 0; my < N; my++) {
            printf("%5d  ", matrix[mx][my]);
        }
        printf("\n");
    }

}

int main(int argc, char *argv[])
{
    printMatrix();

    return 0;
}

```
