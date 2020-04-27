/*
 * UVa-105 The Skyline Problem
 * 
 */
#include <bits/stdc++.h>

#define M_HEIGHT 10010

#define ALL(v) v.begin() , v.end()
#define TRv(v) for(auto it = v.begin() ; it != v.end() ; ++it)
#define INF 1000000005
#define pb push_back
#define mp make_pair
#define isEven(N) ((!(N & 1)) ? 1 : 0)

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

typedef pair<int , int> ii;
typedef pair<int , ii> iii;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef unordered_map<string , int> umsi;
typedef unordered_map<int , int> umii;

int height[M_HEIGHT]; vi result;
int L = 0 , H = 0 , R = 0;

int main(int argc, char **argv) {
	memset(height , 0 , sizeof height);
	int max_R = -1;
	while(scanf("%d %d %d" , &L , &H , &R) != EOF) {
		for(int	i = L ; i < R ; ++i) { if(height[i] < H) height[i] = H; }
		max_R = max(max_R , R);
	}
	for(int i = 0 ; i < max_R ; ++i) {
		if(height[i] != height[i + 1]) {
			result.pb(i + 1); result.pb(height[i + 1]);
		}
	}
	int len = int(result.size());
	for(int i = 0 ; i < len ; ++i) {
		if(i == (len - 1)) printf("%d\n" , result[i]);
		else printf("%d " , result[i]);
	}
	result.clear();
	return 0;
}
