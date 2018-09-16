#import<cstdio>
char s[999],*q=s+1;
int main(){
    for(scanf("%s",q);*q;)*q=*q++%48*3;
    //for(char *i = s; i < q; ++i) printf("%i ", *i); puts("\n");
    for(q[-1]+=8;q>=s;*q=*q--%10+48)q[-1]+=*q/10;
    //for(char *i = s; i < q; ++i) printf("%i ", *i); puts("\n");
    puts(*s>48?s:s+1);
}

