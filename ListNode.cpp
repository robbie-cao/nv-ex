#include <iostream>


typedef unsigned int UINT32;

struct Node {
    UINT32 data;
    Node *next;
};


Node * reverseList(Node *head)
{
    std::stack<Node *> stk = new std::stack<Node *>();

    // Push all nodes into stack
    while (head != NULL) {
        stk.push(head);
        head = head.next;
    }
    if (stk.isEmpty())
        return NULL;
    Node * node = stk.pop();
    Node * res = node;
    // Pop out all nodes from stack and make a list with them
    while (!stk.empty()) {
        Node * tempNode = stk.pop();
        node.next = tempNode;
        node = node.next;
    }
    node.next = NULL;

    return res;
}

