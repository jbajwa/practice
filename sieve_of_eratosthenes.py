__author__ = 'jaideepbajwa'


def Printprime(N):
    #initialise everything to True
    list1 = [True] * N
    for x in range(2,N):
        y= 2
        while ((x*y) < N):
            # if already set then we continue to next element
            if list1[x * y] == False:
                y += 1
                continue
            # set False to all the multiple of current index , but not itself hence
            # we start with y =2
            list1[x * y] = False
            y += 1

    for x in range(1,N):
        if list1[x] is True:
            print (x)


if __name__ == '__main__':
    Printprime(100)
