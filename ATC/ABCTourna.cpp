/*
C - ABC Tournament  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
300
 points

Problem Statement
2
N
 players, labeled 
1
 through 
2
N
, will compete against each other in a single-elimination programming tournament.
The rating of Player 
i
 is 
A
i
. Any two players have different ratings, and a match between two players always results in the victory of the player with the higher rating.

The tournament looks like a perfect binary tree.
Formally, the tournament will proceed as follows:

For each integer 
i
=
1
,
2
,
3
,
…
,
N
 in this order, the following happens.
For each integer 
j
(
1
≤
j
≤
2
N
−
i
)
, among the players who have never lost, the player with the 
(
2
j
−
1
)
-th smallest label and the player with the 
2
j
-th smallest label play a match against each other.
Find the label of the player who will take second place, that is, lose in the final match.

Constraints
1
≤
N
≤
16
1
≤
A
i
≤
10
9
A
i
 are pairwise different.
All values in input are integers.
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
	ll n, s = 0;
	cin >> n;
	ll x = 1;
	foi(n)
	x *= 2;
	ll a[x], idx = 0, idx1 = 0, mx = 0, mx1 = 0;
	foi(x) {
		cin >> a[i];
	}
	foi(x / 2) {
		if (mx < a[i]) {
			mx = a[i], idx = i + 1;
		}
	}
	for (ll i = x / 2; i < x; i++) {
		if (mx1 < a[i]) {
			mx1 = a[i], idx1 = i + 1;
		}
	}
	if (mx > mx1)
		cout << idx1;
	else
		cout << idx;

}

