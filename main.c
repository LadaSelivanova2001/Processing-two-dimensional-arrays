#define _CRT_SECURE_NO_WARNINGS 
#include <locale.h> 
#include <stdio.h> 
#include <stdlib.h>//����������� ����������� ���������
#include <math.h> 

int** massiveinput(int* m, int* n);//���� ������� 
void massiveoutput(int** arr, int m, int n);//����� ������� 
void freemassive(int** arr, int m);//������� ������������ ������ 
void sum(int** arr, int m, int n);

int main()
{
    setlocale(LC_ALL, "Russian");
    int m, n;//���������� ��� ���������� ������� � �������� � ������� 
    int** arr = massiveinput(&m, &n);//����������, ������������� � ���������� ������� 

    massiveoutput(arr, m, n);//����� ������������ ������� 
    sum(arr, m, n);
    freemassive(arr, m);//������������ ������, ���������� ��� ������ 

    return 0;
}

int** massiveinput(int* m, int* n)
{
    int** arr;//���������� ������� ������ ������� 

    do//���� � ���������� ���������� ������� 
    {
        printf("������� ���������� ����� (m>=2)  m=");
        scanf("%d", m);
    } while (*m < 2);

    do//���� � ���������� ���������� �������� 
    {
        printf("������� ���������� �������� (n<=10) n=");
        scanf("%d", n);
    } while ((*n > 10) && (*n < 0));

    arr = (int**)malloc(*m * sizeof(int*));//��������� ������ ��� ��������� �� ������� ������� 

    for (int i = 0; i < *m; i++)//���� �� ���������� �� ������� 
    {
        arr[i] = (int*)malloc(*n * sizeof(int));//��������� ������ �� ������ ������� 
        for (int j = 0; j < *n; j++)//���������� ������ ������� 
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    return arr;//������� ���������� ��������� �� ���������� ������ 
}

void massiveoutput(int** arr, int m, int n)
{
    for (int i = 0; i < m; i++)//���� �� �������� 
    {
        for (int j = 0; j < n; j++)//���� �� �������� 
        {
            printf("%d\t", arr[i][j]);//����� ��������� ������ ����� ������ 
        }
        printf("\n");//������� � ����� ������ 
    }
}

void sum(int** arr, int m, int n)
{
    int max = arr[m - 1][n - 1];
    int min = arr[0][0];
    int sum;

    for (int i = 0; i < m; i++)//���� �� ���������� �� ������� 
    {
        for (int j = 0; j < n; j++)
        {
            if ((i + j) > (m - 1))
            {
                if (max < arr[i][j])
                    max = arr[i][j];
            }
            if ((i + j) < (m - 1))
            {
                if (min > arr[i][j])
                    min = arr[i][j];
            }
        }
    }

    sum = max + min;

    printf("����� ����������� ��������, �������������� ��� �������� ����������, � ����������� ��������, �������������� ��� ���, ����� %d", sum);
}

void freemassive(int** arr, int m)
{
    for (int i = 0; i < m; i++)//���� �� �������� 
    {
        free(arr[i]);//������������ ������ � ������ ������� 
    }
    free(arr);//������������ ������ ��� ���������� �� ������ ������� 
}

