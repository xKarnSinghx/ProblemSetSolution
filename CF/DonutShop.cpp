/*
A. Donut Shops
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are two rival donut shops.

The first shop sells donuts at retail: each donut costs a dollars.

The second shop sells donuts only in bulk: box of b donuts costs c dollars. So if you want to buy x donuts from this shop, then you have to buy the smallest number of boxes such that the total number of donuts in them is greater or equal to x.

You want to determine two positive integer values:

how many donuts can you buy so that they are strictly cheaper in the first shop than in the second shop?
how many donuts can you buy so that they are strictly cheaper in the second shop than in the first shop?
If any of these values doesn't exist then that value should be equal to −1. If there are multiple possible answers, then print any of them.

The printed values should be less or equal to 109. It can be shown that under the given constraints such values always exist if any values exist at all.

Input
The first line contains a single integer t (1≤t≤1000) — the number of testcases.

Each of the next t lines contains three integers a, b and c (1≤a≤109, 2≤b≤109, 1≤c≤109).

Output
For each testcase print two positive integers. For both shops print such x that buying x donuts in this shop is strictly cheaper than buying x donuts in the other shop. x should be greater than 0 and less or equal to 109.

If there is no such x, then print −1. If there are multiple answers, then print any of them.

Example
inputCopy
4
5 10 4
4 5 20
2 2 3
1000000000 1000000000 1000000000
outputCopy
-1 20
8 -1
1 2
-1 1000000000
Note
In the first testcase buying any number of donuts will be cheaper in the second shop. For example, for 3 or 5 donuts you'll have to buy a box of 10 donuts for 4 dollars. 3 or 5 donuts in the first shop would cost you 15 or 25 dollars, respectively, however. For 20 donuts you'll have to buy two boxes for 8 dollars total. Note that 3 and 5 are also valid answers for the second shop, along with many other answers.

In the second testcase buying any number of donuts will be either cheaper in the first shop or the same price. 8 donuts cost 32 dollars in the first shop and 40 dollars in the second shop (because you have to buy two boxes). 10 donuts will cost 40 dollars in both shops, so 10 is not a valid answer for any of the shops.

In the third testcase 1 donut costs 2 and 3 dollars, respectively. 2 donuts cost 4 and 3 dollars. Thus, 1 is a valid answer for the first shop and 2 is a valid answer for the second shop.

In the fourth testcase 109 donuts cost 1018 dollars in the first shop and 109 dollars in the second shop.


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
typedef  map<ll, vll>             mvll;
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
ll powmod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) {
		res = res * x % MOD;
	}
	return res;
}
void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	if (c < a) {
		cout << -1 << " " << b;
	}
	else if (a < c) {
		cout << 1 << " ";
		if (a * b > c) {
			cout << b;
		}
		else
			cout << -1;
	}
	else {
		if (b == 1)
			cout << -1 << " " << -1;
		else
			cout << -1 << " " << b;
	}

}

