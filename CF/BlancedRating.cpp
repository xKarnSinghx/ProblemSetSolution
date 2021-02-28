/*
A. Balanced Rating Changes
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
Another Codeforces Round has just finished! It has gathered n participants, and according to the results, the expected rating change of participant i is ai. These rating changes are perfectly balanced — their sum is equal to 0.

Unfortunately, due to minor technical glitches, the round is declared semi-rated. It means that all rating changes must be divided by two.

There are two conditions though:

For each participant i, their modified rating change bi must be integer, and as close to ai2 as possible. It means that either bi=⌊ai2⌋ or bi=⌈ai2⌉. In particular, if ai is even, bi=ai2. Here ⌊x⌋ denotes rounding down to the largest integer not greater than x, and ⌈x⌉ denotes rounding up to the smallest integer not smaller than x.
The modified rating changes must be perfectly balanced — their sum must be equal to 0.
Can you help with that?

Input
The first line contains a single integer n (2≤n≤13845), denoting the number of participants.

Each of the next n lines contains a single integer ai (−336≤ai≤1164), denoting the rating change of the i-th participant.

The sum of all ai is equal to 0.

Output
Output n integers bi, each denoting the modified rating change of the i-th participant in order of input.

For any i, it must be true that either bi=⌊ai2⌋ or bi=⌈ai2⌉. The sum of all bi must be equal to 0.

If there are multiple solutions, print any. We can show that a solution exists for any valid input.

Examples
inputCopy
3
10
-5
-5
outputCopy
5
-2
-3
inputCopy
7
-7
-29
0
3
24
-29
38
outputCopy
-3
-15
0
2
12
-15
19
Note
In the first example, b1=5, b2=−3 and b3=−2 is another correct solution.

In the second example there are 6 possible solutions, one of them is shown in the example output.
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

//	int t ; cin >> t;
//	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceil(ll x, ll y) {
	return x / y + ((x % y) != 0);
}
void solve()

{
	ll n;
	cin >> n;
	ll f = 1;
	foi (n) {
		ll x;
		cin >> x;
		if (x % 2 == 0) {
			cout << x / 2 << endl;
		} else {
			cout << (x + f) / 2 << endl;
			f *= -1;
		}
	}
}


 
