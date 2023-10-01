from math import sqrt
def is_prime(n):
    if n == 2 or n == 3: return True
    if n < 2 or n % 2 == 0 or n % 3 == 0: return False
    for k in range(5, int(sqrt(int(n))+1), 2):
        if n % int(k) == 0: return False
    return True


def sum_primes(num):
    total = 0
    for k in range(num+1):
        if is_prime(k):
            total = total + k

    return total

n = input("Enter an integer\n")
if(n.isdigit()):
    print(n, end="")
    print(" is",end="")
    if is_prime(int(n)) == False:
        print(" not", end="")
    print(" prime!")
    print("The sum of primes from 2 to", n, "is ", end="")
    print(sum_primes(int(n)))

else:
    print("Input was not integer")

