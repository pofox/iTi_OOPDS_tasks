#include <iostream>
#include <string.h>

struct student
{
    std::string name;
    int ID;
    student* parent = NULL;
    student* left = NULL;
    student* right = NULL;
};


struct BinaryTree {
    student* root = NULL;
    void Insert(student* s)
    {
        bool searching = true;
        student* newroot = root;
        if (root == NULL)
        {
            root = s;
            return;
        }
        while(serching)
        {
            if (s->ID < newroot->ID)
            {
                if (newroot->left == NULL)
                {
                    newroot->left = s;
                    searching = false;
                }
                newroot = newroot->left;
            }
            if (newroot->right == NULL)
            {
                newroot->right = s;
                searching = false;
            }
            newroot = newroot->right;
        }
    }
    bool Find(int id)
    {
        bool searching = true;
        student* newroot = root;
        if (root == NULL)
        {
            return false;
        }
        while(serching)
        {
            if (id == newroot->ID) return true;
            if (id < newroot->ID)
            {
                if (newroot->left == NULL) searching = false;
                newroot = newroot->left;
            }
            if (newroot->right == NULL) searching = false;
            newroot = newroot->right;
        }
        return false;
    }
    void Remove(student* s)
    {

    }


};

int main()
{


    return 0;
}
