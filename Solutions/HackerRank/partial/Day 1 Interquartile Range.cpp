#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void sort_once(vector<int>& a,vector<int>& b,int n){
    int i,j;
    for(i=0;i<n-1;i++){
        int m=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[m]) m=j;
        }
        swap(a[i],a[m]);
        swap(b[i],b[m]);
    }
}
int find_mean(vector<int> a,vector<int> b,int i,int j){///wroooooong
    if((j+1-i)%2==0){
        int m1,m2;
        m1=(i+1+j)/2-1;
        m2=(i+1+j)/2;
        bool c1=true,c2=true;
        for(int k=i;k<=j;k++){
            if(b[k]>=m1 && c1){
                if(b[k]>m1)
                    m1=a[k-1];
                else
                    m1=a[k];
                c1=false;
            }
            if(b[k]>=m2 && c2){
                if(b[k]>m2)
                    m2=a[k-1];
                else
                    m2=a[k];
                c2=false;
            }
        }
        return (m1+m2)/2;
    }
    else{
        int m=(i+j)/2;
        for(int k=i;k<=j;k++){
            if(b[k]>m){
                m=a[k-1];
            }
        }
        return m;
    }
}
int main() {
    int n;cin >> n;
    vector<int> v;
    vector<int> f;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        v.push_back(a);
    } 
    for(int i=0;i<n;i++){
        int b;cin >> b;
        f.push_back(b);
    } 
    sort_once(v,f,n);
    for(int i=1;i<n;i++)
        f[i]+=f[i-1];
    int q1=find_mean(v,f,0,n/2-1);
    int q2=find_mean(v,f,n/2,n-1);
    cout << q1 << " " << q2;
    return 0;
}
