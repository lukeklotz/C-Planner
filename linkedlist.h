#include <iostream>

class linkedlist{

    private:
        struct Node
        {
            Node * next;

        };

        Node * head;
        Node * tail;
    public:
        void copy(const linkedlist& list);
        linkedlist& operator= (linkedlist&& list);

        void printList();
};