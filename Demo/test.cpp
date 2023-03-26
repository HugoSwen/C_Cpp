#include <iostream>
using namespace std;

typedef struct
{
    int data;
    Lnode *p;
}Lnode, *LinkList;

void init(LinkList &L)
{
    L = (Lnode*)malloc(sizeof(Lnode));
    L -> data = 19;
}
