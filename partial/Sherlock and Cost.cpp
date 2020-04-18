#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the cost function below.
int cost(vector<int> B) {
    vector<int> A,A2;int t,T;t=T=0;A={1};A2={B[0]};
    for(int i=1;i<B.size();i++){
        if(abs(A[i-1]-B[i])>abs(A[i-1]-1)) A.push_back(B[i]);
        else A.push_back(1);
        if(abs(A2[i-1]-B[i])>abs(A2[i-1]-1)) A2.push_back(B[i]);
        else A2.push_back(1);
    }
    for(int i=1;i<A.size();i++)
    {
        t+=abs(A[i]-A[i-1]);T+=abs(A2[i]-A2[i-1]);
    }
    return max(T,t);
}

int main()
{
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        vector<int> v;
        while(n--)
        {
            int a;cin >> a;v.push_back(a);
        }
        cout << cost(v) << endl;
    }
}
