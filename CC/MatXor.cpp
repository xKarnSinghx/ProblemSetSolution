/*
Chef has a tasty ingredient ― an integer K. He defines a tasty matrix A with N rows (numbered 1 through N) and M columns (numbered 1 through M) as Ai,j=K+i+j for each valid i,j

.

Currently, Chef is busy in the kitchen making this tasty matrix. Help him find the bitwise XOR of all elements of this matrix.
Input

    The first line of the input contains a single integer T

denoting the number of test cases. The description of T
test cases follows.
The first and only line of each test case contains three space-separated integers N
, M and K

    .

Output

For each test case, print a single line containing one integer ― the bitwise XOR of all elements of the tasty matrix with the given dimensions made with the given special ingredient.
Constraints

    1≤T≤105

1≤N,M≤2⋅106
1≤K≤109
the sum of N
over all test cases does not exceed 2⋅106
the sum of M
over all test cases does not exceed 2⋅106

Example Input

2
2 2 5
2 3 7

Example Output

14
5
*/
#include <bits/stdc++.h>
using namespace std;

int f(int n)
{
    int mod = n % 4;
    if (mod == 0)
        return n;
    else if (mod == 1)
        return 1;
    else if (mod == 2)
        return n + 1;
    else if (mod == 3)
        return 0;
}

int main(){
  int t;
  cin>>t;
  while(t--){
   long long  int k,n,m,l=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
      int h=f(i+k);
     int p=f(i+m+k);
     l=l^(h^p);
    }cout<<l<<endl;}}
