count_domains = lambda do, h=0: '\n'.join("{} ({})".format(K, V) for K, V in sorted({
    k: sum(int(e) for _, e in list(l)) for k, l in __import__("itertools").groupby(
        sorted((k, int(v)) for k, _, v in map(lambda d: __import__("re").findall(r'.*?\.?([^.]+(\.com?)?\.\w*)\s+(\d+)', d)[0], do.split('\n'))),
        key=lambda t: t[0]
    )
}.items(), key=lambda t: (-t[1], t[0])) if V >= h)