#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int step=0;
    int prevstep=0;
    int count=0;
    for(int i=0;i<s.size();i++)
    {  
        prevstep=step;
        if(s[i]=='U') step++;
        if(s[i]=='D') step--;
        if(step==0 && prevstep==-1) count++;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
