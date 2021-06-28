/*
E. Good Array
time limit per test2.0 s
memory limit per test512 MB
inputstandard input
outputstandard output
Let's call an array good if there is an element in the array that equals to the sum of all other elements. For example, the array a=[1,3,3,7] is good because there is the element a4=7 which equals to the sum 1+3+3.

You are given an array a consisting of n integers. Your task is to print all indices j of this array such that after removing the j-th element from the array it will be good (let's call such indices nice).

For example, if a=[8,3,5,2], the nice indices are 1 and 4:

if you remove a1, the array will look like [3,5,2] and it is good;
if you remove a4, the array will look like [8,3,5] and it is good.
You have to consider all removals independently, i. e. remove the element, check if the resulting array is good, and return the element into the array.

Input
The first line of the input contains one integer n (2≤n≤2⋅105) — the number of elements in the array a.

The second line of the input contains n integers a1,a2,…,an (1≤ai≤106) — elements of the array a.

Output
In the first line print one integer k — the number of indices j of the array a such that after removing the j-th element from the array it will be good (i.e. print the number of the nice indices).

In the second line print k distinct integers j1,j2,…,jk in any order — nice indices of the array a.

If there are no such indices in the array a, just print 0 in the first line and leave the second line empty or do not print it at all.

Examples
inputCopy
5
2 5 1 2 2
outputCopy
3
4 1 5
inputCopy
4
8 3 5 2
outputCopy
2
1 4 
inputCopy
5
2 1 2 4 3
outputCopy
0

Note
In the first example you can remove any element with the value 2 so the array will look like [5,1,2,2]. The sum of this array is 10 and there is an element equals to the sum of remaining elements (5=1+2+2).

In the second example you can remove 8 so the array will look like [3,5,2]. The sum of this array is 10 and there is an element equals to the sum of remaining elements (5=3+2). You can also remove 2 so the array will look like [8,3,5]. The sum of this array is 16 and there is an element equals to the sum of remaining elements (8=3+5).

In the third example you cannot make the given array good by removing exactly one element.


*/
import java.lang.AssertionError

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun main(args: Array<String>) {
   var n = readInt()
   var a = readInts()
   var at = IntArray(n)
   var s=0
   var x: Long=0
   val cnt = Array(1000001, {0})
   for (i in 0 until n){
   at[i]=a[i]
   x+=at[i]
   cnt[at[i]]+=1
   }
   var ans = ArrayList<Int>()
   for (i in 0 until n){
    x-=at[i]
    if(x<2000001)
    s=x.toInt()
    cnt[at[i]]-=1
	if (s % 2 <1) {
	if(s/2<1000001){
	if(cnt[s/2]>0){
		ans.add(i+1)
	}
	}
	}
	x += at[i]
	cnt[at[i]]+=1
   }
    println(ans.size)
    println(ans.joinToString(" "))
}
