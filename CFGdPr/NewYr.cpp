/*
D. New Year's Problem
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vlad has n friends, for each of whom he wants to buy one gift for the New Year.

There are m shops in the city, in each of which he can buy a gift for any of his friends. If the j-th friend (1≤j≤n) receives a gift bought in the shop with the number i (1≤i≤m), then the friend receives pij units of joy. The rectangular table pij is given in the input.

Vlad has time to visit at most n−1 shops (where n is the number of friends). He chooses which shops he will visit and for which friends he will buy gifts in each of them.

Let the j-th friend receive aj units of joy from Vlad's gift. Let's find the value α=min{a1,a2,…,an}. Vlad's goal is to buy gifts so that the value of α is as large as possible. In other words, Vlad wants to maximize the minimum of the joys of his friends.

For example, let m=2, n=2. Let the joy from the gifts that we can buy in the first shop: p11=1, p12=2, in the second shop: p21=3, p22=4.

Then it is enough for Vlad to go only to the second shop and buy a gift for the first friend, bringing joy 3, and for the second — bringing joy 4. In this case, the value α will be equal to min{3,4}=3
Help Vlad choose gifts for his friends so that the value of α is as high as possible. Please note that each friend must receive one gift. Vlad can visit at most n−1 shops (where n is the number of friends). In the shop, he can buy any number of gifts.

Input
The first line of the input contains an integer t (1≤t≤104) — the number of test cases in the input.

An empty line is written before each test case. Then there is a line containing integers m and n (2≤n, 2≤n⋅m≤105) separated by a space — the number of shops and the number of friends, where n⋅m is the product of n and m.

Then m lines follow, each containing n numbers. The number in the i-th row of the j-th column pij (1≤pij≤109) is the joy of the product intended for friend number j in shop number i.

It is guaranteed that the sum of the values n⋅m over all test cases in the test does not exceed 105.

Output
Print t lines, each line must contain the answer to the corresponding test case — the maximum possible value of α, where α is the minimum of the joys from a gift for all of Vlad's friends.

Example
inputCopy
5

2 2
1 2
3 4

4 3
1 3 1
3 1 1
1 2 2
1 1 3

2 3
5 3 4
2 5 1

4 2
7 9
8 1
9 6
10 8

2 4
6 5 2 1
7 9 7 2
outputCopy
3
2
4
8
2

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
typedef vector<ld>          vld;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair< ll, pll>      plll;
typedef queue<ll>           qll;
typedef vector<plll>      vplll;
typedef  vector<set<ll>>   vsll;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<vll, ll>             mvlll;
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
ld PI = 3.1415926535897;
const ll N = 1000100;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	ll t; cin >> t;
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
ll ask(ll x, ll y) {
	cout << "?" << " ";
	cout << x << " " << y << endl;
	ll s;
	cin >> s;
	return s;
}
ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
bool is_sorted(vector<ll>a) {
	ll x = 0;
	for (ll i = 0; i < a.size() - 1; i++) {
		if (a[i] < a[i + 1])
			x++;
	}
	return x == a.size() - 1;
}
bool check(string a, string b) {
	ll n = a.size(), m = b.size();
	if (a < b) {
		return true;
	}
	if (a > b) {
		return false;
	}
	foi(a.size()) {
		if (a[i] > b[i]) {
			return false;
		}
		else if (a[i] < b[i]) {
			return true;
		}
	}
	return false;
}
bool isSubSequence(string a, string b, ll m, ll n) {
	ll j = 0;
	for (ll i = 0; i < n and j < m; i++)
		if (a[j] == b[i])
			j++;
	return (j == m);
}
ll power(ll n, ll x) {
	ll ans = 1;
	foi(n) {
		ans *= x;
	}
	return ans;
}
void solve() {
	ll m, n;
	cin >> m >> n;
	graph a(m, vll(n));
	vll b(n + 1, 0);
	foi(m) {
		foj(n) {
			cin >> a[i][j];
			b[j] = max(b[j], a[i][j]);
		}
	}
	ll ans = MOD;
	foi(n) {
		ans = min(ans, b[i]);
	}
	if (n > m) {
		cout << ans;
		return;
	}
	ll fin = -MOD;
	foi(m) {
		sort(all(a[i]));
		fin = max(fin, min(ans, a[i][n - 2]));
	}
	cout << fin;
}
