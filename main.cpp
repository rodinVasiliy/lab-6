#include<libutils/io.h>
#include<iostream>
#include<time.h>
#include<chrono>
#include"Sort.h"
using namespace std;
template<typename T>
void printArr(T* arr, size_t size) {
	for (int i = 0;i < size;++i) {
		printf("%5d", arr[i]);
	}
	printf("\n");
}
template<typename T>
void fillArr(T* arr, size_t size) {
	size_t count = 0;
	while (count != size) {
		arr[count] = rand() % 100000;
		count++;
	}
}
int main() {
	chrono::steady_clock time1;
	int size = utils::read_int("enter size of array\n", 0, 15000000000);
	int* arr = new int[size]();
	//fillArr(arr, size);
	//int arr[16] = { 21,56,64,76,63,78,56,25 };
	//printArr(arr, size*2);
	for(int i=0;i<10;++i)
	{
		fillArr(arr, size);
		//sortIns(arr, size);
		//
		//naturalDoubleMerge<int>(arr, size);
		auto start = time1.now();
		//ShellSort(arr, size);
		merge(arr, size);
		auto end = time1.now();
		chrono::duration<double> diff = end - start;
		cout << "\nTime= " << diff.count() << endl;
	}
 	//merge(arr, size);
	//printArr(arr, size);
	//ShellSort(arr, size);
	//naturalDoubleMergeSort(arr, size);
	//printArr(arr, size);
	delete [] arr;
	arr=nullptr;
	system("pause");
	return 0;
}