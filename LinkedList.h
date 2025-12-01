#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
using namespace std;


class LinkedList {
private:
    struct Node {
        string name;
        Node* next;

        Node(const string& n) {
            name = n;
            next = nullptr;
        }
    };

    Node* head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void push_front(const string& n);


    void push_back(const string& n);

    bool insert_after(const string& target, const string& n);

    bool remove_first(const string& n);

    bool contains(const string& n) const;

    int get_size() const;

    void reverse();

    string to_string() const;
};

#endif
