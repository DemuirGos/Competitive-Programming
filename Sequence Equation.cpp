#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<string> split_string(string);
vector<int> checked(51,-1);
// Complete the permutationEquation function below.
int p_it(int i,vector<int> p)
{
    if(checked[i]>=0) return checked[i];
    for(int j=1;j<=p.size();j++)
        if(p[j-1]==i) 
        {
            checked[i]=j;
            return j;
        }
    return -1;
}
vector<int> permutationEquation(vector<int> p) {
    vector<int> v={};
    for(int i=1;i<=p.size();i++)
    {
        int c = p_it(i,p);
        if(c>=0) 
        {
            int c2=p_it(c,p);
            if(c2>=0) v.push_back(c2);
        }
    }
    return v;

}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    vector<int> result = permutationEquation(p);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
