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
  cout<<"Enter a word : ";
  cin>>txt;
  cout<<palindrome(txt);
}