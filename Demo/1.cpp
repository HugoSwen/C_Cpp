#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// 多项式结构体
typedef struct Polynomial
{
    float coef[MAX_SIZE + 1]; // 系数数组
    int deg;                  // 多项式的度
} Polynomial;

// 初始化多项式
void initPolynomial(Polynomial *p)
{
    for (int i = 0; i <= MAX_SIZE; i++)
        p->coef[i] = 0;
    p->deg = 0;
}

// 读取多项式
void readPolynomial(Polynomial *p)
{
    printf("请输入多项式的最高次数：");
    scanf("%d", &p->deg);
    printf("请输入多项式各项的系数，从低到高依次输入(注:系数为0也需输入)：");
    for (int i = 0; i <= p->deg; i++)
        scanf("%f", &p->coef[i]);
}

// 输出多项式
void printPolynomial(Polynomial p)
{
    // 当多项式为0时输出0
    if (p.deg == 0 && fabs(p.coef[0]) < 1e-6)
        printf("%d", 0);

    // 当多项式不为0时
    for (int i = p.deg; i >= 0; i--)
    {
        if (fabs(p.coef[i]) > 1e-6) // 系数为0的项无需输出
        {
            if (i == p.deg && i != 0)
                printf("%fx^%d", p.coef[i], i);
            else if (i == p.deg && i == 0)
                printf("%f", p.coef[i]);
            else if (i == 1)
            {
                if (p.coef[i] > 0)
                    printf(" + %fx", p.coef[i]);
                else
                    printf(" - %fx", -p.coef[i]);
            }
            else if (i == 0)
            {
                if (p.coef[i] > 0)
                    printf(" + %f", p.coef[i]);
                else
                    printf(" - %f", -p.coef[i]);
            }
            else
            {
                if (p.coef[i] > 0)
                    printf(" + %fx^%d", p.coef[i], i);
                else
                    printf(" - %fx^%d", -p.coef[i], i);
            }
        }
    }
    printf("\n\n");
}