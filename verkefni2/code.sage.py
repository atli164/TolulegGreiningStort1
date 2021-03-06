
# This file was *autogenerated* from the file code.sage
from sage.all_cmdline import *   # import sage library

_sage_const_3 = Integer(3); _sage_const_2 = Integer(2); _sage_const_1 = Integer(1); _sage_const_0 = Integer(0); _sage_const_2p7 = RealNumber('2.7'); _sage_const_4 = Integer(4); _sage_const_100 = Integer(100); _sage_const_4p7 = RealNumber('4.7'); _sage_const_1p5 = RealNumber('1.5'); _sage_const_14p1 = RealNumber('14.1'); _sage_const_8p1 = RealNumber('8.1'); _sage_const_0p3 = RealNumber('0.3'); _sage_const_3p9 = RealNumber('3.9'); _sage_const_0p5 = RealNumber('0.5'); _sage_const_10 = Integer(10); _sage_const_7p8 = RealNumber('7.8'); _sage_const_0p9 = RealNumber('0.9'); _sage_const_1p8 = RealNumber('1.8')# Constants given in exercise
def px(t):
    return _sage_const_0p5  + _sage_const_0p3  * t + _sage_const_3p9  * t ** _sage_const_2  - _sage_const_4p7  * t ** _sage_const_3 

def py(t):
    return _sage_const_1p5  + _sage_const_0p3  * t + _sage_const_0p9  * t ** _sage_const_2  - _sage_const_2p7  * t ** _sage_const_3 

def dpx(t):
    return _sage_const_0p3  + _sage_const_7p8  * t - _sage_const_14p1  * t ** _sage_const_2 

def dpy(t):
    return _sage_const_0p3  + _sage_const_1p8  * t - _sage_const_8p1  * t ** _sage_const_2 

def c1(s):
    return s

def c2(s):
    return s ** (_sage_const_1  / _sage_const_3 )

def c3(s):
    return s ** _sage_const_2 

def c4(s):
    return sin(s * pi / _sage_const_2 )

def c5(s):
    return (_sage_const_1  + sin((_sage_const_2  * s - _sage_const_1 ) * pi / _sage_const_2 )) / _sage_const_2 

cfuncs = [c1, c2, c3, c4, c5]

# Tools to solve
def adaptquad(f, ac, bc, t, ao, bo):
    def appr(x, y):
        return (y - x) * (f(x) + f(y)) / _sage_const_2 
    c = (ac + bc) / _sage_const_2 
    sab = appr(ac, bc)
    sac = appr(ac, c)
    sbc = appr(c, bc)
    ct = _sage_const_3  * t * (bc - ac) / (bo - ao)
    if abs(sab - sac - sbc) < ct:
        return sac + sbc
    else:
        s1 = adaptquad(f, ac, c, t, ao, bo)
        s2 = adaptquad(f, c, bc, t, ao, bo)
        return s1 + s2

def arclen(dx, dy, T, tol):
    def f(x):
        return sqrt(dx(x) ** _sage_const_2  + dy(x) ** _sage_const_2 )
    return adaptquad(f, _sage_const_0 , T, tol, _sage_const_0 , T)

def bissearch(dx, dy, tol, s, c):
    alen = arclen(dx, dy, _sage_const_1 , tol)
    def f(x):
        return arclen(dx, dy, x, tol) - c(s) * alen
    lo, hi = _sage_const_0 , _sage_const_1 
    while hi - lo >= tol:
        mid = (hi + lo) / _sage_const_2 
        if f(mid) < _sage_const_0 :
            lo = mid
        else:
            hi = mid
    return (hi + lo) / _sage_const_2 


# C1: Virkar ekki, synist vera thvi vegurinn er ekki fall?
def newtsearch(dx, dy, tol, s, c):
    alen = arclen(dx, dy, _sage_const_1 , tol)
    def f(x):
        return arclen(dx, dy, x, tol) - c(s) * alen
    def df(x):
        return sqrt(dx(x) ** _sage_const_2  + dy(x) ** _sage_const_2 ) - sqrt(dx(_sage_const_0 ) ** _sage_const_2  - dy(_sage_const_0 ) ** _sage_const_2 )
    if c(s) > _sage_const_0 :
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
    pl = parametric_plot((x(t), y(t)), (t, _sage_const_0 , _sage_const_1 ))
    for i in range(n):
        pos = bissearch(dx, dy, tol, i / (n - _sage_const_1 ), c) # newtsearch($SAMEARGS)
        pl += point((x(pos), y(pos)))
        pl.save(name + '.png')
"""
plotequi(px, py, dpx, dpy, 10 ** (-4), 4, c1, '4pt')

for ci in range(len(cfuncs)):
    plotequi(px, py, dpx, dpy, 10 ** (-4), 20, cfuncs[ci], '20pt' + str(ci))
"""
def frameplot(x, y, dx, dy, tol, n, c, name, xb, yb):
    listi = []
    var('t') # enga hugmynd hvad thetta gerir, en kemur ekki ad sok.
    pl = parametric_plot((x(t), y(t)), (t, _sage_const_0 , _sage_const_1 ),figsize=[_sage_const_3 ,_sage_const_4 ],
                            aspect_ratio=_sage_const_1 ,xmin=xb[_sage_const_0 ],
                            xmax=xb[_sage_const_1 ], ymin=yb[_sage_const_0 ],ymax=yb[_sage_const_1 ])
    for i in range(n):
        pos = bissearch(dx, dy, tol, i / (n - _sage_const_1 ), c)
        listi.append(point((x(pos), y(pos)),figsize=[_sage_const_3 ,_sage_const_4 ],
                     aspect_ratio=_sage_const_1 ,xmin=xb[_sage_const_0 ],
                     xmax=xb[_sage_const_1 ], ymin=yb[_sage_const_0 ],ymax=yb[_sage_const_1 ]))
    a = animate(listi)
    a.gif(savefile=name+'.gif', show_path=True)
        #pl.save(name + '_frame' + str(i//10)+str(i%10) + '.png')

# frameplot(px,py,dpx,dpy,10 ** (-4), 100, c1, 'curve1', (0,1.5), (0,2.0))


def punktskra(x,y,dx,dy,tol,n,c):
    for i in range(n):
        pos = bissearch(dx,dy,tol, i/(n-_sage_const_1 ), c)
        print(x(pos), y(pos))

punktskra(px,py,dpx, dpy, _sage_const_10  ** (-_sage_const_4 ), _sage_const_100 , c1)

