#include <iostream>
#include <string.h>

struct node 
{
    string name;
    string address;
    node* next = NULL;
};
 
 
struct queue {
    node* first = NULL;
    node* last = NULL;

    int Find(node* n)
    {
      if (first == NULL) return -1;
      node* temp=first;
      int idx = 0;
      while(temp != NULL)
      {
        if (temp == n) return idx;
        idx++;
      }
      return -1;
    }
    void Enqueue(node* newNode) 
    {
        if (first == NULL && last == NULL)
        {
            first = last = newNode;
            return;
        }
        last->next = newNode;
        last = newNode;
    }
    void EnqueueAtIndex(node* newNode,int idx) 
    {
        idx--;
        if (first == NULL && last == NULL)
        {
            first = last = newNode;
            return;
        }
        node* n = first;
        while (idx != 0)
        {
          n=n->next;
          idx--;
        }
        newNode->next = n->next;
        n->next = newNode;
    }
    node* Dequeue() 
    {
        if (last == NULL) {
            std::cout << " the queue is empty !" << "\n";
            return NULL;
        }
        node* temp;
        temp = first;
        first = first->next;
        return temp;
    }
    
 
};

int main()
{
  return 0;
}
