/*
C. Not Adjacent Matrix
time limit per test4 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
We will consider the numbers a and b as adjacent if they differ by exactly one, that is, |a−b|=1.

We will consider cells of a square matrix n×n as adjacent if they have a common side, that is, for cell (r,c) cells (r,c−1), (r,c+1), (r−1,c) and (r+1,c) are adjacent to it.

For a given number n, construct a square matrix n×n such that:

Each integer from 1 to n2 occurs in this matrix exactly once;
If (r1,c1) and (r2,c2) are adjacent cells, then the numbers written in them must not be adjacent.
Input
The first line contains one integer t (1≤t≤100). Then t test cases follow.

Each test case is characterized by one integer n (1≤n≤100).

Output
For each test case, output:

-1, if the required matrix does not exist;
the required matrix, otherwise (any such matrix if many of them exist).
The matrix should be outputted as n lines, where each line contains n integers.

Example
inputCopy
3
1
2
3
outputCopy
1
-1
2 9 7
4 6 3
1 8 5

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
ll TT = 1;
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
void solve()
{
	ll n;
	cin >> n;
	ll a[n][n] = {};
	ll x = 1;
	foi(n) {
		foj(n) {
			if ((i + j) % 2) {
				a[i][j] = x;
				x++;
			}
		}
	}
	foi(n) {
		foj(n) {
			if ((i + j) % 2 == 0) {
				a[i][j] = x;
				x++;
			}
		}
	}
	if (n == 2) {
		cout << -1;
		return;
	}
	if (n == 1)
		cout << 1;
	else {
		foi(n) {
			foj(n) {

				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
	}


}

 
