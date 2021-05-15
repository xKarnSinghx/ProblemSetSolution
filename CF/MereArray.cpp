/*
C. Mere Array
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a1,a2,…,an where all ai are integers and greater than 0.

In one operation, you can choose two different indices i and j (1≤i,j≤n). If gcd(ai,aj) is equal to the minimum element of the whole array a, you can swap ai and aj. gcd(x,y) denotes the greatest common divisor (GCD) of integers x and y.

Now you'd like to make a non-decreasing using the operation any number of times (possibly zero). Determine if you can do this.

An array a is non-decreasing if and only if a1≤a2≤…≤an.

Input
The first line contains one integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains one integer n (1≤n≤105) — the length of array a.

The second line of each test case contains n positive integers a1,a2,…an (1≤ai≤109) — the array itself.

It is guaranteed that the sum of n over all test cases doesn't exceed 105.

Output
For each test case, output "YES" if it is possible to make the array a non-decreasing using the described operation, or "NO" if it is impossible to do so.

Example
inputCopy
4
1
8
6
4 3 6 6 2 9
4
4 5 6 7
5
7 5 2 2 4
outputCopy
YES
YES
YES
NO
Note
In the first and third sample, the array is already non-decreasing.

In the second sample, we can swap a1 and a3 first, and swap a1 and a5 second to make the array non-decreasing.

In the forth sample, we cannot the array non-decreasing using the operation.


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
	vll a(n, 0);
	foi(n)
	cin >> a[i];
	ll f = 0;
	foi(n - 1) {
		if (a[i] > a[i + 1]) {
			f = 1;
			break;
		}
	}
	vll b(n, 0);
	b = a;
	sort(all(b));
	if (n == 1 or f == 0) {
		cout << "Yes";
		return;
	}
	ll x = *min_element(all(a));
	foi(n) {
		if (a[i] != b[i] and a[i] % x != 0) {
			cout << "No";
			return;

		}
	}
	cout << "Yes";



}

