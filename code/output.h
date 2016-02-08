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
	};

	struct Output {
		std::vector<Step> step;
	};
	
};
