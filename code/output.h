#ifndef OUTPUT_ADDED
#define OUTPUT_ADDED
#include<vector>


namespace TTE {
	struct Step {
		//type - type of operation
		//0 - PAINT_SQUARE
		//1 - PAINT_LINE
		//2 - ERASE_CELL
		int type;
		int r1, c1, r2, c2;
		int r, c, s;
		
		Step(int newType, int v1, int v2, int v3 = 0, int v4 = 0);
		bool operator<(Step r);
	};

	struct Output {
		std::vector<Step> step;
	};
	
	
	//Applies the output in place
	void apply(int n, int m, char* input, Output toApply);
	void apply(int n, int m, char* input, Step toApply);
	
	int charVal(char c);
};
#endif
