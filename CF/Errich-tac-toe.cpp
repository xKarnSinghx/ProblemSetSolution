/*
C1. Errich-Tac-Toe (Easy Version)
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The only difference between the easy and hard versions is that tokens of type O do not appear in the input of the easy version.

Errichto gave Monogon the following challenge in order to intimidate him from taking his top contributor spot on Codeforces.

In a Tic-Tac-Toe grid, there are n rows and n columns. Each cell of the grid is either empty or contains a token. There are two types of tokens: X and O. If there exist three tokens of the same type consecutive in a row or column, it is a winning configuration. Otherwise, it is a draw configuration.

The patterns in the first row are winning configurations. The patterns in the second row are draw configurations.
In an operation, you can change an X to an O, or an O to an X. Let k denote the total number of tokens in the grid. Your task is to make the grid a draw in at most ⌊k3⌋ (rounding down) operations.

You are not required to minimize the number of operations.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤300) — the size of the grid.

The following n lines each contain a string of n characters, denoting the initial grid. The character in the i-th row and j-th column is '.' if the cell is empty, or it is the type of token in the cell: 'X' or 'O'.

It is guaranteed that not all cells are empty.

In the easy version, the character 'O' does not appear in the input.

The sum of n across all test cases does not exceed 300.

Output
For each test case, print the state of the grid after applying the operations.

We have proof that a solution always exists. If there are multiple solutions, print any.

Example
inputCopy
3
3
.X.
XXX
.X.
6
XX.XXX
XXXXXX
XXX.XX
XXXXXX
XX.X.X
XXXXXX
5
XXX.X
.X..X
XXX.X
..X..
..X..
outputCopy
.X.
XOX
.X.
XX.XXO
XOXXOX
OXX.XX
XOOXXO
XX.X.X
OXXOXX
XOX.X
.X..X
XXO.O
..X..
..X..
Note
In the first test case, there are initially three 'X' consecutive in the second row and the second column. By changing the middle token to 'O' we make the grid a draw, and we only changed 1≤⌊5/3⌋ token.

In the second test case, we change only 9≤⌊32/3⌋ tokens, and there does not exist any three 'X' or 'O' consecutive in a row or column, so it is a draw.

In the third test case, we change only 3≤⌊12/3⌋ tokens, and the resulting grid is a draw.
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



void solve()

{
	ll n;
	cin >> n;
	string s[n];
	foi(n)
	cin >> s[i];
	ll c[3] = {0, 0, 0};
	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < n; ++j)
		{
			if (s[i][j] == 'X') {
				c[(i + j) % 3]++;
			}
		}
	}
ll s1 = min_element(c, c + 3) - c;
	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < n; ++j)
		{
			if (s[i][j] == 'X' && (i + j) % 3 == s1) {
				s[i][j] = 'O';
			}
		}
	}
	foi(n)
	cout << s[i] << endl;
}

 
