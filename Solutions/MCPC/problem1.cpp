 #include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    long long t;cin >> t;
    while(t--)
    {
        vector<double> v;
        int n=6;
        while(n--)
        {
            double m;cin >> m;v.push_back(m);
        }
        double alt=sqrt(pow(v[0],2)+pow(v[1],2)+pow(v[2],2));
        double theta=acos((v[0]*v[3]+v[1]*v[4]+v[2]*v[5])/(alt*alt));
        double d=sqrt(pow(v[3]-v[0],2)+pow(v[4]-v[1],2)+pow(v[5]-v[2],2));
        double r=d/(2*sin(theta/2));
        cout<< setprecision(13) <<theta*r << endl;
    }
}