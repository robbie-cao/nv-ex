#include <iostream>

using std;

int main(void)
{
    char *pb = new char[100];

    unsigned int pp = (unsigned int)pb;
    unsigned int p2 = reinterpret_cast<unsigned int>(pb);
    unsigned int p3 = static_cast<unsigned int>(pb);

    //std::cout<< pp << p2 << p3 << endl;
    return 0;
}
