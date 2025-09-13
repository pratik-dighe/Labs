class Item:
    def __init__(self, profit, weight):
        self.profit = profit
        self.weight = weight

def fractionalKnapsack(w, arr):
    arr.sort(key=lambda x: x.profit/x.weight, reverse=True)
    finalValue = 0.0
    for item in arr:
        if w >= item.weight:
            finalValue += item.profit
            w -= item.weight
        else:
            finalValue += item.profit * (w/item.weight)
            break
    return finalValue

if __name__ == "__main__":
    n = int(input("Enter number of items-\n"))
    arr = []
    for i in range(n):
        profit = int(input("Enter profit of item " + str(i + 1) + "-\n"))
        weight = int(input("Enter weight of item " + str(i + 1) + "-\n"))
        arr.append(Item(profit, weight))
    w = int(input("Enter capacity of knapsack-\n"))
    print("Maximum value in knapsack: ", fractionalKnapsack(w, arr))
    
''' 
If the provided items are already sorted into a decreasing order of piwipiwi,
then the whileloop takes a time in O(n); 
Therefore, the total time including the sort is in O(n logn).

Ex:
capacity of the knapsack W = 60

Item        A   B   C   D
Profit     280 100 120 120
Weight     40   10 20  24
Ratio (piwi)/(piwi) 7 10 6 5

Solution
After sorting all the items according to piwipiwi. First all of B is chosen as weight of B is less than the capacity of the knapsack. Next, item A is chosen, as the available capacity of the knapsack is greater than the weight of A. Now, C is chosen as the next item. However, the whole item cannot be chosen as the remaining capacity of the knapsack is less than the weight of C.
Hence, fraction of C (i.e. (60 − 50)/20) is chosen.
Now, the capacity of the Knapsack is equal to the selected items. Hence, no more item can be selected.
The total weight of the selected items is 10 + 40 + 20 * (10/20) = 60
And the total profit is 100 + 280 + 120 * (10/20) = 380 + 60 = 440
This is the optimal solution. We cannot gain more profit selecting any different combination of items.


#The Knapsack Problem is a problem where you have a bag (or knapsack) with a limited capacity, 
#and you need to decide which items to put in the bag to maximize their total value or profit.
'''