/*
D. Recommendations
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
VK news recommendation system daily selects interesting publications of one of n disjoint categories for each user. Each publication belongs to exactly one category. For each category i batch algorithm selects ai publications.

The latest A/B test suggests that users are reading recommended publications more actively if each category has a different number of publications within daily recommendations. The targeted algorithm can find a single interesting publication of i-th category within ti seconds.

What is the minimum total time necessary to add publications to the result of batch algorithm execution, so all categories have a different number of publications? You can't remove publications recommended by the batch algorithm.

Input
The first line of input consists of single integer n — the number of news categories (1≤n≤200000).

The second line of input consists of n integers ai — the number of publications of i-th category selected by the batch algorithm (1≤ai≤109).

The third line of input consists of n integers ti — time it takes for targeted algorithm to find one new publication of category i (1≤ti≤105).

Output
Print one integer — the minimal required time for the targeted algorithm to get rid of categories with the same size.

Examples
inputCopy
5
3 7 9 7 8
5 2 5 7 5
outputCopy
6
inputCopy
5
1 2 3 4 5
1 1 1 1 1
outputCopy
0
Note
In the first example, it is possible to find three publications of the second type, which will take 6 seconds.

In the second example, all news categories contain a different number of publications.


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
	ll n;
	cin >> n;
	vpll a(n);
	foi(n) {
		ll x;
		cin >> x;
		a[i].ff = x;
	}
	foi(n) {
		ll x;
		cin >> x;
		a[i].ss = x;
	}
	sort(all(a));
	pq q;
	ll ans = 0, s = 0, idx = 0, cur = 0;
	while (!q.empty() or idx < n)
	{
		if (q.empty())
			cur = a[idx].ff;
		while (idx < n and a[idx].ff == cur) {
			q.push(a[idx].ss), s += a[idx].ss;
			idx++;
		}
		s -= q.top(), q.pop();
		ans += s, cur++;
	}
	cout << ans ;
}

 
