long long solve(long long k){
    long long res=1;
    while(k){
        if(k%2)res*=x%mod;
        x=x*x%mod;
        k=k/2;
    }
    return res;
}
