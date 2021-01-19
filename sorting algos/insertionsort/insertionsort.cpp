#include<iostream>
using namespace std;
int main() {
  int arr[] = {5,2,6,72,9,4,10,1,7,8};
  int i,j,k;
  for(i=0;arr[i]!=NULL;i++) cout<<arr[i]<<"\t";
  cout<<endl;
  for(i=1;arr[i]!=NULL;i++) {
    k=j=i;
        for(j=i;j>-1;j--) {
          if(arr[k]<arr[j]) {
            arr[j] = arr[j] + arr[k];
            arr[k] = arr[j] - arr[k];
            arr[j] = arr[j] - arr[k];
            k--;
          }

        }

  }
  for(i=0;arr[i]!=NULL;i++) cout<<arr[i]<<"\t";

}