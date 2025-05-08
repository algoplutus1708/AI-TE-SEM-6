#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[5]={5,4,2,3,1};
	for(int i=0;i<5;i++){
		int mn=arr[i],ind=i;
		for(int j=i+1;j<5;j++){
			if(arr[j]<mn){
				mn=arr[j];
				ind=j;
			}
		}
		swap(arr[i],arr[ind]);
	}
	for(int i=0;i<5;i++) cout<<arr[i];
}