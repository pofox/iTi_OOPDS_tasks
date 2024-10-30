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
        while(searching)
        {
            if (s->ID < newroot->ID)
            {
                if (newroot->left == NULL)
                {
                    newroot->left = s;
                    s->parent = newroot;
                    searching = false;
                    continue;
                }
                newroot = newroot->left;
            }
            if (newroot->right == NULL)
            {
                newroot->right = s;
                s->parent = newroot;
                searching = false;
                continue;
            }
            newroot = newroot->right;
        }
    }
    bool Find(int id)
    {
        bool searching = true;
        student* newroot = root;
        if (root == NULL) return false;
        while(searching)
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
        bool searching = true;
        student* newroot = root;
        if (root == NULL) return;
        while(searching)
        {
            if (s->ID == newroot->ID)
            {
                if (newroot == root)
                {
                    if (newroot->left != NULL)
                    {
                        if (newroot->right != NULL)
                        {
                            root = newroot->left;
                            Insert(newroot->right);
                            return;
                        }
                        root = newroot->left;
                        return;
                    }
                    if (newroot->right != NULL)
                    {
                        root = newroot->right;
                        return;
                    }
                    root = NULL;
                    return;
                }
                if (newroot->left != NULL)
                {
                    if (newroot->right != NULL)
                    {
                        newroot->left->parent = newroot->parent;
                        if (newroot->ID < newroot->parent->ID)
                        {
                            newroot->parent->left = newroot->left;
                        }
                        newroot->parent->right = newroot->left;
                        Insert(newroot->right);
                        return;
                    }
                    if (newroot->ID < newroot->parent->ID)
                    {
                        newroot->parent->left = newroot->left;
                        newroot->left->parent = newroot->parent;
                        return;
                    }
                    newroot->parent->right = newroot->left;
                    newroot->left->parent = newroot->parent;
                    return;
                }
                if (newroot->right != NULL)
                {
                    if (newroot->ID < newroot->parent->ID)
                    {
                        newroot->parent->left = newroot->right;
                        newroot->right->parent = newroot->parent;
                        return;
                    }
                    newroot->parent->right = newroot->right;
                    newroot->right->parent = newroot->parent;
                    return;
                }
                newroot->parent = NULL;
                return;
            }
            if (s->ID < newroot->ID)
            {
                if (newroot->left == NULL) return;
                newroot = newroot->left;
            }
            if (newroot->right == NULL) return;
            newroot = newroot->right;
        }
    }


};

int main()
{
    student s1,s2,s3,s4;
    s1.name = "a";
    s2.name = "b";
    s3.name = "c";
    s4.name = "d";
    s1.ID = 1;
    s2.ID = 2;
    s3.ID = 3;
    s4.ID = 4;

    BinaryTree b;
    b.Insert(&s3);
    b.Insert(&s1);
    b.Insert(&s2);
    b.Insert(&s4);

    std::cout<<"find index 2 : "<<b.Find(2)<<"\n";

    b.Remove(&s2);

    return 0;
}
