class Node:
    def __init__(self,value,next=None):
        self.value = value
        self.next = None


def insertItemHead(argList,newValue):
    newNode = Node(newValue)
    newNode.value = newValue
    newNode.value = argList.value

    argList.value = newNode




if __name__ == "__main__":


    #Lista com cabeça
    newNode = Node(5)
    insertItemHead(newNode,6)
    print(vars(newNode))
