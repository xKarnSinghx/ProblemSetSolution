/*
B. Neighbor Grid
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a grid with n rows and m columns, where each cell has a non-negative integer written on it. We say the grid is good if for each cell the following condition holds: if it has a number k>0 written on it, then exactly k of its neighboring cells have a number greater than 0 written on them. Note that if the number in the cell is 0, there is no such restriction on neighboring cells.

You are allowed to take any number in the grid and increase it by 1. You may apply this operation as many times as you want, to any numbers you want. Perform some operations (possibly zero) to make the grid good, or say that it is impossible. If there are multiple possible answers, you may find any of them.

Two cells are considered to be neighboring if they have a common edge.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤5000)  — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n and m (2≤n,m≤300)  — the number of rows and columns, respectively.

The following n lines contain m integers each, the j-th element in the i-th line ai,j is the number written in the j-th cell of the i-th row (0≤ai,j≤109).

It is guaranteed that the sum of n⋅m over all test cases does not exceed 105.

Output
If it is impossible to obtain a good grid, print a single line containing "NO".

Otherwise, print a single line containing "YES", followed by n lines each containing m integers, which describe the final state of the grid. This final grid should be obtainable from the initial one by applying some operations (possibly zero).

If there are multiple possible answers, you may print any of them.

Example
inputCopy
5
3 4
0 0 0 0
0 1 0 0
0 0 0 0
2 2
3 0
0 0
2 2
0 0
0 0
2 3
0 0 0
0 4 0
4 4
0 0 0 0
0 2 0 1
0 0 0 0
0 0 0 0
outputCopy
YES
0 0 0 0
0 1 1 0
0 0 0 0
NO
YES
0 0
0 0
NO
YES
0 1 0 0
1 4 2 1
0 2 0 0
1 3 1 0
Note
In the first test case, we can obtain the resulting grid by increasing the number in row 2, column 3 once. Both of the cells that contain 1 have exactly one neighbor that is greater than zero, so the grid is good. Many other solutions exist, such as the grid

0100
0210
0000
All of them are accepted as valid answers.

In the second test case, it is impossible to make the grid good.

In the third test case, notice that no cell has a number greater than zero on it, so the grid is automatically good.
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
	ll a[n][m];
	foi(n) {
		foj(m) {
			cin >> a[i][j];
		}
	}
	foi(n) {
		foj(m) {
			ll h = 0;
			if (i == 0 || i == n - 1) h++;
			if (j == 0 || j == m - 1) h++;
			if (a[i][j] > 4 - h) {
				cout << "NO";
				return;
			}
			a[i][j] = 4 - h;
		}
	}
	cout << "YES\n";
	foi(n) {
		foj(m) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

