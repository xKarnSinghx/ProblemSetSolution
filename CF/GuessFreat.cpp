/*
C2. Guessing the Greatest (hard version)
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The only difference between the easy and the hard version is the limit to the number of queries.

This is an interactive problem.

There is an array a of n different numbers. In one query you can ask the position of the second maximum element in a subsegment a[l..r]. Find the position of the maximum element in the array in no more than 20 queries.

A subsegment a[l..r] is all the elements al,al+1,...,ar. After asking this subsegment you will be given the position of the second maximum from this subsegment in the whole array.

Input
The first line contains a single integer n (2≤n≤105) — the number of elements in the array.

Interaction
You can ask queries by printing "? l r" (1≤l<r≤n). The answer is the index of the second maximum of all elements al,al+1,...,ar. Array a is fixed beforehand and can't be changed in time of interaction.

You can output the answer by printing "! p", where p is the index of the maximum element in the array.

You can ask no more than 20 queries. Printing the answer doesn't count as a query.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
see documentation for other languages
Hacks

To make a hack, use the following test format.

In the first line output a single integer n (2≤n≤105). In the second line output a permutation of n integers 1 to n. The position of n in the permutation is the position of the maximum

Example
inputCopy
5

3

4

outputCopy
? 1 5

? 4 5

! 1
Note
In the sample suppose a is [5,1,4,2,3]. So after asking the [1..5] subsegment 4 is second to max value, and it's position is 3. After asking the [4..5] subsegment 2 is second to max value and it's position in the whole array is 4.

Note that there are other arrays a that would produce the same interaction, and the answer for them might be different. Example output is given in purpose of understanding the interaction.

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

		solve();
	
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll pos(ll l, ll r) {
	if (l >= r)
		return -1;
	cout << "? " << l + 1 << ' ' << r + 1 << endl;
	ll ans;
	cin >> ans;
	return ans - 1;
}

void solve()

{

	ll n;
	cin >> n;
	ll mx2 = pos(0, n - 1);
	if (mx2 == 0 || pos(0, mx2) != mx2) {
		ll l = mx2, r = n - 1;
		while (r - l > 1) {
			ll m = (l + r) / 2;
			if (pos(mx2, m) == mx2) {
				r = m;
			} else {
				l = m;
			}
		}
		cout << "! " << r + 1 << endl;
	} else {
		ll l = 0, r = mx2;
		while (r - l > 1) {
			ll m = (l + r) / 2;
			if (pos(m, mx2) == mx2) {
				l = m;
			} else {
				r = m;
			}
		}
		cout << "! " << l + 1 << endl;
	}

}

 
