/*
D. Yet Another Yet Another Task
time limit per test1.5 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
Alice and Bob are playing yet another card game. This time the rules are the following. There are n cards lying in a row in front of them. The i-th card has value ai.

First, Alice chooses a non-empty consecutive segment of cards [l;r] (l≤r). After that Bob removes a single card j from that segment (l≤j≤r). The score of the game is the total value of the remaining cards on the segment (al+al+1+⋯+aj−1+aj+1+⋯+ar−1+ar). In particular, if Alice chooses a segment with just one element, then the score after Bob removes the only card is 0.

Alice wants to make the score as big as possible. Bob takes such a card that the score is as small as possible.

What segment should Alice choose so that the score is maximum possible? Output the maximum score.

Input
The first line contains a single integer n (1≤n≤105) — the number of cards.

The second line contains n integers a1,a2,…,an (−30≤ai≤30) — the values on the cards.

Output
Print a single integer — the final score of the game.

Examples
inputCopy
5
5 -2 10 -1 4
outputCopy
6
inputCopy
8
5 2 5 3 -30 -30 6 9
outputCopy
10
inputCopy
3
-10 6 -15
outputCopy
0
Note
In the first example Alice chooses a segment [1;5] — the entire row of cards. Bob removes card 3 with the value 10 from the segment. Thus, the final score is 5+(−2)+(−1)+4=6.

In the second example Alice chooses a segment [1;4], so that Bob removes either card 1 or 3 with the value 5, making the answer 5+2+3=10.

In the third example Alice can choose any of the segments of length 1: [1;1], [2;2] or [3;3]. Bob removes the only card, so the score is 0. If Alice chooses some other segment then the answer will be less than 0.


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
	ll n;
	cin >> n;
	vll a(n, 0);
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
	}
	ll ans = -111111111111, mx = *max_element(all(a)) + 1;
	if (mx <= 0) {
		cout << 0;
		return;
	}
	while (mx--) {
		vll b(n, 0);
		foi(n) {
			b[i] = a[i];
			if (b[i] > mx)
				b[i] = -111111111111;
		}
		ans = max(ans, kadanesAlgo(b) - mx);
		b.clear();
	}
	cout << ans;

}
// Another Approach
/*
#include<bits/stdc++.h>
using namespace std;
 
const int N = 1000 * 100 + 10;
int n, a[N], L[N], R[N];
 
struct Node {
	int sum = 0, pref = 0, suf = 0, best = 0;
	void merge(Node L, Node R) {
		sum = L.sum + R.sum;
		pref = max(L.pref, L.sum + R.pref);
		suf = max(R.suf, R.sum + L.suf);
		best = max({L.best, R.best, L.suf + R.pref});
	}
} seg[N << 2];
 
int getR(int i, int x) {
	return a[i] > x? i: getR(R[i], x);
}
 
int getL(int i, int x) {
	return a[i] > x? i: getL(L[i], x);
}
 
void build(int l = 1, int r = n, int root = 1) {
	if (l == r) {
		seg[root].sum = a[l], seg[root].pref = seg[root].suf = seg[root].best = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, root << 1), build(mid + 1, r, root << 1 | 1);
	seg[root].merge(seg[root << 1], seg[root << 1 | 1]);
}
 
Node get(int l, int r, int lv = 1, int rv = n, int root = 1) {
	Node res;
	if (l <= lv && r >= rv)
		return seg[root];
	int mid = lv + rv >> 1;
	if (l <= mid && r >= mid + 1) {
		res.merge(get(l, r, lv, mid, root << 1), get(l, r, mid + 1, rv, root << 1 | 1));
		return res;
	}
	if (l <= mid)
		return get(l, r, lv, mid, root << 1);
	return get(l, r, mid + 1, rv, root << 1 | 1);
}
 
int main() { 
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[0] = a[n + 1] = 1 << 30;
	build();
	for (int i = 1; i <= n; i++)
		L[i] = getL(i - 1, a[i]);
	for (int i = n; i >= 1; i--)
		R[i] = getR(i + 1, a[i]);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		Node t = get(L[i] + 1, R[i] - 1);
		ans = max(ans, t.best - a[i]);
	}
	cout << ans << '\n';
	return 0;
}*/
