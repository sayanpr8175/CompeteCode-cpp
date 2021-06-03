#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("taktakin.txt","r", stdin);
	freopen("taktakout.txt","w", stdout);
	
	int full_moon = 0;
	int no_fruits = 0;
	cin >> no_fruits;
	
	while(no_fruits%11!=1){
		no_fruits*=2;
		full_moon++;
	}
	
	cout << full_moon << " " << no_fruits << endl;
	
}
