#include<bits/stdc++.h>

using namespace std;
typedef pair<int , int> ii;
typedef pair<double , ii> dii;
typedef vector<dii> vdii;

int main(int arg , char**argc) {
	int m = 0 , n = 0;
	double profit = 0;
	vdii input;
	cin >> m >> n;
	input.assign(n , dii());
	for(int i = 0 ; i < n ; i++) {
		cin >> input[i].second.first;
	}
	for(int i = 0 ; i < n ; i++) {
		cin >> input[i].second.second;
	}
	for(int i = 0 ; i < n ; i++) {
		input[i].first = (double)input[i].second.first / input[i].second.second;
	}
	sort(input.begin() , input.end());
	int i;
	for(i = n - 1 ; i >= 0 ; i--) {
		if(m > 0 && input[i].second.second <= m) {
			profit += input[i].second.first;
			m -= input[i].second.second;
		}
		else break;
	}
	if(m > 0) profit += ((double)input[i].second.first * m / input[i].second.second);
	cout << profit << endl;
	return 0;
}
