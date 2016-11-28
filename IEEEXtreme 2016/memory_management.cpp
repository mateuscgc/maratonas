#include <bits/stdc++.h>

using namespace std;

int main () {
	int t;
	cin >> t;
	//cout << t << endl;
	while(t--) {
		int p,s,n;
		cin >> p >> s >> n;
		//cout << p << endl;
		//cout << n << endl;
		
		deque<int> fifo;
		int ans_fifo = 0;
		
		deque<int> lru;
		int ans_lru = 0;
		 
		for(int i = 0; i < n; i++) {
			int cur; cin >> cur;
			//cout << cur << endl;
			cur = cur/s;
			
			//cout << "bla" << endl;
			if(find(fifo.begin(), fifo.end(), cur) == fifo.end()) {
				//cout << "bla\n";
				if(fifo.size() == p) {
					ans_fifo++;
					fifo.pop_front();
				}
				fifo.push_back(cur); 
			}
			
			deque<int>::iterator it = find(lru.begin(), lru.end(), cur);
			if(it == lru.end()) {
				
				if(lru.size() == p) {
					lru.pop_front();
					ans_lru++;
				}
				 
			} else {
				lru.erase(it);
			}
			lru.push_back(cur);
		}
		
		if(ans_lru < ans_fifo)
			cout << "yes ";
		else
			cout << "no ";
		cout << ans_fifo << " " << ans_lru << "\n";
	}
}