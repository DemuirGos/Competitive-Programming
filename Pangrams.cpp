#include <bits/stdc++.h>

using namespace std;
// Complete the pangrams function below.
string pangrams(string s) {
    map<char,int> m;int count=0;
    for(auto i:s)
    {
        i=tolower(i);
        if(m[i] || i==' ')
        {
            continue;
        }
        else
        {
            m[i]++;
            count++;
        }
    }
    if(count==26)
        return"pangram";
    else
        return"not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
