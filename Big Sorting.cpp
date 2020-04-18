#include <bits/stdc++.h>

using namespace std;

bool is_big(string &s1,string &s2) 
{ 
    return s1.size() < s2.size(); 
} 
void bigSort(vector<string> v) {
    sort(v.begin(),v.end(),is_big);v.push_back(v[v.size()-1]+"9");
    int c=v[0].size();int t=0;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].size()==c)
        {
            t++;
        }
        if(v[i].size()!=c)
        {
            sort(v.begin()+i-t-1,v.begin()+i);
            t=0;c=v[i].size();
        }
    }
    v.pop_back();
    for(auto i:v) cout << i << endl;
}

int main()
{
    int n;vector<string> v;
    cin >> n;while(n--)
    {
        string s;cin >> s;
        v.push_back(s);
    }
    bigSort(v);
}
