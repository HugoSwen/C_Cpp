#include <iostream>
using namespace std;

union
{
    int nX;
    char cY[10];
} u;

int main()
{
    u.nX = 45678;
    gets(u.cY);

    printf("%d,", u.nX);
    puts(u.cY);
    return 0;
}