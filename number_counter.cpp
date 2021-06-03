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
	
	while(true){
		
	string nums;
	cin>> nums;
	
	//cout << nums.length() << endl;
	
	int * arr = new int[nums.length()+1]();
	
	for(int i= 0; i<nums.length(); i++){
		arr[i] = nums[i] - '0';
		
	}
	
	cout << num_codes(arr, nums.length()) << endl;
	
	
	delete[] arr;
		
	}
	
	return 0;	
}


