#include <bits/stdc++.h>
#include <string>
using namespace std;
#include <cmath>
vector<string> split_string(string);

// Complete the beautifulDays function below.
int rever(int n)
{
    string s=to_string(n);
    for(int i=0;i<s.size()/2;i++)
        swap(s[i],s[s.size()-i-1]);
    return stoi(s);
}
void swap(char a,char b)
{
    char c=a;
    a=b;
    b=c;
}
int abs(int n)
{   if(n<0) return -n;
    else return n;
}
int beautifulDays(int i, int j, int k) {
    int count=0;
    for(int n=i;n<=j;n++)
        if(abs(n-rever(n))%k==0) count++;

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ijk_temp;
    getline(cin, ijk_temp);

    vector<string> ijk = split_string(ijk_temp);

    int i = stoi(ijk[0]);

    int j = stoi(ijk[1]);

    int k = stoi(ijk[2]);

    int result = beautifulDays(i, j, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
