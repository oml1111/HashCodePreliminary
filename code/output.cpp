#include"output.h"

TTE::Step::Step(int newType, int v1, int v2, int v3 = 0, int v4 = 0) {
	type = newType;
	if(newType == 0) {
		r = v1, c = v2;
		s = v3;
	}
	else if(newType == 1) {
		r1=v1, r2=v2;
		c1=v3, c2=v4;
	}
	else if(newType == 2) {
		r = v1, c = v2;
	}
	else
		throw 1;
}


void TTE::apply(int n, int m, char* input, TTE::Output toApply){
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






