#ifndef Sorted_List_H
#define Sorted_List_H

class Sorted_List
{
public:
    void delete_first();
    struct Node;
    Node *head{};
    void insert(int value);

    Sorted_List();
    ~Sorted_List();
    Sorted_List(const Sorted_List& original);
    Sorted_List(Sorted_List&& original);
    Sorted_List& operator=(Sorted_List& right);
    Sorted_List& operator=(Sorted_List&& right);

    void removeAll();
    void display() const;
    int getFirst() const;
    int size() const;
    bool is_empty() const;
    int get(int id) const;

private:
    int sizeCount{};
    Node* recursive_ordered_insert(Node *n,int value);
    static Node* copyList(Node *aList);
    static void destroyList(Node *aList);
};

#endif