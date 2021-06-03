#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("mixin.txt","r",stdin);
	freopen("mixout.txt", "w", stdout);
	
	int num1, num2;
	cin >> num1 >> num2;
	if(num1%num2 != 0){
		cout << num1/num2 << " " << num1%num2 << "/" << num2 << endl;	
	}
	else{
		cout << num1/num2 << endl;
	}
	
}
