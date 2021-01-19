#include<iostream>
using namespace std;
int factorial(int num) {
  if(num > 1) return num*factorial(num-1);
  else return 1;
}
int main() {
  int num;
  cout<<"Enter a number : ";
  cin>>num;
  cout<<factorial(num);
}