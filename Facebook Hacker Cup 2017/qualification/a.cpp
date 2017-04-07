#include <bits/stdc++.h>

using namespace std;

int in_circle(double x, double y) {
	// cout << sqrt(x*x+y*y) << endl;
	return (sqrt(x*x+y*y) <= 50);
}

double angulo(double x, double y) {
	// cout << atan(x/y) << endl;
	if(x >= 0 && y < 0)
		return 180+atan(x/y)*180/M_PI;
	else if(x < 0 && y < 0)
		return 180+atan(x/y)*180/M_PI;
	else if(x < 0 && y >= 0)
		return 360+atan(x/y)*180/M_PI;
	else
		return atan(x/y)*180/M_PI;
}

int main() {

	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		double p; double x, y;
		cin >> p >> x >> y;
		x -= 50;
		y -= 50;
		// cout << p << " " << x << " " << y << endl;

		// cout << angulo(x,y) << endl;
		if(angulo(x,y) <= p/100*360 && in_circle(x,y))
			cout << "Case #" << i << ": black" << endl;
		else
			cout << "Case #" << i << ": white" << endl;
	}
}