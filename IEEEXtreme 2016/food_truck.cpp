#include <bits/stdc++.h>

using namespace std;

struct registro {
	int mes, dia, ano, hora, minuto;
	long double lat1, longi1;
};

long double dist(long double lat1, long double longi1, long double lat2, long double longi2){
	long double seno = sin((lat2-lat1)/2);
	long double seno2 = sin((longi2-longi1)/2);
	long double res = 12756.274*asin(sqrt(seno*seno +cos(lat1)*cos(lat2)*seno2*seno2));
	cout << res << endl;
	return res;
}

long double deg2rad(double deg) {
  return (deg * acos(-1) / 180);
}

//  This function converts radians to decimal degrees
long double rad2deg(double rad) {
  return (rad * 180 / acos(-1));
}

long double distanceEarth(long double lat1d, long double lon1d, long double lat2d, long double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 12756.274* asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

int main(){
	long double lat, longi, radius;
	scanf("%Lf,%Lf", &lat, &longi);
	scanf("%Lf", &radius);
	map<long long, registro> gps;
	string joga;
	cin >> joga;
	int mes,dia,ano,hora,minuto;
	long double lat1, longi1;
	char c;
	long long number;
	//set<long long> resp;
	while(scanf("%d/%d/%d %d:%d,%Lf,%Lf,%lld",&mes,&dia,&ano,&hora,&minuto,&lat1,&longi1,&number)!= EOF){
		//cout << lat1 << endl << longi1 << endl << number << endl << endl;
		registro aux = {mes,dia,ano,hora,minuto,lat1,longi1};
		if(gps.count(number)) {
			//cout << "bla" << endl;
			if(ano > gps[number].ano) {
				gps[number] = aux;
			} else if(ano == gps[number].ano) {
				if(mes > gps[number].mes) {
					gps[number] = aux;
 				} else if(mes == gps[number].mes) {
					if(dia > gps[number].dia) {
						gps[number] = aux;		
					} else if(dia == gps[number].dia) {
						if(hora > gps[number].hora) {
							gps[number] = aux;		
						} else if(hora == gps[number].hora) {
							if(minuto > gps[number].minuto) {
								gps[number] = aux;		
							}
						}
					}
				}
			}	
		} else {
			gps[number] = aux;
		}	
		//cout << gps[9020320007].hora << endl;
		
	}
	int flag=0;
	//for(long long it : resp){
	//	if(!flag){
	//		cout << it;
	//		flag = 1;
	//	}
	//	else cout << "," << it;
	//}
	for(pair<long long, registro> it : gps) {

		if(distanceEarth(lat,longi,it.second.lat1,it.second.longi1) <= radius){
			if(!flag){
				cout << it.first;
				flag = 1;
			}
			else cout << "," << it.first;
		}
	}

	cout << endl;	
}