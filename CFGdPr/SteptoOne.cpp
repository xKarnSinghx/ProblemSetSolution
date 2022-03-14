/*
D. Steps to One
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vivek initially has an empty array a and some integer constant m.

He performs the following algorithm:

Select a random integer x uniformly in range from 1 to m and append it to the end of a.
Compute the greatest common divisor of integers in a.
In case it equals to 1, break
Otherwise, return to step 1.
Find the expected length of a. It can be shown that it can be represented as PQ where P and Q are coprime integers and Q≠0(mod109+7). Print the value of P⋅Q−1(mod109+7).

Input
The first and only line contains a single integer m (1≤m≤100000).

Output
Print a single integer — the expected length of the array a written as P⋅Q−1(mod109+7).

Examples
inputCopy
1
outputCopy
1
inputCopy
2
outputCopy
2
inputCopy
4
outputCopy
333333338
Note
In the first example, since Vivek can choose only integers from 1 to 1, he will have a=[1] after the first append operation, and after that quit the algorithm. Hence the length of a is always 1, so its expected value is 1 as well.

In the second example, Vivek each time will append either 1 or 2, so after finishing the algorithm he will end up having some number of 2's (possibly zero), and a single 1 in the end. The expected length of the list is 1⋅12+2⋅122+3⋅123+…=2.


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
void solve() {
	ll n, ans = 1;
	cin >> n;
	vll gc(n + 1, 0);
	for (ll i = n; i > 1; i--) {
		gc[i] = (binpow(MOD + 1 - ((n / i * binpow(n, MOD - 2, MOD)) % MOD), MOD - 2, MOD) - 1 ) % MOD;
		for (ll j = i + i; j <= n; j += i) {
			gc[i] = (gc[i] - gc[j] + MOD) % MOD;
		}
		ans = (ans + gc[i]) % MOD;
	}
	cout << ans % MOD;
}
