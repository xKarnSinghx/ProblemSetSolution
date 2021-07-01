/*
D. Xenia and Colorful Gems
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Xenia is a girl being born a noble. Due to the inflexibility and harshness of her family, Xenia has to find some ways to amuse herself.


 
Recently Xenia has bought nr red gems, ng green gems and nb blue gems. Each of the gems has a weight.

Now, she is going to pick three gems.

Xenia loves colorful things, so she will pick exactly one gem of each color.

Xenia loves balance, so she will try to pick gems with little difference in weight.

Specifically, supposing the weights of the picked gems are x, y and z, Xenia wants to find the minimum value of (x−y)2+(y−z)2+(z−x)2. As her dear friend, can you help her?

Input
The first line contains a single integer t (1≤t≤100)  — the number of test cases. Then t test cases follow.

The first line of each test case contains three integers nr,ng,nb (1≤nr,ng,nb≤105)  — the number of red gems, green gems and blue gems respectively.

The second line of each test case contains nr integers r1,r2,…,rnr (1≤ri≤109)  — ri is the weight of the i-th red gem.

The third line of each test case contains ng integers g1,g2,…,gng (1≤gi≤109)  — gi is the weight of the i-th green gem.

The fourth line of each test case contains nb integers b1,b2,…,bnb (1≤bi≤109)  — bi is the weight of the i-th blue gem.

It is guaranteed that ∑nr≤105, ∑ng≤105, ∑nb≤105 (the sum for all test cases).

Output
For each test case, print a line contains one integer  — the minimum value which Xenia wants to find.

Example
inputCopy
5
2 2 3
7 8
6 3
3 1 4
1 1 1
1
1
1000000000
2 2 2
1 2
5 4
6 7
2 2 2
1 2
3 4
6 7
3 4 1
3 2 1
7 3 3 4
6
outputCopy
14
1999999996000000002
24
24
14
Note
In the first test case, Xenia has the following gems:



If she picks the red gem with weight 7, the green gem with weight 6, and the blue gem with weight 4, she will achieve the most balanced selection with (x−y)2+(y−z)2+(z−x)2=(7−6)2+(6−4)2+(4−7)2=14.

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
ll cal(ll a, ll b, ll c) {
	return (a - b) * (a - b) + (b - c) * (b - c) + (c - a) * (c - a);
}
void solve() {
	ll nr, nb, ng;
	cin >> nr >> ng >> nb;
	vll a(nr, 0), b(ng, 0), c(nb, 0);
	foi(nr) {
		ll x;
		cin >> x;
		a[i] = x;
	}
	foi(ng) {
		ll x;
		cin >> x;
		b[i] = x;
	}
	foi(nb) {
		ll x;
		cin >> x;
		c[i] = x ;
	}
	sort(all(a)), sort(all(b)), sort(all(c));
	ll it = 0, it1 = 0, it2 = 0;
	ll ans = cal(a[it], b[it1], c[it2]);
	while (it < nr - 1 or it1 < ng - 1 or it2 < nb - 1) {
		ll a1 = 2e18, b1 = 2e18, c1 = 2e18;
		if (it <= nr - 2) {
			a1 = cal(a[it + 1], b[it1], c[it2]);
		}
		if (it1 <= ng - 2) {
			b1 = cal(a[it], b[it1 + 1], c[it2]);
		}
		if (it2 <= nb - 2) {
			c1 = cal(a[it], b[it1], c[it2 + 1]);
		}
		if (a1 <= b1 and a1 <= c1) {
			ans = min(ans, a1), it++;
		}
		else if (b1 <= a1 and b1 <= c1) {
			ans = min(ans, b1), it1++;
		}
		else {
			ans = min(ans, c1), it2++;
		}
	}
	cout << min(ans, cal(a[nr - 1], b[ng - 1], c[nb - 1]));
}

