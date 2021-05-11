/*
A. Fence
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Yura is tasked to build a closed fence in shape of an arbitrary non-degenerate simple quadrilateral. He's already got three straight fence segments with known lengths a, b, and c. Now he needs to find out some possible integer length d of the fourth straight fence segment so that he can build the fence using these four segments. In other words, the fence should have a quadrilateral shape with side lengths equal to a, b, c, and d. Help Yura, find any possible length of the fourth side.

A non-degenerate simple quadrilateral is such a quadrilateral that no three of its corners lie on the same line, and it does not cross itself.

Input
The first line contains a single integer t — the number of test cases (1≤t≤1000). The next t lines describe the test cases.

Each line contains three integers a, b, and c — the lengths of the three fence segments (1≤a,b,c≤109).

Output
For each test case print a single integer d — the length of the fourth fence segment that is suitable for building the fence. If there are multiple answers, print any. We can show that an answer always exists.

Example
inputCopy
2
1 2 3
12 34 56
outputCopy
4
42
Note
We can build a quadrilateral with sides 1, 2, 3, 4.

We can build a quadrilateral with sides 12, 34, 56, 42.


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
#define graph          vector<vector<int>>
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
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
const ll MOD = 1000000007;
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
void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	cout << a + b + c - 1;
}
