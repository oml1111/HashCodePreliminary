#include"greedy.h"
#include"output.h"
#include<string>
#include<vector>
#define f first
#define s second
#define mp make_pair
using namespace std;
using namespace TTE;


//. = don't paint
//# = paint
//* = painted

//Process line, get the best operation to apply there
//format: (cost, [l, r) )
pair<int, pair<int, int> > bestLineOp(int m, char* inpLine) {
	vector<int> sumUpto(m+1, 0);
	
	for(int i=0;i<m;i++) {
		sumUpto[i+1] = sumUpto[i] + charVal(inpLine[i]);
	}
	
	//Next actually get the result
	pair<int, pair<int, int> > ret(mp(0, mp(0, 0) ) );
	
	//Format: (cost, endpoint)
	pair<int, int> prevLowest = mp(0, 0);
	
	for(int i=1;i<=m;i++)
		ret = max(ret, mp(sumUpto[i] - prevLowest.f,  mp(prevLowest.s, i) ) );
	
	return ret;
}



//------------------------------------------------------
//Process input to get the best rectangle to place

struct SurfaceVector : vector<int> {
	int nCols;
	SurfaceVector(int n, int m, int val) : vector<int>(n*m, val) {
		nCols = m;
	}
	
	int* operator[](int ind) {
		return &at(ind);
	}
};




pair<int, Step> getRectangle(int n, int m, char* input) {
	SurfaceVector sumUpto(n+1, m+1, col);
	
	//initialize sumUpto
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			sumUpto[i+1][j+1] = sumUpto[i][j+1] + sumUpto[i+1][j] - sumUpto[i][j]
								+ charVal(input[i*m + j]);
	
	//Next actually find the result
	pair<int, Step> ret = mp(0, Step(-1, 0, 0) );
	
	
	//And try the optima
	for(int len = 1; len <= 41; len+=2)
		for(int i=0; i+len <= n; i++)
			for(int j=0; j+len <= m; j++) {
				int cval = sumUpto[i+len][j+len] - sumUpto[i][j+len] - sumUpto[i+len][j] + sumUpto[i][j];
				
				if(cval > ret.f)
					ret = mp(cval, Step(0, i+len/2, j+len/2, len/2) );
			}
	
	return ret;
};






//Simple operation to find the best step to take
Step simpleGetStep(int n, int m, char* input) {
	int stepCost = 0;
	Step ret(-1, 1, 1);
	
	//First deal with the horizontal lines
	for(int i=0;i<n;i++) {
		auto ret = bestLineOP(m, input + i*m);
		
		if(ret.f > stepCost) {
			stepCost = ret.f;
			ret = Step(1, i, ret.s.f, i, ret.s.s-1);
		}
	}
	
	//Next the vertical lines
	for(int j=0;j<m;j++) {
		String cstr;
		for(int i=0;i<n;i++)
			cstr.push_back(input[i*m + j]);
		
		auto ret = bestLineOP(n, cstr.c_str() );
		
		if(ret.f > stepCost) {
			stepCost = ret.f;
			ret = Step(1, ret.s.f, j, ret.s.s-1, j);
		}
		
	}
}






Output TTE::greedy(int n, int m, char* input) {
	return 0;
}































