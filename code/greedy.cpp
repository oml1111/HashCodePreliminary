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
		int curcost = 0;
		if(inpLine[i] == '.') curcost = -1;
		if(inpLine[i] == '#') curcost = 1;
		
		sumUpto[i+1] = sumUpto[i] + 1;
	}
	
	//Next actually get the result
	pair<int, pair<int, int> > ret(mp(0, mp(0, 0) ) );
	
	//Format: (cost, endpoint)
	pair<int, int> prevLowest = mp(0, 0);
	
	for(int i=1;i<=m;i++)
		ret = max(ret, mp(sumUpto[i] - prevLowest.f,  mp(prevLowest.s, i) ) );
	
	return ret;
}





//Simple operation to find the best step to take
Step simpleGetStep(int n, int m, char* input) {
	
}


int greedy(int n, int m, char* input) {
	
}































