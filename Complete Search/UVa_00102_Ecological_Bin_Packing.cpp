/*
 * UVa-00102 Ecological Bin Packing
 * O(no. of inputs) Solution
 * 
 */
#include <bits/stdc++.h>
#define ALL(v) v.begin() , v.end() 
#define TRv(v) for(auto it = v.begin() ; it != v.end() ; ++it)
#define INF 1000000005
#define SIZE 3

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

int movenments[SIZE][SIZE] = {};
vi v(SIZE * SIZE); 
vi glass = {1 , 2 , 3} , b(SIZE);

int main(int argc, char **argv) {
	while(scanf("%d%d%d%d%d%d%d%d%d" , &v[0] , &v[2] , &v[1] , &v[3] , &v[5] , &v[4] , &v[6] , &v[8] , &v[7]) != EOF) {
		int i = 0;
		for(int j = 0 ; j < 9 ; ++j) { if(j == 3 || j == 6) ++i; 
			movenments[(j % 3)][i] = v[(j + 3) % 9] + v[(j + 6) % 9]; 
		}
		int mn = INT_MAX;
		do {
			i = movenments[glass[0] - 1][0] + movenments[glass[1] - 1][1] + movenments[glass[2] - 1][2];
			if(i < mn) { mn = i; b = glass; }
		}while(next_permutation(ALL(glass)));
		for(int y : b) {
			if(y == 1) printf("B");
			else if(y == 2) printf("C");
			else printf("G");
		}
		printf(" %d\n" , mn);
	} 
	return 0;
}

