#include <bits/stdc++.h>

using namespace std;
int extract_hg(vector<vector<int>> v,int k,int l)
{
    int sum=0;
    for(int i=0;i<3;i++)
        sum+=v[l][k+i]+v[l+2][k+i];
    sum+=v[l+1][k+1];
    return sum;
}


int main()
{
    int m=-100;
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            m=max(m,extract_hg(arr,j,i));
    }
    cout << m;
    return 0;
}
