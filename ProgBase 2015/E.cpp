#include <bits/stdc++.h>

using namespace std;

struct Edge{
  int next;
  double time;
  int dist;
  
  Edge(){
    next = 0, time = 0, dist = 0;
  }
  Edge(int a, double b, int c) : next(a), time(b), dist(c){}
  
  bool operator<(const Edge & rhs) const{
    if(time < rhs.time) return true;
    else if(time == rhs.time) return dist < rhs.dist;
    return false;
  }
};

struct State{
  int vert;
  Edge e;
  
  State(int a, Edge b) : vert(a), e(b){}
  
  bool operator<(const State & rhs) const{
    return rhs.e < e;
  }
};

int main(){
    int source, sink,  n, m;
    while(scanf("%d%d%d%d", &source, &sink, &n, &m), n){
	vector< vector<Edge> > adj;
	adj.assign(n+1, vector<Edge>());
	
	while(m--){
	      int a, b, d, v;
	      scanf("%d%d%d%d", &a, &b, &d, &v);
	      adj[a].push_back(Edge(b, 1.0*d/v, d));
	      adj[b].push_back(Edge(a, 1.0*d/v, d));
	}
	
	vector<Edge> t(n+1, Edge(0,(int)0x3f3f3f3f,(int)0x3f3f3f3f));
	t[source] = Edge(0, 0, 0);
	
	priority_queue<State> pq;
	pq.push(State(source, Edge()));
	
	while(!pq.empty()){
	  State st = pq.top(); pq.pop();
	  if(t[st.vert] < st.e) continue;
	  
	  for(int j = 0; j < adj[st.vert].size(); j++){
	    Edge e = adj[st.vert][j];
	    Edge nil = Edge(0, st.e.time + e.time, st.e.dist + e.dist);
	    if(nil < t[e.next]){
	      t[e.next] = nil;
	      pq.push(State(e.next, nil));
	    }
	  }
	}
	
	if(t[sink].dist == 0x3f3f3f3f)
	  puts("SEM CAMINHO");
	else
	  printf("%d\n", t[sink].dist);
    }
}