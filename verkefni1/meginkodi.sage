# Liður 2 aukakóði

h = g(4, 0, 4, 2, sqrt(2), sqrt(2), pi/2, sqrt(5), sqrt(5), sqrt(5))
plot(h, (-pi,pi))

# Liður 3 aukakóði

plotter(4, 0, 4, 2, sqrt(2), sqrt(2), 2, 1, pi/4, pi/2)
plotter(4, 0, 4, 2, sqrt(2), sqrt(2), 1, 2, -pi/4, pi/2)

# Liður 4 aukakóði

h = g(5, 0, 6, 3, 3*sqrt(2), 3, pi/4, 5, 5, 3)
plot(h, (-pi,pi))

r = find_all_roots(g(5, 0, 6, 3, 3*sqrt(2), 3, pi/4, 5, 5, 3), -pi, pi)

xys = [xyfromth(5, 0, 6, 3, 3*sqrt(2), 3, pi/4, 5, 5, 3, k) for k in r]

for i in range(len(r)):
    plotter(5, 0, 6, 3, 3*sqrt(2), 3, xys[i][0], xys[i][1], r[i], pi/4)

# Liður 5 aukakóði

h = g(5, 0, 6, 3, 3*sqrt(2), 3, pi/4, 5, 7, 3)
plot(h, (-pi,pi))

r = find_all_roots(g(5, 0, 6, 3, 3*sqrt(2), 3, pi/4, 5, 7, 3), -pi, pi)

xys = [xyfromth(5, 0, 6, 3, 3*sqrt(2), 3, pi/4, 5, 7, 3, k) for k in r]

for i in range(len(r)):
    plotter(5, 0, 6, 3, 3*sqrt(2), 3, xys[i][0], xys[i][1], r[i], pi/4)

# Liður 7 aukakóði

plot(solsnumfromp2(5, 0, 6, 3, 3*sqrt(2), 3, pi/4, 5, 3), 0, 20)

curh = solsnumfromp2(5, 0, 6, 3, 3*sqrt(2), 3, pi/4, 5, 3)
curv = curh(0)
changes = []
for i in range(1000):
    nxtv = curh((i + 1) / 100)
    if nxtv != curv:
        changes.append((i / 100), (i + 1) / 100))
    curv = nxtv

exactchanges = [float("-inf")]
for c in changes:
    lpos, rpos = c[0], c[1]
    lval, rval = curh(lpos), curh(rpos)
    while rpos - lpos > 1e-9:
        mpos = ((lpos + rpos) / 2).n()
        mval = curh(mpos)
        if mval == lval:
            lpos = mpos
        else:
            rpos = mpos
    exactchanges.append((lpos + rpos) / 2)
exactchanges.append(float("inf"))

intervals = []
for i in range(len(exactchanges) - 1):
    intervals.append(((exactchanges[i], exactchanges[i + 1]), curh((exactchanges[i] + exactchanges[i + 1]) / 2)))
