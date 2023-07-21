#include <bits/stdc++.h>

using namespace std;
unsigned long long solution(const vector<unsigned long long>& arr){
    if (arr.size()==1)return arr[0];
    unsigned long long x = __gcd(arr[0],arr[1]);
    for (int i=2;i<arr.size();i++)x=__gcd(x,arr[i]);
    return arr.size()*x;   
}