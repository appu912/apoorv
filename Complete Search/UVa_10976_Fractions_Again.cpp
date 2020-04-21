/*
 * UVa-10976 Fractions Again ?
 * 
 */
#include <bits/stdc++.h>
#define ALL(v) v.begin() , v.end() 
#define TRv(v) for(auto it = v.begin() ; it != v.end() ; ++it)
#define INF 1000000005
#define pb push_back
#define mp make_pair

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

typedef pair<int , int> ii;
typedef pair<int , ii> iii;

typedef vector<int> vi;
typedef vector<ull> vull;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef unordered_map<string , int> umsi;
typedef unordered_map<int , int> umii;

double k = 0.0 , x = 0.0 , y = 0.0;
vector<pair<double , double>> v;
int c = 0;

int main(int argc, char **argv) {
	
	while(scanf("%lf" , &k) != EOF) {
		x = k + 1; c = 0;
		do {
			y = (x * k) / (x - k); // Always apply division at the end.
			if(floor(y) == y) { ++c; v.pb({y , x}); } // Checking whether y is a pure integer.
			++x; // x goes from k + 1 until it becomes equal to y.
		}while(x < y);
		printf("%d\n" , c);
		for(auto a : v) {
			printf("1/%.0lf = 1/%.0lf + 1/%.0lf\n" , k , a.first , a.second);
		}
		v.clear();
	}
	return 0;
}

