/*
A. Sweet Problem
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have three piles of candies: red, green and blue candies:

the first pile contains only red candies and there are r candies in it,
the second pile contains only green candies and there are g candies in it,
the third pile contains only blue candies and there are b candies in it.
Each day Tanya eats exactly two candies of different colors. She is free to choose the colors of eaten candies: the only restriction that she can't eat two candies of the same color in a day.

Find the maximal number of days Tanya can eat candies? Each day she needs to eat exactly two candies.

Input
The first line contains integer t (1≤t≤1000) — the number of test cases in the input. Then t test cases follow.

Each test case is given as a separate line of the input. It contains three integers r, g and b (1≤r,g,b≤108) — the number of red, green and blue candies, respectively.

Output
Print t integers: the i-th printed integer is the answer on the i-th test case in the input.

Example
inputCopy
6
1 1 1
1 2 1
4 1 1
7 4 10
8 1 4
8 2 8
outputCopy
1
2
2
10
5
9
Note
In the first example, Tanya can eat candies for one day only. She can eat any pair of candies this day because all of them have different colors.

In the second example, Tanya can eat candies for two days. For example, she can eat red and green candies on the first day, and green and blue candies on the second day.

In the third example, Tanya can eat candies for two days. For example, she can eat red and green candies on the first day, and red and blue candies on the second day. Note, that two red candies will remain uneaten.


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
	ll a[3];
	foi(3)
	cin >> a[i];
	sort(a, a + 3);
	if (a[2] - a[1] - a[0] <= 0) {
		cout << (a[1] + a[0] + a[2]) / 2;
	}
	else
		cout << a[0] + a[1];

}


