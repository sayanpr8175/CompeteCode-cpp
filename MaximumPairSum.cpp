#include<iostream>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

void update(int * arr, pair<int, int>* tree, int start, int end, int treeNode, int idx, int value){
	
	if(start == end){
		arr[idx] = value;
		tree[treeNode] = make_pair(value, INT_MIN);
		return;
	}
	
	int mid = (start+end)/2;
	
	if(idx<=mid){
		update(arr, tree, start, mid, 2*treeNode+1, idx, value);
	}else{
		update(arr, tree, mid+1, end, 2*treeNode+2, idx, value);
	}
	
	pair<int, int> left = tree[2*treeNode+1];
	pair<int, int> right = tree[2*treeNode+2];
	
	tree[treeNode].first = max(left.first, right.second);
	tree[treeNode].second = min(max(left.first, right_second), max(right_first, left_second));
	
	return;	
	
}




void buildTree(int* arr, pair<int, int> * tree, int start, int end, int TreeNode){
	
	if(start==end){
		tree[TreeNode] = make_pair(arr[start], INT_MIN);
		return;
	}
	
	int mid = (start+end)/2;
	
	buildTree(arr,  tree, start, mid, 2*TreeNode+1);
	buildTree(arr,  tree, mid+1, end, 2*TreeNode+2);
	
	pair<int, int> left = tree[2*TreeNode+1];
	pair<int, int> right = tree[2*TreeNode+2];
	
	tree[TreeNode].first = max(left.first, right.first);
	tree[TreeNode].second = min(max(left.first, right.second), max(left.second, right.first));
	
}



int main(){
	
	int n;
	cin >> n;
	int * arr = new int[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	pair<int, int> * tree = new pair<int,int>[4*n];
	buildTree(arr, tree, 0, n-1, 0);
	//int d;
	//cin >> d;
//	while(d--){	
//	}


	
	
}
