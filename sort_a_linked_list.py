__author__ = 'jaideepbajwa'
class Node:
    def __init__(self, data):
        self.value = data
        self.nextNode = None

def printList (n):
    while n != None:
        print("{}".format(n.value))
        n = n.nextNode

def sortList (n):
    pass

if __name__ == '__main__':
    # Create a linked list from the number of sequence
    # provided in stdin
    userInput = raw_input('Enter the sequence of number that you want to sort: ')
    numSeq = userInput.split(" ")

    print("You entered following list \n {} ".format(numSeq))
    n = Node(numSeq[0])
    head = n
    for i in numSeq[1:]:
        n.nextNode = Node(i)
        n = n.nextNode

    n.nextNode = None

    print("Printing List \n")
    printList(head)

    b = sortList(head)

    print("Sorted List \n")
    printList(b)




