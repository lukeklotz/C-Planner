#include <iostream>
#include "userInfo.h"

class linkedlist{

    private:
        struct Node
        {
            userInfo newUser;
            Node * next;
            Node(userInfo& aUser)
            {
                newUser = aUser;
                next = nullptr;
            }
        };

        Node * head;
        Node * tail;
        int size;

        void destroy();
        void append(userInfo& aUser);
        void copy(linkedlist& list);

    public:
        linkedlist();
        void copy(const linkedlist& list);
        linkedlist& operator= (linkedlist&& list);

        void printList();

};