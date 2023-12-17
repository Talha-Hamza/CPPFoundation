#include <iostream>
using namespace std;

// create a class called "List" that creates a linked list of integers
class List {
    public:
    int data;
    List *next;

    List(int input){
        data = input;
        next = nullptr;
    }

    void printList(List* head){
        List* current = head;
        while(current != nullptr){
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main(){
    List *head = new List(1);
    List *second = new List(2);
    List *third = new List(3);

    head->next = second;
    second->next = third;

    head->printList(head);  // its is a member function and hence called using the object

    // Clean up: Freeing the allocated memory
    delete head;
    delete second;
    delete third;

    return 0;
}