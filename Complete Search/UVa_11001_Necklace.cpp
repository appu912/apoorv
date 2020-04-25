/*
 * UVa-11001 Necklace
 * 
 */
#include <bits/stdc++.h>
#define ALL(v) v.begin() , v.end() 
#define TRv(v) for(auto it = v.begin() ; it != v.end() ; ++it)
#define INF 1000000005
#define EPS 1e-9
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

int n = 0 , V_total = 0 , V_0 = 0;
vd v;

double diameter(double V) {
	if(V <= V_0) return 0;
	else return 0.3 * sqrt(V - V_0);
}
		
int main(int argc, char **argv) {
	double D = 0.0 , length = 0.0; 
	while(scanf("%d %d" , &V_total , &V_0) , V_total | V_0) {
		D = length = 0.0;
		for(n = 1 ; (V_total / (double)n >= V_0) && n < V_total ; ++n) {
			D = diameter(V_total / (double)n);
			v.pb(n * D);
		}
		auto i = max_element(ALL(v)); length = *i; 
		*i = 0;
		double l = *max_element(ALL(v));
		if(fabs(l - length) < EPS) puts("0");
		else printf("%d\n" , int(i - v.begin() + 1));
		v.clear();
	}
	return 0;
}

