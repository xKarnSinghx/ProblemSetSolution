/*
C. Johnny and Another Rating Drop
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The last contest held on Johnny's favorite competitive programming platform has been received rather positively. However, Johnny's rating has dropped again! He thinks that the presented tasks are lovely, but don't show the truth about competitors' skills.

The boy is now looking at the ratings of consecutive participants written in a binary system. He thinks that the more such ratings differ, the more unfair is that such people are next to each other. He defines the difference between two numbers as the number of bit positions, where one number has zero, and another has one (we suppose that numbers are padded with leading zeros to the same length). For example, the difference of 5=1012 and 14=11102 equals to 3, since 0101 and 1110 differ in 3 positions. Johnny defines the unfairness of the contest as the sum of such differences counted for neighboring participants.

Johnny has just sent you the rating sequence and wants you to find the unfairness of the competition. You have noticed that you've got a sequence of consecutive integers from 0 to n. That's strange, but the boy stubbornly says that everything is right. So help him and find the desired unfairness for received numbers.

Input
The input consists of multiple test cases. The first line contains one integer t (1≤t≤10000) — the number of test cases. The following t lines contain a description of test cases.

The first and only line in each test case contains a single integer n (1≤n≤1018).

Output
Output t lines. For each test case, you should output a single line with one integer — the unfairness of the contest if the rating sequence equals to 0, 1, ..., n−1, n.

Example
inputCopy
5
5
7
11
1
2000000000000
outputCopy
8
11
19
1
3999999999987
Note
For n=5 we calculate unfairness of the following sequence (numbers from 0 to 5 written in binary with extra leading zeroes, so they all have the same length):

000
001
010
011
100
101
The differences are equal to 1, 2, 1, 3, 1 respectively, so unfairness is equal to 1+2+1+3+1=8.


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

	int t ; cin >> t;
	while (t--)
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
	ll ans = 0;
	foi(60) {
		if (n & (1LL << i))
			ans += (1LL << (i + 1)) - 1;
	}
	cout << ans;
}



