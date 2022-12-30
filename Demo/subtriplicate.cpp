#include <iostream>
using namespace std;

int main()
{
    char a[10];
    char b[6];
    char c[3];

    for (int i = 0; i < 6; i++)
        scanf("%c", &a[i]);

    for (int i = 0; i < 6; i++)
        cin >> b[i];

    printf("%p\t%p\t%p", a, b, c);

    return 0;
}