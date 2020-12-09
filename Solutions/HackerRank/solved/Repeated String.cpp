#include <bits/stdc++.h>

using namespace std;
long long count_a(string s,long k)
{
    long long a=0;
    for(long long i=0;i<k;i++) if(s[i]=='a') a++;
    return a;
}
// Complete the repeatedString function below.
long long repeatedString(string s, long n) {
    long long count=0;
    count = (long long)(n/s.size())*count_a(s,s.size());
    count+= count_a(s,n%s.size());
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
