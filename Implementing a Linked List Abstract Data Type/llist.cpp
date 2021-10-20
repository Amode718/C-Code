//  name: annalisse chang, rebecca zaldivar, andrei modiga
//  assignment number: 2
//  assignment: c++ linked list
//  file name: llist.cpp
//  date last modified: oct 4, 2021
//  honor statement: i have neither given nor received any unauthorized help on this assignment

#include "llist.h"
#include <string>

LinkedList::LinkedList() : head(new Node("")), tail(new Node("")), len(0)
{
    head->next = tail;
    tail->prev = head;
};

LinkedList::Node::Node(const string &item) : data(item), next(nullptr), prev(nullptr){};

LinkedList::Iterator::Iterator(Node *p) : ptr(p){};

string &LinkedList::Iterator::operator*()
{

    return this->ptr->data;
}

LinkedList::Iterator &LinkedList::Iterator::operator++()
{
    ptr = ptr->next;
    return *this;
}

LinkedList::Iterator LinkedList::Iterator::operator++(int)
{

    Iterator Iter1 = *this;
    ++(*this);
    return Iter1;
}

LinkedList::Iterator &LinkedList::Iterator::operator--()
{
    ptr = ptr->prev;
    return *this;
}

LinkedList::Iterator LinkedList::Iterator::operator--(int)
{
    Iterator Iter1 = *this;
    --(*this);
    return Iter1;
}

bool LinkedList::Iterator::operator==(const Iterator &other)
{
    return other.ptr == this->ptr;
}

bool LinkedList::Iterator::operator!=(const Iterator &other)
{
    return other.ptr != this->ptr;
}

LinkedList::Iterator LinkedList::begin() const
{

    return Iterator(head->next);
}

LinkedList::Iterator LinkedList::end() const
{

    return Iterator(tail);
}

int LinkedList::length() const
{
    return len;
}

void LinkedList::insert(const Iterator &iter, const string &item)
{
    Node *new_node = new Node(item);

    new_node->next = iter.ptr;
    new_node->prev = iter.ptr->prev;
    iter.ptr->prev->next = new_node;
    iter.ptr->prev = new_node;

    len++;
}

LinkedList::LinkedList(const LinkedList &other) : head(new Node("")), tail(new Node("")), len(0)
{
    head->next = tail;
    tail->prev = head;
    
    Iterator iter1 = other.begin();

    while (iter1 != other.end())
    {
        insert(this->end(), iter1.ptr->data);
        iter1++;
    }
}

// not done
LinkedList::~LinkedList()
{
    this->clear();
    delete this->head;
    delete this->tail;
}

// not done
LinkedList &LinkedList::operator=(const LinkedList &other)
{
    Iterator iterOther = other.begin();
    this->clear();
    while (iterOther != other.end())
    {
        this->insert(end(), iterOther.ptr->data);
        iterOther++;
    }
    return *this;
}

// not done
void LinkedList::remove(Iterator &iter)
{
    Node *node = iter.ptr;
    iter++;
    node->prev->next = node->next;
    node->next->prev = node->prev;

    delete node;
    len--;
}

// not done
LinkedList::Iterator LinkedList::find(const string &seek) const
{

    Iterator iter1 = begin();

    while (iter1 != end())
    {
        if (seek.compare(iter1.ptr->data) == 0)
        {
            return iter1;
        }
        iter1++;
    }
    return Iterator(tail);
}

// not done
void LinkedList::clear()
{
    Iterator iter1 = this->begin();
    while (iter1 != end())
    {
        iter1++;
        delete iter1.ptr->prev;
    }

    head->next = tail;
    tail->prev = head;

    len == 0;
}

// not done
bool LinkedList::operator==(const LinkedList &other) const
{
    Iterator iterThis = this->begin();
    Iterator iterOther = other.begin();
    while (iterThis != end())
    {
        if (iterThis.ptr->data.compare(iterOther.ptr->data) != 0)
        {
            return false;
        }
        iterThis++;
        iterOther++;
    }
    return true;
}

// not done
bool LinkedList::operator!=(const LinkedList &other) const
{
    return !(*this == other);
}