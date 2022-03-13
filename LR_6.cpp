#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int N;
    cout << "Введите размер массива N: " << "\n";
    cin >> N;
    double *a;
    a = new double[N];

    cout << "Введите элементы массива:" << "\n";

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    
    double sum = 0.0;
    int index_min = 0;
    int index_max = N;
    double curMin = a[0];
    double curMax = a[N];
    for (int i = 0; i < N; i++)
    {
        if (a[i] < 0)
        {
            sum += a[i];
        }

        if (a[i] < curMin)
        {
            curMin = a[i];
            index_min = i;
        }

        if (a[i] > curMax)
        {
            curMax = a[i];
            index_max = i;
        }
    }

    cout << "\n" << "1) сумма отрицательных элементов массива: " << sum << "\n";
    
    bool flag = false;
    double prod = 1.0;
    if (fabs(index_max - index_min) != 1)
    {
        flag = true; 
        if (index_max < index_min)
        {
            for (int i = index_max + 1; i < index_min; i++)
            {
                prod *= a[i];
            }
        }
        else if (index_max > index_min)
        {
            for (int i = index_min + 1; i < index_max; i++)
            {
                prod *= a[i];
            }
        }
    }
    
    if (flag)
    {
        cout << "2) произведение (max; min) элементов массива: " << prod << "\n";
    }
    else
    {
        cout << "2) Мин. и макс. элементы массива стоят друг за другом" << "\n";
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                double temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "\n" << "Отсортированный по возрастанию массив: " << "\n";
    for(int i = 0; i < N; i++)
    {
        cout << a[i] << "\n";
    }
}
