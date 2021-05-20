/*
D. Grid-00100
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A mad scientist Dr.Jubal has made a competitive programming task. Try to solve it!

You are given integers n,k. Construct a grid A with size n×n consisting of integers 0 and 1. The very important condition should be satisfied: the sum of all elements in the grid is exactly k. In other words, the number of 1 in the grid is equal to k.

Let's define:

Ai,j as the integer in the i-th row and the j-th column.
Ri=Ai,1+Ai,2+...+Ai,n (for all 1≤i≤n).
Cj=A1,j+A2,j+...+An,j (for all 1≤j≤n).
In other words, Ri are row sums and Cj are column sums of the grid A.
For the grid A let's define the value f(A)=(max(R)−min(R))2+(max(C)−min(C))2 (here for an integer sequence X we define max(X) as the maximum value in X and min(X) as the minimum value in X).
Find any grid A, which satisfies the following condition. Among such grids find any, for which the value f(A) is the minimum possible. Among such tables, you can find any.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤100) — the number of test cases. Next t lines contain descriptions of test cases.

For each test case the only line contains two integers n, k (1≤n≤300,0≤k≤n2).

It is guaranteed that the sum of n2 for all test cases does not exceed 105.

Output
For each test case, firstly print the minimum possible value of f(A) among all tables, for which the condition is satisfied.

After that, print n lines contain n characters each. The j-th character in the i-th line should be equal to Ai,j.

If there are multiple answers you can print any.

Example
inputCopy
4
2 2
3 8
1 0
4 16
outputCopy
0
10
01
2
111
111
101
0
0
0
1111
1111
1111
1111
Note
In the first test case, the sum of all elements in the grid is equal to 2, so the condition is satisfied. R1=1,R2=1 and C1=1,C2=1. Then, f(A)=(1−1)2+(1−1)2=0, which is the minimum possible value of f(A).

In the second test case, the sum of all elements in the grid is equal to 8, so the condition is satisfied. R1=3,R2=3,R3=2 and C1=3,C2=2,C3=3. Then, f(A)=(3−2)2+(3−2)2=2. It can be proven, that it is the minimum possible value of f(A).


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
	ll n, k;
	cin >> n >> k;
	ll a[n][n] = {}, r[n] = {}, c[n] = {}, i = 0, j = 0;
	while (k--) {
		if (a[i][j] == 0)
			a[i][j] = 1, r[i]++, c[j]++;
		else {
			i++; i %= n;
			k++;
			continue;
		}
		i++, j++;
		i %= n;
		j %= n;
	}
	sort(r, r + n);
	sort(c, c + n);
	cout << (r[n - 1] - r[0])*(r[n - 1] - r[0]) + (c[n - 1] - c[0])*(c[n - 1] - c[0]) << endl;;
	foi(n) {
		foj(n) {
			cout << a[i][j];
		}
		cout << endl;
	}
}
 
