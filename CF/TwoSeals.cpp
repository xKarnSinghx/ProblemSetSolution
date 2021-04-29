/*
C. Two Seals
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
One very important person has a piece of paper in the form of a rectangle a × b.

Also, he has n seals. Each seal leaves an impression on the paper in the form of a rectangle of the size xi × yi. Each impression must be parallel to the sides of the piece of paper (but seal can be rotated by 90 degrees).

A very important person wants to choose two different seals and put them two impressions. Each of the selected seals puts exactly one impression. Impressions should not overlap (but they can touch sides), and the total area occupied by them should be the largest possible. What is the largest area that can be occupied by two seals?

Input
The first line contains three integer numbers n, a and b (1 ≤ n, a, b ≤ 100).

Each of the next n lines contain two numbers xi, yi (1 ≤ xi, yi ≤ 100).

Output
Print the largest total area that can be occupied by two seals. If you can not select two seals, print 0.

Examples
inputCopy
2 2 2
1 2
2 1
outputCopy
4
inputCopy
4 10 9
2 3
1 1
5 10
9 11
outputCopy
56
inputCopy
3 10 10
6 6
7 7
20 5
outputCopy
0
Note
In the first example you can rotate the second seal by 90 degrees. Then put impression of it right under the impression of the first seal. This will occupy all the piece of paper.

In the second example you can't choose the last seal because it doesn't fit. By choosing the first and the third seals you occupy the largest area.

In the third example there is no such pair of seals that they both can fit on a piece of paper.


*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <chrono>
#include <complex>
using namespace std;
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define mp                   make_pair
#define eb                   emplace_back
#define pb                   push_back
#define pf                   push_front
#define popb                 pop_back
#define popf                 pop_front
#define hashmap              unordered_map
#define hashset              unordered_set
#define lb                   lower_bound
#define ub                   upper_bound
#define all(a)               (a).begin(), (a).end()
#define rall(a)              (a).rbegin(), (a).rend()
#define ff                   first
#define ss                   second
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define fok(n) for(ll k=0;k<n;k++)
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forrr(i,b,a) for(ll i=b;i>=a;i--)
#define forrrr(i,a,b,k) for(ll i=a;i<b;i=i+k)
#define graph          vector<vector<int>>
#define sz(v) v.size()
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair< ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
const ll MOD = 1000000007;
ll TT = 1;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif


	//ll t ; cin >> t;
	//while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceils(ll x, ll y) {
	return x / y + ((x % y) != 0);
}
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll sod(ll n) {
	ll s = 0;
	while (n > 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}
ll a, b;
ll cal(ll x1, ll y1, ll x2, ll y2)
{
	ll area = x1 * y1 + x2 * y2;
	if (x1 + x2 <= a && y1 <= b && y2 <= b)
		return area;
	if (y1 + y2 <= b && x1 <= a && x2 <= a)
		return area;
	return 0;
}
void solve()
{
	ll n;
	cin >> n >> a >> b;
	ll x[n], y[n];
	foi(n) {
		cin >> x[i] >> y[i];
	}
	ll ans = 0;
	foi(n) {
		for (ll j = 0; j < i; j++) {
			ans = max(ans, cal(x[i], y[i], x[j], y[j]));
			ans = max(ans, cal(x[i], y[i], y[j], x[j]));
			ans = max(ans, cal(y[i], x[i], x[j], y[j]));
			ans = max(ans, cal(y[i], x[i], y[j], x[j]));
		}
	}
	cout << ans;
}


