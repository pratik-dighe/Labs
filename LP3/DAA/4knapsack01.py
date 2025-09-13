import collections

Item = collections.namedtuple('Item', ['profit', 'weight'])

def Knapsack(arr, n, w):
    if(n == 0 or w == 0):
        return 0
    if(arr[n-1].weight <= w):
        return max(Knapsack(arr, n-1, w - arr[n-1].weight) + arr[n-1].profit ,
                    Knapsack(arr, n-1, w)                   
                   )
    else:
        return Knapsack(arr, n-1, w)
 
def main():
    #characters for huffman tree & # frequency of characters
    arr = [Item(60, 10), Item(100, 20), Item(120, 30)]
    n = len(arr)
    print(Knapsack(arr, n, 50))

main()

'''
#The Knapsack Problem is a problem where you have a bag (or knapsack) with a limited capacity, 
#and you need to decide which items to put in the bag to maximize their total value or profit.

1 Importing Collections: The collections module provides alternatives to Pythons built-in types. 
Here, it is used to create a namedtuple. which provides alternatives to Python’s built-in types.

2 Defining the Item Structure: It defines Item as a namedtuple with two fields: profit and weight. 
This structure makes it easy to represent each item with its corresponding profit and weight.

3 Defining the Knapsack Function: 
The Knapsack function takes three parameters: arr (a list of items), n (the number of items), 
and w (the maximum weight capacity of the knapsack). 
If there are no items or no capacity, the function returns 0 because there are no items to include.

4 Recursive Cases: If the weight of the last item is less than or equal to the current weight capacity, there are two possibilities:

Include the item: Add its profit to the maximum profit of the remaining items with the reduced weight.
Exclude the item: Consider the maximum profit of the remaining items without including the current item.
The function returns the maximum of these two values.
If the weight of the last item is greater than the current weight capacity, 
the item cannot be included, and the function recursively calls itself for the remaining items without changing the weight capacity.

5 Defining the Main Function: The main function initializes a list of items, 
each represented as Item(profit, weight). 
It includes three items with their respective profits and weights. 
It calculates the number of items and calls the Knapsack function with a maximum weight capacity of 50, 
printing the result (maximum profit).

6 Running the Main Function: Finally, the code calls the main function to execute the knapsack calculation.
'''