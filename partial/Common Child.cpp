#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s,c;cin >> s >> c;string t="";
    for(int i=0;i<s.size();i++)
    {
        size_t f=c.find(s[i]);
        if(f!=string::npos)
        {
            t+=s[i];
        }
    }
    int m=0;
    //cout << t << endl;
    if(t!="")
    {
        for(int i=0;i<t.size();i++)
        {
            int count=0;
            //cout << t[i];
            size_t f=c.find(t[i]);
            if(f!=string::npos)
            {
                count+=1;
                for(int j=i+1;j<t.size();j++)
                {
                    size_t ftemp=c.find(t[j],f+1);
                    if(ftemp!=string::npos)
                    {
                        /*cout << t[j];*/f=ftemp;count++;
                    }
                }
                m=max(m,count);
            }
            //cout << endl;
        }
    }
    cout << m;
}
