/*
B. Gifts Fixing
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have n gifts and you want to give all of them to children. Of course, you don't want to offend anyone, so all gifts should be equal between each other. The i-th gift consists of ai candies and bi oranges.

During one move, you can choose some gift 1≤i≤n and do one of the following operations:

eat exactly one candy from this gift (decrease ai by one);
eat exactly one orange from this gift (decrease bi by one);
eat exactly one candy and exactly one orange from this gift (decrease both ai and bi by one).
Of course, you can not eat a candy or orange if it's not present in the gift (so neither ai nor bi can become less than zero).

As said above, all gifts should be equal. This means that after some sequence of moves the following two conditions should be satisfied: a1=a2=⋯=an and b1=b2=⋯=bn (and ai equals bi is not necessary).

Your task is to find the minimum number of moves required to equalize all the given gifts.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

The first line of the test case contains one integer n (1≤n≤50) — the number of gifts. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤109), where ai is the number of candies in the i-th gift. The third line of the test case contains n integers b1,b2,…,bn (1≤bi≤109), where bi is the number of oranges in the i-th gift.

Output
For each test case, print one integer: the minimum number of moves required to equalize all the given gifts.

Example
inputCopy
5
3
3 5 6
3 2 3
5
1 2 3 4 5
5 4 3 2 1
3
1 1 1
2 2 2
6
1 1000000000 1000000000 1000000000 1000000000 1000000000
1 1 1 1 1 1
3
10 12 8
7 5 4
outputCopy
6
16
0
4999999995
7
Note
In the first test case of the example, we can perform the following sequence of moves:

choose the first gift and eat one orange from it, so a=[3,5,6] and b=[2,2,3];
choose the second gift and eat one candy from it, so a=[3,4,6] and b=[2,2,3];
choose the second gift and eat one candy from it, so a=[3,3,6] and b=[2,2,3];
choose the third gift and eat one candy and one orange from it, so a=[3,3,5] and b=[2,2,2];
choose the third gift and eat one candy from it, so a=[3,3,4] and b=[2,2,2];
choose the third gift and eat one candy from it, so a=[3,3,3] and b=[2,2,2].*/
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
	ll a[n], b[n], s = 1111111111, s1 = 1111111111;
	foi(n) {
		cin >> a[i];
		s = min(s, a[i]);
	}
	foi(n) {
		cin >> b[i];

		s1 = min(s1, b[i]);
	}
	ll ans = 0;
	foi(n) {
		while (a[i] > s and b[i] > s1) {
			ll x = min(a[i] - s, b[i] - s1);
			ans += x;
			a[i] -= x;
			b[i] -= x;
		}
		while (a[i] > s ) {
			ans += (a[i] - s);
			a[i] -= (a[i] - s);
		}
		while (b[i] > s1) {
			ans += (b[i] - s1);
			b[i] -= (b[i] - s1);
		}

	}
	cout << ans;

}

