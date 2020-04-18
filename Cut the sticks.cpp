#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr;
    int n;
    scanf("%d",&n);
    while(n>0)
    {
     int i;
     scanf("%d",&i);
     arr.push_back(i);
     n--;
    }
    sort(arr.begin(),arr.end(),greater<int>());
    while(arr.size()>=1)
    {
        cout << arr.size()<< endl;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==arr[arr.size()-1]) {arr.pop_back();i--;continue;}
            arr[i]-=arr[arr.size()-1];
        }
    }
}
