#include<iostream>
using namespace std;

int num_codes(int * n, int size){
	
	if(size == 1 || size == 0){
		return 1;
	}
	
	int output = num_codes(n, size-1);
	
	if(((n[size-2]*10)+n[size-1]) <= 26){
		output += num_codes(n, size-2);
	}
	
	return output;
	
}


int main(){
	
	int * n;
	int size;
	
	cin >> size;
	
	n = new int[size+1];
	
	for(int i=0; i<size; i++){
		cin >> n[i];
		
	}
	
	for(int i=0; i<size; i++){
		cout << n[i] << " ";
	}
	cout << endl;
	
	cout << num_codes(n, size) << endl;
	
}
