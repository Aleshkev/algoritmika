#include<stdio.h>
char*p,s[999],*q=s;
int main(){
    for(scanf("%s",s);*q;)*q=*q++*3-144;
    for(p=q-1,*p+=8;p>s;)*(p-1)+=*p/10,*p--%=10;
    for(;p<q;++p)printf("%i",*p);

}


