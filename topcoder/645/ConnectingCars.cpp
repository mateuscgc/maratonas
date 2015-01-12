#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

class ConnectingCars {
public:
	long long minimizeCost(vector <int>, vector <int>);
};

long long ConnectingCars::minimizeCost(vector <int> positions, vector <int> lengths) {
	vector < pair < int, int >> carros;
	int i, j;
	long long min = numeric_limits<long long>::max();
	cout << min;
	
	for (i = 0; i < positions.size(); i++) {
		carros.push_back(make_pair(positions[i], positions[i]+lengths[i]));
	}
	
	sort(carros.begin(), carros.end());
	for (i = 0; i < carros.size(); i++) {
		long long eng = 0;
		int ini = carros[i].first;
		for (j = i - 1; j >= 0; j--) {
			eng += ini - carros[j].second;
			ini = carros[j].first + (ini - carros[j].second);
		}
		ini = carros[i].second;
		for (j = i + 1; j < carros.size(); j++){
			eng += carros[j].first - ini;
			ini = carros[j].second - (carros[j].first - ini);
		}
		if (eng < min) {
			min = eng;
		}
	}
	
	return min;
}


//Powered by [KawigiEdit] 2.0!
