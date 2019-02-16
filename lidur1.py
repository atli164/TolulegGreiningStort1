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
    return N1**2+N2**2-p1**2*D**2
