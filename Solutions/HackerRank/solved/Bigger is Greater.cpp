#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biker_is_stroonekr(string w) {
    map<int,int> m;
    bool p=false;
    for(int i=w.size();i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(w[j]<w[i]){
                m[i]=j;
                break;
            } 
        }
    }
    top:
    int j=-1;int i=-1;
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
        if(it->second>=j && it->first>i) {
            j=it->second;i=it->first;
        }
    }
    if(j!=-1) {char t=w[i];w[i]=w[j];w[j]=t;if(j!=w.size()-1) p=!p;}
    
    if(p)
    {
        sort(w.begin()+j+1,w.end());
    }
    return w;
}

int main()
{
    int n,m;cin >> n;m=n;
    while(n--)
    {
        string s;cin >> s;string ss=biker_is_stroonekr(s);
        s=(ss==s?"no answer":ss);cout << s << "\n" ;//
    }

}
