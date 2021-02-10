/*
B. Inflation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have a statistic of price changes for one product represented as an array of n positive integers p0,p1,…,pn−1, where p0 is the initial price of the product and pi is how the price was increased during the i-th month.

Using these price changes you are asked to calculate the inflation coefficients for each month as the ratio of current price increase pi to the price at the start of this month (p0+p1+⋯+pi−1).

Your boss said you clearly that the inflation coefficients must not exceed k %, so you decided to increase some values pi in such a way, that all pi remain integers and the inflation coefficients for each month don't exceed k %.

You know, that the bigger changes — the more obvious cheating. That's why you need to minimize the total sum of changes.

What's the minimum total sum of changes you need to make all inflation coefficients not more than k %?

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains two integers n and k (2≤n≤100; 1≤k≤100) — the length of array p and coefficient k.

The second line of each test case contains n integers p0,p1,…,pn−1 (1≤pi≤109) — the array p.

Output
For each test case, print the minimum total sum of changes you need to make all inflation coefficients not more than k %.

Example
inputCopy
2
4 1
20100 1 202 202
3 100
1 1 1
outputCopy
99
0
Note
In the first test case, you can, for example, increase p0 by 50 and p1 by 49 and get array [20150,50,202,202]. Then you get the next inflation coefficients:

5020150≤1100;
20220150+50≤1100;
20220200+202≤1100;
In the second test case, you don't need to modify array p, since the inflation coefficients are already good:

11≤100100;
11+1≤100100;
TAG:binary search    brute force    greedy    math    *1300
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
void solve()

{
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = 0, sum = a[0];
	for (ll i = 1; i < n; i++) {
		ans = max(ans, (100 * a[i] + k - 1) / k  - sum);
		sum += a[i];
	}
	cout << ans;


}

 
