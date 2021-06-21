#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

#define ll long long int
using namespace std;

struct Item{
	int ti;
	int xi;
	int yi;
};

bool compare(Item a, Item b){
	
	if(a.ti==b.ti){
		
		if(a.yi==b.yi){
			
			return a.xi<b.xi;
			
		}return a.yi>b.yi;
		
	}
	return a.ti < b.ti;	
}


int knapSack(Item * arr, ll n, ll d){
	
	ll current_cost = arr[0].xi;
	ll current_area_covered = 0;
	ll current_worker_index = 0;
	
	for(ll i=1; i<n && current_area_covered<d; i++){
		
		current_area_covered += (arr[i].ti - arr[i-1].ti)*arr[current_worker_index].yi;
		
		if(current_area_covered >= d){
			
			return current_cost;
		}
		if(arr[current_worker_index].yi < arr[i].yi){
			
			current_worker_index = i;
			current_cost += arr[current_worker_index];
		}
		
	}
	
	return current_index;
	
}



int main(){
	
	int n, d;
	cin >> n >> d;
	
	int t, x, y;
	
	Item * input = new Item[n];
	
	for(int i=0; i<n; i++){
		
		cin >> t >> x >> y;
		
		input[i].ti = t;
		input[i].xi = x;
		input[i].yi = y;
	}
	
	
	
	return 0;
}
