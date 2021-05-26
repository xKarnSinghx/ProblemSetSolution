/*
D. Kavi on Pairing Duty
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Kavi has 2n points lying on the OX axis, i-th of which is located at x=i.

Kavi considers all ways to split these 2n points into n pairs. Among those, he is interested in good pairings, which are defined as follows:

Consider n segments with ends at the points in correspondent pairs. The pairing is called good, if for every 2 different segments A and B among those, at least one of the following holds:

One of the segments A and B lies completely inside the other.
A and B have the same length.
Consider the following example:


A is a good pairing since the red segment lies completely inside the blue segment.

B is a good pairing since the red and the blue segment have the same length.

C is not a good pairing since none of the red or blue segments lies inside the other, neither do they have the same size.

Kavi is interested in the number of good pairings, so he wants you to find it for him. As the result can be large, find this number modulo 998244353.

Two pairings are called different, if some two points are in one pair in some pairing and in different pairs in another.

Input
The single line of the input contains a single integer n (1≤n≤106).

Output
Print the number of good pairings modulo 998244353.

Examples
inputCopy
1
outputCopy
1
inputCopy
2
outputCopy
3
inputCopy
3
outputCopy
6
inputCopy
100
outputCopy
688750769
Note
The good pairings for the second example are:


In the third example, the good pairings are:


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

//	ll t ; cin >> t;
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
ll powmod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) {
		res = res * x % MOD;
	}
	return res;
}
const ll mod = 998244353;
void solve() {
	ll n;
	cin >> n;
	ll dp[2 * n + 1] = {};
	for (ll i = 1; i <= n; i++) {
		for (ll j = 2 * i; j <= n; j += i) {
			dp[j]++;
		}
	}
	ll xn = 1;
	for (ll i = 1; i <= n; i++) {
		dp[i] += xn;
		dp[i] %= mod;
		xn += dp[i];
		xn %= mod;
	}
	cout << dp[n];
}


