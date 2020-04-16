/*
 * UVa-00414 Machined Surfaces
 * O(no. of inputs) Solution
 * 
 */
#include <bits/stdc++.h>
#define ALL(v) v.begin() , v.end() 
#define INF 1000000005

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

int len_x = 0 , len_y = 0 , N = 0; 
char x[30] , y[30];
vi v;
												  // This code takes O(no. of inputs)
int main(int argc, char **argv) {
	while(scanf("%d" , &N) , N) {                 // O(no. of inputs)
		scanf("\n"); v.assign(N , 0);
		for(int i = 0 ; i < N ; i++) {			  // O(N) = O(13)
			scanf("%s" , x); len_x = strlen(x);
			if(len_x < 25) scanf("%s" , y); 
			else y[0] = 0;
			len_y = strlen(y);
			v[i] = len_x + len_y;
		}
		int max = *max_element(ALL(v));            // O(N) = O(13)
		int sum = 0;
		for(int a : v) { sum += (max - a); }
		printf("%d\n" , sum); v.clear();
	}
	return 0;
}

