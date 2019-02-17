def f(th):
    A2 = L3*cos(th)-x1
    B2 = L3*sin(th)
    A3 = L2*cos(th+gam) - x2
    B3 = L2*sin(th+gam) - y2
    D = 2*(A2*B3-B2*A3)
    if D == 0:
        raise ValueError("D is 0")
    N1 = B3*(p2**2-p1**2-A2**2-B2**2)
    N1 -= B2*(p3**2-p1**2-A3**2-B3**2)
    N2 = A2*(p3**2-p1**2-A3**2-B3**2)
    N2 -= A3*(p2**2-p1**2-A2**2-B2**2)
    return (N1**2+N2**2-p1**2*D**2).n()

def g(x1, x2, y2, L1, L2, L3, gam, p1, p2, p3):
    def f(th):
        A2 = L3*cos(th)-x1
        B2 = L3*sin(th)
        A3 = L2*cos(th+gam) - x2
        B3 = L2*sin(th+gam) - y2
        D = 2*(A2*B3-B2*A3)
        if D == 0:
            raise ValueError("D is 0")
        N1 = B3*(p2**2-p1**2-A2**2-B2**2)
        N1 -= B2*(p3**2-p1**2-A3**2-B3**2)
        N2 = A2*(p3**2-p1**2-A3**2-B3**2)
        N2 -= A3*(p2**2-p1**2-A2**2-B2**2)
        return (N1**2+N2**2-p1**2*D**2).n()
    return f

def plotter(x1, x2, y2, L1, L2, L3, x, y, th, gam):
    res = circle((0,0),0.025,fill=True,rgbcolor=(0,0,1))
    res += circle((x1,0),0.025,fill=True,rgbcolor=(0,0,1))
    res += circle((x2,y2),0.025,fill=True,rgbcolor=(0,0,1))
    res += circle((x,y),0.025,fill=True,rgbcolor=(0,0,1))
    res += circle((x+L3*cos(th),y+L3*sin(th)),0.025,fill=True,rgbcolor=(0,0,1))
    res += circle((x+L2*cos(th+gam),y+L2*sin(th+gam)),0.025,fill=True,rgbcolor=(0,0,1))
    res += line([(0,0),(x,y),(x+L2*cos(th+gam),y+L2*sin(th+gam))],rgbcolor=(0,0,1))
    res += line([(x1,0),(x+L3*cos(th),y+L3*sin(th)),(x,y)],rgbcolor=(0,0,1))
    res += line([(x2,y2),(x+L2*cos(th+gam),y+L2*sin(th+gam)),(x+L3*cos(th),y+L3*sin(th))],rgbcolor=(0,0,1))
    return res

def xyfromth(x1, x2, y2, L1, L2, L3, gam, p1, p2, p3, th):
    A2 = L3*cos(th)-x1
    B2 = L3*sin(th)
    A3 = L2*cos(th+gam) - x2
    B3 = L2*sin(th+gam) - y2
    D = 2*(A2*B3-B2*A3)
    if D == 0:
        raise ValueError("D is 0")
    N1 = B3*(p2**2-p1**2-A2**2-B2**2)
    N1 -= B2*(p3**2-p1**2-A3**2-B3**2)
    N2 = A2*(p3**2-p1**2-A3**2-B3**2)
    N2 -= A3*(p2**2-p1**2-A2**2-B2**2)
    return (N1/D).n(), (N2/D).n()

def find_all_roots(f, a, b, eps=0.0000000001):
    roots = []
    intervals_to_check = [(a,b)]
    while intervals_to_check:
        start, end = intervals_to_check.pop()
        try:
            root = find_root(f, start, end)
        except RuntimeError:
            continue
        if root in roots:
            continue
        if abs(f(root)) < 1:
            roots.append(root)
        intervals_to_check.extend([(start, root-eps), (root+eps, end)])
    roots.sort()
    return roots

