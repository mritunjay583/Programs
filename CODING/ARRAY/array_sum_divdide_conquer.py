

#sum of elements of a list using divide and conquer
def divide_sum(arr):
    if len(arr)==1:
        return arr[0]
    mid=(0+len(arr))//2
    num1=divide_sum(arr[:mid])
    num2=divide_sum(arr[mid:])
    return num1+num2


#Nested recursion
#sum of digits recursively
def add_digits(n):
    if(n<10):
        return n
    else:
        #or you can do :  
        #res=add_digits(n//10+n%10)
        #return add_digits(res)
        return add_digits(add_digits(n//10)+n%10)


#sum of n natural  numbers
def sum_to_n(n):
    if n==1:
        return 1
    else:
        if n%2==0:
            return 2*sum_to_n(n//2)+(n//2)**2
        else:
            return 2*sum_to_n(n//2)+(n//2)**2+n
    
#power function
def power_function(x,n):
    if(n==0):
        return 1
    else:
        if(n%2==0):
            return power_function(x,n//2)**2
        else:
            return power_function(x,n//2)**2*x

#max of a list
def max_of_list(l):
    if(len(l)==1):
        return l[0]
    else:
        left_max=max_of_list(l[:len(l)//2])
        righ_max=max_of_list(l[len(l)//2:])
        return max(left_max,righ_max)

import math
#finding setbits in a number recursively
def set_bits(n):
    if n==0:
        return 0
    elif(n==1):
        return 1
    return set_bits(n//2)+n%2

#printing digts of a number vertically

def print_number_vertically(n):
    if(n<10):
        print(n)
    else:
        print(n//10**math.floor(math.log10(n)))
        print_number_vertically(n%10**math.floor(math.log10(n))) 

#reversing strings using recursion
def reverse_string(s):
    if len(s)==1:
        return s
    else:
        s=reverse_string(s[1:])+s[0]
        return s

import time 
t=time.time()
print(reverse_string("sahil"))
# time.sleep(1)
elapsed_time=time.time()-t
print(time.sleep(1))
print(elapsed_time)
# print(print_number_vertically(12345))
# print(set_bits(15))
# print(max_of_list([4,2,5,8,100,9,0,34,7,23,64,21,31,45]))
# print(power_function(2,10))
# print(sum_to_n(10))
# print(add_digits(9299))
