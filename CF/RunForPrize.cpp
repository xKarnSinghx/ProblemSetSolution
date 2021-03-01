/*
B. Run For Your Prize
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You and your friend are participating in a TV show "Run For Your Prize".

At the start of the show n prizes are located on a straight line. i-th prize is located at position ai. Positions of all prizes are distinct. You start at position 1, your friend — at position 106 (and there is no prize in any of these two positions). You have to work as a team and collect all prizes in minimum possible time, in any order.

You know that it takes exactly 1 second to move from position x to position x + 1 or x - 1, both for you and your friend. You also have trained enough to instantly pick up any prize, if its position is equal to your current position (and the same is true for your friend). Carrying prizes does not affect your speed (or your friend's speed) at all.

Now you may discuss your strategy with your friend and decide who will pick up each prize. Remember that every prize must be picked up, either by you or by your friend.

What is the minimum number of seconds it will take to pick up all the prizes?

Input
The first line contains one integer n (1 ≤ n ≤ 105) — the number of prizes.

The second line contains n integers a1, a2, ..., an (2 ≤ ai ≤ 106 - 1) — the positions of the prizes. No two prizes are located at the same position. Positions are given in ascending order.

Output
Print one integer — the minimum number of seconds it will take to collect all prizes.

Examples
inputCopy
3
2 3 9
outputCopy
8
inputCopy
2
2 999995
outputCopy
5
Note
In the first example you take all the prizes: take the first at 1, the second at 2 and the third at 8.

In the second example you take the first prize in 1 second and your friend takes the other in 5 seconds, you do this simultaneously, so the total time is 5.

*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
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
typedef pair<ll, pll>      plll;
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
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
#define MOD  1000000007;
void solve();


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif


		solve();
	
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceil(ll x, ll y) {
	return x / y + ((x % y) != 0);
}


void solve()
{
	ll n;
	cin >> n;
	ll a[n], mx = -11111;
	foi(n)
	{
		cin >> a[i];
		if (a[i] <= 500000)
			mx = max(mx, a[i] - 1);
		else
			mx = max(mx, 1000000 - a[i]);
	}
	cout << mx;
}



