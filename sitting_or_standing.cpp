#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("sitin.txt", "r", stdin);
	//freopen("sitout.txt", "w", stdout);
	
	int stand, seat;
	
	int row, col, tickets;
	cin >> row >> col;
	
	int nos = row*col;
	cin >> tickets ;
	if(tickets <= nos ){
		cout << tickets << " " << 0 << endl;
	}
	else{
		cout << nos << " " <<tickets-nos << endl;
	}
	return 0;
}
