/*
D2. Sage's Birthday (hard version)
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
This is the hard version of the problem. The difference between the versions is that in the easy version all prices ai are different. You can make hacks if and only if you solved both versions of the problem.

Today is Sage's birthday, and she will go shopping to buy ice spheres. All n ice spheres are placed in a row and they are numbered from 1 to n from left to right. Each ice sphere has a positive integer price. In this version, some prices can be equal.

An ice sphere is cheap if it costs strictly less than two neighboring ice spheres: the nearest to the left and the nearest to the right. The leftmost and the rightmost ice spheres are not cheap. Sage will choose all cheap ice spheres and then buy only them.

You can visit the shop before Sage and reorder the ice spheres as you wish. Find out the maximum number of ice spheres that Sage can buy, and show how the ice spheres should be reordered.

Input
The first line contains a single integer n (1≤n≤105) — the number of ice spheres in the shop.

The second line contains n integers a1,a2,…,an (1≤ai≤109) — the prices of ice spheres.

Output
In the first line print the maximum number of ice spheres that Sage can buy.

In the second line print the prices of ice spheres in the optimal order. If there are several correct answers, you can print any of them.

Example
inputCopy
7
1 3 2 2 4 5 4
outputCopy
3
3 1 4 2 4 2 5 
Note
In the sample it's not possible to place the ice spheres in any order so that Sage would buy 4 of them. If the spheres are placed in the order (3,1,4,2,4,2,5), then Sage will buy one sphere for 1 and two spheres for 2 each.


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
void solve() {
	ll n;
	cin >> n;
	ll a[n];
	foi(n)
	cin >> a[i];
	sort(a, a + n);
	ll c = 0;
	foi(n - 1) {
		if (a[i] == a[i + 1])
			c++;
	}
	if (c == n - 1) {
		cout << 0 << endl;
		foi(n)
		cout << a[i] << " ";
		return;
	}
	ll l = 0, r = n / 2;
	vll x;
	while (l < n / 2 and r < n) {
		x.pb(a[r]);
		x.pb(a[l]);
		r++, l++;
	}
	if (n % 2)
		x.pb(a[n - 1]);
	ll ans = 0;
	for (ll i = 1; i < n - 1; i++) {
		if (x[i] < x[i - 1] and x[i] < x[i + 1])
			ans++;
	}
	cout << ans << endl;
	foi(n)
	cout << x[i] << " ";
}
