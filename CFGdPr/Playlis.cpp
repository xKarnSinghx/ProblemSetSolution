/*
C. Playlist
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have a playlist consisting of n songs. The i-th song is characterized by two numbers ti and bi — its length and beauty respectively. The pleasure of listening to set of songs is equal to the total length of the songs in the set multiplied by the minimum beauty among them. For example, the pleasure of listening to a set of 3 songs having lengths [5,7,4] and beauty values [11,14,6] is equal to (5+7+4)⋅6=96.

You need to choose at most k songs from your playlist, so the pleasure of listening to the set of these songs them is maximum possible.

Input
The first line contains two integers n and k (1≤k≤n≤3⋅105) – the number of songs in the playlist and the maximum number of songs you can choose, respectively.

Each of the next n lines contains two integers ti and bi (1≤ti,bi≤106) — the length and beauty of i-th song.

Output
Print one integer — the maximum pleasure you can get.

Examples
inputCopy
4 3
4 7
15 1
3 6
6 8
outputCopy
78
inputCopy
5 3
12 31
112 4
100 100
13 55
55 50
outputCopy
10000
Note
In the first test case we can choose songs 1,3,4, so the total pleasure is (4+3+6)⋅6=78.

In the second test case we can choose song 3. The total pleasure will be equal to 100⋅100=10000.


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
const ll mod = 998244353;
ld PI = 3.1415926535897;
const ll N = 1000010;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
//	ll t; cin >> t;
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
void solve() {
	ll n, k;
	cin >> n >> k;
	vpll a(n);
	foi(n) {
		cin >> a[i].ff >> a[i].ss;
	}
	ll ans = 0, cur = ans;
	sort(rall(a), [&](pll a, pll b) {
		return a.ss < b.ss;
	});
	multiset<ll>s;
	foi(n) {
		s.insert(a[i].ff);
		cur += a[i].ff;
		while (s.size() > k) {
			cur -= *s.begin();
			s.erase(s.begin());
		}
		ans = max(ans, a[i].ss * cur);
	}
	cout << ans;
}
