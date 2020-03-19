#include <bits/stdc++.h>

using namespace std;

class knapsack {
		
	public:
		
		static bool sort_by_sec(const pair<int , double> &a , const pair<int , double> &b) {
			return a.second > b.second;
		}
		
		double maximum_cost(vector<int> p , vector<int> w , int m , int n) {
			double profit = 0.0;
			int i = 0;
			vector<pair<int , double>> profit_per_object;
			for(i = 0 ; i < n ; ++i) 
				profit_per_object.push_back(make_pair(i , (double)p[i] / (double)w[i]));
			sort(profit_per_object.begin() , profit_per_object.end() , sort_by_sec);
			for(i = 0 ; i < n ; ++i) {
				if(m > 0 && w[profit_per_object[i].first] <= m) {
					m -= w[profit_per_object[i].first];
					profit += p[profit_per_object[i].first];
				} else break;
			}
			if(m > 0) profit += p[profit_per_object[i].first] * ((double)m / (double)w[profit_per_object[i].first]);
			return profit;
			}
};

int main(int argc , char **argv) {
	knapsack ob;
	int m = 0 , n = 0;
	cin >> m >> n;
	vector<int> p(n);
	vector<int> w(n);
	for(int i = 0 ; i < n ; ++i) cin >> p[i];
	for(int i = 0 ; i < n ; ++i) cin >> w[i];
	cout << ob.maximum_cost(p , w , m , n) << endl;
	return 0;
}

