/*
 * =====================================================================================
 *
 *       Filename:  d.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  01/21/2021 14:48:44
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

//class A {
//    int width;
// public:
//    int getWidth() const;
//};
//
//int foo(const A& a)
//{
//    return a.getWidth();
//}
//
int main(void)
{
    class A {
        int a;
        long b;
        char c;
    };

    A arrayOfA[1024][100];

    printf("%ld\n", (char *)&arrayOfA[5][10] - (char *)&arrayOfA[0][0]);

    class B {
        int a;
    };

    B (*arrayOfB)[100];
    printf("%ld\n", (char *)(arrayOfB + 5) - (char *)arrayOfB);

    return 0;
}
