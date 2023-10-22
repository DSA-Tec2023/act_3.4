#pragma once
#include "node.hpp"

class queue {
public:
    Node* data;
    queue* next;
    queue(Node* p);

    void push(Node* p);
    Node* front();
    void pop();
    bool empty();
    void print();

};