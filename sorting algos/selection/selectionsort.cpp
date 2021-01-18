#include<iostream>
using namespace std;
int main() {
  int arr[] = {12,4,7,1,13,-1,7};
  int min;
  for(int i=0;arr[i]!=NULL;i++) cout<<arr[i]<<"\t";
  for(int i=0;arr[i]!=NULL;i++) {
    min = i;
    for(int j=i;arr[j]!=NULL;j++) 
      min = (arr[min]<arr[j])? min : j;
    if(arr[i]>arr[min]) {
      arr[i] = arr[i] ^ arr[min];
      arr[min] = arr[i] ^ arr[min];
      arr[i] = arr[i] ^ arr[min];
    } 
  }
  cout<<endl;
  for(int i=0;arr[i]!=NULL;i++) cout<<arr[i]<<"\t";
}