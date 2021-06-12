#include<bits/stdc++.h>
using namespace std;

/*

Maximum Sum using Kadane's optimized solution

*/



int kadane(int * arr, int n){
	
	int currentSum = 0;
	int bestSum = INT_MIN;
	for(int i=1; i<n; i++){
		currentSum += arr[i];
		if(bestSum < currentSum){
			bestSum = currentSum;
		}
		
		if(currentSum < 0){
			currentSum = 0;
		}
	}
	return bestSum;
}

void findMaxSum(int ** M, int ROW, int COL){
	
	int maxSum = INT_MIN;
	int finalLeft, finalRight, finalTop, finalBottom;
	
	int left, right, i;
	int sum, start, finish;
	int temp[ROW];
	
	for(left = 0; left<COL ; ++left){
		
		memset(temp, 0, sizeof(temp));
		
		for(right = left; right<COL; ++right){
			
			for(i = 0; i < ROW; i++){
				temp[i] += M[i][right];	
			}
			
			sum = kadane(temp, ROW);
			if(sum>maxSum){
				maxSum = sum;
			}
			
		}
		
	}
	cout << maxSum << endl;
	
	
}


int main(){
	int n, m;
	cin >> n >> m;
	
	int ** input = new int*[n];
	
	for(int i=0; i<n; i++){
		
		input[i] = new int[m];
		
		for(int j=0; j<m; j++){
			cin >> input[i][j];	
		}
	}
	
	findMaxSum(input, n, m);
	
	
	return 0;
}


