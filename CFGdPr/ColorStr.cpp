/*
C. Color Stripe
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A colored stripe is represented by a horizontal row of n square cells, each cell is pained one of k colors. Your task is to repaint the minimum number of cells so that no two neighbouring cells are of the same color. You can use any color from 1 to k to repaint the cells.

Input
The first input line contains two integers n and k (1 ≤ n ≤ 5·105; 2 ≤ k ≤ 26). The second line contains n uppercase English letters. Letter "A" stands for the first color, letter "B" stands for the second color and so on. The first k English letters may be used. Each letter represents the color of the corresponding cell of the stripe.

Output
Print a single integer — the required minimum number of repaintings. In the second line print any possible variant of the repainted stripe.

Examples
inputCopy
6 3
ABBACC
outputCopy
2
ABCACA
inputCopy
3 2
BBB
outputCopy
1
BAB
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
	ll n, k;
	vll a;
	string s;
	cin >> n >> k;
	cin >> s;
	if (k > 2)	{
		for (ll i = 1; i < n; i++) {
			if (s[i - 1] == s[i]) {
				a.pb(i);
				i++;
			}
		}
		foi(a.size()) {
			for (char c = 'A'; c <= 'Z'; c++) {
				if ((s[a[i] - 1] != c) and (a[i] + 1 == n || s[a[i] + 1] != c)) {
					s[a[i]] = c;
					break;
				}
			}
		}
		cout << a.size() << endl;
		cout << s;
		return;
	}
	else {
		string s1 = "", s2 = "";
		ll c1 = 0, c2 = 0;
		foi(n) {
			if (i % 2 == 0)
				s1 += 'A', s2 += 'B';
			else
				s1 += 'B', s2 += 'A';
		}
		foi(n) {
			if (s[i] != s1[i])
				c1++;
			if (s[i] != s2[i])
				c2++;
		}
		if (c1 < c2) {
			cout << c1 << endl;
			cout << s1;
			return;;
		}

		cout << c2 << endl;
		cout << s2;
	}

}
 
