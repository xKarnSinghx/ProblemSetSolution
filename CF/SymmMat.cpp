/*
B. Symmetric Matrix
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Masha has n types of tiles of size 2×2. Each cell of the tile contains one integer. Masha has an infinite number of tiles of each type.

Masha decides to construct the square of size m×m consisting of the given tiles. This square also has to be a symmetric with respect to the main diagonal matrix, and each cell of this square has to be covered with exactly one tile cell, and also sides of tiles should be parallel to the sides of the square. All placed tiles cannot intersect with each other. Also, each tile should lie inside the square. See the picture in Notes section for better understanding.

Symmetric with respect to the main diagonal matrix is such a square s that for each pair (i,j) the condition s[i][j]=s[j][i] holds. I.e. it is true that the element written in the i-row and j-th column equals to the element written in the j-th row and i-th column.

Your task is to determine if Masha can construct a square of size m×m which is a symmetric matrix and consists of tiles she has. Masha can use any number of tiles of each type she has to construct the square. Note that she can not rotate tiles, she can only place them in the orientation they have in the input.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤100) — the number of test cases. Then t test cases follow.

The first line of the test case contains two integers n and m (1≤n≤100, 1≤m≤100) — the number of types of tiles and the size of the square Masha wants to construct.

The next 2n lines of the test case contain descriptions of tiles types. Types of tiles are written one after another, each type is written on two lines.

The first line of the description contains two positive (greater than zero) integers not exceeding 100 — the number written in the top left corner of the tile and the number written in the top right corner of the tile of the current type. The second line of the description contains two positive (greater than zero) integers not exceeding 100 — the number written in the bottom left corner of the tile and the number written in the bottom right corner of the tile of the current type.

It is forbidden to rotate tiles, it is only allowed to place them in the orientation they have in the input.

Output
For each test case print the answer: "YES" (without quotes) if Masha can construct the square of size m×m which is a symmetric matrix. Otherwise, print "NO" (withtout quotes).

Example
inputCopy
6
3 4
1 2
5 6
5 7
7 4
8 9
9 8
2 5
1 1
1 1
2 2
2 2
1 100
10 10
10 10
1 2
4 5
8 4
2 2
1 1
1 1
1 2
3 4
1 2
1 1
1 1
outputCopy
YES
NO
YES
NO
YES
YES
Note
The first test case of the input has three types of tiles, they are shown on the picture below.


Masha can construct, for example, the following square of size 4×4 which is a symmetric matrix:


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
	vpll x;
	foi(2 * n) {
		ll y, z;
		cin >> y >> z;
		x.pb(mp(y, z));
	}
	if (m % 2) {
		cout << "NO";
		return;
	}
	else {
		for (ll i = 0; i < 2 * n - 1; i += 2) {
			if (x[i].ss == x[i + 1].ff) {
				cout << "YES";
				return;
			}

		}
	}
	cout << "NO";

}
