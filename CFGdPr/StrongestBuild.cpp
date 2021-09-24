/*
D. The Strongest Build
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ivan is playing yet another roguelike computer game. He controls a single hero in the game. The hero has n equipment slots. There is a list of ci items for the i-th slot, the j-th of them increases the hero strength by ai,j. The items for each slot are pairwise distinct and are listed in the increasing order of their strength increase. So, ai,1<ai,2<⋯<ai,ci.

For each slot Ivan chooses exactly one item. Let the chosen item for the i-th slot be the bi-th item in the corresponding list. The sequence of choices [b1,b2,…,bn] is called a build.

The strength of a build is the sum of the strength increases of the items in it. Some builds are banned from the game. There is a list of m pairwise distinct banned builds. It's guaranteed that there's at least one build that's not banned.

What is the build with the maximum strength that is not banned from the game? If there are multiple builds with maximum strength, print any of them.

Input
The first line contains a single integer n (1≤n≤10) — the number of equipment slots.

The i-th of the next n lines contains the description of the items for the i-th slot. First, one integer ci (1≤ci≤2⋅105) — the number of items for the i-th slot. Then ci integers ai,1,ai,2,…,ai,ci (1≤ai,1<ai,2<⋯<ai,ci≤108).

The sum of ci doesn't exceed 2⋅105.

The next line contains a single integer m (0≤m≤105) — the number of banned builds.

Each of the next m lines contains a description of a banned build — a sequence of n integers b1,b2,…,bn (1≤bi≤ci).

The builds are pairwise distinct, and there's at least one build that's not banned.

Output
Print the build with the maximum strength that is not banned from the game. If there are multiple builds with maximum strength, print any of them.

Examples
inputCopy
3
3 1 2 3
2 1 5
3 2 4 6
2
3 2 3
3 2 2
outputCopy
2 2 3 
inputCopy
3
3 1 2 3
2 1 5
3 2 4 6
2
3 2 3
2 2 3
outputCopy
1 2 3
inputCopy
3
3 1 2 3
2 1 5
3 2 4 6
2
3 2 3
2 2 3
outputCopy
3 2 2
inputCopy
4
1 10
1 4
1 7
1 3
0
outputCopy
1 1 1 1 

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
const ll modx = 998244353;
ld PI = 3.1415926535897;
const ll N = 200010;
ull pows(ull x1, ll y1, ll mod)
{
	ull r1 = 1;
	x1 = x1 % mod;
	while (y1 > 0)	{
		if (y1 & 1)
			r1 = (r1 * x1) % mod;
		y1 = y1 >> 1;
		x1 = (x1 * x1) % mod;
	}
	return r1;
}
ull f[N];
ull mi(ull x, ll mod) {
	return pows(x, mod - 2, mod);
}
ull ncr(ull x, ll y, ll mod) {
	if (x < y)
		return 0;
	if (y == 0)
		return 1;
	ll ans = f[x] * mi(f[y], mod) % mod;
	ll z = (ans * mi(f[x - y], mod) % mod) % mod;
	return z % mod;
}
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif

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
string ask(ll x, ll y) {
	cout << x + 1 << " " << y + 1;
	string s;
	cin >> s;
	return s;
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
bool is_sorted(vector<ll>a) {
	ll x = 0;
	for (ll i = 0; i < a.size() - 1; i++) {
		if (a[i] < a[i + 1])
			x++;
	}
	return x == a.size() - 1;
}
bool check(string a, string b) {
	ll n = a.size(), m = b.size();
	if (a < b) {
		return true;
	}
	if (a > b) {
		return false;
	}
	foi(a.size()) {
		if (a[i] > b[i]) {
			return false;
		}
		else if (a[i] < b[i]) {
			return true;
		}
	}
	return false;
}
bool isSubSequence(string a, string b, ll m, ll n) {
	ll j = 0;
	for (ll i = 0; i < n and j < m; i++)
		if (a[j] == b[i])
			j++;
	return (j == m);
}
ll n;
graph g(10);
ll sum(const vll &v) {
	ll s = 0;
	foi(n) {
		s += g[i][v[i] - 1];
	}
	return s;
}
void solve() {
	cin >> n;
	vll id(n);
	foi(n) {
		cin >> id[i];
		g[i].resize(id[i]);
		foj(id[i]) {
			cin >> g[i][j];
		}
	}
	mvlll m;
	ll z;
	cin >> z;
	while (z--) {
		vll ban(n);
		foi(n) {
			cin >> ban[i];
		}
		m[ban]++;
	}
	set<pair <ll, vll >, greater<> > s;
	vll t = id;
	s.insert({sum(t), t});
	while (!s.empty()) {
		auto a = s.begin()->second;
		s.erase(s.begin());
		if (!m[a]) {
			foj(n) {
				cout << a[j] << " ";
			}
			return;
		}
		foi(n) {
			if (a[i] == 1)
				continue;
			a[i]--;
			s.insert({sum(a), a});
			a[i]++;
		}

	}
}



