#include<iostream>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n, k, l;
	cin >> n >> k >> l;
	
	int * arr = new int[n]();
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	int minimumCost = INT_MAX;
	int x = *min_element(arr, arr+n);
	int y = *max_element(arr, arr+n);
	
	for(int i=x; i<=y; i++){
		
		int increment = 0, decrement = 0;
		
		for(int j=0; j<n; j++){
			
			if(arr[j] < i){ 
					increment += (i - arr[j]);	
			}
			
			else if(arr[j] > i){
					decrement += abs(arr[j] - i);	
			}
			if(decrement < increment){
				int cost = (decrement*k)+((increment - decrement)*l);
				//cout << cost << endl;
				if(cost < minimumCost){
					minimumCost = cost;
			}	
				
			}
			
		}
	}
	cout << minimumCost << endl;
	return 0;
}
