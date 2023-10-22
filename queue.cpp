#include "queue.hpp"


queue::queue(Node* p) {
    this->data = p;
    this->next = nullptr;
}

void queue::push(Node* p) {
    if (this->next == nullptr) {
        this->next = new queue(p);
    }
    else {
        queue* current = this->next;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new queue(p);
    }
}

Node* queue::front() {
    return this->next->data;
}

void queue::pop() {
    queue* temp = this->next;
    this->next = this->next->next;
    delete temp;
}

bool queue::empty() {
    if (this->next == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

void queue::print() {
    queue* current = this->next;
    while (current != nullptr) {
        std::cout << current->data->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}