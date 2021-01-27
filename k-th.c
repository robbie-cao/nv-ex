#include <iostream>

using namespace std;

struct Node {
    Node *next;
    double value;
};

// remove any node that has the give target_val
void filter(Node * head, double target_val)
{
    Node *itr = head;
    Node *p = nullptr;

    if (head == nullptr) {
        return ;
    }

    p = itr;
    while (!itr) {
        if (itr->value == target_val)
        {
            p = itr;
            itr = itr->next;
            delete p;
            //break;
        }
        itr = itr->next;
        p = itr;
    }

    if (!p) {
        delete p;
    }

}
