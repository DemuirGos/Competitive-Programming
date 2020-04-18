#include <bits/stdc++.h>
#include<utility>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
int main()
{
    map<int,pair<int,vector<int>>> m;
    int n;cin >> n;int count=0;
    for(;n>0;n--) 
    {
            int i;cin >>i;
            m[-i].first=1;m[-i].second={};
    }
    int k;cin >> k;vector<int> result(k+1,0);
    for(;k>0;k--) 
    { 
        int i;cin >>i;
        m[-i].first+=2;m[-i].second.push_back(k);
    }
    for(map<int,pair<int,vector<int>>>::iterator i=m.begin();i!=m.end();i++)
    {
        count++;
        if(i->second.first>=2) 
        {
            if(i->second.first%2==0) {
                while(!i->second.second.empty())
                {   
                    result[i->second.second[i->second.second.size()-1]]=count;
                    i->second.second.pop_back();
                }
                count--;
            }
            if(i->second.first%2==1) {
                while(!i->second.second.empty())
                {   
                    result[i->second.second[i->second.second.size()-1]]=count;
                    i->second.second.pop_back();
                }
            }
        }
    }
    for(int i=result.size()-1;i>0;i--) cout << result[i] << endl;
}
