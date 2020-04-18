#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
int find_substr(string s,string t)
{
    int it=0;
    int min=s.size()<t.size()?s.size():t.size();
    for(int i=0;i<min;i++)
    if(s[i]==t[i]) it++;
    else return it;
    return it;
}

string appendAndDelete(string s, string t, int k) {
    vector<char> s_v,t_v;
    int min;
    min = s.size()+t.size()-2*find_substr(s,t);//-2
    if(k>= min && ( k>s.size()+t.size() || (k-min)%2==0)) return "Yes";
    else 
    {
        return "No";
    }
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
