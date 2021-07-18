#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void buildTree(int * arr, int * tree, int start, int end, int treeIndex){
	
	if(start==end){
		tree[treeIndex] = arr[start];
		return;
	}
	
	int mid = (start+end)/2;
	buildTree(arr, tree, start, mid, 2*treeIndex);
	buildTree(arr, tree, mid+1, end, 2*treeIndex+1);
	
	tree[treeIndex] = min(tree[2*treeIndex], tree[2*treeIndex+1]);
}


void updateSegmentTreeLazy(int * tree, int * lazy, int low, int high, int startR, int endR, int currPos, int inc){
	
	if(low > high){
		return;
	}
	
	if(lazy[currPos] != 0){
		tree[currPos] += lazy[currPos];
		
		if(low!=high){
			lazy[2*currPos] += lazy[currPos];
			lazy[2*currPos+1] += lazy[currPos];
		}
		lazy[currPos] = 0;
	}
	
	// No Overlap
	if(startR>high || endR < low){
		return;
	}
	
   // Complete Overlap
   
   if(startR <= low && high <= endR){
   		
   		tree[currPos] += inc;
   		if(low!=high){
   			lazy[2*currPos]	+= inc;
   			lazy[2*currPos+1] += inc;
		}
		return;
   }
   
   // Partial Overlap
   
   int mid = (low+high)/2;
   updateSegmentTreeLazy(tree, lazy, low, mid, startR, endR, 2*currPos, inc);
   updateSegmentTreeLazy(tree, lazy, mid+1, high, startR, endR, 2*currPos+1, inc);
	
   tree[currPos] = min(tree[2*currPos], tree[2*currPos+1]);
   
}

int main(){
	
	cout << "Inserting array length " << endl;
	
	int n; 
	cin >> n;
	int * arr = new int[n];
	
	cout << "Start inserting array elements "<< endl;
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int * tree = new int[3*n]();
	buildTree(arr, tree, 0, n-1, 1);
	
	int * lazy = new int[3*n]();
	
	cout << "Enter low (array index) : " ;
	int low, high;
	cin >> low;
	cout <<endl << "Enter high(array index) : " ;
	cin >> high;
	
	int startR, endR, inc;
	cout <<endl << "Enter starting(cmd index) : " ;
	cin >> startR;
	cout << endl << "Enter ending(cmd index) : " ;
	cin >> endR;
	
	cout << endl << "Add number : ";
	cin >> inc;
	cout << endl;
	
	
	
	updateSegmentTreeLazy(tree, lazy, low, high, startR, endR, 1, inc);
	
	cout << "Enter low (array index) : " ;
	
	cin >> low;
	cout <<endl << "Enter high(array index) : " ;
	cin >> high;
	
	cout <<endl << "Enter starting(cmd index) : " ;
	cin >> startR;
	cout << endl << "Enter ending(cmd index) : " ;
	cin >> endR;
	
	cout << endl << "Add number : ";
	cin >> inc;
	cout << endl;
	
	updateSegmentTreeLazy(tree, lazy, low, high, startR, endR, 1, inc);
	
	cout << endl;
	
   cout << "Segment Tree" << endl;
   for(int i=1; i<3*n; i++){
   		cout << tree[i] << endl;
   }
   
   
   cout << "Lazy Tree" << endl;
   for(int i=1; i<3*n; i++){
		cout << lazy[i] << endl;
   }
			
	return 0;
}
