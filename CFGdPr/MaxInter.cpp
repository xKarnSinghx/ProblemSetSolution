/*
C. Maximize the Intersections
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
On a circle lie 2n distinct points, with the following property: however you choose 3 chords that connect 3 disjoint pairs of points, no point strictly inside the circle belongs to all 3 chords. The points are numbered 1,2,…,2n in clockwise order.

Initially, k chords connect k pairs of points, in such a way that all the 2k endpoints of these chords are distinct.

You want to draw n−k additional chords that connect the remaining 2(n−k) points (each point must be an endpoint of exactly one chord).

In the end, let x be the total number of intersections among all n chords. Compute the maximum value that x can attain if you choose the n−k chords optimally.

Note that the exact position of the 2n points is not relevant, as long as the property stated in the first paragraph holds.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases. Then t test cases follow.

The first line of each test case contains two integers n and k (1≤n≤100, 0≤k≤n) — half the number of points and the number of chords initially drawn.

Then k lines follow. The i-th of them contains two integers xi and yi (1≤xi,yi≤2n, xi≠yi) — the endpoints of the i-th chord. It is guaranteed that the 2k numbers x1,y1,x2,y2,…,xk,yk are all distinct.

Output
For each test case, output the maximum number of intersections that can be obtained by drawing n−k additional chords.

Example
inputCopy
4
4 2
8 2
1 5
1 1
2 1
2 0
10 6
14 6
2 20
9 10
13 18
15 12
11 7
outputCopy
4
0
1
14
Note
In the first test case, there are three ways to draw the 2 additional chords, shown below (black chords are the ones initially drawn, while red chords are the new ones):


We see that the third way gives the maximum number of intersections, namely 4.

In the second test case, there are no more chords to draw. Of course, with only one chord present there are no intersections.

In the third test case, we can make at most one intersection by drawing chords 1−3 and 2−4, as shown below:


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
typedef queue<ll>           qll;
typedef vector<plll>      vplll;
typedef  vector<set<ll>>   vsll;
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
typedef  unordered_map< ll, ld>           umld;
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
	ll t ; cin >> t;
	while (t--)
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
bool COMP(pll l, pll r) {
	return l.ss < r.ss;
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
	ll n, k;
	cin >> n >> k;
	vll vis(2 * n, 0);
	vpll a;
	foi(k) {
		ll x, y;
		cin >> x >> y;
		if (x > y) {
			swap(x, y);
		}
		x--, y--;
		vis[y] = 1, vis[x] = 1;
		a.pb(mp(x, y));
	}
	vll ans;
	ll s = n - k;
	foi(2 * n) {
		if (vis[i] == 0) {
			ans.pb(i);
		}
	}
	foi(s) {
		a.pb(mp(ans[i], ans[i + s]));
	}
	ll score = 0;
	foi(n) {
		foj(n) {
			if (a[i].ff < a[j].ff and a[i].ss<a[j].ss and a[i].ss>a[j].ff) {
				score++;
			}
		}
	}
	cout << score;
	a.clear();
}


