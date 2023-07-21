def team_dinner(available:list[list[int]]) -> int | None:
    xz = [set(l) for l in available]
    dp = {d for l in available for d in l}
    dance = {d: [len(a) for a in xz if d in a] for d in dp if 2 * len([len(a) for a in xz if d in a]) >= len(available)}
    return max(dance, key=lambda x: (len(dance[x]), sum(dance[x]), -x), default=None)