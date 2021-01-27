/*
 * =====================================================================================
 *
 *       Filename:  c.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  01/21/2021 14:35:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int x = 0;
    int y = 0;

    if (x++ || y++)
    {
        y += 2;
    }

    printf("%d, %d, %d\n", x, y, x+y);

    return 0;
}
