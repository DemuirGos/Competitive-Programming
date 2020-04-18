#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;cin >>n ;
    while(n--){
        long k;cin >> k;
        int r=0;
        for(int i=1;i<=sqrt(k);i++){
            if(k%i==0) {
                if(i%2==0) r++;
                if(k/i!=i && (k/i)%2==0) r++;
            }
        }
        cout << r << endl;
    }
}
