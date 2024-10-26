

#include <iostream>

struct position
{
    float x;
    float y;
};
struct character
{
    position p;
    int health;
};

struct player
{
    character c;
    char name[10];
};

struct enemy
{
    character c;
    bool boss;
};

struct npc
{
    character c;
    char dialog[100];
};

struct collectable
{
    char name[10];
    int id;
};

struct enventory
{
    int ids[10];
};

int main()
{
    std::cout << sizeof(position) <<"\n";
    std::cout << sizeof(character) << "\n";
    std::cout << sizeof(player) << "\n";
    std::cout << sizeof(enemy) << "\n";
    std::cout << sizeof(npc) << "\n";
    std::cout << sizeof(collectable) << "\n";
    std::cout << sizeof(enventory) << "\n";
}


