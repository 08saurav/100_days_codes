#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define dbg(var) cout<<#var<<"= "<<var<<" \n"
int V;
int power(int num,int base) {
    if(base==0)
      return 1;
  
    if(base%2)
      return (num*power(num,base-1));
   else {
   	int x=power(num,base/2);
    x=(x*x);
     return x;
   }
 }

double dist(int x1, int y1, int x2, int y2)
{
	return sqrt(power(x2 - x1, 2) +
	            power(y2 - y1, 2) * 1.0);
}

double tvp(double g[][101], int s)
{
	vector<int> vert;
	for (int i = 0; i < V; i++)
		if (i != s)
			vert.push_back(i);
	double minimum_path_distance = DBL_MAX;
	do {
		double curr_w = 0;
		int k = s;
		for (int i = 0; i < vert.size(); i++) {
			curr_w += g[k][vert[i]];
			k = vert[i];
		}
		minimum_path_distance = min(minimum_path_distance, curr_w);

	} while (next_permutation(vert.begin(), vert.end()));

	return minimum_path_distance;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	n++;
	pair<int, int>a[100001];
	for (int i = 0; i < n - 1; ++i) {
		cin >> a[i].first;
		a[i].second = 0;
	}
	cin >> a[n - 1].first >> a[n - 1].second;
	double g[101][101];
	V = n;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; ++j)
		{
			g[i][j] = dist(a[i].first, a[i].second, a[j].first, a[j].second);
		}

	}
	double res = tvp(g, k - 1);
	printf("%0.6f\n", res);

	return 0;
}
