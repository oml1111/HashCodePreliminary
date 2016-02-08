#include"output.h"
#include"greedy.h"
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
	
	for(int i=1;i<=m;i++) {
		ret = max(ret, mp(sumUpto[i] - prevLowest.f,  mp(prevLowest.s, i) ) );
		prevLowest = min(prevLowest, mp(sumUpto[i], i) );
	}
	
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
		return &at(ind*nCols);
	}
};




pair<int, Step> getRectangle(int n, int m, char* input) {
	SurfaceVector sumUpto(n+1, m+1, 0);
	
	//initialize sumUpto
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			sumUpto[i+1][j+1] = sumUpto[i][j+1] + sumUpto[i+1][j] - sumUpto[i][j]
								+ charVal(input[i*m + j]);
	
	//Next actually find the result
	pair<int, Step> ret = mp(0, Step(0, 0, 0) );
	
	
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
	Step result(0, 0, 0);
	
	//First deal with the horizontal lines
	for(int i=0;i<n;i++) {
		auto ret = bestLineOp(m, input + i*m);
		
		if(ret.f > stepCost) {
			stepCost = ret.f;
			result = Step(1, i, ret.s.f, i, ret.s.s-1);
		}
	}
	
	//Next the vertical lines
	for(int j=0;j<m;j++) {
		string cstr;
		for(int i=0;i<n;i++)
			cstr.push_back(input[i*m + j]);
		
		auto ret = bestLineOp(n, (char*)cstr.c_str() );
		
		if(ret.f > stepCost) {
			stepCost = ret.f;
			result = Step(1, ret.s.f, j, ret.s.s-1, j);
		}
	}
	
	
	//Finally just get the rectangle
	auto ret = getRectangle(n, m, input);
	
	if(ret.f > stepCost)
		result = ret.s;
	
	return result;
}





//----------------------------------------------------------------
//Finally the actual greedy function


Output TTE::greedy(int n, int m, char* input) {
	string cur(input, input + n*m);
	Output result;
	
	//Now just start greedily picking the steps
	while(cur.find('#') != string::npos ) {
		Step curStep = simpleGetStep(n, m, (char*)cur.c_str() );
		result.step.push_back(curStep);
		
		apply(n, m, (char*)cur.c_str(), curStep );
	}
	
	//Finally create add the erasures
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(input[i*m+j] == '.' && cur[i*m+j] == '*')
				result.step.push_back(Step(2, i, j) );
	
	//Aaaand we're done
	return result;
}































