#include<iostream>
#include<math.h>
#include<bits/stdc++.h>

#define MOD 1000000007

using namespace std;



int num_codes(int * n, int size){
	 if(size==0 || size==1){
        return 1;
    }
    
    long long * output = new long long[size+1]();
    
    output[0] = 1; 
    output[1] = 1;
    
    for(int i=2; i<=size; i++){
        output[i] = 0;
        if(output[i-1]!=0){
        	output[i] = output[i-1];    
        }
        
        
        if((n[i-2]*10 + n[i-1]) <= 26 && n[i-2]!=0){
            output[i] = ((output[i]%MOD)+(output[i-2]%MOD))%MOD;
            
        }
        
    }
    
    long ans = output[size];
    delete [] output;
    return ans;
    
}


int main(){
	
	while(1){
        
		string s;
		cin >> s;
        if(s=="0"){
            break;
        }
		int sz = s.size();
		int * n = new int[sz];
	
		for(int i=0; i<sz; i++){
			n[i] = s[i] - '0';
			
		}
        
        if(n[0]==0 && sz==1){
            return 0;
        }
	
		cout << num_codes(n, sz) << endl;
		
	}
	return 0;
	
}

