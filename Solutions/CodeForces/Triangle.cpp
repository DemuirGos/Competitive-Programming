#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#define int long
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    auto rotate = [](pair<int,int> p,double angle){
        return make_pair(cos(angle)*p.first - sin(angle)*p.second,
                         sin(angle)*p.first + cos(angle)*p.second);
    }; 
    for(int i=1; i<a; i++){
        float j = sqrt(a*a - i*i);
        if(floor(j)==j){
            double theta = atan(i/j);
            auto img = rotate(make_pair(0,b),theta);
            double epsilon = 0.0001;
            if  (abs(img.first - round(img.first)) < epsilon && abs(img.second - round(img.second)) < epsilon && 
                ((int)img.first != j && (int)img.second != i ))
            {
                cout << "YES" << endl << 0 << " " << 0 << endl << j << " " << i << endl << img.first << " " << img.second;
                return 0;
            }
        }
    }
    cout << "NO";
}