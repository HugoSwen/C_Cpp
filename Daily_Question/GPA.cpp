#include <iostream>
using namespace std;

int n, gra[15], sco[15];
double pnt[105];
double GP, GS;

int main()
{
    for (int i = 60; i <= 63; i++)
        pnt[i] = 1.0;
    for (int i = 64; i <= 67; i++)
        pnt[i] = 1.5;
    for (int i = 68; i <= 71; i++)
        pnt[i] = 2.0;
    for (int i = 72; i <= 74; i++)
        pnt[i] = 2.3;
    for (int i = 75; i <= 77; i++)
        pnt[i] = 2.7;
    for (int i = 78; i <= 81; i++)
        pnt[i] = 3.0;
    for (int i = 82; i <= 84; i++)
        pnt[i] = 3.3;
    for (int i = 85; i <= 89; i++)
        pnt[i] = 3.7;
    for (int i = 90; i <= 100; i++)
        pnt[i] = 4.0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &gra[i]);
        GS += gra[i]; // 学分总和
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sco[i]);
        GP += gra[i] * pnt[sco[i]]; // 学分绩点总和
    }

    printf("%.2f", GP / GS);
}
