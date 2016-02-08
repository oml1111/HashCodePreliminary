#include<vector>

namespace TTE {
	struct Step {
		//type - type of operation
		//0 - PAINT_SQUARE
		//1 - PAINT_LINE
		//2 - ERASE_CELL
		int type;
		int r1, r2, c1, c2;
		int r, c, s;
		
		Step(int newType, int v1, int v2, int v3 = 0, int v4 = 0);
	};

	struct Output {
		std::vector<Step> step;
	};
	
	//Applies the output in place
	void apply(int n, int m, char* input, Output toApply);
};
