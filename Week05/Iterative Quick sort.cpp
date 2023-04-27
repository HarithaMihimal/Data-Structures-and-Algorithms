#include <iostream>
#include <chrono>
#include<ctime>
#include<cstdlib>
using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    int stack[high - low + 1];
    int top = -1;
    stack[++top] = low;
    stack[++top] = high;
 
    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];
 
        int p = partition(arr, low, high);
 
        if (p - 1 > low) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }
 
        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
}

int main()

{   

    for(int j=1000;j<=10000;j+=2000){
    const int sizes=j;
    int arr[sizes];
    srand(time(NULL));
    for(int i=0;i<sizes;i++){
        arr[i]=rand()%100;

    }


     auto t_start = chrono::high_resolution_clock::now();

     quicksort(arr,0,sizes-1);

    auto t_end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(t_end - t_start).count();
    cout << "Size of array =\t" << j <<"\tTime taken = "<<duration<<endl;

}

return 0;
}
