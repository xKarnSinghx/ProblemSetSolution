/*
E1. Reading Books (easy version)
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Easy and hard versions are actually different problems, so read statements of both problems completely and carefully.

Summer vacation has started so Alice and Bob want to play and joy, but... Their mom doesn't think so. She says that they have to read some amount of books before all entertainments. Alice and Bob will read each book together to end this exercise faster.

There are n books in the family library. The i-th book is described by three integers: ti — the amount of time Alice and Bob need to spend to read it, ai (equals 1 if Alice likes the i-th book and 0 if not), and bi (equals 1 if Bob likes the i-th book and 0 if not).

So they need to choose some books from the given n books in such a way that:

Alice likes at least k books from the chosen set and Bob likes at least k books from the chosen set;
the total reading time of these books is minimized (they are children and want to play and joy as soon a possible).
The set they choose is the same for both Alice an Bob (it's shared between them) and they read all books together, so the total reading time is the sum of ti over all books that are in the chosen set.

Your task is to help them and find any suitable set of books or determine that it is impossible to find such a set.

Input
The first line of the input contains two integers n and k (1≤k≤n≤2⋅105).

The next n lines contain descriptions of books, one description per line: the i-th line contains three integers ti, ai and bi (1≤ti≤104, 0≤ai,bi≤1), where:

ti — the amount of time required for reading the i-th book;
ai equals 1 if Alice likes the i-th book and 0 otherwise;
bi equals 1 if Bob likes the i-th book and 0 otherwise.
Output
If there is no solution, print only one integer -1. Otherwise print one integer T — the minimum total reading time of the suitable set of books.

Examples
inputCopy
8 4
7 1 1
2 1 1
4 0 1
8 1 1
1 0 1
1 1 1
1 0 1
3 0 0
outputCopy
18
inputCopy
5 2
6 0 0
9 0 0
1 0 1
2 1 1
5 1 0
outputCopy
8
inputCopy
5 3
3 0 0
2 1 0
3 1 0
5 0 1
3 0 1
outputCopy
-1

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
void solve() {
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	vll x, y, z;
	foi(n) {
		ll c, a, b;
		cin >> c >> a >> b;
		if (a == b and a == 1)
			x.pb(c);
		else if (a)
			y.pb(c);
		else if (b)
			z.pb(c);
	}
	sort(all(y));
	sort(all(z));
	if (x.size() + y.size() < k or x.size() + z.size() < k) {
		cout << -1;
		return;
	}
	foi(min(y.size(), z.size())) {
		x.pb(y[i] + z[i]);
	}

	sort(all(x));
	foi(k)
	ans += x[i];
	cout << ans;

}

