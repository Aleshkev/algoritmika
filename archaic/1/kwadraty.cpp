#include <bits/stdc++.h>
using namespace std;typedef long long int I;const I inf = 9e18;int main(){I a,b;cin>>a>>b;if(b>a){I t=b;b=a;a=t;}I x=a-b;I sqrt_x=sqrt(x)+1,min_n=inf;for(I c=1;c<=sqrt_x;++c){if(x%c)continue;I d=x/c;I p=(c+d)/2,q=(c-d)/2;I n1=p*p-a,n2=q*q-b;if(n1!=n2)continue;if(n1<min_n)min_n=n1;}if(min_n<inf)cout<<min_n<<'\n';else cout<<"brak\n";return 0;}
