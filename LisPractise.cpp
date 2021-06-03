#include<iostream>
using namespace std;

int lis(int * input, int n){
	
	int * output = new int[n];
	output[0] = 1;
	
	for(int i=0; i<n; i++){
		output[i] = 1;
		for(int j = i-1; j>=0; j--){
			
			if(input[j]>input[i]){
				continue;
			}
			
			int possiblevalue = output[j]+1;
			if(possiblevalue > output[i]){
				output[i] = possiblevalue;
			}
		}
	}
	
	int finalAns = 0;
	for(int i=0; i<n; i++){
		if(finalAns < output[i]){
			finalAns = output[i];
		}
	}
	
	delete [] output;
	return finalAns;

}



int main(){
	int size;
	cin >> size;
	int * input = new int[size];
	
	for(int i=0; i<size; i++){
		cin >> input[i];
	}
	int num = lis(input, size);
	
	cout << num << endl;
	
}
