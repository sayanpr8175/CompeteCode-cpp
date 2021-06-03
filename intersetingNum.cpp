#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k, l;
	cin >> n >> k >> l;
	
	int * arr = new int[n];
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	int ans = INT_MAX;
	sort(arr, arr+n);
	
	for(int j = arr[0]; j<=arr[n-1]; j++){
		
		int dec=0, incr = 0;
		
		for(int i=0; i<n; i++){
			
			int m = j-arr[i];
			if(m>0){
				incr += m;
			}
			else{
				dec += abs(m);
			}
			
		}
		if(dec > incr ){ 
			continue;
		}
		else{
			int z = 0;
			z += (dec*k);
			z += ((incr-dec)*l);
			if(z<ans){
				ans = z;
			}
			
		}
			
	}
	cout << ans << endl;
	return 0;
	
	
}
