#include <bits/stdc++.h>

using namespace std;


const double EPS = 1e-9;

struct Point{
	double x, y;
	
	Point(){}
	Point(double a, double b) : x(a), y(b) {}
};

struct Line{
	Point a1, a2;
	double a, b, c;
	
	Line(Point p1, Point p2){
		a1 = p1, a2 = p2;
		if(fabs(p1.x - p2.x) < EPS){
			a = 1.0, b = 0.0, c = -p1.x;
		}else{
			a = - (p1.y-p2.y)/(p1.x-p2.x);
			b = 1.0;
			c = - (a * p1.x) - p1.y;
		}
	}
	
	bool parallel(const Line & rhs) const{
 		return (fabs(a-rhs.a) < EPS) && (fabs(b-rhs.b) < EPS);
	}
	
	bool intersect(const Line & rhs, Point & p) const{
		if(this->parallel(rhs)) return false;
		p.x = (rhs.b * c - b * rhs.c) / (rhs.a*b - a*rhs.b);
		if(fabs(b) > EPS) p.y = -(a*p.x + c);
		else p.y = -(rhs.a * p.x + rhs.c);
		return true;
	}
};

struct Edge{
	int next;
	double dist;
	Edge(int a, double b) : next(a), dist(b){}
};

struct State{
	int vert;
	double dist;
	State(int a, double b) : vert(a), dist(b){}
	
	bool operator<(const State & rhs) const{
		return dist > rhs.dist;
	}
};

vector<Line> lines;
vector<Point> points;

int get_line(int i){
	if(i < 2) return -1;
	return (i-2)/2;
}

bool is_between(double x, double a, double b){
	return min(a,b) <= x && x <= max(a,b);
}

int main(){
	int x1, y1, x2, y2, n;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	points.push_back(Point(x1, y1));
	points.push_back(Point(x2, y2));
	
	vector< vector<Edge> > adj; // setar aqui
	
	for(int i = 0; i < n; i++){
		int x, y; int a, b; cin >> x >> y >> a >> b;
		lines.push_back(Line(Point(x,y), Point(a,b)));
		points.push_back(Point(x,y));
		points.push_back(Point(a,b));
	}
	
	adj.assign(points.size(), vector<Edge>());
	
	for(int i = 0; i < points.size(); i++){
		Point x = points[i];
		for(int j = i+1; j < points.size(); j++){
			Point p = points[j];
			bool ok = true;
			
			for(int k = 0; k < lines.size(); k++){
				if(get_line(i) == k || get_line(j) == k) continue;
				Point in(0,0);
				bool intersect = lines[k].intersect(Line(x, p), in);
				if(!intersect) continue;
				
				if(is_between(in.x, p.x, x.x) && is_between(in.y, p.y, x.y) &&
					is_between(in.x, lines[k].a1.x, lines[k].a2.x) && is_between(in.y, lines[k].a1.y, lines[k].a2.y)
				){
					ok = false;
					break;
				}
			}
			
			if(ok){
				double dist = hypot(p.x-x.x, p.y-x.y);
				adj[i].push_back(Edge(j, dist));
				adj[j].push_back(Edge(i, dist));
			}
		}
	}
	
	// grafo pronto
	vector<double> dist(points.size(), 0x7f7f7f7f);
	dist[0] = 0;
	priority_queue<State> pq;
	pq.push(State(0, 0));
	
	while(!pq.empty()){
		State st = pq.top(); pq.pop();
		if(st.dist > dist[st.vert]) continue;
		
		for(int j = 0; j < adj[st.vert].size(); j++){
			Edge e = adj[st.vert][j];
			if(e.dist + st.dist < dist[e.next]){
				dist[e.next] = e.dist + st.dist;
				pq.push(State(e.next, dist[e.next]));
			}
		}
	}
	
	cout << fixed << setprecision(2);
	cout << dist[1] << endl;
}