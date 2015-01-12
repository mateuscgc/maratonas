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

using namespace std;

class BacteriesColony {
public:
	vector <int> performTheExperiment(vector <int>);
};

vector <int> BacteriesColony::performTheExperiment(vector <int> colonies) {
	int i;
	int changed = 1;
	vector <int> update(colonies.size());
	while (changed) {
		changed = 0;
		for (i = 1; i < colonies.size()-1; i++) {
			if (colonies[i-1] > colonies[i] && colonies[i+1] > colonies[i]){
				update[i] = -1;
				changed = 1;
			} else if (colonies[i-1] < colonies[i] && colonies[i+1] < colonies[i]) {
				update[i];
				changed = 1;
			}
		}
		for (i = 1; i < colonies.size()-1; i++) {
			if (update[i]) {
				colonies[i] += update[i];
				update[i] = 0;
			}
		}
	}
	
	cout <<"bla bla";
	for (i = 0; i < colonies.size(); i++)
		cout << colonies[i];
	
	return colonies;
}

//Powered by [KawigiEdit] 2.0!
