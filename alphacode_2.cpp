#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;



int num_codes(int * n, int size, int * arr){
	if(size==1 || size == 0){
		return 1;
	}
	
	if(arr[size] > 0){
		return arr[size];
	}
	int output = num_codes(n, size-1, arr);
	
	
	if(n[size-2]*10 + n[size-1] <= 26){
		output += num_codes(n, size-1,arr);
	}
	if(output>(pow(10,9)+7)){
		output = output % pow(10, 9)+7;
	}
	
	arr[size] = output;
	return output;
}


int main(){
	
	//While(1){
		
		
	// }
	string s;
	cin >> s;
	int sz = s.size();
	int * n = new int[sz];
	
	for(int i=0; i<sz; i++){
		n[i] = s[i] - '0';
			
	}

	int * arr = new int[sz+1]();	
	cout << num_codes(n, sz, arr) << endl;
	
}

