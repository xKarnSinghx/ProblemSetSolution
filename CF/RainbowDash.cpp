/*
A. Rainbow Dash, Fluttershy and Chess Coloring
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
One evening Rainbow Dash and Fluttershy have come up with a game. Since the ponies are friends, they have decided not to compete in the game but to pursue a common goal.

The game starts on a square flat grid, which initially has the outline borders built up. Rainbow Dash and Fluttershy have flat square blocks with size 1×1, Rainbow Dash has an infinite amount of light blue blocks, Fluttershy has an infinite amount of yellow blocks.

The blocks are placed according to the following rule: each newly placed block must touch the built on the previous turns figure by a side (note that the outline borders of the grid are built initially). At each turn, one pony can place any number of blocks of her color according to the game rules.

Rainbow and Fluttershy have found out that they can build patterns on the grid of the game that way. They have decided to start with something simple, so they made up their mind to place the blocks to form a chess coloring. Rainbow Dash is well-known for her speed, so she is interested in the minimum number of turns she and Fluttershy need to do to get a chess coloring, covering the whole grid with blocks. Please help her find that number!

Since the ponies can play many times on different boards, Rainbow Dash asks you to find the minimum numbers of turns for several grids of the games.

The chess coloring in two colors is the one in which each square is neighbor by side only with squares of different colors.

Input
The first line contains a single integer T (1≤T≤100): the number of grids of the games.

Each of the next T lines contains a single integer n (1≤n≤109): the size of the side of the grid of the game.

Output
For each grid of the game print the minimum number of turns required to build a chess coloring pattern out of blocks on it.

Example
inputCopy
2
3
4
outputCopy
2
3
Note
For 3×3 grid ponies can make two following moves:*/
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
	cout << n / 2 + 1;
}
