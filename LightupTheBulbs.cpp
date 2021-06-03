#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define llg long long


int main(){
	
	string s1;
	llg x, y, len;
	cin >> len >> x >> y;
	cin >> s1;
	string s2;
	
	int zerogroup = 0;
	for(int i=1; i<len-1; i++){
		
		if(s1[i]=='0' && s1[i] != s1[i+1]){
			zerogroup++;
		}
		
	}
	if(zerogroup==0 && s1[0] == '1'){
		cout << zerogroup << endl;
	}
	
	else if(zerogroup == 0 && s1[0] == '0'){
		cout << y << endl;
	}
	
	
	else if(zerogroup > 1){
		llg ll = (zerogroup-1)*min(x,y)+y;
		cout << ll << endl;
		
	}
	
	
	
}
