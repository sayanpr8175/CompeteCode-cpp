#include<iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
	
	string arr1, arr2;
	cin >> arr1 >> arr2;

	int count = 0;
	
	for(int i=0; i<n; i++){
		if((arr1[i] != arr1[i+1]) && (arr1[i+1] != arr2[i+1])){
			i++;
		}
		count++;
		else{
			
			i++;
		}
	}
	
	cout << count << endl;
	return 0;
}
