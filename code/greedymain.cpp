#include"output.h"
#include"greedy.h"
#include<iostream>
#include<string>
using namespace std;
using namespace TTE;

int main() {
	int n, m;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	
	string input;
	
	{
		string tmp;
		getline(cin, tmp);
		
		for(int i=0;i<n;i++) {
			getline(cin, tmp);
			input += tmp;
		}
	}
	
	Output steps = greedy(n, m, (char*)input.c_str() );
	
	cout << steps.step.size() << '\n';
	for(auto step : steps.step) {
		if(step.type == 0)
			cout << "PAINT_SQUARE " << step.r << ' ' << step.c << ' ' << step.s << '\n';
		else if(step.type == 1)
			cout << "PAINT_LINE " << step.r1 << ' ' << step.c1 << ' ' << step.r2 << ' ' << step.c2 << '\n';
		else
			cout << "ERASE_CELL " << step.r << ' ' << step.c << '\n';
	}
	
	return 0;
}
