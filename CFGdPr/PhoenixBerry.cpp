/*
E. Phoenix and Berries
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Phoenix is picking berries in his backyard. There are n shrubs, and each shrub has ai red berries and bi blue berries.

Each basket can contain k berries. But, Phoenix has decided that each basket may only contain berries from the same shrub or berries of the same color (red or blue). In other words, all berries in a basket must be from the same shrub or/and have the same color.

For example, if there are two shrubs with 5 red and 2 blue berries in the first shrub and 2 red and 1 blue berries in the second shrub then Phoenix can fill 2 baskets of capacity 4 completely:

the first basket will contain 3 red and 1 blue berries from the first shrub;
the second basket will contain the 2 remaining red berries from the first shrub and 2 red berries from the second shrub.
Help Phoenix determine the maximum number of baskets he can fill completely!

Input
The first line contains two integers n and k (1≤n,k≤500) — the number of shrubs and the basket capacity, respectively.

The i-th of the next n lines contain two integers ai and bi (0≤ai,bi≤109) — the number of red and blue berries in the i-th shrub, respectively.

Output
Output one integer — the maximum number of baskets that Phoenix can fill completely.

Examples
inputCopy
2 4
5 2
2 1
outputCopy
2
inputCopy
1 5
2 3
outputCopy
1
inputCopy
2 5
2 1
1 3
outputCopy
0
inputCopy
1 2
1000000000 1
outputCopy
500000000
Note
The first example is described above.

In the second example, Phoenix can fill one basket fully using all the berries from the first (and only) shrub.

In the third example, Phoenix cannot fill any basket completely because there are less than 5 berries in each shrub, less than 5 total red berries, and less than 5 total blue berries.

In the fourth example, Phoenix can put all the red berries into baskets, leaving an extra blue berry behind.


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
#define graph          vector<vector<ll>>
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
typedef  map<ll, vll>             mvll;
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll modx = 998244353;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
//	ll t ; cin >> t;
//	while (t--)
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
ll powmod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) {
		res = res * x % MOD;
	}
	return res;
}
bool isPrime(ll n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
ll kadanesAlgo(vll a)
{
	ll n = a.size();

	ll currMax = 0;
	ll mx = INT_MIN;

	foi(n)
	{
		currMax += a[i];

		if (currMax <= a[i])
		{
			currMax = a[i];
		}

		mx = max(currMax, mx);
	}
	return mx;
}
void solve() {
	ll n, xk;
	cin >> n >> xk;
	vll a(n + 1, 0), b(n + 1, 0);
	ll r = 0, bl = 0;
	foi(n) {
		ll x, y;
		cin >> x >> y;
		a[i + 1] = x, b[i + 1] = y, r += x, bl += y;
	}
	bool g[510][510];
	foi(510) {
		foj(510) {
			g[i][j] = false;
		}
	}
	g[0][0] = true;
	for (ll i = 1; i <= n; i++) {
		foj(xk) {
			g[i][j] = g[i - 1][(j - a[i] % xk + xk) % xk];
			fok(min(xk - 1, a[i]) + 1) {
				if ((a[i] - k) % xk + b[i] >= xk)
					g[i][j] |= g[i - 1][(j - k + xk) % xk];
			}
		}
	}
	foi(xk) {
		if (g[n][i]) {
			cout << (r + bl - i) / xk;
			return;
		}
	}
}
 
