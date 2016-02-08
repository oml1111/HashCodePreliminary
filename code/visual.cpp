#include <bits/stdc++.h>
#include <SDL/SDL.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const ll INF = 1e18;
const int X = 600, R = 46, M = 10, R_LIM = 56, R_CONST = 200, N_CONST = 50;
int n = 5, iter, r = 3;
double add_c = 0.5, rad_c = 0.10, rem_c = 0.005;
double mr = 1.0;
ll red_sum[X][X],green_sum[X][X],blue_sum[X][X];
vector<int> rval;
double rand01(){
	return (double)rand()/RAND_MAX;
}
bool chance(double expected){
	return rand01()<expected;
}
int red(Uint32 t){
	return t % 0x1000000 / 0x10000;
}
int green(Uint32 t){
	return t % (0x10000) / (0x100);
}
int blue(Uint32 t){
	return t % (0x100);
}
Uint32 make_color(int red, int green, int blue){
//	cout << red << ' ' << green << ' ' << blue << '\n';
	return red*0x10000+green*0x100+blue;
}
Uint32 get_pixel32(SDL_Surface *surface, int x, int y){
	Uint32 *pixels = (Uint32 *)surface->pixels;
	return pixels[(y * surface->w) + x];
}
void put_pixel32(SDL_Surface *surface, int x, int y, Uint32 pixel){
	Uint32 *pixels = (Uint32 *)surface->pixels;
	pixels[(y * surface->w) + x] = pixel;
}
int mag = 3;
void show_goal(int n, int m, vector<string> grid, SDL_Surface *screen){
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
				for(int k = 0; k < mag; ++k)
					for(int l = 0; l < mag; ++l){
						if(grid[i][j]=='.'){
							put_pixel32(screen,mag*j+k,mag*i+l,0x0);
						}
						else{
							put_pixel32(screen,mag*j+k,mag*i+l,0xffffff);
						}
					}
}
int main(){
	int n,m,id;
	string name;
	cout << "enter magnification rate, 2 = twice as big\n";
	cin >> mag;
	cout << "enter number of input file, {1,2,3}" << '\n';
	cin >> id;
	if(id == 1)
		name = "learn_and_teach";
	else if(id == 2)
		name = "logo";
	else
		name = "right_angle";
	string full_path = "../input/" + name + ".in";
	ifstream goal(full_path.c_str());
//	ifstream sol("sol.txt");
	goal >> n >> m;
	vector<string> grid(n);
	for(int i = 0; i < n; ++i)
		goal >> grid[i];
	srand(time(0));
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface *screen = SDL_SetVideoMode(mag*m,mag*n,32,SDL_SWSURFACE);
	SDL_Event event;
	bool run = true;
	while(run){
		while(SDL_PollEvent(&event)){
			if(event.type==SDL_QUIT){
				run=false;
				break;
			}
			if(event.type==SDL_KEYDOWN){
				if(event.key.keysym.sym==SDLK_ESCAPE){
					run=false;
					break;
				}
			}
		}
		show_goal(n,m,grid,screen);
		SDL_Flip(screen);
	}
}

