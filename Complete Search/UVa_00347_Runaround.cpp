/*
 * UVa-00347 Runaround number
 * 
 */
#include <bits/stdc++.h>

#define ALL(v) v.begin() , v.end()
#define TRv(v) for(auto it = v.begin() ; it != v.end() ; ++it)
#define INF 1000000005
#define pb push_back
#define mp make_pair
#define nDigits(N) ((int)floor(log10(N) + 1))
#define uniqueDigits(N) 
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

int R = 0;
vi numbers;

void generate(int r) {
	int digit , numOfDigit , c , x , used;
    string num;
	int i = r;
	while(i <= 10000000) {
		numOfDigit = (int)floor(log10(i) + 1);
		num = to_string(i);
		c = 0; x = 0; used = 0;
		while(c < numOfDigit) {
			digit = num[x] - '0';
			if(!digit) { break; } // Checking for zero digit
			else if(digit % numOfDigit == 0) { break; } // Runaround to same position
			else if((used & (1 << digit)) != 0) { break; }  // Distinct Digit
			else {
				x = ((digit % numOfDigit) + (x % numOfDigit)) % numOfDigit;
				used |= (1 << digit);
				++c;
			}
		}
		if(c == numOfDigit && __builtin_popcount(used) == numOfDigit && x == 0) { numbers.pb(i); }
		++i;
	}
}

int linearSearch(int r) {
	TRv(numbers) {
		if(*it >= r) return *it; 
	}
	return -1;
}

int main() {
	int cases = 1;
	generate(10);
	while(scanf("%d" , &R) , R) {
		printf("Case %d: %d\n" , cases , linearSearch(R));
		++cases;
	}
	return 0;
}
