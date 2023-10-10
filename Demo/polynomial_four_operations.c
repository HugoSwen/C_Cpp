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

// 多项式加法
Polynomial addPolynomial(Polynomial p1, Polynomial p2)
{
    Polynomial result;
    initPolynomial(&result);

    // 和的度理论值为两多项式较大的度
    int deg = p1.deg > p2.deg ? p1.deg : p2.deg;
    result.deg = deg;

    for (int i = 0; i <= deg; i++)
        result.coef[i] = p1.coef[i] + p2.coef[i];

    // 去除结果的前导零
    while (result.deg > 0 && fabs(result.coef[result.deg]) < 1e-6)
        result.deg--;

    return result;
}

// 多项式减法
Polynomial subPolynomial(Polynomial p1, Polynomial p2)
{
    Polynomial result;
    initPolynomial(&result);

    // 差的度理论值为两多项式较大的度
    int deg = p1.deg > p2.deg ? p1.deg : p2.deg;
    result.deg = deg;

    for (int i = 0; i <= deg; i++)
        result.coef[i] = p1.coef[i] - p2.coef[i];

    // 去除结果的前导零
    while (result.deg > 0 && fabs(result.coef[result.deg]) < 1e-6)
        result.deg--;

    return result;
}

// 多项式乘法
Polynomial mulPolynomial(Polynomial p1, Polynomial p2)
{
    Polynomial result;
    initPolynomial(&result);

    // 积的度为两多项式度之和
    int deg = p1.deg + p2.deg;
    result.deg = deg;

    for (int i = 0; i <= p1.deg; i++)
        for (int j = 0; j <= p2.deg; j++)
            result.coef[i + j] += p1.coef[i] * p2.coef[j];

    // 去除结果的前导零
    while (result.deg > 0 && fabs(result.coef[result.deg]) < 1e-6)
        result.deg--;

    return result;
}

// 多项式除法
void divPolynomial(Polynomial p1, Polynomial p2, Polynomial *quotient, Polynomial *remainder)
{
    initPolynomial(quotient);
    initPolynomial(remainder);

    Polynomial dividend = p1; // 被除数
    Polynomial divisor = p2;  // 除数

    // 除数判零
    if (divisor.deg == 0 && fabs(divisor.coef[0]) < 1e-6)
    {
        printf("除数不能为0!\n\n");
        return;
    }

    int deg_dif = dividend.deg - divisor.deg; // 两多项式最高次数差
    if (quotient->deg < deg_dif)
        quotient->deg = deg_dif; // 商的度为两多项式度之差

    while (deg_dif >= 0)
    {
        Polynomial temquo, tempro; // 定义临时存储商和积的容器
        initPolynomial(&temquo);
        initPolynomial(&tempro);

        float factor = dividend.coef[dividend.deg] / divisor.coef[divisor.deg]; // 计算当前次数对应的系数
        quotient->coef[deg_dif] = temquo.coef[deg_dif] = factor;                // 同时给商和临时商赋值
        temquo.deg = deg_dif;                                                   // 临时商的度为当前次数

        tempro = mulPolynomial(temquo, divisor);    // 用除数乘临时商，得到一个临时积
        dividend = subPolynomial(dividend, tempro); // 被除数减去临时积，得到新的被除数
        deg_dif = dividend.deg - divisor.deg;       // 更新最高次数差
    }

    *remainder = dividend; // 无法操作时，被除数即为余数
}

int main()
{
    Polynomial p1, p2; // 定义运算多项式p1,p2

    initPolynomial(&p1), initPolynomial(&p2); // 初始化多项式
    readPolynomial(&p1), readPolynomial(&p2); // 读取多项式

    Polynomial res, quotient, remainder; // 定义多项式加减乘结果res，除结果quotient, remainder

    // 测试
    int n;
    bool ex = false;
    while (!ex)
    {
        printf("请输入您需要进行的操作序号：\n");
        printf("1. 多项式加法\n2. 多项式减法\n3. 多项式乘法\n4. 多项式除法\n5. 退出\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("和：\n");
            res = addPolynomial(p1, p2);
            break;
        case 2:
            printf("差：\n");
            res = subPolynomial(p1, p2);
            break;
        case 3:
            printf("积：\n");
            res = mulPolynomial(p1, p2);
            break;
        case 4:
            divPolynomial(p1, p2, &quotient, &remainder);
            break;
        case 5:
            ex = true;
            break;
        }

        if (n != 4)
            printPolynomial(res); // 输出结果多项式
        else
        {
            if (p2.deg != 0 || fabs(p2.coef[0]) > 1e-6)
            {
                printf("商：\n");
                printPolynomial(quotient);
                printf("余数：\n");
                printPolynomial(remainder);
            }
        }
    }

    return 0;
}