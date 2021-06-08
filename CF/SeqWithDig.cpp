/*
A. Sequence with Digits
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's define the following recurrence:
an+1=an+minDigit(an)⋅maxDigit(an).
Here minDigit(x) and maxDigit(x) are the minimal and maximal digits in the decimal representation of x without leading zeroes. For examples refer to notes.

Your task is calculate aK for given a1 and K.

Input
The first line contains one integer t (1≤t≤1000) — the number of independent test cases.

Each test case consists of a single line containing two integers a1 and K (1≤a1≤1018, 1≤K≤1016) separated by a space.

Output
For each test case print one integer aK on a separate line.

Example
inputCopy
8
1 4
487 1
487 2
487 3
487 4
487 5
487 6
487 7
outputCopy
42
487
519
528
544
564
588
628
Note
a1=487

a2=a1+minDigit(a1)⋅maxDigit(a1)=487+min(4,8,7)⋅max(4,8,7)=487+4⋅8=519

a3=a2+minDigit(a2)⋅maxDigit(a2)=519+min(5,1,9)⋅max(5,1,9)=519+1⋅9=528

a4=a3+minDigit(a3)⋅maxDigit(a3)=528+min(5,2,8)⋅max(5,2,8)=528+2⋅8=544

a5=a4+minDigit(a4)⋅maxDigit(a4)=544+min(5,4,4)⋅max(5,4,4)=544+4⋅5=564

a6=a5+minDigit(a5)⋅maxDigit(a5)=564+min(5,6,4)⋅max(5,6,4)=564+4⋅6=588

a7=a6+minDigit(a6)⋅maxDigit(a6)=588+min(5,8,8)⋅max(5,8,8)=588+5⋅8=628

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
	ll a, k, x;
	cin >> x >> k;

	while (k > 1)
	{
		a = x;
		ll l = 0, s = 9;
		while (a)
		{
			ll r = a % 10;
			l = max(r, l);
			s = min(r, s);
			a = a / 10;
		}
		x = x + l * s;
		if (s == 0)
		{
			break;
		}
		k--;
	}

	cout << x;

}
