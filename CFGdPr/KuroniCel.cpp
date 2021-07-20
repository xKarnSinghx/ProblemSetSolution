/*
D. Kuroni and the Celebration
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
This is an interactive problem.

After getting AC after 13 Time Limit Exceeded verdicts on a geometry problem, Kuroni went to an Italian restaurant to celebrate this holy achievement. Unfortunately, the excess sauce disoriented him, and he's now lost!

The United States of America can be modeled as a tree (why though) with n vertices. The tree is rooted at vertex r, wherein lies Kuroni's hotel.

Kuroni has a phone app designed to help him in such emergency cases. To use the app, he has to input two vertices u and v, and it'll return a vertex w, which is the lowest common ancestor of those two vertices.

However, since the phone's battery has been almost drained out from live-streaming Kuroni's celebration party, he could only use the app at most ⌊n2⌋ times. After that, the phone would die and there will be nothing left to help our dear friend! :(

As the night is cold and dark, Kuroni needs to get back, so that he can reunite with his comfy bed and pillow(s). Can you help him figure out his hotel's location?

Interaction
The interaction starts with reading a single integer n (2≤n≤1000), the number of vertices of the tree.

Then you will read n−1 lines, the i-th of them has two integers xi and yi (1≤xi,yi≤n, xi≠yi), denoting there is an edge connecting vertices xi and yi. It is guaranteed that the edges will form a tree.

Then you can make queries of type "? u v" (1≤u,v≤n) to find the lowest common ancestor of vertex u and v.

After the query, read the result w as an integer.

In case your query is invalid or you asked more than ⌊n2⌋ queries, the program will print −1 and will finish interaction. You will receive a Wrong answer verdict. Make sure to exit immediately to avoid getting other verdicts.

When you find out the vertex r, print "! r" and quit after that. This query does not count towards the ⌊n2⌋ limit.

Note that the tree is fixed beforehand and will not change during the queries, i.e. the interactor is not adaptive.

After printing any query do not forget to print end of line and flush the output. Otherwise, you might get Idleness limit exceeded. To do this, use:

fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
see the documentation for other languages.
Hacks

To hack, use the following format:

The first line should contain two integers n and r (2≤n≤1000, 1≤r≤n), denoting the number of vertices and the vertex with Kuroni's hotel.

The i-th of the next n−1 lines should contain two integers xi and yi (1≤xi,yi≤n) — denoting there is an edge connecting vertex xi and yi.

The edges presented should form a tree.

Example
inputCopy
6
1 4
4 2
5 3
6 3
2 3

3

4

4

outputCopy






? 5 6

? 3 1

? 1 2

! 4
Note
Note that the example interaction contains extra empty lines so that it's easier to read. The real interaction doesn't contain any empty lines and you shouldn't print any extra empty lines as well.

The image below demonstrates the tree in the sample test:




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
typedef queue<ll>           qll;
typedef vector<plll>      vplll;
typedef  vector<set<ll>>   vsll;
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
		cout << endl;
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
	cout << "? " << x << " " << y << endl;
	ll z;
	cin >> z;
	return z;
}
qll l;
vsll g;
void solve() {
	ll n;
	cin >> n;
	g.resize(n + 1);
	foi(n - 1) {
		ll x, y;
		cin >> x >> y;
		g[x].insert(y);
		g[y].insert(x);
	}
	foi(n+1) {
	    if(i==0)
	    continue;
		if (g[i].size() == 1) {
			l.push(i);
		}
	}
	while (true) {
		if (l.size() == 1) {
			cout << "! " << l.front() << endl;
			return;
		}
		ll a = l.front();
		l.pop();
		ll b = l.front();
		l.pop();
		ll ans=ask(a,b);
		if (ans == a or ans == b) {
			cout << "! " << ans << endl;
			return;
		}
		ll x = *g[a].begin(), y = *g[b].begin();
		g[x].erase(a), g[y].erase(b);
		if (g[x].size() <= 1) {
			l.push(x);
		}
		if (x != y and g[y].size() <= 1) {
			l.push(y);
		}
	}

}
