__author__ = 'jaideep'
class Node:
    def __init__(self, data):
        self.value = data
        self.nextNode = None

if __name__ == '__main__':
    # creating a circular linked list
    N = 9
    M = 5
    head = Node(1)
    n = head
    for i in range (2,N+1):
        n.nextNode = Node(i)
        n = n.nextNode
    n.nextNode = head
    n = head
    # printing the list
    while n.nextNode != head:
        print (" {} ".format(n.value))
        n = n.nextNode
    print (" {} ".format(n.value))
    # here n points to the last element of the list, where
    # n.nextNode = head
    while n != n.nextNode:
        # jump M-1 element and del the Mth element
        for i in range(M-1):
            n = n.nextNode
        print("removing node {}".format(n.nextNode.value))
        n.nextNode = n.nextNode.nextNode
    #last remaining element
    print ("\nnode left {}".format(n.value))


