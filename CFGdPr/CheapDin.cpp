/*
E. Cheap Dinner
time limit per test4 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
Ivan wants to have a good dinner. A good dinner should consist of a first course, a second course, a drink, and a dessert.

There are n1 different types of first courses Ivan can buy (the i-th of them costs ai coins), n2 different types of second courses (the i-th of them costs bi coins), n3 different types of drinks (the i-th of them costs ci coins) and n4 different types of desserts (the i-th of them costs di coins).

Some dishes don't go well with each other. There are m1 pairs of first courses and second courses that don't go well with each other, m2 pairs of second courses and drinks, and m3 pairs of drinks and desserts that don't go well with each other.

Ivan wants to buy exactly one first course, one second course, one drink, and one dessert so that they go well with each other, and the total cost of the dinner is the minimum possible. Help him to find the cheapest dinner option!

Input
The first line contains four integers n1, n2, n3 and n4 (1≤ni≤150000) — the number of types of first courses, second courses, drinks and desserts, respectively.

Then four lines follow. The first line contains n1 integers a1,a2,…,an1 (1≤ai≤108), where ai is the cost of the i-th type of first course. Three next lines denote the costs of second courses, drinks, and desserts in the same way (1≤bi,ci,di≤108).

The next line contains one integer m1 (0≤m1≤200000) — the number of pairs of first and second courses that don't go well with each other. Each of the next m1 lines contains two integers xi and yi (1≤xi≤n1; 1≤yi≤n2) denoting that the first course number xi doesn't go well with the second course number yi. All these pairs are different.

The block of pairs of second dishes and drinks that don't go well with each other is given in the same format. The same for pairs of drinks and desserts that don't go well with each other (0≤m2,m3≤200000).

Output
If it's impossible to choose a first course, a second course, a drink, and a dessert so that they go well with each other, print −1. Otherwise, print one integer — the minimum total cost of the dinner.

Examples
inputCopy
4 3 2 1
1 2 3 4
5 6 7
8 9
10
2
1 2
1 1
2
3 1
3 2
1
1 1
outputCopy
26
inputCopy
1 1 1 1
1
1
1
1
1
1 1
0
0
outputCopy
-1
Note
The best option in the first example is to take the first course 2, the second course 1, the drink 2 and the dessert 1.

In the second example, the only pair of the first course and the second course is bad, so it's impossible to have dinner.
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
vll p;
const ll N = 1000010;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	/*ll t; cin >> t;
	vb is_prime(N / 10, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= N / 10; i++) {
		if (is_prime[i]) {
			p.pb(i);
			for (int j = i * i; j <= N / 10; j += i)
				is_prime[j] = false;
		}
	}
	reverse(all(p));
	while (t--)*/
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
ll ask(ll x) {
	cout << "?" << " ";
	cout << x + 1 << endl;
	ll s;
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
ll power(ll n, ll x) {
	ll ans = 1;
	foi(n) {
		ans *= x;
	}
	return ans;
}
void solve() {
	vll n(4);
	foi(4) {
		cin >> n[i];
	}
	graph a(4);
	foi(4) {
		a[i].resize(n[i]);
		foj(n[i]) {
			cin >> a[i][j];
		}
	}
	vll m(3);
	vector<graph> c(3);
	foi(3) {
		cin >> m[i];
		c[i].resize(n[i]);
		foj(m[i]) {
			ll x, y;
			cin >> x >> y;
			x--; y--;
			c[i][x].pb(y);
		}
	}
	for (ll i = 2; i >= 0; i --) {
		multiset<ll> s(all(a[i + 1]));
		foj(n[i]) {
			for (ll k : c[i][j]) {
				auto z = s.find(a[i + 1][k]);
				s.erase(z);
			}
			if (!s.empty())
				a[i][j] += *s.begin();
			else
				a[i][j] = MOD * MOD;
			if (a[i][j] > MOD * MOD)
				a[i][j] = MOD * MOD;
			for (ll k : c[i][j])
				s.insert(a[i + 1][k]);
		}
	}
	ll ans = *min_element(all(a[0]));
	(ans == MOD * MOD) ? cout << -1 : cout << ans;

}
