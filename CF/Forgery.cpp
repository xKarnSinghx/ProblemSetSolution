/*
B. Forgery
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Student Andrey has been skipping physical education lessons for the whole term, and now he must somehow get a passing grade on this subject. Obviously, it is impossible to do this by legal means, but Andrey doesn't give up. Having obtained an empty certificate from a local hospital, he is going to use his knowledge of local doctor's handwriting to make a counterfeit certificate of illness. However, after writing most of the certificate, Andrey suddenly discovered that doctor's signature is impossible to forge. Or is it?

For simplicity, the signature is represented as an n×m grid, where every cell is either filled with ink or empty. Andrey's pen can fill a 3×3 square without its central cell if it is completely contained inside the grid, as shown below.


xxx
x.x
xxx
Determine whether is it possible to forge the signature on an empty n×m grid.

Input
The first line of input contains two integers n and m (3≤n,m≤1000).

Then n lines follow, each contains m characters. Each of the characters is either '.', representing an empty cell, or '#', representing an ink filled cell.

Output
If Andrey can forge the signature, output "YES". Otherwise output "NO".

You can print each letter in any case (upper or lower).

Examples
inputCopy
3 3
###
#.#
###
outputCopy
YES
inputCopy
3 3
###
###
###
outputCopy
NO
inputCopy
4 3
###
###
###
###
outputCopy
YES
inputCopy
5 7
.......
.#####.
.#.#.#.
.#####.
.......
outputCopy
YES
Note
In the first sample Andrey can paint the border of the square with the center in (2,2).

In the second sample the signature is impossible to forge.

In the third sample Andrey can paint the borders of the squares with the centers in (2,2) and (3,2):

we have a clear paper:

...
...
...
...
use the pen with center at (2,2).

###
#.#
###
...
use the pen with center at (3,2).

###
###
###
###
In the fourth sample Andrey can paint the borders of the squares with the centers in (3,3) and (3,5).
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


	//ll t ; cin >> t;
	//while (t--)
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
		foj(m)
		cin >> a[i][j];
	}
	ll ok[n][m] = {};
	foi(n - 2) {
		foj(m - 2) {
			if (a[i][j] == '#' and a[i + 1][j] == '#' and a[i + 2][j] == '#' and a[i + 2][j + 1] == '#' and a[i + 2][j + 2] == '#' and a[i + 1][j + 2] == '#' and a[i][j + 2] == '#' and a[i][j + 1] == '#') {
				ok[i][j] = 1, ok[i + 1][j] = 1, ok[i][j + 1] = 1, ok[i + 2][j] = 1, ok[i + 2][j + 1] = 1, ok[i + 2][j + 2] = 1, ok[i + 1][j + 2] = 1, ok[i][j + 2] = 1;
			}
		}
	}
	foi(n) {
		foj(m)
		if (a[i][j] == '#')
			if (ok[i][j] == 0) {
				cout << "NO";
				return;
			}
	}
	cout << "YES";

}
