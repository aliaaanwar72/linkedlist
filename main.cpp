#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList students;

    cout << "adding students " << endl;
    students.push_front("Aliaa");
    students.push_front("Anwar");
    students.push_front("Mohamed");

    cout << "List students: " << students.to_string() << endl;

    cout << "Add at back..." << endl;
    students.push_back("Mohamed");
    students.push_back("Hassan");

    cout << "List now: " << students.to_string() << endl;

    cout << "Insert Dina after Aliaa" << endl;
    students.insert_after("Aliaa", "Dina");
    cout << students.to_string() << endl;

    cout << "Remove Mohamed" << endl;
    students.remove_first("Mohamed");
    cout << students.to_string() << endl;

    cout << "Reverse list" << endl;
    students.reverse();
    cout << students.to_string() << endl;

    cout << "students " << students.get_size() << endl;

    return 0;
}
