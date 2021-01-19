#include<iostream>
using namespace std;
int powerOf(int num,int power) {
  if(power>0) return num*powerOf(num,power-1);
  else return 1;
}
int main() {
  int num,power;
  cout<<"Enter a number : ";
  cin>>num;
  cout<<"Enter power : ";
  cin>>power;
  cout<<num<<" to the power "<<power<<" is "<<powerOf(num,power);
}