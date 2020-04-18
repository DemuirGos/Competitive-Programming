#include <bits/stdc++.h>

using namespace std;
// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    map<char,pair<int,int>> m;m[b[0]].first++;m[b[0]].second++;
    bool c=true;
    for(int i=1;i<b.size();i++)
    {
        if(b[i-1]==b[i])
        {   
            if(c)
            {
                m[b[i]].first++;m[b[i]].second--;c=false;
            }
            else
            {
                m[b[i]].first++;
            }
        }
        else
        {    m[b[i]].first++;m[b[i]].second++;c=true;}
    }
    for(map<char,pair<int,int>>::iterator i=m.begin();i!=m.end();i++)
    {
        if((i->second.first==1  && i->first!='_')||(m['_'].first==0&&i->second.second>=1))
        {
            return"NO";
        }
    }
    return"YES";
}

int main()
{
    int g;
    cin >> g;
    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        string b;
        cin >> b;
        cout << happyLadybugs(b) << "\n";
    }
}
