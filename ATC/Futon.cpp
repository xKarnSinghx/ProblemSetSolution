/*
B - Futon  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
200
 points

Problem Statement
We have a grid with 
H
 horizontal rows and 
W
 vertical columns of squares, where each square is tidy or untidy.

You will now place a mattress on this grid.

The mattress can be placed on two horizontally or vertically adjacent tidy squares in the grid.

Given are integers 
H
, 
W
, and 
H
 strings 
S
i
 of length 
W
 each. If the 
j
-th character of 
S
i
 is ., the square at the 
i
-th row from the top and the 
j
-th column from the left is tidy; if the 
j
-th character of 
S
i
 is #, the square at the 
i
-th row from the top and the 
j
-th column from the left is untidy.

Find the number of ways to choose the position for the mattress.

Constraints
2
≤
H
≤
100
2
≤
W
≤
100
S
i
 is a string of length 
W
 consisting of . and #.
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
	ll h, w;
	cin >> h >> w;
	char a[h][w];
	foi(h) {
		foj(w) {
			cin >> a[i][j];
		}
	}
	ll ans = 0;
	foi(h) {
		foj(w) {
			if (a[i][j] == '.' and a[i][j + 1] == '.' and j < w - 1)
				ans++;
			if (a[i][j] == '.' and a[i + 1][j] == '.' and i < h - 1)
				ans++;
		}
	}
	cout << ans;
}

