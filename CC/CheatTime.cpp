/*
Chef's college is conducting an online exam, where his camera will be monitored by one or more invigilators (supervisors). Once again, Chef failed to prepare for the exam on time and decided to google answers during it.

The exam starts at time 0 and ends at time F minutes. Chef needs a total of K minutes of googling during the exam in order to pass it. There are N invigilators (numbered 1 through N); for each valid i, the i-th invigilator monitors Chef's camera during the time interval starting at Si minutes since the start of the exam and ending at Ei minutes (where 0≤Si≤Ei≤F). He was resourceful enough to somehow get hold of these times and now he wants to know if he would be able to pass the exam if he googles the answers during the times when no one is looking at his camera.

Note: The time of googling need not be continuous and there can be multiple invigilators at some interval of time.
Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, K and F.
N lines follow. For each valid i, the i-th of these lines contains two space-separated integers Si and Ei.
Output
For each test case, print a single line containing the string "YES" if it is possible to pass the exam or "NO" if it is impossible.

You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤105
1≤N≤105
1≤F≤109
0≤K≤F
0≤Si≤Ei≤F for each valid i
the sum of N over all test cases does not exceed  2⋅10
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
void solve() {
	ll n, k, f;
	cin >> n >> k >> f;
	pll p[n];
	ll ans = 0;
	foi(n) {
		ll x, y;
		cin >> x >> y;
		p[i] = mp(x, y);
	}
	sort(p, p + n);
	if (p[0]. ff != 0)
		ans = p[0].ff;
	ll h = p[0]. ss;
	for (ll i = 1; i < n; i++) {
		if (h < p[i].ff) {
			ans += p[i].ff - h;
		}
		h = max(p[i].ss, h);
	}
	if (h < f)
		ans += f - h;
	if (ans >= k)
		cout << "YES";
	else
		cout << "NO";
}



