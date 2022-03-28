/*
D. Flood Fill
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a line of n colored squares in a row, numbered from 1 to n from left to right. The i-th square initially has the color ci.

Let's say, that two squares i and j belong to the same connected component if ci=cj, and ci=ck for all k satisfying i<k<j. In other words, all squares on the segment from i to j should have the same color.

For example, the line [3,3,3] has 1 connected component, while the line [5,2,4,4] has 3 connected components.

The game "flood fill" is played on the given line as follows:

At the start of the game you pick any starting square (this is not counted as a turn).
Then, in each game turn, change the color of the connected component containing the starting square to any other color.
Find the minimum number of turns needed for the entire line to be changed into a single color.

Input
The first line contains a single integer n (1≤n≤5000) — the number of squares.

The second line contains integers c1,c2,…,cn (1≤ci≤5000) — the initial colors of the squares.

Output
Print a single integer — the minimum number of the turns needed.

Examples
inputCopy
4
5 2 2 1
outputCopy
2
inputCopy
8
4 5 2 2 1 3 5 5
outputCopy
4
inputCopy
1
4
outputCopy
0
Note
In the first example, a possible way to achieve an optimal answer is to pick square with index 2 as the starting square and then play as follows:

[5,2,2,1]
[5,5,5,1]
[1,1,1,1]
In the second example, a possible way to achieve an optimal answer is to pick square with index 5 as the starting square and then perform recoloring into colors 2,3,5,4 in that order.

In the third example, the line already consists of one color only.


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
typedef vector<ld>          vld;
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
typedef  map<vll, ll>             mvlll;
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
const ll mod = 998244353;
ld PI = 3.1415926535897;
const ll N = 100010;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
// 	ll t; cin >> t;
// 	while (t--)
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
ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
ll ans(ll i, ll j, graph &dp, vll &b) {
	if (i > j)
		return MOD;
	if (i == j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	return dp[i][j] = min({ans(i + 1, j - 1, dp, b) + 1 + (b[i] != b[j]), ans(i + 1, j, dp, b) + 1, ans(i, j - 1, dp, b) + 1});
}
void solve() {
	ll n;
	cin >> n;
	vll a(n);
	foi(n) {
		cin >> a[i];
	}
	vll b;
	b.pb(a[0]);
	foi(n) {
		if (i == 0)
			continue;
		if (a[i] != a[i - 1])
			b.pb(a[i]);
	}
	graph dp(n, vll(n, -1));
	cout << ans(0, b.size() - 1, dp, b);
}
