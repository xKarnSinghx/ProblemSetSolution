/*
C. Save the Nature
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are an environmental activist at heart but the reality is harsh and you are just a cashier in a cinema. But you can still do something!

You have n tickets to sell. The price of the i-th ticket is pi. As a teller, you have a possibility to select the order in which the tickets will be sold (i.e. a permutation of the tickets). You know that the cinema participates in two ecological restoration programs applying them to the order you chose:

The x% of the price of each the a-th sold ticket (a-th, 2a-th, 3a-th and so on) in the order you chose is aimed for research and spreading of renewable energy sources.
The y% of the price of each the b-th sold ticket (b-th, 2b-th, 3b-th and so on) in the order you chose is aimed for pollution abatement.
If the ticket is in both programs then the (x+y)% are used for environmental activities. Also, it's known that all prices are multiples of 100, so there is no need in any rounding.

For example, if you'd like to sell tickets with prices [400,100,300,200] and the cinema pays 10% of each 2-nd sold ticket and 20% of each 3-rd sold ticket, then arranging them in order [100,200,300,400] will lead to contribution equal to 100⋅0+200⋅0.1+300⋅0.2+400⋅0.1=120. But arranging them in order [100,300,400,200] will lead to 100⋅0+300⋅0.1+400⋅0.2+200⋅0.1=130.

Nature can't wait, so you decided to change the order of tickets in such a way, so that the total contribution to programs will reach at least k in minimum number of sold tickets. Or say that it's impossible to do so. In other words, find the minimum number of tickets which are needed to be sold in order to earn at least k.

Input
The first line contains a single integer q (1≤q≤100) — the number of independent queries. Each query consists of 5 lines.

The first line of each query contains a single integer n (1≤n≤2⋅105) — the number of tickets.

The second line contains n integers p1,p2,…,pn (100≤pi≤109, pimod100=0) — the corresponding prices of tickets.

The third line contains two integers x and a (1≤x≤100, x+y≤100, 1≤a≤n) — the parameters of the first program.

The fourth line contains two integers y and b (1≤y≤100, x+y≤100, 1≤b≤n) — the parameters of the second program.

The fifth line contains single integer k (1≤k≤1014) — the required total contribution.

It's guaranteed that the total number of tickets per test doesn't exceed 2⋅105.

Output
Print q integers — one per query.

For each query, print the minimum number of tickets you need to sell to make the total ecological contribution of at least k if you can sell tickets in any order.

If the total contribution can not be achieved selling all the tickets, print −1.

Example
inputCopy
4
1
100
50 1
49 1
100
8
100 200 100 200 100 200 100 100
10 2
15 3
107
3
1000000000 1000000000 1000000000
50 1
50 1
3000000000
5
200 100 100 100 100
69 5
31 2
90
outputCopy
-1
6
3
4
Note
In the first query the total contribution is equal to 50+49=99<100, so it's impossible to gather enough money.

In the second query you can rearrange tickets in a following way: [100,100,200,200,100,200,100,100] and the total contribution from the first 6 tickets is equal to 100⋅0+100⋅0.1+200⋅0.15+200⋅0.1+100⋅0+200⋅0.25=10+30+20+50=110.

In the third query the full price of each ticket goes to the environmental activities.

In the fourth query you can rearrange tickets as [100,200,100,100,100] and the total contribution from the first 4 tickets is 100⋅0+200⋅0.31+100⋅0+100⋅0.31=62+31=93.*/
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
const ll N = 200010;
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
string ask(ll x, ll y) {
	cout << x + 1 << " " << y + 1;
	string s;
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
ll x, y, a, b, k;
bool ans(ll p, vll &c) {
	ll t = p / lcm(a, b), i = 0, tot = 0;
	while (i < p and t>0) {
		tot += c[i] * (x + y);
		t--, i++;
	}
	ll t1 = p / a - p / lcm(a, b);
	while (i < p and t1 >0 ) {
		tot += c[i] * x;
		t1--, i++;
	}
	ll t2 = p / b - p / lcm(a, b);
	while (i < p and t2>0) {
		tot += c[i] * y;
		t2--, i++;
	}
	return tot < k;
}
void solve() {
	ll n;
	cin >> n;
	vll p(n, 0);
	foi(n) {
		ll x;
		cin >> x;
		p[i] = x / 100;
	}
	cin >> x >> a >> y >> b >> k;
	if (x < y) {
		swap(x, y), swap(a, b);
	}
	ll l = 0, r = n;
	sort(rall(p));
	while (l <= r) {
		ll m = (l + r) >> 1;
		if (ans(m, p))
			l = m + 1;
		else
			r = m - 1;
	}
	if (l > n or r < 0) {
		cout << -1;
		return;
	}
	cout << l;
}



