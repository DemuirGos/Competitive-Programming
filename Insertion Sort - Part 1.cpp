#include <bits/stdc++.h>

using namespace std;
void sort(vector<int> arr)  
{  
    int i, key, j;
    for (i = 1; i < arr.size(); i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            for(auto i:arr) cout << i << " ";
            cout << endl;
            j = j - 1; 
        }  
        arr[j + 1] = key;  
    } 
    for(auto i:arr) cout << i << " ";
    cout << endl;
}  

int main()
{
    int n;cin >> n;
    vector<int> v;
    while(n--)
    {
        int a;cin >> a;
        v.push_back(a);
    }
    sort(v);
}
