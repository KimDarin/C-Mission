#include <iostream>

class Arr
{
public:
    int sum;
    double average;

    Arr() : sum(0), average(0.0) {}

    void cal(int arr[], int size) {
        sum = 0;

        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }

        average = sum / size;
    }

};

int main()
{
    const int size = 5;
    int arr[size] = { 100, 95, 85, 88, 98 };

    Arr calculator;
    calculator.cal(arr, size);

    printf("Sum = %d\n", calculator.sum);
    printf("average = %.2f\n", calculator.average);
}

