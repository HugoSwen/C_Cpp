#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// ����ʽ�ṹ��
typedef struct Polynomial
{
    float coef[MAX_SIZE + 1]; // ϵ������
    int deg;                  // ����ʽ�Ķ�
} Polynomial;

// ��ʼ������ʽ
void initPolynomial(Polynomial *p)
{
    for (int i = 0; i <= MAX_SIZE; i++)
        p->coef[i] = 0;
    p->deg = 0;
}

// ��ȡ����ʽ
void readPolynomial(Polynomial *p)
{
    printf("���������ʽ����ߴ�����");
    scanf("%d", &p->deg);
    printf("���������ʽ�����ϵ�����ӵ͵�����������(ע:ϵ��Ϊ0Ҳ������)��");
    for (int i = 0; i <= p->deg; i++)
        scanf("%f", &p->coef[i]);
}

// �������ʽ
void printPolynomial(Polynomial p)
{
    // ������ʽΪ0ʱ���0
    if (p.deg == 0 && fabs(p.coef[0]) < 1e-6)
        printf("%d", 0);

    // ������ʽ��Ϊ0ʱ
    for (int i = p.deg; i >= 0; i--)
    {
        if (fabs(p.coef[i]) > 1e-6) // ϵ��Ϊ0�����������
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

// ����ʽ�ӷ�
Polynomial addPolynomial(Polynomial p1, Polynomial p2)
{
    Polynomial result;
    initPolynomial(&result);

    // �͵Ķ�����ֵΪ������ʽ�ϴ�Ķ�
    int deg = p1.deg > p2.deg ? p1.deg : p2.deg;
    result.deg = deg;

    for (int i = 0; i <= deg; i++)
        result.coef[i] = p1.coef[i] + p2.coef[i];

    // ȥ�������ǰ����
    while (result.deg > 0 && fabs(result.coef[result.deg]) < 1e-6)
        result.deg--;

    return result;
}

// ����ʽ����
Polynomial subPolynomial(Polynomial p1, Polynomial p2)
{
    Polynomial result;
    initPolynomial(&result);

    // ��Ķ�����ֵΪ������ʽ�ϴ�Ķ�
    int deg = p1.deg > p2.deg ? p1.deg : p2.deg;
    result.deg = deg;

    for (int i = 0; i <= deg; i++)
        result.coef[i] = p1.coef[i] - p2.coef[i];

    // ȥ�������ǰ����
    while (result.deg > 0 && fabs(result.coef[result.deg]) < 1e-6)
        result.deg--;

    return result;
}

// ����ʽ�˷�
Polynomial mulPolynomial(Polynomial p1, Polynomial p2)
{
    Polynomial result;
    initPolynomial(&result);

    // ���Ķ�Ϊ������ʽ��֮��
    int deg = p1.deg + p2.deg;
    result.deg = deg;

    for (int i = 0; i <= p1.deg; i++)
        for (int j = 0; j <= p2.deg; j++)
            result.coef[i + j] += p1.coef[i] * p2.coef[j];

    // ȥ�������ǰ����
    while (result.deg > 0 && fabs(result.coef[result.deg]) < 1e-6)
        result.deg--;

    return result;
}

// ����ʽ����
void divPolynomial(Polynomial p1, Polynomial p2, Polynomial *quotient, Polynomial *remainder)
{
    initPolynomial(quotient);
    initPolynomial(remainder);

    Polynomial dividend = p1; // ������
    Polynomial divisor = p2;  // ����

    // ��������
    if (divisor.deg == 0 && fabs(divisor.coef[0]) < 1e-6)
    {
        printf("��������Ϊ0!\n\n");
        return;
    }

    int deg_dif = dividend.deg - divisor.deg; // ������ʽ��ߴ�����
    if (quotient->deg < deg_dif)
        quotient->deg = deg_dif; // �̵Ķ�Ϊ������ʽ��֮��

    while (deg_dif >= 0)
    {
        Polynomial temquo, tempro; // ������ʱ�洢�̺ͻ�������
        initPolynomial(&temquo);
        initPolynomial(&tempro);

        float factor = dividend.coef[dividend.deg] / divisor.coef[divisor.deg]; // ���㵱ǰ������Ӧ��ϵ��
        quotient->coef[deg_dif] = temquo.coef[deg_dif] = factor;                // ͬʱ���̺���ʱ�̸�ֵ
        temquo.deg = deg_dif;                                                   // ��ʱ�̵Ķ�Ϊ��ǰ����

        tempro = mulPolynomial(temquo, divisor);    // �ó�������ʱ�̣��õ�һ����ʱ��
        dividend = subPolynomial(dividend, tempro); // ��������ȥ��ʱ�����õ��µı�����
        deg_dif = dividend.deg - divisor.deg;       // ������ߴ�����
    }

    *remainder = dividend; // �޷�����ʱ����������Ϊ����
}

int main()
{
    Polynomial p1, p2; // �����������ʽp1,p2

    initPolynomial(&p1), initPolynomial(&p2); // ��ʼ������ʽ
    readPolynomial(&p1), readPolynomial(&p2); // ��ȡ����ʽ

    Polynomial res, quotient, remainder; // �������ʽ�Ӽ��˽��res�������quotient, remainder

    // ����
    int n;
    bool ex = false;
    while (!ex)
    {
        printf("����������Ҫ���еĲ�����ţ�\n");
        printf("1. ����ʽ�ӷ�\n2. ����ʽ����\n3. ����ʽ�˷�\n4. ����ʽ����\n5. �˳�\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("�ͣ�\n");
            res = addPolynomial(p1, p2);
            break;
        case 2:
            printf("�\n");
            res = subPolynomial(p1, p2);
            break;
        case 3:
            printf("����\n");
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
            printPolynomial(res); // ����������ʽ
        else
        {
            if (p2.deg != 0 || fabs(p2.coef[0]) > 1e-6)
            {
                printf("�̣�\n");
                printPolynomial(quotient);
                printf("������\n");
                printPolynomial(remainder);
            }
        }
    }

    return 0;
}