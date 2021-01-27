#include <iostream>

using namespace std;

class A {
    public:
        virtual ~A() {}
};

class B : public A {
    public:
        void foo() {}
};

int main(int argc, char *argv[])
{
    A *paa = new A;
    A *pab = new B;
    B *pb;

    pb = dynamic_cast<B *>(paa);
    if (pb == NULL) {
        cout << "paa -> pb fail" << endl;
    }
    pb = dynamic_cast<B *>(pab);
    if (pb == NULL) {
        cout << "pab -> pb fail" << endl;
    }

    return 0;
}
