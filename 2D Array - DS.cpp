#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> arr(6);
int addSHG(int i,int j)
{
    int total=0;
    for(int k=i;k<i+3;k+=2)
    {
        for(int l=j;l<j+3;l++)
        {
            total+=arr[k][l];
        }
    }
    total+=arr[i+1][j+1];
    return total;
}
// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int m=-63;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            m=max(m,addSHG(i,j));
        }
    }
    return m;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
