/*
C. Parsa's Humongous Tree
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Parsa has a humongous tree on n vertices.

On each vertex v he has written two integers lv and rv.

To make Parsa's tree look even more majestic, Nima wants to assign a number av (lv≤av≤rv) to each vertex v such that the beauty of Parsa's tree is maximized.

Nima's sense of the beauty is rather bizarre. He defines the beauty of the tree as the sum of |au−av| over all edges (u,v) of the tree.

Since Parsa's tree is too large, Nima can't maximize its beauty on his own. Your task is to find the maximum possible beauty for Parsa's tree.

Input
The first line contains an integer t (1≤t≤250) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer n (2≤n≤105) — the number of vertices in Parsa's tree.

The i-th of the following n lines contains two integers li and ri (1≤li≤ri≤109).

Each of the next n−1 lines contains two integers u and v (1≤u,v≤n,u≠v) meaning that there is an edge between the vertices u and v in Parsa's tree.

It is guaranteed that the given graph is a tree.

It is guaranteed that the sum of n over all test cases doesn't exceed 2⋅105.

Output
For each test case print the maximum possible beauty for Parsa's tree.

Example
inputCopy
3
2
1 6
3 8
1 2
3
1 3
4 6
7 9
1 2
2 3
6
3 14
12 20
12 19
2 12
10 17
3 17
3 2
6 5
1 5
2 6
4 6
outputCopy
7
8
62
Note
The trees in the example:


In the first test case, one possible assignment is a={1,8} which results in |1−8|=7.

In the second test case, one of the possible assignments is a={1,5,9} which results in a beauty of |1−5|+|5−9|=8
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
graph v, dp, cost;
void dfs(ll x, ll z) {
	for (auto y : v[x]) {
		if (y == z)
			continue;
		else {
			dfs(y, x);
			dp[x][0] += max(dp[y][0] + abs(cost[y][0] - cost[x][0]), dp[y][1] + abs(cost[y][1] - cost[x][0]));
			dp[x][1] += max(dp[y][0] + abs(cost[y][0] - cost[x][1]), dp[y][1] + abs(cost[y][1] - cost[x][1]));
		}
	}
}
void solve() {
	ll n;
	cin >> n;
	v.clear();
	v.resize(n + 1);
	cost.clear();
	cost.resize(n + 1, vll(2));
	dp.clear();
	dp.resize(n + 1, vll(2));
	foi(n) {
		ll x, y;
		cin >> x >> y;
		cost[i + 1][0] = x;
		cost[i + 1][1] = y;
	}
	foi(n - 1) {
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]);
}


