/*
D. Playlist
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Arkady has a playlist that initially consists of n songs, numerated from 1 to n in the order they appear in the playlist. Arkady starts listening to the songs in the playlist one by one, starting from song 1. The playlist is cycled, i. e. after listening to the last song, Arkady will continue listening from the beginning.

Each song has a genre ai, which is a positive integer. Let Arkady finish listening to a song with genre y, and the genre of the next-to-last listened song be x. If gcd(x,y)=1, he deletes the last listened song (with genre y) from the playlist. After that he continues listening normally, skipping the deleted songs, and forgetting about songs he listened to before. In other words, after he deletes a song, he can't delete the next song immediately.

Here gcd(x,y) denotes the greatest common divisor (GCD) of integers x and y.

For example, if the initial songs' genres were [5,9,2,10,15], then the playlist is converted as follows: [5, 9, 2, 10, 15] → [5, 9, 2, 10, 15] → [5, 2, 10, 15] (because gcd(5,9)=1) → [5, 2, 10, 15] → [5, 2, 10, 15] → [5, 2, 10, 15] → [5, 2, 10, 15] → [5, 2, 10, 15] → [5, 10, 15] (because gcd(5,2)=1) → [5, 10, 15] → [5, 10, 15] → ... The bold numbers represent the two last played songs. Note that after a song is deleted, Arkady forgets that he listened to that and the previous songs.

Given the initial playlist, please determine which songs are eventually deleted and the order these songs are deleted.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤10000). Description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤105) — the number of songs.

The second line contains n integers a1,a2,…,an (1≤ai≤109) — the genres of the songs.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case, print a single line. First, print a single integer k — the number of deleted songs. After that print k distinct integers: deleted songs in the order of their deletion.

Example
inputCopy
5
5
5 9 2 10 15
6
1 2 4 2 4 2
2
1 2
1
1
1
2
outputCopy
2 2 3 
2 2 1 
2 2 1 
1 1 
0 
Note
Explanation of the first test case is given in the statement.

In the second test case, the playlist is converted as follows: [1, 2, 4, 2, 4, 2] → [1, 2, 4, 2, 4, 2] → [1, 4, 2, 4, 2] (because gcd(1,2)=1) → [1, 4, 2, 4, 2] → [1, 4, 2, 4, 2] → [1, 4, 2, 4, 2] → [1, 4, 2, 4, 2] → [1, 4, 2, 4, 2] → [4, 2, 4, 2] (because gcd(2,1)=1) → [4, 2, 4, 2] → ...

In the third test case, the playlist is converted as follows: [1, 2] → [1, 2] → [1] (because gcd(1,2)=1) → [1] → [1] (Arkady listened to the same song twice in a row) → [] (because gcd(1,1)=1).

The fourth test case is same as the third after deletion of the second song.

In the fifth test case, the same song is listened to over and over again, but since gcd(2,2)≠1, it is not deleted.*/
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
	ll n;
	cin >> n;
	vll a(n, 0);
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
	}
	vll l(n, 0), r(n, 0);
	foi(n - 1) {
		r[i] = i + 1;
		l[i + 1] = i;
	}
	r[n - 1] = 0;
	l[0] = n - 1;
	set<ll> s;
	vll ans;
	foi(n - 1) {
		if (gcd(a[i], a[i + 1]) == 1)
			s.insert(i);
	}
	if (gcd(a[n - 1], a[0]) == 1)
		s.insert(n - 1);
	ll pos = 0;
	while (s.size()) {
		auto it = s.lb(pos);
		if (it == s.end())
			it = s.begin();
		ll cur = *it, tr = r[*it];
		if (s.count(tr))
			s.erase(tr);
		ans.push_back(tr);
		if (ans.size() == n) {
			break;
		}
		s.erase(it);
		r[cur] = r[tr];
		l[r[cur]] = cur;
		if (gcd(a[cur], a[r[cur]]) == 1)
			s.insert(cur);
		pos = r[cur];
	}

	cout << ans.size() << ' ';
	foi(ans.size()) {
		cout << ans[i] + 1 << ' ';
	}
}
 
