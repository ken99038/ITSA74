#include <stdio.h>
#include <stdlib.h>
int main(){
    long long int n;
    long long int p;
    long double r;
    long double money = 0.0;
    scanf("%llf %lld %lld", &r, &n, &p);
    r = r + 1.0;
    for(int i = 0; i < n; i ++){
        money += p;
        money *= r; 
    }
    long long int output = (long long int)money;
    printf("%lld\n", output);
    return 0;
}