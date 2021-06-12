/*
D. Renting Bikes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A group of n schoolboys decided to ride bikes. As nobody of them has a bike, the boys need to rent them.

The renting site offered them m bikes. The renting price is different for different bikes, renting the j-th bike costs pj rubles.

In total, the boys' shared budget is a rubles. Besides, each of them has his own personal money, the i-th boy has bi personal rubles. The shared budget can be spent on any schoolchildren arbitrarily, but each boy's personal money can be spent on renting only this boy's bike.

Each boy can rent at most one bike, one cannot give his bike to somebody else.

What maximum number of schoolboys will be able to ride bikes? What minimum sum of personal money will they have to spend in total to let as many schoolchildren ride bikes as possible?

Input
The first line of the input contains three integers n, m and a (1 ≤ n, m ≤ 105; 0 ≤ a ≤ 109). The second line contains the sequence of integers b1, b2, ..., bn (1 ≤ bi ≤ 104), where bi is the amount of the i-th boy's personal money. The third line contains the sequence of integers p1, p2, ..., pm (1 ≤ pj ≤ 109), where pj is the price for renting the j-th bike.

Output
Print two integers r and s, where r is the maximum number of schoolboys that can rent a bike and s is the minimum total personal money needed to rent r bikes. If the schoolchildren cannot rent any bikes, then r = s = 0.

Examples
inputCopy
2 2 10
5 5
7 6
outputCopy
2 3
inputCopy
4 5 2
8 1 1 2
6 3 7 5 2
outputCopy
3 8
Note
In the first sample both schoolchildren can rent a bike. For instance, they can split the shared budget in half (5 rubles each). In this case one of them will have to pay 1 ruble from the personal money and the other one will have to pay 2 rubles from the personal money. In total, they spend 3 rubles of their personal money. This way of distribution of money minimizes the amount of spent personal money.

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
	ll n, m1 , a;
	cin >> n >> m1 >> a;
	vll m(n, 0);
	foi(n) {
		ll x;
		cin >> x;
		m[i] = x;
	}
	vll p(m1, 0);
	foi(m1) {
		ll x;
		cin >> x;
		p[i] = x;
	}
	sort(all(p));
	sort(all(m));
	ll l = 0, r = min(n, m1), no = 0, ans = -a;
	while (l < r) {
		ll s = 0, mid = ceils(l + r, 2);
		foi(mid) {
			if (p[i] > m[n + i - mid])
				s += p[i] - m[n - mid + i];
		}
		if (s <= a) {
			l = mid;
		}
		else
			r = mid - 1;
	}
	cout << l << " ";;
	foi(l) {
		ans += p[i];
	}
	if (ans < 0)
		cout << 0;
	else
		cout << ans;

}
