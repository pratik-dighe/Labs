# Function to calculate Fibonacci number using recursion
def fibonacci_recursive(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)

# Function to calculate Fibonacci number using iteration (dynamic programming)
def fibonacci_iterative(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1

    fib = [0] * (n + 1)
    fib[1] = 1

    for i in range(2, n + 1):
        fib[i] = fib[i - 1] + fib[i - 2]

    return fib[n]

# Function to count the number of steps needed to calculate a Fibonacci number using recursion
def count_steps_recursive(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return 1 + count_steps_recursive(n - 1) + count_steps_recursive(n - 2)

# Function to count the number of steps needed to calculate a Fibonacci number using iteration
def count_steps_iterative(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1

    steps = [0] * (n + 1)
    steps[1] = 1

    for i in range(2, n + 1):
        steps[i] = 1 + steps[i - 1] + steps[i - 2]

    return steps[n]

# Input the desired Fibonacci number 'n'
n = int(input("Enter the value of n: "))

# Calculate and print the Fibonacci number using recursion
fib_recursive = fibonacci_recursive(n)
print(f"Fibonacci number (Recursive) for n = {n}: {fib_recursive}")

# Calculate and print the number of steps needed using recursion
steps_recursive = count_steps_recursive(n)
print(f"Number of steps (Recursive) to calculate Fibonacci number for n = {n}: {steps_recursive}")

# Calculate and print the Fibonacci number using iteration
fib_iterative = fibonacci_iterative(n)
print(f"Fibonacci number (Iterative) for n = {n}: {fib_iterative}")

# Calculate and print the number of steps needed using iteration
steps_iterative = count_steps_iterative(n)
print(f"Number of steps (Iterative) to calculate Fibonacci number for n = {n}: {steps_iterative}")

def generate_fibonacci_sequence(n):
    if n <= 0:
        return []
    
    fibonacci_sequence = []
    a, b = 0, 1
    
    while a <= n:
        fibonacci_sequence.append(a)
        a, b = b, a + b
    
    return fibonacci_sequence

# Generate and print the list of Fibonacci numbers up to 'n'
fib_sequence = generate_fibonacci_sequence(n)
print(f"Fibonacci sequence up to {n}: {fib_sequence}")

'''
Fibonacci Series using Iteration and Recursion
// Iteration :
// Time Complexity = O(N)
// Space Complexity : O(1)
// Recursion :
// Time Complexity : O(1.618^N)
// Space Complexity : O(N) due to Auxilliary Stack Space
// Time Complexity is derived using Binet's Formula
// Time Complexity = 1/root(5)*[(1+root(5)/2)^n-(1-root(5)/2)^n]

The Fibonacci series is a sequence of numbers where each number is the sum of the two preceding ones, 
typically starting with 0 and 1
0,1,1,2,3,5,8,13,21,34,…

Each term is calculated as: F(n) = F(n-1) + F(n-2)

with the initial conditions: F(0) = 0 and F(1) = 1

Example:
F(2)=F(1)+F(0)=1+0=1
F(3)=F(2)+F(1)=1+1=2
F(4)=F(3)+F(2)=2+1=3
F(5)=F(4)+F(3)=3+2=5

Recursion: 
A function calls itself to solve smaller instances of the same problem until a base condition is met. 
It breaks down problems into simpler sub-problems, often resulting in a function stack.

Iteration: 
A set of instructions repeatedly executes within a loop (e.g., for, while) until a condition is no longer met. 
It directly repeats tasks without additional function calls.
'''