#include <bits/stdc++.h>

using namespace std;

struct air{
    int s;
    int f;
    int v;
    vector<air*> neighbors;
};
bool showOverlap(air* s1,air* s2){
     return !(s2->s>s1->f || s2->f<s1->s);
}

void colorGraph(vector<int>& result,map<int,bool> isp,air* n){
    if(!isp[n->v]){
        isp[n->v]=true;
        vector<int> dR=result;
        for(auto i:n->neighbors){
            dR.push_back(i->v);
            colorGraph(dR,isp,i);
            if(dR.size()>result.size()){
                result=dR;
            }
            dR.pop_back();
        }
    }
}

int main(){
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<air*> shows;
        vector<int> recorded;
        for(int i=1;i<=n;i++){
            air* show = new air();
            air* repShow = new air();
            cin >> show->s >> show->f;
            cin >> repShow->s >> repShow->f;
            show->v=repShow->v=i;
            shows.push_back(show);
            shows.push_back(repShow);
        }
        for(int i=0;i<shows.size();i++){
            for(int j=0;j<shows.size();j++){
                if(i!=j){
                    if(!showOverlap(shows[i],shows[j])){
                        shows[i]->neighbors.push_back(shows[j]);
                    }
                }
            }
        }
        vector<int> dR=recorded;
        for(auto s:shows){
            map<int,bool> processed;
            dR.push_back(s->v);
            colorGraph(dR,processed,s);
            if(dR.size()>recorded.size()){
                recorded=dR;
            }
        }
        for(auto i:recorded) cout << i << " ";
        cout << endl;
    }
}
