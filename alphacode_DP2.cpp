#include<bits/stdc++.h>
#define MOD 100000007
using namespace std;


int main(){
	
	string s;
	int n, i, x;
	long long int A[5001];
	
	while(1){
		cin >> s;
		
		if(s=="0"){
			break;
		}
		
		n = s.size();
		for(i=0; i<5000; i++){
			A[i] = 0;
		}
		A[0] = 1;
		for(int i=1; i<n; i++){
			x = (s[i-1] - '0')*10 + s[i]-'0';
			
			if(s[i]!='0'){
				A[i] = A[i-1];
			}
			if(x>=10 && x<=26 && i>1){
				A[i] += A[i-2];
			}
			else if(x>=10 && x<=26){
				A[i]++;
			}
			A[i] = A[i]%MOD;
			
		}
		cout << A[n-1] << endl;	
	}
	
	
	
	
}
