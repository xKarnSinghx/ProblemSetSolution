/*
D. GCD and MST
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a of n (n≥2) positive integers and an integer p. Consider an undirected weighted graph of n vertices numbered from 1 to n for which the edges between the vertices i and j (i<j) are added in the following manner:

If gcd(ai,ai+1,ai+2,…,aj)=min(ai,ai+1,ai+2,…,aj), then there is an edge of weight min(ai,ai+1,ai+2,…,aj) between i and j.
If i+1=j, then there is an edge of weight p between i and j.
Here gcd(x,y,…) denotes the greatest common divisor (GCD) of integers x, y, ....

Note that there could be multiple edges between i and j if both of the above conditions are true, and if both the conditions fail for i and j, then there is no edge between these vertices.

The goal is to find the weight of the minimum spanning tree of this graph.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains two integers n (2≤n≤2⋅105) and p (1≤p≤109) — the number of nodes and the parameter p.

The second line contains n integers a1,a2,a3,…,an (1≤ai≤109).

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
Output t lines. For each test case print the weight of the corresponding graph.

Example
inputCopy
4
2 5
10 10
2 5
3 3
4 5
5 2 4 9
8 8
5 3 3 6 10 100 9 15
outputCopy
5
3
12
46
Note
Here are the graphs for the four test cases of the example (the edges of a possible MST of the graphs are marked pink):

For test case 1


For test case 2


For test case 3


For test case 4



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
	ll n, p;
	cin >> n >> p;
	vll a(n + 1), visited(n + 1, 0);
	vpll tree;
	foi(n) {
		ll x;
		cin >> x;
		a[i + 1] = x;
		tree.pb(mp(a[i + 1], i + 1));
	}
	sort(all(tree));
	ll ans = 0, cnt = 0;
	for (auto it : tree) {
		if (it.ff >= p)
			break;
		ll l = it.ss, r = it.ss;
		while (l > 1) {
			if (visited[l - 1] == 1)
				break;
			if (a[l - 1] % it.ff)
				break;
			l--;
			visited[l] = 1;
		}
		while (r < n) {
			if (visited[r] == 1)
				break;
			if (a[r + 1] % it.ff)
				break;
			r++;
			visited[r - 1] = 1;
		}
		cnt += r - l;
		ans += (r - l) * it.ff;
	}
	ans += (n - 1 - cnt) * p;
	cout << ans;

}
