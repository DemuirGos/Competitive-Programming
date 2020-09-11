#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;cin >> n;
    vector<int> pop;map<int,int> city;
    for(int i=0;i<n;i++){
        int p;cin >> p;
        pop.push_back(p);
    }
    for(int i=0;i<n;i++){
        int c;cin >> c;
        city[c]=pop[i];
    }
    int m;cin >> m;
    map<int,int> cover;vector<int> cloud;
    for(int i=0;i<m;i++){
        int c;cin >> c;
        cloud.push_back(c);
    }
    int mx=0;
    for(int i=0;i<m;i++){
        int r;cin >> r;int cov=0;
        for(map<int,int>::iterator j=city.begin();j!=city.end();j++){
            if(j->first<=cloud[i]+r || j->first>=cloud[i]-r){
                cover[cloud[i]]+=j->second;
            }   
        }
    }
    for(map<int,int>::iterator j=cover.begin();j!=cover.end();j++){
        mx=max(mx,j->second);
    } 
    cout << mx << endl;
}
