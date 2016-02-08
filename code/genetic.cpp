#include <bits/stdc++.h>
#include "output.h"
using namespace std;
typedef long double ld;
typedef long long ll;
void apply(int n, int m, char* input, TTE::Output toApply){
	// assuming input starts out empty
	// '.' is empty
	// '*' is painted 
	for(auto cur : toApply.step){
		if(cur.type==0){
			for(int i = cur.r-cur.s; i <= cur.r+cur.s; ++i)
				for(int j = cur.c-cur.s; j <= cur.c+cur.s; ++j)
					input[i*m+j] = '*';
		}
		if(cur.type==1){
			if(cur.r1==cur.r2){
				for(int i = min(cur.c1,cur.c2); i <= max(cur.c1,cur.c2); ++i)
					input[cur.r1*m+i] = '*';
			}
			else{
				for(int i = min(cur.r1,cur.r2); i <= max(cur.r1,cur.r2); ++i)
					input[i*m+cur.c1] = '*';
			}
		}
		if(cur.type==2){
			input[m*cur.r+cur.c] = '.';
		}
	}
}
//Output greedy(int n, int m, char* input){ }
TTE::Output genetic(int n, int m, char* input){
}
int main(){
}

