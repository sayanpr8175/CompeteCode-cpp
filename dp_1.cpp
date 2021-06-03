#include<iostream>
using namespace std;

int fib(int n, int * arr){
	if(n==0 || n==1){
		return 1;	
	}
	if(arr[n]>0){
		return arr[n];
	}
	
	int x =  fib(n-1, arr) + fib(n-2, arr);
	
	arr[n] = x;
	
	return x;
}

int fibi(int n){
	int * arr = new int[n+1];
	arr[0] = 0;
	arr[1] = 1;
	
	for(int i=2; i<=n; i++){
		arr[i] = arr[i-1]+arr[i-2];
	}
	
	int output = arr[n];
	
	return output;
	
}


int main(){
	int n;
	
	cin >> n;
	
	int * arr = new int[n+1]();
	
	cout << fibi(n) << endl;
	
}
