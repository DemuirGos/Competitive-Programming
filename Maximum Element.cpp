#include <bits/stdc++.h>

using namespace std;
int main() {
    std::stack<int> st;
    int n;cin >> n;
    for (int i = 0; i < n; i++) {
        int read;cin >> read;
        switch (read)
        {
        case 1:
            int m;cin>>m;
            if (st.empty()) {
                st.push(m);
            }
            else {
                st.push(max(m, st.top()));
            }
            break;

        case 2:
            if (!st.empty()) {
                st.pop();
            }
            break;

        case 3:
            cout <<  st.top() << "\n";
            break;

        default:
            break;
        }
    }

    return 0;
}
