/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main()
{
    int t;cin >> t;
    while(t--)
    {
    map<int,vector<int>> id;
    int n,money;cin >> money>> n;
    vector<bool> id_v(money,0);
    for(int j=1;j<=n;j++) 
    {
        int i;cin >> i;if(i<money) 
        {
        id[i].push_back(j);id_v[i]=1;
        }
        
    }
    set<int> rslt;
    for(int i=1;i<=id_v.size()/2;i++)
    {
        if(id_v[i]&&id_v[id_v.size()-i] && id[i].size()==1)
        {
            rslt.insert(id[i][0]);rslt.insert(id[id_v.size()-i][0]);
            break;
        }
    }
    if(id[id_v.size()/2].size()>1 )
    {
            rslt.insert(id[id_v.size()/2][0]);rslt.insert(id[id_v.size()/2][1]);
    }
    for(auto i:rslt) cout << i << " ";
    cout << endl;
    }
}

