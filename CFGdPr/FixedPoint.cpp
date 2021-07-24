/*
E. Fixed Points
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Consider a sequence of integers a1,a2,…,an. In one move, you can select any element of the sequence and delete it. After an element is deleted, all elements to the right are shifted to the left by 1 position, so there are no empty spaces in the sequence. So after you make a move, the sequence's length decreases by 1. The indices of the elements after the move are recalculated.

E. g. let the sequence be a=[3,2,2,1,5]. Let's select the element a3=2 in a move. Then after the move the sequence will be equal to a=[3,2,1,5], so the 3-rd element of the new sequence will be a3=1 and the 4-th element will be a4=5.

You are given a sequence a1,a2,…,an and a number k. You need to find the minimum number of moves you have to make so that in the resulting sequence there will be at least k elements that are equal to their indices, i. e. the resulting sequence b1,b2,…,bm will contain at least k indices i such that bi=i.

Input
The first line contains one integer t (1≤t≤100) — the number of test cases. Then t test cases follow.

Each test case consists of two consecutive lines. The first line contains two integers n and k (1≤k≤n≤2000). The second line contains a sequence of integers a1,a2,…,an (1≤ai≤n). The numbers in the sequence are not necessarily different.

It is guaranteed that the sum of n over all test cases doesn't exceed 2000.

Output
For each test case output in a single line:

−1 if there's no desired move sequence;
otherwise, the integer x (0≤x≤n) — the minimum number of the moves to be made so that the resulting sequence will contain at least k elements that are equal to their indices.
Example
inputCopy
4
7 6
1 1 2 3 4 5 6
5 2
5 1 3 2 3
5 2
5 5 5 5 4
8 4
1 2 3 3 2 2 5 5
outputCopy
1
2
-1
2
Note
In the first test case the sequence doesn't satisfy the desired condition, but it can be provided by deleting the first element, hence the sequence will be [1,2,3,4,5,6] and 6 elements will be equal to their indices.

In the second test case there are two ways to get the desired result in 2 moves: the first one is to delete the 1-st and the 3-rd elements so that the sequence will be [1,2,3] and have 3 elements equal to their indices; the second way is to delete the 2-nd and the 3-rd elements to get the sequence [5,2,3] with 2 desired elements.

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
#define graph          vector<vector<ll>>
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
typedef queue<ll>           qll;
typedef vector<plll>      vplll;
typedef  vector<set<ll>>   vsll;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  unordered_map< ll, ld>           umld;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll modx = 998244353;
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
ll powmod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) {
		res = res * x % MOD;
	}
	return res;
}
bool isPrime(ll n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
bool COMP(pll l, pll r) {
	return l.ss < r.ss;
}
ll kadanesAlgo(vll a)
{
	ll n = a.size();

	ll currMax = 0;
	ll mx = INT_MIN;

	foi(n)
	{
		currMax += a[i];

		if (currMax <= a[i])
		{
			currMax = a[i];
		}

		mx = max(currMax, mx);
	}
	return mx;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	graph g(n + 1, vll(n + 1, 0));
	foi(n) {
		ll x;
		cin >> x;
		foj(i + 1) {
			g[i + 1][j + 1] = max(g[i + 1][j + 1], g[i][j]);
			if (x - i + j == 1) {
				g[i + 1][j] = max(g[i + 1][j], g[i][j] + 1);
			}
			else {
				g[i + 1][j] = max(g[i + 1][j], g[i][j]);
			}
		}
	}
	foi(n) {
		if (g[n][i] >= k) {
			cout << i;
			return;
		}
	}
	cout << -1;
}
 
