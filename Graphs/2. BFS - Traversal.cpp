#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

void PrintBFS(int ** edges, int n, int si, bool * visited){
	
	queue<int> q;
	
	q.push(si);
	visited[si] = true;
	
	while(!q.empty()){
		int currentVertex = q.front();	
		q.pop();
		cout << currentVertex << endl;
		for(int i=0; i<n; i++){
			
			if(i == currentVertex){
				continue;	
			}
			
			if(edges[currentVertex][i] == 1 && !visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}
	
	
}


int main(){
	int n, e;   // Number of nodes and Number of edges
	
	cout << "Enter number of nodes : ";
	cin >> n;
	
	cout << endl << "Enter number of edges : ";
	cin >> e;
	cout << endl;
	
	int ** edges = new int*[n];
	
	for(int i=0; i<n; i++){				// Empty adjacent matrix
		edges[i] = new int[n];
		for(int j=0; j<n; j++){
			edges[i][j] = 0;
		}
	}
	
	cout << "Start inserting values " << endl;
	for(int i=0; i<e; i++){           // Buling Edge connections;
		int first, second;
		cin >> first >> second;
		
		edges[first][second] = 1;
		edges[second][first] = 1;
		
	}
	
	
	bool * visited = new bool[n];   // This array is to keep track of the visited node to avoid re entering previous nodes in above function
	for(int i = 0; i<n; i++){
		visited[i] = false;
	}
	
	cout << "Breath wise printed value " << endl;
	
	PrintBFS(edges, n, 0, visited);
	
	// Deleting the memory
	delete [] visited;
	
	for(int i=0; i<n; i++){
		delete[] edges[i];
	}
	
	delete [] edges;
	
	
	return 0;
}


