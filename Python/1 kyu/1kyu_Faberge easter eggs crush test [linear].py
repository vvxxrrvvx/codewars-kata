MOD = 998244353
f = [0, 1]
for v in range(2,80000+1):
        f.append((MOD-MOD//v)*f[MOD % v]%MOD)
def height(n,m):  
    h,t=0,1
    m%=MOD
    for i in range(1,n+1): 
        t=t*(m-i+1)*f[i]%MOD
        h=(h+t)%MOD
    return h%MOD
