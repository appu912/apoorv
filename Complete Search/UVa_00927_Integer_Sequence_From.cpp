/*
 * UVa-00927 Integer Sequence from...
 * 
 */
#include <bits/stdc++.h>
#define ALL(v) v.begin() , v.end() 
#define TRv(v) for(auto it = v.begin() ; it != v.end() ; ++it)
#define INF 1000000005
#define pb push_back
#define mp make_pair
#define SUM(n) (n * (n + 1) / 2)

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

unsigned int TC = 0 , i = 0 , k = 0 , d = 0;
vull coeff; ull a_n = 0;

ull kth_term() { // For d = 1 it will run 1000 times(maximum)
	ull n = 1; ull sum = 0;
	while(d * SUM(n) <= k) { sum = d * SUM(n); ++n; }
	if(sum == k) return n - 1;
	else return n;
}
	
int main(int argc, char **argv) {
	scanf("%u" , &TC);
	while(TC--) { scanf("%u" , &i); a_n = 0; coeff.assign(i + 1 , 0);
		for(unsigned int x = 0 ; x <= i ; ++x) { scanf("%llu" , &coeff[x]); }
		scanf("%u %u" , &d , &k);
		int n = kth_term();
		for(unsigned int x = 0 ; x <= i ; ++x) {
			a_n += (coeff[x] * (ull)pow(n , x));
		}
		printf("%llu\n" , a_n);
		coeff.clear();
	}
	return 0;
}

