#include<iostream>
#include<vector>
#include<utility> 
#include <algorithm>
#include <string>
using namespace std;
int inline isPal(int n) {
        int temp = n;
        int rev = 0;
        while(n){
            rev= rev*10 + n%10;
            n /= 10;
        }
        return temp == rev;
    }
int main(){
    double p=1.0,q=1.0;
    cin >> p >> q ;
    double ratio = p/q;
    vector<pair<double,double>> arr = vector<pair<double,double>>(10000000,make_pair(0.0,1.0));
    arr[0] = make_pair(0,0);
    arr[1] = make_pair(1,0);
    
    for(int i = 2; i<arr.size(); i++){
        if(arr[i].second == 1){
            for(int j = i<<1; j<arr.size(); j+=i){
                arr[j].second = 0;
            }
        }
        arr[i].first = isPal(i);
    }
    for(int i = 0; i<arr.size()-1; i++){
        arr[i+1].second += arr[i].second;
        arr[i+1].first  += arr[i].first ;
    }
    int result = -1;
    for(int i=0;i<arr.size();i++){
        if((arr[i].second/arr[i].first) <= ratio) 
            result = max(result,i); 
    }
    cout << (result==-1 ? "Palindromic tree is better than splay tree": to_string(result));
}