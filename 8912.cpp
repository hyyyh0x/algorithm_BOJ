//#Sales
#include<stdio.h>
#include<string.h>
int A[5001];
int bitQuery(int i){
    int s=0;
    while(i>0){
        s+=A[i];
        i-=i&-i;
    }
    return s;
}

void bitUpdate(int i, int x){
    while(i<5001){
        A[i]+=x;
        i+=i&-i;
    }
}

int main(){
    int T,n,a;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        long long int s=0;
        memset(A, 0, sizeof(A));
        for(int j=0;j<n;j++){
            scanf("%d",&a);
            s+=bitQuery(a);
            bitUpdate(a,1);
        }
        printf("%lld\n",s);
    }
}
