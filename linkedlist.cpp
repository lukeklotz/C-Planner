#include "linkedlist.h"

linkedlist::linkedlist()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void linkedlist::destroy()
{
    Node * curr = head;
    while(head)
    {
        head = curr->next;
        delete curr;
        curr = head;
    }

}

void linkedlist::copy(linkedlist& list)
{
    this->head = new Node((list.head)->newUser);
    Node *currSource = (list.head)->next;
    Node *currDestination = this->head;

    while(currSource)
    {
        currDestination->next = new Node(currSource->newUser);
        currSource = currSource->next;
        currDestination = currDestination->next;

    }
}

linkedlist& linkedlist::operator= (linkedlist&& list)
{
    if(this == &list)
    {
        return *this;
    }
    this->size = list.size;
    if(this->head)
    {
        destroy();
    }
    this->head = list.head;
    list.head = NULL;
    list.size = 0;
    return *this;

}

void linkedlist::append(userInfo& aUser)
{
    Node * newNode = new Node(aUser);
    newNode->next = nullptr;
    Node * curr = head;
    Node * prev = nullptr;
    if(!head){
        head = newNode;
        tail = newNode;
    } else {
        //insert at tail
        tail->next = newNode;
        tail = newNode;
    }
}

void linkedlist::printList()
{
    Node * curr = head;

    while(curr)
    {
        cout << curr->newUser.getUsername();
        cout << curr->newUser.getPassword() << endl;
        curr = curr->next;
    }
}
