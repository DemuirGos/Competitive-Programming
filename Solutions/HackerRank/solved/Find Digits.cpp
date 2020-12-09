#include <bits/stdc++.h>

using namespace std;
// Complete the findDigits function below.
int main()
{
    int n;
    vector<string> input;
    cin >> n;
    while(n>0)
    {
        string inpt;
        cin >> inpt;
        input.push_back(inpt);
        n--;
    }
    for(string s:input)
    {
        int s2i=stoi(s);
        int m=0;
        for(char i_s:s)
        {
            int i=i_s-'0';
            if(i==0) continue;
            if(s2i%i==0) m++;
        }
        cout<< m << endl;

    }
}
