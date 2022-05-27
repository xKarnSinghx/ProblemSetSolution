/*
F. Vlad and Unfinished Business
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vlad and Nastya live in a city consisting of n houses and n−1 road. From each house, you can get to the other by moving only along the roads. That is, the city is a tree.

Vlad lives in a house with index x, and Nastya lives in a house with index y. Vlad decided to visit Nastya. However, he remembered that he had postponed for later k things that he has to do before coming to Nastya. To do the i-th thing, he needs to come to the ai-th house, things can be done in any order. In 1 minute, he can walk from one house to another if they are connected by a road.

Vlad does not really like walking, so he is interested what is the minimum number of minutes he has to spend on the road to do all things and then come to Nastya. Houses a1,a2,…,ak he can visit in any order. He can visit any house multiple times (if he wants).

Input
The first line of input contains an integer t (1≤t≤104) — the number of input test cases. There is an empty line before each test case.

The first line of each test case contains two integers n and k (1≤k≤n≤2⋅105) — the number of houses and things, respectively.

The second line of each test case contains two integers x and y (1≤x,y≤n) — indices of the houses where Vlad and Nastya live, respectively.

The third line of each test case contains k integers a1,a2,…,ak (1≤ai≤n) — indices of houses Vlad need to come to do things.

The following n−1 lines contain description of city, each line contains two integers vj and uj (1≤uj,vj≤n) — indices of houses connected by road j.

It is guaranteed that the sum of n for all cases does not exceed 2⋅105.

Output
Output t lines, each of which contains the answer to the corresponding test case of input. As an answer output single integer — the minimum number of minutes Vlad needs on the road to do all the things and come to Nastya.

Example
inputCopy
3

3 1
1 3
2
1 3
1 2

6 4
3 5
1 6 2 1
1 3
3 4
3 5
5 6
5 2

6 2
3 2
5 3
1 3
3 4
3 5
5 6
5 2
outputCopy
3
7
2
Note
Tree and best path for the first test case:

1→2→1→3
Tree and best path for the second test case:

3→1→3→5→2→5→6→5
Tree and best path for the third test case:

3→5→2

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
const ll N = 1000001;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	ll t; cin >> t;
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
multiset<ll> Lis(vll a) {
	multiset<ll> S;
	multiset<ll>::iterator it;
	foi(a.size()) {
		S.insert(a[i]);
		it = S.lower_bound(a[i]);
		it++;
		if (it != S.end()) S.erase(it);
	}
	return S;
}
void solve() {
	ll n, k;
	cin >> n >> k;
	ll s, d;
	cin >> s >> d;
	s--, d--;
	vll thing(n, 0), vis(n, 0);
	vis[d]++;
	foi(k) {
		ll x;
		cin >> x;
		thing[x - 1]++;
	}
	graph g(n, vll());
	foi(n - 1) {
		ll x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y), g[y].pb(x);
	}
	function<void(ll, ll)>dfs = [&](ll u, ll p) {
		for (ll v : g[u]) {
			if (v == p)
				continue;
			dfs(v, u);
			if (thing[v]) {
				thing[u]++;
			}
			if (vis[v]) {
				vis[u]++;
			}
		}
	};
	dfs(s, -1);
	ll ans = 0;
	foi(n) {
		if (i == s)
			continue;
		if (vis[i])
			ans++;
		else if (thing[i])
			ans += 2;
	}
	cout << ans;
}
