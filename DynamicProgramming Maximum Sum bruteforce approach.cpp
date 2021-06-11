#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
	Brute force approach for Maximum sum sub array
	
	Maximum sum subarray 2D matrix Brute force


*/


int main(){
	
	int n, m;
	cin >> n >> m;
	int ** arr = new int*[n];
	
	for(int i = 0; i<n; i++){
		arr[i] = new int[m];
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}	
	}
	
	cout << endl;
/*	
	for(int i = 0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	} */
	
	int max = INT_MIN;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			
		for(int k = n-1; k>=i; k--){
			for(int l = m-1; l>=j; l--){
				
			//	cout << endl << " i = " << i <<" j = "<< j << " k = " << k << " L = " << endl;
				
				int localsum = 0;
				
				for(int q = i; q<=k; q++){
					for(int r=j; r<=l; r++){
						
						localsum += arr[q][r];
					}
				
				}
				
				if(localsum>max){
					max = localsum;
				}
				
			}	
		}
			
	}
	
}
cout << max << endl;
	
return 0;	
	
}
