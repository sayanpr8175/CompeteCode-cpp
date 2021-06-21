#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

struct Item{
	int value, weight;
};


bool compare(struct Item a, struct Item b){
	double value1 = ((double)(a.value)/(a.weight));
	double value2 = ((double)(b.value)/(b.weight));	
	
	return value1 > value2;
}

double fknapsnack(struct Item arr[], int w, int n){
	
	sort(arr, arr+n, compare);
	
	int currW = 0;
	double fvalue = 0;
	
	for(int i=0; i<n; i++){
		
		if(currW + arr[i].weight <= w){
			currW += arr[i].weight;
			fvalue += arr[i].value;
		}else{
			
			int rw = w - currW;
			fvalue += (arr[i].value)*((double)rw / (arr[i].weight));
			break;	
		}

	}
	return fvalue;
	
}




int main(){
	int n;
	cin >> n;
	Item * input = new Item[n];
	
	int weight;
	cin >> weight;
	
	for(int i=0; i<n; i++){
		
		int x, y;
		cin >> x >> y;
		
		input[i].value = x;
		input[i].weight = y;
	}
	
	
	cout << fknapsnack(input, weight, n) << endl;
	
	
	
	
return 0;	
}
