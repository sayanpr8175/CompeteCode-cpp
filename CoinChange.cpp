#include<iostream>
using namespace std;


int coin_change(int n, int * d, int numD, int ** output){
	
	if(n==0){
		return 1;
	}
	
	if (n < 0){
		return 0;
	}
	
	if (numD == 0){
		return 0;
	}
	
	if(output[n][numD] > -1){
		return output[n][numD];
	}
	
	int first = coin_change(n-d[0], d, numD, output);
	int second = coin_change(n, d+1, numD-1, output);
	
	output[n][numD] = first+second;
	
	return first+second;
	
}


int main(){
	
	int size , target;
	cin >> size;
	int * input = new int[size];
	
	
	for(int i=0; i<size; i++){
		cin >> input[i];
	}
	
	cin >> target;
	
	int **arr = new int * [target+1];
	for(int i=0; i<(target+1); i++){
		
		arr[i] = new int[size+1];
		
		for(int j = 0; j<(size+1); j++){
			arr[i][j] = -1;
		}
		
	}
	
	
	int value = coin_change(target, input, size, arr);
	
  	cout << value << endl;
	
	
}
