
#include <iostream>
#include <vector>

using namespace std;

void insertion(vector <int> &arr){
    
    int num,j;
	for(int i=0;i<arr.size();i++){
		num=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>num){
			arr[j+1]=arr[j];
			--j;
		}
		arr[j+1]=num;
	
	}
		for(int k=0;k<arr.size();k++){
			cout<<arr[k]<<" ";
		}
		cout<<"    ";
    
}
float get_median(vector<int> arr2){
    if (arr2.size()%2==1){
        return arr2[(arr2.size()-1)/2.0];
    }
    else{
        return ((arr2[arr2.size()/2]+arr2[(arr2.size()/2)-1])/2.0);
    }
}

int main(){
	vector<int> arr={35,7,12,5,2,73,6,8,19,3,56};
	vector<int> arr2;
	for(int i=0;i<arr.size();i++){
	    arr2.push_back(arr[i]);
	    
	       insertion(arr2);
	       cout<<"Median value is "<<get_median(arr2)<<endl;
	    
	    
	}

	
}
