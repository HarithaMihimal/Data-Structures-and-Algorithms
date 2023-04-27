#include <iostream>
#include <chrono>
#include<ctime>
#include<cstdlib>

using namespace std;


int partitions(int arr[],int start,int end){
    int pivot =arr[end];
    int i=start-1;
    for(int j=start;j<=end-1;j++){
        if(arr[j]<pivot){
            i++;
            int temp =arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    i++;
      int temp =arr[i];
            arr[i]=arr[end];
            arr[end]=temp;
        return i;
}
void quicksort(int arr[],int start,int end){
    if(end<=start){
        return;  //base
    }
    int pivot;
    pivot=partitions(arr,start,end);
    quicksort(arr,start,pivot-1);
    quicksort(arr,pivot+1,end);

}
int main()

{   int sizze;


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
