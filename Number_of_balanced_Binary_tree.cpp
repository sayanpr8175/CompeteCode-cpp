/*
	Number Of Balanced BTs
	
	Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 24
Time Limit: 1 sec

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int balancedBT(int n){
	
	if(n==0 || n == 1){
		return 1;
	}
	
	int m = pow(10,9)+7;
	
	int x = balancedBTs(n-1);
	int y = balancedBTs(n-2);
	
	long res1 = (long)(x*x);
	long res2 = (long)(x*y*2);
	
	int ans1 = (int)(res1%m);
	int ans2 = (int)(res2%m);
	
	
	int ans = (ans1+ans2)%m;
	
	return ans;
	
}



int main(){
	
	int h = 6;
	cout << balancedBT(h) << endl;
	
	return 0;
}

