__author__ = 'jaideepbajwa'
class Node:
    def __init__(self, data):
        self.value = data
        self.nextNode = None

def printList (n):
    if n is None:
        return

    while n.nextNode != None:
        n = n.nextNode
        print("{}".format(n.value))


def sortList (n):
    if n is None:
        return None
    # Creating a new linked list to store element in sorted order
    headsort  = Node(-1)
    headsort.nextNode = None
    while n.nextNode != None:
        sortn = headsort
        prevn = n
        n = n.nextNode
        nextn = n.nextNode
        # removing n
        prevn.nextNode = nextn
        copyn = Node (n.value)

        while True:
            #If the last element add at 2nd last position
            if sortn.nextNode is None:
                sortn.nextNode = copyn
                copyn.nextNode = None
                break
            prevn = sortn
            sortn = sortn.nextNode
            if copyn.value < sortn.value:
                prevn.nextNode = copyn
                copyn.nextNode = sortn
                break

    return headsort

if __name__ == '__main__':
    # Create a linked list from the number of sequence
    # provided in stdin
    userInput = raw_input('Enter the sequence of number that you want to sort: ')
    numSeq = userInput.split(" ")

    print("You entered following list \n {} ".format(numSeq))
    n = Node(numSeq[0])
    head = Node(-1)
    head.nextNode = n
    for i in numSeq[1:]:
        n.nextNode = Node(i)
        n = n.nextNode

    n.nextNode = None

    print("Printing List \n")
    printList(head)

    b = sortList(head)

    print("Sorted List \n")
    printList(b)




