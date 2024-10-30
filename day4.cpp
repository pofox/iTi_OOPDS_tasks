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
    student s1,s2,s3,s4,s5;
    s1.name = "a";
    s2.name = "b";
    s3.name = "c";
    s4.name = "d";
    s5.name = "e";
    queue q;
    q.Enqueue(&s1);
    q.Enqueue(&s2);
    q.Enqueue(&s3);
    q.EnqueueAtIndex(&s4,1);
    q.EnqueueAtIndex(&s5,3);
    for(int i=0;i<5;i++)
    {
        student* temp=q.Dequeue();
        std::cout<<"name : "<<temp->name<<"\n";
    }
    return 0;
}
