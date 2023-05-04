#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    // parent node is at the position "root"
    int Right,Left,large;
    Left=2*root+1;  // left child node is at the position (2*i+1)
    Right =2*root+2;  //right node is at (2*i +2).
    large=root;

   if(arr[root]<arr[Left] && Left<n ) //compare value of root and value of Left and check is index overflow the array length
   {
       large=Left; //store index
   }
   if(arr[large]<arr[Right] && Right<n) //compare values and check is index overflow the array length
   {
       large=Right; //store index
   }
   if(large!=root){
       //swap the values in the array
       int temp=arr[root];
       arr[root]=arr[large];
       arr[large]=temp;
       // recursion part
       heapify(arr,n,large);
   }


}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

   // extracting elements from heap one by one
   for(int i=n-1;i>=0;i--)
   {
       //swap the values in array
       swap(arr[0],arr[i]);
       //recall the heapify function
       heapify(arr,i,0);
   }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   int heap_arr[] = {4,10,66,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
