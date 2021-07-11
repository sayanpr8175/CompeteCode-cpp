/*
	creation of Segment Tree
*/

#include<iostream>
using namespace std;

void buildTree(int * arr, int* tree, int start, int end, int treeNode){
	
	if(start==end){
		tree[treeNode] = arr[start];
		return;
	}
	
	
	int mid = (start+end)/2;
	
	buildTree(arr, tree, start, mid, 2*treeNode);
	buildTree(arr, tree, mid+1, end, 2*treeNode+1);
	
	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
	
}
void updateTree(int * arr, int * tree, int start, int end, int treeNode, int idx, int value){
	
	if(start == end){
		arr[idx] = value;
		tree[treeNode] = value;
		return;
	}
	
	int mid = (start+end)/2;
	
	if(idx>mid){
		updateTree(arr, tree, mid+1, end, 2*treeNode+1, idx, value);
	}else{
		updateTree(arr, tree, start, mid, 2*treeNode, idx, value);
	}
	
	tree[treeNode]  = tree[2*treeNode] + tree[2*treeNode+1];
	
	
}

int Query(int * tree, int start, int end, int treeNode, int left, int right){
	
	// Completely outside
	
	if(start > right || end < left){
		return 0;
	}
	
	// Completely given inside range
	if(start>=left && end<=right){
		return tree[treeNode];
	}
	
	// Partially inside and Partially outside
	
	int mid = (start+end)/2;
	
	int ans1 = Query(tree, start, mid, 2*treeNode, left, right);
	int ans2 = Query(tree, mid+1, end, 2*treeNode+1, left, right);
	
	return ans1+ans2;
	
}


int main(){
	
	int n;
	cin >> n;
	int * arr = new int[n+1];
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
		
	int * tree = new int[2*n];
	
	buildTree(arr, tree, 0, n-1, 1);
	
	
	for(int i=1; i<2*n; i++){
		cout << tree[i] << " ";
	}
	
	
	
	/*cout << " enter two values within the sum will be formed "<< endl << " ";
	
	int c1,c2;
	cin >> c1 >> c2;
	cout << endl;
	
	int ans = Query(tree, 0, n-1, 1,c1, c2);
	
	cout << " Sum : " << ans << endl; */
	
}
