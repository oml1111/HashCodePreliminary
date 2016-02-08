#include<vector>

namespace TTE {
	struct Step {
		int type;
		int r1, r2, c1, c2;
		int r, c, s;
	};

	struct Output {
		vector<Step> step;
	};
	
};
