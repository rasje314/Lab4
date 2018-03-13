#include "Sorted_List.h"
#include <iostream>

using namespace std;

// 7-1.
// 7-2.

struct Sorted_List::Node
{
    int value{};
    Node *next{NULL};
    Node(int val, Node *ne = NULL)
    {
        value = val;
        next = ne;
    }
};

Sorted_List::
Sorted_List(Sorted_List&& original)
{
    //cout << "=====MOVE CONSTRUCTOR=====" << endl;
    head = original.head;
    sizeCount = original.sizeCount;
    original.head = nullptr;
    original.sizeCount=0;
}

Sorted_List&
Sorted_List:: operator=(Sorted_List&& right)
{
    //cout << "=====MOVE ASSIGNMENT=====" << endl;
    head = right.head;
    sizeCount = right.sizeCount;
    right.head = nullptr;
    right.sizeCount=0;
}

Sorted_List::
Sorted_List(const Sorted_List& original)
{
    //cout << "=====COPY CONSTRUCTOR=====" << endl;
    destroyList(head);
    head = copyList(original.head);
    sizeCount = original.sizeCount;
}

Sorted_List&
Sorted_List:: operator=(Sorted_List& right)
{
    //cout << "=====ASSIGNMENT OPERATOR=====" << endl;
    destroyList(head);
    sizeCount = right.sizeCount;
    head = copyList(right.head);
}

Sorted_List::Node *
Sorted_List::copyList(Node *aList)
{
    if(aList == NULL)
    {
        return NULL;
    }
    else
    {
        Node *tailCopy = copyList(aList->next);
        return new Node(aList->value, tailCopy);
    }
}

void Sorted_List::destroyList(Node *aList = NULL)
{
    if(aList != NULL)
    {
        Node *tail = aList->next;
        delete aList;
        destroyList(tail);
    }
}

Sorted_List::Sorted_List():
head(NULL), sizeCount(0)
{
}

Sorted_List::Node * create_node( int value, Sorted_List::Node *next = nullptr )
{
    return new Sorted_List::Node { value, next };
}

Sorted_List::Node* Sorted_List::recursive_ordered_insert( Sorted_List::Node *node,int value )
{
    if ( ( node == nullptr ) || !( node->value < value ) )
    {
        return create_node( value, node );
    }

    node->next = recursive_ordered_insert( node->next, value );
    return node;
}

void Sorted_List::insert(int value)
{
    Sorted_List::sizeCount++;
    head = recursive_ordered_insert(head, value);
}

void Sorted_List::display() const
{
    Node *ptr = head;
    while (ptr)
    {
        cout << ptr->value << endl;
        ptr = ptr->next;
    }
}

int Sorted_List::getFirst() const
{
    return head->value;
}

int Sorted_List::size() const
{
    return Sorted_List::sizeCount;
}

bool Sorted_List::is_empty() const
{
    if (Sorted_List::size() == 0)
    { 
        return true;
    }
    else 
    {
        return false;
    }
}

int Sorted_List::get(int id) const
{
    Node *ptr = head;
    int counter{0};
    while (counter < id && ptr)
    {
        ptr = ptr->next;
        counter++;
    }
    try
    {
        return ptr->value;
    }
    catch (const std::exception&)
    {
        return -1;
    }
}

void Sorted_List::delete_first()
{
    if(sizeCount > 0)
    {
        Node *ptr;
        ptr = head;
        head = head->next;
        delete ptr;
        Sorted_List::sizeCount--;
    }
}

void Sorted_List::removeAll()
{
   Sorted_List::Node *ptr = head;
   head = NULL;
    while (ptr != NULL)
    {
        Node *garbage = ptr;
        ptr = ptr->next;
        delete garbage;
    }
    sizeCount=0;
}

Sorted_List::~Sorted_List()
{
    //cout << "=====DESTRUCTOR=====" << endl;
    Sorted_List::Node *ptr = head;
    while (ptr != NULL)
    {
        Node *garbage = ptr;
        ptr = ptr->next;
        delete garbage;
    }
}
