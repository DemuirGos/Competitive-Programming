#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int cercle) {
    vector<vector<int>> m;
    int l=matrix.size();int w=matrix[0].size();
    for(int j=0;j<min(w,l)/2;j++)
    {
        vector<int> v;
        for(int i=0;i<l-2*j-1;i++)
        {
            v.push_back(matrix[j+i][j]);
        }
        for(int i=0;i<w-2*j-1;i++)
        {
            v.push_back(matrix[l-j-1][i+j]);
        }
        for(int i=0;i<l-2*j-1;i++)
        {
            v.push_back(matrix[l-1-j-i][w-1-j]);
        }
        for(int i=0;i<w-2*j-1;i++)
        {
            v.push_back(matrix[j][w-1-j-i]);
        }
        m.push_back(v);
    }
    for(int i=0;i<m.size();i++)
    {
        vector<int> r(m[i].size());
        for(int j=0;j<m[i].size();j++)
        {
            r[(j+cercle)%m[i].size()]=m[i][j];
        }
        m[i]=r;
    }
    for(int j=0;j<m.size();j++)
    {
        int k=0;
        for(int i=0;i<l-2*j-1;i++,k++)
        {
            matrix[j+i][j]=m[j][k];
        }
        for(int i=0;i<w-2*j-1;i++,k++)
        {
            matrix[l-j-1][i+j]=m[j][k];
        }
        for(int i=0;i<l-2*j-1;i++,k++)
        {
            matrix[l-1-j-i][w-1-j]=m[j][k];
        }
        for(int i=0;i<w-2*j-1;i++,k++)
        {
            matrix[j][w-1-j-i]=m[j][k];
        }
    }
    for(auto i:matrix)
    {
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
