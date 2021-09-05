#define _CRT_SECURE_NO_WARNINGS 
#include <locale.h> 
#include <stdio.h> 
#include <stdlib.h>//подключение стандартных библиотек
#include <math.h> 

int** massiveinput(int* m, int* n);//ввод массива 
void massiveoutput(int** arr, int m, int n);//вывод массива 
void freemassive(int** arr, int m);//функци€ освобождени€ пам€ти 
void sum(int** arr, int m, int n);

int main()
{
    setlocale(LC_ALL, "Russian");
    int m, n;//переменные дл€ количества строчек и столбцов в массиве 
    int** arr = massiveinput(&m, &n);//объ€вление, инициализаци€ и заполнение массива 

    massiveoutput(arr, m, n);//вывод изначального массива 
    sum(arr, m, n);
    freemassive(arr, m);//освобождение пам€ти, выделенной под массив 

    return 0;
}

int** massiveinput(int* m, int* n)
{
    int** arr;//объ€вление массива внутри функции 

    do//ввод и считывание количества строчек 
    {
        printf("¬ведите количество строк (m>=2)  m=");
        scanf("%d", m);
    } while (*m < 2);

    do//ввод и считывание количества столбцов 
    {
        printf("¬ведите количество столбцов (n<=10) n=");
        scanf("%d", n);
    } while ((*n > 10) && (*n < 0));

    arr = (int**)malloc(*m * sizeof(int*));//выделение пам€ти под указатели на строчки массива 

    for (int i = 0; i < *m; i++)//цикл по указател€м на строчки 
    {
        arr[i] = (int*)malloc(*n * sizeof(int));//выделение пам€ти на строку массива 
        for (int j = 0; j < *n; j++)//заполнение строки массива 
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    return arr;//функци€ возвращает указатель на заполенный массив 
}

void massiveoutput(int** arr, int m, int n)
{
    for (int i = 0; i < m; i++)//цикл по строчкам 
    {
        for (int j = 0; j < n; j++)//цикл по столбцам 
        {
            printf("%d\t", arr[i][j]);//вывод элементов строки через пробел 
        }
        printf("\n");//переход к новой строке 
    }
}

void sum(int** arr, int m, int n)
{
    int max = arr[m - 1][n - 1];
    int min = arr[0][0];
    int sum;

    for (int i = 0; i < m; i++)//цикл по указател€м на строчки 
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

    printf("—умма наибольшего элемента, расположенного под побочной диагональю, и наименьшего элемента, расположенного над ней, равна %d", sum);
}

void freemassive(int** arr, int m)
{
    for (int i = 0; i < m; i++)//цикл по строчкам 
    {
        free(arr[i]);//освобождение пам€ти в строке массива 
    }
    free(arr);//освобождение пам€ти дл€ указателей на строки массива 
}

