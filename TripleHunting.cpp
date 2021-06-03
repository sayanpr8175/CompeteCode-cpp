#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("tripin.txt","r",stdin);
	freopen("tripout.txt","w",stdout);
	
	int n;
	cin >> n;
	int arr[n];
	int arr2[n];
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	int count = 0;
	int k =0;

	for(int i=0; i<n; i++){
		if(arr[i]%3==0){
			arr2[k] = i+1;
			k++; count++;
		}
	}
	if(count!=0){
		cout << count << endl;
		for(int i=0; i<k; i++){
			cout << arr2[i] << " ";
		}
		cout << endl;
		
	}else{
		cout << "Nothing here!" << endl;
	}
	
	
}
