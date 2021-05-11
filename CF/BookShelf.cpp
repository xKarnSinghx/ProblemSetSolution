/*
B. Yet Another Bookshelf
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is a bookshelf which can fit n books. The i-th position of bookshelf is ai=1 if there is a book on this position and ai=0 otherwise. It is guaranteed that there is at least one book on the bookshelf.

In one move, you can choose some contiguous segment [l;r] consisting of books (i.e. for each i from l to r the condition ai=1 holds) and:

Shift it to the right by 1: move the book at index i to i+1 for all l≤i≤r. This move can be done only if r+1≤n and there is no book at the position r+1.
Shift it to the left by 1: move the book at index i to i−1 for all l≤i≤r. This move can be done only if l−1≥1 and there is no book at the position l−1.
Your task is to find the minimum number of moves required to collect all the books on the shelf as a contiguous (consecutive) segment (i.e. the segment without any gaps).

For example, for a=[0,0,1,0,1] there is a gap between books (a4=0 when a3=1 and a5=1), for a=[1,1,0] there are no gaps between books and for a=[0,0,0] there are also no gaps between books.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤200) — the number of test cases. Then t test cases follow.

The first line of the test case contains one integer n (1≤n≤50) — the number of places on a bookshelf. The second line of the test case contains n integers a1,a2,…,an (0≤ai≤1), where ai is 1 if there is a book at this position and 0 otherwise. It is guaranteed that there is at least one book on the bookshelf.

Output
For each test case, print one integer: the minimum number of moves required to collect all the books on the shelf as a contiguous (consecutive) segment (i.e. the segment without gaps).

Example
inputCopy
5
7
0 0 1 0 1 0 1
3
1 0 0
5
1 1 0 0 1
6
1 0 0 0 0 1
5
1 1 0 1 1
outputCopy
2
0
2
4
1
Note
In the first test case of the example, you can shift the segment [3;3] to the right and the segment [4;5] to the right. After all moves, the books form the contiguous segment [5;7]. So the answer is 2.

In the second test case of the example, you have nothing to do, all the books on the bookshelf form the contiguous segment already.

In the third test case of the example, you can shift the segment [5;5] to the left and then the segment [4;4] to the left again. After all moves, the books form the contiguous segment [1;3]. So the answer is 2.

In the fourth test case of the example, you can shift the segment [1;1] to the right, the segment [2;2] to the right, the segment [6;6] to the left and then the segment [5;5] to the left. After all moves, the books form the contiguous segment [3;4]. So the answer is 4.

In the fifth test case of the example, you can shift the segment [1;2] to the right. After all moves, the books form the contiguous segment [2;5]. So the answer is 1.


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
	ll a[n], tot = 0;
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
		if (x == 1)
			tot++;
	}
	ll s = 0, s1 = 0, f = 0, f1 = 0;
	foi(n) {
		if (a[i] == 1) {
			f++;
		}
		if (f > 0 and a[i] == 0 and f < tot )
			s++;
	}
	for (ll i = n - 1; i > -1; i--) {
		if (a[i] == 1) {
			f1++;
		}
		if (f1 > 0 and a[i] == 0 and f1 < tot )
			s1++;
	}
	cout << min(s, s1);

}
