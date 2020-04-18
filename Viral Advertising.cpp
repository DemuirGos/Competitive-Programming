#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertisingrec(int n,int k) {
    int c=(int) (k/2);
    if(n==1) return c;
    else return c+viralAdvertisingrec(n-1,3*c);
}
int viralAdvertisingit(int n,int k) {
    int count=0;
    while(n>0)
    {
        count+=(int)(k/2);
        k=3*(int)(k/2);
        n--;
    }
    return count;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertisingit(n,5);

    fout << result << "\n";

    fout.close();

    return 0;
}
