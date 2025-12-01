#include "LinkedList.h"
#include <iostream>
//aliaa anwer
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    Node* cur = head;
    while (cur != nullptr) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
}

void LinkedList::push_front(string name) {
    Node* n = new Node(name);
    n->next = head;
    head = n;
    size++;
}

void LinkedList::push_back(string name) {
    Node* n = new Node(name);

    if (head == nullptr) {
        head = n;
    } else {
        Node* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = n;
    }

    size++;
}

bool LinkedList::insert_after(string target, string name) {
    Node* cur = head;

    while (cur != nullptr) {
        if (cur->data == target) {
            Node* n = new Node(name);
            n->next = cur->next;
            cur->next = n;
            size++;
            return true;
        }
        cur = cur->next;
    }

    return false;
}

bool LinkedList::remove_first(string name) {
    if (head == nullptr) return false;

    if (head->data == name) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        size--;
        return true;
    }

    Node* cur = head;
    while (cur->next != nullptr) {
        if (cur->next->data == name) {
            Node* del = cur->next;
            cur->next = del->next;
            delete del;
            size--;
            return true;
        }
        cur = cur->next;
    }

    return false;
}

bool LinkedList::contains(string name) const {
    Node* cur = head;
    while (cur != nullptr) {
        if (cur->data == name) return true;
        cur = cur->next;
    }
    return false;
}

int LinkedList::get_size() const {
    return size;
}

void LinkedList::reverse() {
    Node* prev = nullptr;
    Node* cur = head;
    Node* nxt = nullptr;

    while (cur != nullptr) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    head = prev;
}

string LinkedList::to_string() const {
    string s = "";
    Node* cur = head;

    while (cur != nullptr) {
        s += cur->data;
        if (cur->next != nullptr) s += " -> ";
        cur = cur->next;
    }

    return s;
}
