/*
D. Districts Connection
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n districts in the town, the i-th district belongs to the ai-th bandit gang. Initially, no districts are connected to each other.

You are the mayor of the city and want to build n−1 two-way roads to connect all districts (two districts can be connected directly or through other connected districts).

If two districts belonging to the same gang are connected directly with a road, this gang will revolt.

You don't want this so your task is to build n−1 two-way roads in such a way that all districts are reachable from each other (possibly, using intermediate districts) and each pair of directly connected districts belong to different gangs, or determine that it is impossible to build n−1 roads to satisfy all the conditions.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤500) — the number of test cases. Then t test cases follow.

The first line of the test case contains one integer n (2≤n≤5000) — the number of districts. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤109), where ai is the gang the i-th district belongs to.

It is guaranteed that the sum of n does not exceed 5000 (∑n≤5000).

Output
For each test case, print:

NO on the only line if it is impossible to connect all districts satisfying the conditions from the problem statement.
YES on the first line and n−1 roads on the next n−1 lines. Each road should be presented as a pair of integers xi and yi (1≤xi,yi≤n;xi≠yi), where xi and yi are two districts the i-th road connects.
For each road i, the condition a[xi]≠a[yi] should be satisfied. Also, all districts should be reachable from each other (possibly, using intermediate districts).

Example
inputCopy
4
5
1 2 2 1 3
3
1 1 1
4
1 1000 101 1000
4
1 2 3 4
outputCopy
YES
1 3
3 5
5 4
1 2
NO
YES
1 2
2 3
3 4
YES
1 2
1 3
1 4

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
		//cout << "\n";
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
void solve() {
	ll n;
	cin >> n;
	ll a[n], s = 0;
	foi(n)
	cin >> a[i];
	ll z = a[0], y = 0, y1 = 0;
	foi(n) {
		if (a[i] == z)
			s++;
		if (y == 0 and a[i] != z)
			y = a[i], y1 = i;

	}
	if (s == n) {
		cout << "NO"<<endl;
		return;
	}
	vpll x;
	foi(n) {
		if (a[i] != a[0]) {
			x.pb(mp(1, i + 1));
		}
	}
	for (ll i = 1; i < n; i++) {
		if (a[i] == z) {
			x.pb(mp(y1 + 1, i + 1));
		}
	}
	cout << "YES" << endl;
	for (auto u : x) {
		cout << u.ff << " " << u.ss << endl;
	}

}
