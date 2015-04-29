#include <bits/stdc++.h>

bool tr[101], le[101];

using namespace std;

int main() {
	for (;;) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		
		
		memset(tr, 0, sizeof tr);
		memset(le, 0, sizeof le);
		
		bool ok = true;
		
		for (int i = 1; i <= n; i++) {
			int num;
			string s;
			cin >> s >> num >> s >> s;
				//cout << s << endl;
			
			if(s[0] == 't'){
				if(num == i) ok = false;
				tr[num] = true;
			}else{
				le[num] = true;
			}
			
			if(s == "leal") cin >> s >> s;
		}
		
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			cnt += tr[i];
			if(tr[i] && le[i]) ok = false;
		}
		
		if(ok)
			cout << cnt << endl;
		else
			cout << "Inconsistente" << endl;
	}
  
}
