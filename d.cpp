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

class A {
    int width;
 public:
    int getWidth() const;
};

int foo(const A& a)
{
    return a.getWidth();
}
