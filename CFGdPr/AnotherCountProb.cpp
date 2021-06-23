/*
C. Yet Another Counting Problem
time limit per test3.5 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two integers a and b, and q queries. The i-th query consists of two numbers li and ri, and the answer to it is the number of integers x such that li≤x≤ri, and ((xmoda)modb)≠((xmodb)moda). Calculate the answer for each query.

Recall that ymodz is the remainder of the division of y by z. For example, 5mod3=2, 7mod8=7, 9mod4=1, 9mod9=0.

Input
The first line contains one integer t (1≤t≤100) — the number of test cases. Then the test cases follow.

The first line of each test case contains three integers a, b and q (1≤a,b≤200; 1≤q≤500).

Then q lines follow, each containing two integers li and ri (1≤li≤ri≤1018) for the corresponding query.

Output
For each test case, print q integers — the answers to the queries of this test case in the order they appear.

Example
inputCopy
2
4 6 5
1 1
1 3
1 5
1 7
1 9
7 10 2
7 8
100 200
outputCopy
0 0 0 2 4 
0 91 

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

void solve() {
	ll a, b, q;
	cin >> a >> b >> q;
	vll ans(a * b + 1, 0);
	for (ll i = 1; i <= a * b; i++) {
		ans[i] = ans[i - 1];
		if ((i % a) % b == (i % b) % a)
			ans[i] = ans[i - 1];
		else
			ans[i] = ans[i - 1] + 1;
	}
	while (q--) {
		ll x, y;
		cin >> x >> y;
		if (x == y) {
			if ((x % a) % b == (y % b) % a) {
				cout << 0 << " ";
			}
			else
				cout << 1 << " ";
		}
		else {
			x--;
			cout << (y / (a * b))*ans[a * b] + ans[y % (a * b)] - ((x / (a * b))*ans[a * b] + ans[x % (a * b)]) << " ";
		}
	}

}
 
