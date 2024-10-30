#include <iostream>
#include <string.h>

struct student 
{
    std::string name;
    std::string address;
    student* next = NULL;
};
 
 
struct queue {
    student* first = NULL;
    student* last = NULL;

    int Find(student* n)
    {
      if (first == NULL) return -1;
      student* temp=first;
      int idx = 0;
      while(temp != NULL)
      {
        if (temp == n) return idx;
        idx++;
      }
      return -1;
    }
    void Enqueue(student* newstudent) 
    {
        if (first == NULL && last == NULL)
        {
            first = last = newstudent;
            return;
        }
        last->next = newstudent;
        last = newstudent;
    }
    void EnqueueAtIndex(student* newstudent,int idx) 
    {
        idx--;
        if (first == NULL && last == NULL)
        {
            first = last = newstudent;
            return;
        }
        student* n = first;
        while (idx != 0)
        {
          n=n->next;
          idx--;
        }
        newstudent->next = n->next;
        n->next = newstudent;
    }
    student* Dequeue() 
    {
        if (last == NULL) {
            std::cout << " the queue is empty !" << "\n";
            return NULL;
        }
        student* temp;
        temp = first;
        first = first->next;
        return temp;
    }
    
 
};

int main()
{
  return 0;
}
