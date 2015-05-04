__author__ = 'jaideepbajwa'


class Node:
    def __init__(self, data):
        self.value = data
        self.nextNode = None


def Reverselist(n):
    # reverse my list here
    y = n.nextNode
    n.nextNode = None
    while y!= None:
        t= y.nextNode
        y.nextNode = n
        n= y
        y = t
    return n

def printList (n):
    while n != None:
        print("{}".format(n.value))
        n = n.nextNode

if __name__ == '__main__':
    # create a linked list

    N = 10
    head = Node(1)
    n = head
    for i in range(2, N):
        n.nextNode = Node(i)
        n = n.nextNode
    n.nextNode = None
    # print the linked list
    print ("printing list \n")
    printList(head)

    # give head to reverse list function
    newHead = Reverselist(head)

    print ("printing reverse list \n")
    printList(newHead)












