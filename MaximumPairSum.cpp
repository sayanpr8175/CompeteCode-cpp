#include<bits/stdc++.h>
#include<utility>
using namespace std;

pair <int, int> Query(pair <int, int> * tree, int start, int end, int treeNode, int left, int right){
	
	
	if(start>right || end<left){
		pair<int,int> l;
		l.first =INT_MIN;
		l.second = INT_MIN;
		return l;
	}
	if(start>=left && end<=right){
		
		return tree[treeNode];
	}
	
	int mid = (start+end)/2;
	
    pair<int, int> l = Query(tree, start, mid, 2*treeNode, left, right);
    pair<int, int> r = Query(tree, mid+1, end, 2*treeNode+1, left, right);
    
    pair<int, int> x;
    x.first = max(l.first, r.first);
    x.second = min (max(l.first, r.second), max(l.second, r.first));
	
	return x;
}


void UpdateTree(int * arr, pair<int, int> * tree, int start, int end, int treeNode, int idx, int value){
	
	if(start == end){
		arr[idx] = value;
		tree[treeNode].first = value;
		tree[treeNode].second = INT_MIN;
		return;
	}
	
	int mid = (start+end)/2;
	if(idx>mid){
		UpdateTree(arr, tree, mid+1, end, 2*treeNode+1, idx, value);
	}
	else{
		UpdateTree(arr, tree, start, mid, 2*treeNode, idx, value);
	}
	
	pair<int, int> left = tree[2*treeNode];
	pair<int, int> right = tree[2*treeNode+1];
	
	tree[treeNode].first = max(left.first, right.first);
	tree[treeNode].second = min(max(left.first, right.second), max(left.second, right.first));
}


void buildTree(int * arr, pair<int,int> * tree, int start, int end, int treeIndex){
	
	if(start==end){
		
		tree[treeIndex].first = arr[start];
		tree[treeIndex].second = INT_MIN;
		return;
	}
	
	
	int mid = (start+end)/2;
	
	buildTree(arr, tree, start, mid, 2*treeIndex);
	buildTree(arr, tree, mid+1, end, 2*treeIndex+1);
	
	pair<int, int> left = tree[2*treeIndex];
	pair<int, int> right = tree[2*treeIndex+1];
	
	tree[treeIndex].first = max(left.first, right.first);
	tree[treeIndex].second = min(max(left.first, right.second), max(left.second, right.first));
	return;
}

int main(){
	
	int n;
	cin >> n;
	int * arr = new int[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int z;
    cin >> z;
    
	pair<int , int> * tree = new pair<int , int>[3*n];
	
	buildTree(arr, tree, 0, n-1, 1);
	
	//for(int i=1; i<3*n; i++){	
	//	cout << tree[i].first << "  "  << tree[i].second << endl;
	//}
	
    while(z--){
        
        char ch;
        int start, end;
        cin >> ch >> start >> end;
        
        if(ch=='Q'){
            
            pair<int, int> zam = Query(tree, 0, n-1, 1, start-1, end-1);
            cout << (zam.first+zam.second) << endl;
        }else{
            UpdateTree(arr, tree, 0, n-1, 1, start-1, end);
        }
        
    }
	
	
	
	
	return 0;
		
}
