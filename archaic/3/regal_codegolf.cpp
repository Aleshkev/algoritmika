#include <bits/stdc++.h>
using namespace std;int n,i,j,l[1000];int main(){char t[1<<20];cin>>n;while(cin>>t){l[i++]=strlen(t);}sort(l,l+n);while(j<n){cout<<string(l[j++],'O')<<'\n';}}
