/*
B. A New Technique
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
All techniques in the ninja world consist of hand seals. At the moment Naruto is learning a new technique, which consists of n⋅m different seals, denoted by distinct numbers. All of them were written in an n×m table.

The table is lost now. Naruto managed to remember elements of each row from left to right, and elements of each column from top to bottom, but he doesn't remember the order of rows and columns. Please restore the table consistent with this data so that Naruto will be able to learn the new technique.

Input
The first line of the input contains the only integer t (1≤t≤100000) denoting the number of test cases. Their descriptions follow.

The first line of each test case description consists of two space-separated integers n and m (1≤n,m≤500) standing for the number of rows and columns in the table, respectively. All hand seals are encoded by the positive integers from 1 to n⋅m.

The following n lines contain m space separated integers each, denoting elements of an arbitrary row in the table left to right.

The following m lines contain n space separated integers each, denoting elements of an arbitrary column in the table top to bottom.

Sum of nm over all test cases does not exceed 250000. It is guaranteed that each row occurs in the input exactly once, as well as each column. It is also guaranteed that each number from 1 to nm occurs exactly once in all rows, as well as in all columns. Finally, it is guaranteed that a table consistent with the input exists.

Output
For each test case, output n lines with m space-separated integers each, denoting the restored table. One can show that the answer is always unique.

Example
inputCopy
2
2 3
6 5 4
1 2 3
1 6
2 5
3 4
3 1
2
3
1
3 1 2
outputCopy
1 2 3 
6 5 4 
3 
1 
2 
Note
Consider the first test case. The matrix is 2×3. You are given the rows and columns in arbitrary order.

One of the rows is [6,5,4]. One of the rows is [1,2,3].

One of the columns is [1,6]. One of the columns is [2,5]. One of the columns is [3,4].

You are to reconstruct the matrix. The answer is given in the output.

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
		//cout << "\n";
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
	ll col[n * m + 1] = {};
	foi(n) {
		foj(m)
		{
			ll x;
			cin >> x;
			col[x] = j;
		}
	}
	foj(m) {
		foi(n) {
			ll x;
			cin >> x;
			a[i][j] = x;
		}
	}
	foi(n)
	{
		ll b[m];
		foj(m)
		{
			b[col[a[i][j]]] = a[i][j];
		}
		foj(m)
		cout << b[j] << " ";
		cout << endl;
	}
}
