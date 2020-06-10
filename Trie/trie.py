

class Node:
    def __init__(self, ch):
        self.ch = ch
        self.flag = 0
        self.childs = [0 for x in range(128)]

root = Node(1)

def AddString(str):
    print("Adding: " + str)
    currentNode = root
    
    for i in range(len(str)):
        ch = ord(str[i])
        if currentNode.childs[ch] == 0:
            child = Node(ch)
            #print("create new node " + chr(ch))
            currentNode.childs[ch] = child
        currentNode = currentNode.childs[ch]
    currentNode.flag = 1

def Trivesal(node, str):
    if node.flag == 1:
        print("\tfound " + str + chr(node.ch))
    else:
        for i in range(128):
            if node.childs[i] != 0:
                Trivesal(node.childs[i], str + chr(node.ch))
                
    
def SearchString(str):
    print("Search for: " + str)
    currentNode = root

    for i in range(len(str)):
        ch = ord(str[i])
        if currentNode.childs[ch] == 0:
            print(str +" not found")
            return
        currentNode = currentNode.childs[ch];

    if currentNode.flag == 1:
        print("\tfound " + str )
    for i in range(128):
            if currentNode.childs[i] != 0:
                Trivesal(currentNode.childs[i], str)


AddString("ll")
AddString("lmq")
AddString("lmqa")
SearchString("lmq")



