__author__ = 'jaideep'
class QuickUnion:
    count = 0
    list1 = []
    def __init__(self, N):
        self.count = 0
        self.list1 = [ x for x in range (N)]

    def connected(self,x,y):
        if self.root(x) == self.root(y):
            return True
        return False

    def union(self, x, y):
        a = self.root(x)
        b = self.root(y)
        if a == b:
            return
        self.list1[a] = b
        self.count -= 1

    def root(self, x):
        while x != self.list1[x]:
            x= self.list1[x]
        return x


if __name__ == '__main__':
    qf = QuickUnion(10)
    p = [3,4,8,2,5,2,5,7,4,5,0,6]
    q = [4,9,0,3,6,9,9,3,8,6,2,1]
    print("p q   {} ".format(str(qf.list1)[1:-1]))
    for x in range (len(p)):
        if qf.connected(p[x], q[x]):
            continue
        qf.union(p[x] , q[x])
        print("{} {}   {} ".format(p[x], q[x], str(qf.list1)[1:-1]))

    print("Component {} ".format(qf.count))