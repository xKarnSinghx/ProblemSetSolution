/*
B. Permutation Sort
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a permutation a consisting of n numbers 1, 2, ..., n (a permutation is an array in which each element from 1 to n occurs exactly once).

You can perform the following operation: choose some subarray (contiguous subsegment) of a and rearrange the elements in it in any way you want. But this operation cannot be applied to the whole array.

For example, if a=[2,1,4,5,3] and we want to apply the operation to the subarray a[2,4] (the subarray containing all elements from the 2-nd to the 4-th), then after the operation, the array can become a=[2,5,1,4,3] or, for example, a=[2,1,5,4,3].

Your task is to calculate the minimum number of operations described above to sort the permutation a in ascending order.

Input
The first line contains a single integer t (1≤t≤2000) — the number of test cases.

The first line of the test case contains a single integer n (3≤n≤50) — the number of elements in the permutation.

The second line of the test case contains n distinct integers from 1 to n — the given permutation a.

Output
For each test case, output a single integer — the minimum number of operations described above to sort the array a in ascending order.

Example
inputCopy
3
4
1 3 2 4
3
1 2 3
5
2 1 4 5 3
outputCopy
1
0
2
Note
In the explanations, a[i,j] defines the subarray of a that starts from the i-th element and ends with the j-th element.

In the first test case of the example, you can select the subarray a[2,3] and swap the elements in it.

In the second test case of the example, the permutation is already sorted, so you don't need to apply any operations.

In the third test case of the example, you can select the subarray a[3,5] and reorder the elements in it so a becomes [2,1,3,4,5], and then select the subarray a[1,2] and swap the elements in it, so a becomes [1,2,3,4,5].

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
	ll a[n];
	foi(n)
	cin >> a[i];
	ll c = 0;
	foi(n - 1) {
		if (a[i] > a[i + 1])
			c++;
	}
	if (c == 0)
		cout << 0;
	else if (a[0] == n and a[n - 1] == 1) {
		cout << 3;
	}
	else if (a[0] == 1 or a[n - 1] == n) {
		cout << 1;
	}
	else
		cout << 2;
}

