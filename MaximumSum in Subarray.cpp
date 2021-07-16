#include<iostream>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;


struct node {
	int sum;  // Sum
	int bps; // Best prefix sum
	int bss; // Best Suffix sum
	int maxsum; // max sum
};

void buildTree(int * arr, node * tree, int start, int end, int treeIndex){
	
	if(start==end){
		tree[treeIndex].sum = arr[start];
		tree[treeIndex].bps = arr[start];
		tree[treeIndex].bss = arr[start];
		tree[treeIndex].maxsum = arr[start];
		return;
	}
	
	int mid = (start+end)/2;
	buildTree(arr, tree, start, mid, 2*treeIndex);
	buildTree(arr, tree, mid+1, end, 2*treeIndex+1);
	
	node left = tree[2*treeIndex];
	node right = tree[2*treeIndex+1];
	
	tree[treeIndex].sum = left.sum + right.sum;
	tree[treeIndex].bps = max(left.bps, (left.sum + right.bps));
	tree[treeIndex].bss = max(right.bss, (right.sum+left.bss));
	tree[treeIndex].maxsum = max(left.maxsum, max(right.maxsum, max( (left.sum+right.bps), max( (right.sum + left.bss), (left.bss+right.bps) ))));
	
	
}

node query(node * tree, int start, int end, int treeNode, int left, int right){
	
	// totally outside
	
	if(start>right || end<left){
		
		node x;
		x.bps = -100000;
		x.bss = -100000;
		x.maxsum = -100000;
		x.sum = -100000;
		
		return x;
	}
	
	// exactly what I want
	
	if(start>=left && end<=right){
		return tree[treeNode];
	}
	
	// Partially inside / partially outside
	
	int mid = (start+end)/2;
	
	node t1 = query(tree, start, mid, 2*treeNode, left, right);
	node t2 = query(tree, mid+1, end, 2*treeNode+1,left, right);
	
	node tx;
	tx.sum = t1.sum + t2.sum;
	tx.bps = max(t1.bps, t1.sum+t2.bps);
	tx.bss = max(t1.bss+t2.sum, t2.bss);
	tx.maxsum = max(t1.maxsum, max(t2.maxsum, max( (t1.sum+t2.bps), max( (t2.sum + t1.bss), (t1.bss+t2.bps) ))));
	
	return tx;
}


node queryx(node* tree, int start, int end, int treenode, int left, int right)
{
	//completely outside
	if (start > right || end < left)
	{
		return {-100000, -100000, -100000, -100000};
        //not used int min here because during recursion it will become +ve if any number is subtracted from it.
	}
	//completely inside
	if (start >= left && end <= right)
	{
		return tree[treenode];
	}
	//partially outside and partially inside
	int mid = (start + end) / 2;
	node q1 = query(tree, start, mid, 2 * treenode, left, right);
	node q2 = query(tree, mid + 1, end, 2 * treenode + 1, left, right);
	node ans;
	ans.sum = q1.sum + q2.sum;
	ans.bps = max(q1.bps, q1.sum + q2.bps);
	ans.bss = max(q1.bss + q2.sum, q2.bss);
	ans.maxsum = max
	(
		q1.maxsum,
		max
		(
			q2.maxsum,
			max
			(
				q1.sum + q2.bps,
				max
				(
					q2.sum + q1.bss,
					q1.bss + q2.bps
				)
			)
		)
	);
	return ans;
}



int main(){
	int n;
	cin >> n;
	int * arr = new int[n];
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	node * tree = new node[4*n];
	
	buildTree(arr, tree, 0, n-1, 1);
	
	int m;
	cin >> m;
	while(m--){
		int x1, x2;
		cin >> x1 >> x2;
		cout << query(tree, 0, n-1, 1, x1-1, x2-1).maxsum << endl;
		
	}	
}
