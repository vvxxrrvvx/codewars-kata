def lp(x):
    t=1
    while t<x:
        t<<=1
    return t

def rs(l,r):
    return (l+r)*(r-l+1)//2

def elder_age(m,n,l,t):
    if m==0 or n==0:
        return 0
    if m>n:
        m,n=n,m
    lm,ln=lp(m),lp(n)
    if l>ln:
        return 0
    if lm == ln:
        return (rs(1,ln-l-1)*(m+n-ln)+elder_age(ln-n,lm-m,l,t))% t
    
    if lm<ln:
        lm = ln//2
        tmp = rs(1,ln-l-1)*m-(ln-n)*rs(max(0,lm-l),ln-l-1)
        if l <= lm:
            tmp+=(lm-l)*(lm-m)*(ln-n)+elder_age(lm-m,ln-n,0,t)
        else:
            tmp += elder_age(lm-m,ln-n,l-lm,t)
        return tmp%t
