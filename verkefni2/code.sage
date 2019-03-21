# Constants given in exercise
def px(t):
    return 0.5 + 0.3 * t + 3.9 * t ** 2 - 4.7 * t ** 3

def py(t):
    return 1.5 + 0.3 * t + 0.9 * t ** 2 - 2.7 * t ** 3

def dpx(t):
    return 0.3 + 7.8 * t - 14.1 * t ** 2

def dpy(t):
    return 0.3 + 1.8 * t - 8.1 * t ** 2

def c1(s):
    return s

def c2(s):
    return s ** (1 / 3)

def c3(s):
    return s ** 2

def c4(s):
    return sin(s * pi / 2)

def c5(s):
    return (1 + sin((2 * s - 1) * pi / 2)) / 2

cfuncs = [c1, c2, c3, c4, c5]

# Tools to solve
def adaptquad(f, ac, bc, t, ao, bo):
    def appr(x, y):
        return (y - x) * (f(x) + f(y)) / 2
    c = (ac + bc) / 2
    sab = appr(ac, bc)
    sac = appr(ac, c)
    sbc = appr(c, bc)
    ct = 3 * t * (bc - ac) / (bo - ao)
    if abs(sab - sac - sbc) < ct:
        return sac + sbc
    else:
        s1 = adaptquad(f, ac, c, t, ao, bo)
        s2 = adaptquad(f, c, bc, t, ao, bo)
        return s1 + s2

def arclen(dx, dy, T, tol):
    def f(x):
        return sqrt(dx(x) ** 2 + dy(x) ** 2)
    return adaptquad(f, 0, T, tol, 0, T)

def bissearch(dx, dy, tol, s, c):
    alen = arclen(dx, dy, 1, tol)
    def f(x):
        return arclen(dx, dy, x, tol) - c(s) * alen
    lo, hi = 0, 1
    while hi - lo >= tol:
        mid = (hi + lo) / 2
        if f(mid) < 0:
            lo = mid
        else:
            hi = mid
    return (hi + lo) / 2


# C1: Virkar ekki, synist vera thvi vegurinn er ekki fall?
def newtsearch(dx, dy, tol, s, c):
    alen = arclen(dx, dy, 1, tol)
    def f(x):
        return arclen(dx, dy, x, tol) - c(s) * alen
    def df(x):
        return sqrt(dx(x) ** 2 + dy(x) ** 2) - sqrt(dx(0) ** 2 - dy(0) ** 2)
    if c(s) > 0:
        x0 = c(s)/alen # c(s)/1 er formengi => giskum c(s)/alen thvi ca. equiv
    else:
        x0 = tol # thetta tilfelli aetti ekki ad thurfa. Sja C1.
    fx0 = f(x0)
    while fx0 > tol:
        x0 -= fx0 / df(x0)
        fx0 = f(x0) # var ad reyna lata thetta ganga oggulitid hradar.
    return x0

def plotequi(x, y, dx, dy, tol, n, c, name):
    var('t')
    pl = parametric_plot((x(t), y(t)), (t, 0, 1))
    for i in range(n):
        pos = bissearch(dx, dy, tol, i / (n - 1), c) # newtsearch($SAMEARGS)
        pl += point((x(pos), y(pos)))
        pl.save(name + '.png')
"""
plotequi(px, py, dpx, dpy, 10 ** (-4), 4, c1, '4pt')

for ci in range(len(cfuncs)):
    plotequi(px, py, dpx, dpy, 10 ** (-4), 20, cfuncs[ci], '20pt' + str(ci))
"""
def frameplot(x, y, dx, dy, tol, n, c, name, xb, yb):
    var('t') # enga hugmynd hvad thetta gerir, en kemur ekki ad sok.
    for i in range(n):
        pl = parametric_plot((x(t), y(t)), (t, 0, 1),figsize=[3,4],
                             aspect_ratio=1,xmin=xb[0],
                             xmax=xb[1], ymin=yb[0],ymax=yb[1], fig_tight=True)
        pos = bissearch(dx, dy, tol, i / (n - 1), c)
        pl += point((x(pos), y(pos)))
        pl.save(name + '_frame' + str(i//10)+str(i%10) + '.png')

frameplot(px,py,dpx,dpy,10 ** (-4), 100, c1, 'curve1', (0,1.5), (0,2.0))



