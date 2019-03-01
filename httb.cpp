
 #include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, i, im;
	double tm=1e20, t, vb, vs, xu, yu, x[102];
	cin>>n>>vb>>vs;
	for (i=1; i<=n; i++) cin>>x[i];
	cin>>xu>>yu;
	for (i=2; i<=n; i++) {
		t = x[i]/vb+sqrt((x[i]-xu)*(x[i]-xu)+yu*yu)/vs;
		if (t<=tm) {
			im=i; tm=t;
		}
	}
	cout<<im<<endl;
	return 0;
}
