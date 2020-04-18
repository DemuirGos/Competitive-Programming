#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
    	cin >> a[a_i];
    }
    int num_swaps=0;
    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                num++;num_swaps++;
            }
        }
        if (num == 0) {
            break;
        }
    }
    printf("Array is sorted in %d swaps.\nFirst Element: %d\nLast Element: %d",num_swaps,a[0],a[a.size()-1]);
    return 0;
}

