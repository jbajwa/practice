__author__ = 'jaideep'
class QuickFind:
    count =0
    list1 = []
    def __init__(self):
        self.count = 0
        list1 = []

    def __init__(self,N):
        self.list1 = [x for x in range(N) ]

    def connected(self,x,y):
        if (self.list1[x] == self.list1[y]):
            return True
        return False

    def union(self,x,y):
        if (self.connected(x,y)):
            return
        z = self.list1[x]
        for x in range(len(self.list1)):
            if (self.list1[x] == z):
                self.list1[x] = self.list1[y]
        self.count -= 1


if __name__ == '__main__':
    qf = QuickFind(10)
    p = [3,4,8,2,5,2,5,7,4,5,0,6]
    q = [4,9,0,3,6,9,9,3,8,6,2,1]
    print "p q   {} ".format(str(qf.list1)[1:-1])
    for x in range (len(p)):
        if (qf.connected(p[x], q[x])):
            continue
        qf.union(p[x] , q[x])
        print "{} {}   {} ".format(p[x], q[x], str(qf.list1)[1:-1])

    print "Component {} ".format(qf.count)
        