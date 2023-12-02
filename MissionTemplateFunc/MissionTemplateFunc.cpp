#include <iostream>

template <typename T>
T Max(T arr[], int size) {

	T max = arr[0];

	for(int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
	
int main()
{
	int intArr[] = { 2, 26, 7, 10, 97, 98 };
	int intMax = Max(intArr, 6);
	printf("int 배열 최댓값: %d\n", intMax);

	double doubleArr[] = { 10.1, 11.2, 12.5, 13.9 };
	double doubleMax = Max(doubleArr, 4);
	printf("double 배열 최댓값: %.1f\n", doubleMax);
}

