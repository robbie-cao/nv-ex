/*
 * =====================================================================================
 *
 *       Filename:  b.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  01/21/2021 14:26:48
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
//#include <iostream>

int main(void)
{
    //std::cout << sizeof(int) << std::endl;

    int *x = new int[10];

    //std::cout<< x << std::endl;
    printf("#08x\n", (int)x);

    //std::cout << x + 3 << std::endl;
    printf("#08x\n", (int)(x + 3));

    return 0;
}

