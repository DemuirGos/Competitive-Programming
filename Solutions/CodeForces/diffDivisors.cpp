#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int getNextPrime(int n){
    auto isPrime = [](int n){
        if (n <= 1) 
            return false; 
        for (int i = 2; i < n; i++) 
            if (n % i == 0) 
                return false; 
        return true; 
    };
    for(int j=n;;j++){
        if(isPrime(j)) return j;
    }
}
int solve(){
    int offset=1;
    cin >> offset;
    int curr = 1;
    int result = 1;
    for(int i=1;i<3;i++){
        curr = getNextPrime(curr + offset);
        result*=curr;
    }
    return result;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
}