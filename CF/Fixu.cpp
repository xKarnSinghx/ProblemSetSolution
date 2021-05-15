/*
B. Fix You
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Consider a conveyor belt represented using a grid consisting of n rows and m columns. The cell in the i-th row from the top and the j-th column from the left is labelled (i,j).

Every cell, except (n,m), has a direction R (Right) or D (Down) assigned to it. If the cell (i,j) is assigned direction R, any luggage kept on that will move to the cell (i,j+1). Similarly, if the cell (i,j) is assigned direction D, any luggage kept on that will move to the cell (i+1,j). If at any moment, the luggage moves out of the grid, it is considered to be lost.

There is a counter at the cell (n,m) from where all luggage is picked. A conveyor belt is called functional if and only if any luggage reaches the counter regardless of which cell it is placed in initially. More formally, for every cell (i,j), any luggage placed in this cell should eventually end up in the cell (n,m).

This may not hold initially; you are, however, allowed to change the directions of some cells to make the conveyor belt functional. Please determine the minimum amount of cells you have to change.

Please note that it is always possible to make any conveyor belt functional by changing the directions of some set of cells.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤10). Description of the test cases follows.

The first line of each test case contains two integers n,m (1≤n≤100, 1≤m≤100)  — the number of rows and columns, respectively.

The following n lines each contain m characters. The j-th character in the i-th line, ai,j is the initial direction of the cell (i,j). Please note that an,m= C.

Output
For each case, output in a new line the minimum number of cells that you have to change to make the conveyor belt functional.

Example
inputCopy
4
3 3
RRD
DDR
RRC
1 4
DDDC
6 9
RDDDDDRRR
RRDDRRDDD
RRDRDRRDR
DDDDRDDRR
DRRDRDDDR
DDRDRRDDC
1 1
C
outputCopy
1
3
9
0
Note
In the first case, just changing the direction of (2,3) to D is enough.

You can verify that the resulting belt is functional. For example, if we place any luggage at (2,2), it first moves to (3,2) and then to (3,3).

In the second case, we have no option but to change the first 3 cells from D to R making the grid equal to RRRC.
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
	ll n, m;
	cin >> n >> m;
	char a[n][m];
	foi(n) {
		foj(m) {
			cin >> a[i][j];
		}
	}
	if (n == 1 and m == 1) {
		if (a[0][0] == 'C')
			cout << 0;
		else
			cout << 1;
	}
	else {
		ll ans = 0;
		foi(n - 1) {
			if (a[i][m - 1] == 'R')
				ans++;
		}
		foi(m - 1) {
			if (a[n - 1][i] == 'D')
				ans++;
		}
		cout << ans;

	}

}

