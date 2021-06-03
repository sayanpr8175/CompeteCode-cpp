#include<iostream>
using namespace std;
bool search(int arr[], int val, int n){
	
	for(int i=0; i<n; i++){
		if(arr[i]==val){
			return true;
		}
	}
	return false;
}

int totalSum(int **input, int n){
	
	int * dia1 = new int[n];
	int * dia2 = new int[n];
	
	int * row1 = new int[n];
	int * row2 = new int[n];
	
	int * col1 = new int[n];
	int * col2 = new int[n];
	
	for(int i=0; i<n; i++){
		dia1[i] = 0;
		dia2[i] = 0;
		
		row1[i] = 0;
		row2[i] = 0;
		
		col1[i] = 0;
		col2[i] = 0;
	}
	
	for(int i=0; i<n; i++){
		row1[i] = input[0][i];
		row2[i] = input[n-1][i];
	}
	
	int k=0;
	for(int i=1; i<n-1; i++){
		col1[k] = input[i][0];
		col2[k] = input[i][n-1];
		k++;
	}
	
	k=0;
	for(int i=1; i<n-1;i++){
		dia1[k] = input[i][i];
		k++;
	}
	
	for(int i=1; i<n-1; i++){
		if(n-i != i){
			dia2[k] = input[n-i][i];
			k++;
		}	
	}
	
	int sumx = 0;
	for(int i=0; i<n; i++){
		sumx+= dia1[i];
		sumx+= dia2[i];
		sumx+= row1[i];
		sumx+= row2[i];
		sumx+= col1[i];
		sumx+= col2[i];
	}
	
	return sumx;
	
	
}




int main(){
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		
		int ** arr = new int*[n];
		for(int i=0; i<n; i++){
			arr[i] = new int[n];
			for(int j=0; j<n; j++){
				cin >> arr[i][j];
			}
		}
		
		cout << totalSum(arr, n) << endl;
	}
	
}
