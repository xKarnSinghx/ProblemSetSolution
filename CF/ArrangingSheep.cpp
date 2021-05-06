/*
E. Arranging The Sheep
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are playing the game "Arranging The Sheep". The goal of this game is to make the sheep line up. The level in the game is described by a string of length n, consisting of the characters '.' (empty space) and '*' (sheep). In one move, you can move any sheep one square to the left or one square to the right, if the corresponding square exists and is empty. The game ends as soon as the sheep are lined up, that is, there should be no empty cells between any sheep.

For example, if n=6 and the level is described by the string "**.*..", then the following game scenario is possible:

the sheep at the 4 position moves to the right, the state of the level: "**..*.";
the sheep at the 2 position moves to the right, the state of the level: "*.*.*.";
the sheep at the 1 position moves to the right, the state of the level: ".**.*.";
the sheep at the 3 position moves to the right, the state of the level: ".*.**.";
the sheep at the 2 position moves to the right, the state of the level: "..***.";
the sheep are lined up and the game ends.
For a given level, determine the minimum number of moves you need to make to complete the level.

Input
The first line contains one integer t (1≤t≤104). Then t test cases follow.

The first line of each test case contains one integer n (1≤n≤106).

The second line of each test case contains a string of length n, consisting of the characters '.' (empty space) and '*' (sheep) — the description of the level.

It is guaranteed that the sum of n over all test cases does not exceed 106.

Output
For each test case output the minimum number of moves you need to make to complete the level.

Example
inputCopy
5
6
**.*..
5
*****
3
.*.
3
...
10
*.*...*.**
outputCopy
1
0
0
0
9

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
void solve() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll ans = 0, st = 0, t = 0;
	foi(s.size()) {
		if (s[i] == '*')
			t++;
	}
	foi(s.size()) {
		if (s[i] == '*')
			st++;
		else
			ans += min(st, t - st);
	}
	cout << ans;


}
