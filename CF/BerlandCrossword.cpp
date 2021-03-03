/*
B. Berland Crossword
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Berland crossword is a puzzle that is solved on a square grid with n rows and n columns. Initially all the cells are white.

To solve the puzzle one has to color some cells on the border of the grid black in such a way that:

exactly U cells in the top row are black;
exactly R cells in the rightmost column are black;
exactly D cells in the bottom row are black;
exactly L cells in the leftmost column are black.
Note that you can color zero cells black and leave every cell white.

Your task is to check if there exists a solution to the given puzzle.

Input
The first line contains a single integer t (1≤t≤1000) — the number of testcases.

Then the descriptions of t testcases follow.

The only line of each testcase contains 5 integers n,U,R,D,L (2≤n≤100; 0≤U,R,D,L≤n).

Output
For each testcase print "YES" if the solution exists and "NO" otherwise.

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES are all recognized as positive answer).

Example
inputCopy
4
5 2 5 3 1
3 0 0 0 0
4 4 1 4 0
2 1 1 1 1
outputCopy
YES
YES
NO
YES
Note
Here are possible solutions to testcases 1, 2 and 4:



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

	int t ; cin >> t;
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


void solve()
{

	string s;
	cin >> s;;
	ll t = 0, f = 0, f1 = 0;
	foi(s.size()) {
		if (s[i] == s[0])
			t++;
		else if (s[i] == s[s.size() - 1])
			t--;
		else
			t--;
		if (t < 0)
			f = 1;
	}
	ll t1 = 0;
	foi(s.size()) {
		if (s[i] == s[0])
			t1++;
		else if (s[i] == s[s.size() - 1])
			t1--;
		else
			t1++;
		if (t1 < 0)
			f1 = 1;
	}
	if (s[0] == s[s.size() - 1])
		cout << "NO";
	else if ((t == 0 && f == 0) || ( f1 == 0 && t1 == 0) )
		cout << "YES";
	else
		cout << "NO";




}


 
