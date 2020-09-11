#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	deque<int> d;
    for(int i=0;i<=n;){
        if(d.size()<k) {
            d.push_back(arr[i]);
            i++;
        }
        else{
            int m=-1;
            for(deque<int>::iterator i=d.begin();i!=d.end();i++){
                m=max(*i,m);
            }
            cout << m << (i==n?"\n":" ");
            d.pop_front();
        }
    }
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

