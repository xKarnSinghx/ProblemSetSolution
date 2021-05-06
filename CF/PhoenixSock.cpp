/*
D. Phoenix and Socks
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
To satisfy his love of matching socks, Phoenix has brought his n socks (n is even) to the sock store. Each of his socks has a color ci and is either a left sock or right sock.

Phoenix can pay one dollar to the sock store to either:

recolor a sock to any color c′ (1≤c′≤n)
turn a left sock into a right sock
turn a right sock into a left sock
The sock store may perform each of these changes any number of times. Note that the color of a left sock doesn't change when it turns into a right sock, and vice versa.

A matching pair of socks is a left and right sock with the same color. What is the minimum cost for Phoenix to make n/2 matching pairs? Each sock must be included in exactly one matching pair.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains three integers n, l, and r (2≤n≤2⋅105; n is even; 0≤l,r≤n; l+r=n) — the total number of socks, and the number of left and right socks, respectively.

The next line contains n integers ci (1≤ci≤n) — the colors of the socks. The first l socks are left socks, while the next r socks are right socks.

It is guaranteed that the sum of n across all the test cases will not exceed 2⋅105.

Output
For each test case, print one integer — the minimum cost for Phoenix to make n/2 matching pairs. Each sock must be included in exactly one matching pair.

Example
inputCopy
4
6 3 3
1 2 3 2 2 2
6 2 4
1 1 2 2 2 2
6 5 1
6 5 4 3 2 1
4 0 4
4 4 4 3
outputCopy
2
3
5
3
Note
In the first test case, Phoenix can pay 2 dollars to:

recolor sock 1 to color 2
recolor sock 3 to color 2
There are now 3 matching pairs. For example, pairs (1,4), (2,5), and (3,6) are matching.
In the second test case, Phoenix can pay 3 dollars to:

turn sock 6 from a right sock to a left sock
recolor sock 3 to color 1
recolor sock 4 to color 1
There are now 3 matching pairs. For example, pairs (1,3), (2,4), and (5,6) are matching.

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
ll TT = 1;
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
ll n, l, r;
void solve()
{
	cin >> n >> l >> r;
	ll b[n + 1] = {}, c[n + 1] = {};
	if (r > l) {
		foi(l) {
			ll x;
			cin >> x;
			b[x]++;
		}
		foi(r) {
			ll x;
			cin >> x;
			c[x]++;
		}
	}
	else {
		foi(l) {
			ll x;
			cin >> x;
			c[x]++;
		}
		foi(r) {
			ll x;
			cin >> x;
			b[x]++;
		}
		swap(l, r);
	}
	foi(n + 1) {
		ll mn = min(b[i], c[i]);
		b[i] -= mn, c[i] -= mn, r -= mn, l -= mn;
	}
	ll cost = 0;
	foi(n + 1) {
		ll mn = min((r - l) / 2, (c[i]) / 2);
		cost += mn, r -= mn * 2;
		if (i == n)
			cost += r;
	}
	cout << cost ;


}

 
