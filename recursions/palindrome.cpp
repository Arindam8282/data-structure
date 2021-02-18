#include<iostream>
#include<string>
using namespace std;
string rev(string str) {
  if(str.length()>0) return str[str.length()-1]+rev(str.substr(0,str.length()-1));
  else return "";
}
string palindrome(string str) {
  if(rev(str) == str) return "PALINDROME";
  else return "NOT PALINDROME";
}


int main() {
  string txt;
  int p=0,np=0;
  int s = 4200;
  int e = 19000;
  for(int i=s;i<=e;i++)   
  if(palindrome(to_string(i))=="PALINDROME") p++;
  else np++;
  cout<<"number of Palindrome : "<<p<<"\nnumber of not : "<<np;
}