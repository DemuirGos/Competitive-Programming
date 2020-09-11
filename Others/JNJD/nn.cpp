#include<iostream>
using namespace std;
int main(){
  int n;cin >> n;
  int s=0;
  while(n--){
    int a;cin >> a;
    s+=a;
  }
  cout << s;
}