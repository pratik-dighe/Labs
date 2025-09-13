import heapq

class node:
    def __init__(self, freq, symbol, left=None, right=None):
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right
        self.huff = ""
    
    def __lt__(self, other):
        return self.freq < other.freq
    
def printNodes(node, val=""):
    newval = val + node.huff
    if node.left:
        printNodes(node.left, newval)
    if node.right:
        printNodes(node.right, newval)
    else:
        print(f"{node.symbol} -> {newval}")

chars = ["a", "b", "c", "d", "e", "f"]
freqs = [5, 9, 12, 13, 16, 45]
nodes = []

for i in range(len(chars)):
    heapq.heappush(nodes, node(freqs[i], chars[i]))

while len(nodes) > 1:
    left = heapq.heappop(nodes)
    right = heapq.heappop(nodes)
    left.huff = "0"
    right.huff = "1"
    newnode = node(left.freq + right.freq, left.symbol + right.symbol, left, right)
    heapq.heappush(nodes, newnode)

printNodes(nodes[0])

'''
Huffman Codes:
Huffman Coding is a compression algorithm used to reduce the size 
of data by encoding it with variable-length codes based on character frequency.

Huffman codes provide a method of encoding data efficiently. 
Normally when characters are coded using standard codes like ASCII or the Unicode, 
each character is represented by a fixed-length codeword of bits (e.g., 8 or 16 bits per character).

1 node Class:
Represents each character with its frequency and binary code path (huff).
__lt__ method enables comparison between nodes based on frequency, which heapq needs for sorting.

2 printNodes Function:
Recursively prints each character and its Huffman code.
Traverses the binary tree built by the algorithm to determine each character's code.

3 Main Logic:
Creates nodes for each character with freqs as the frequency list.
Adds nodes to a heap (nodes), which keeps the smallest frequencies at the top.
Repeatedly combines two smallest nodes, assigns "0" and "1" to their paths, and creates a new node with combined frequency.
This forms a binary tree where each path to a leaf node (character) is its Huffman code.

4 Final Output:
Calls printNodes to display each character's Huffman code.
'''