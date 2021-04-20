import math
#decimal to binary conversion
def decimal_to_binary(n):
    if(n<2):
        return n
    return decimal_to_binary(n//2)*10+n%2

#decimal to any_b conversion
def decimal_to_anyb(n,b):
    if(n<b):
        return n
    return decimal_to_anyb(n//b,b)*10+n%b


#check string is palindrome or not
def check_palindrome(s):
    if(len(s)==1):
        return True
    if(len(s)==2):
        return s[0]==s[-1]
    else:
        return (s[0]== s[-1]) and check_palindrome(s[1:-1])



#recursive selection sort
def recursive_selection_sort(n):
    if(len(n)<=1):
        return n
    else:   
        b=n
        min_index=n.index(min(n))
        n[0],n[min_index]=n[min_index],n[0]
        return  [n[0]] + recursive_selection_sort(b[1:])

#honours method to evaluate plynomial in linear time
def honours(c,x):
    if(len(c)==1):
        return c[0]
    else:
        return c[0]+x * honours(c[1:],x)

#printing nth row of pascal triangle
def nth_row_of_pascal_triangle(n):
    if n==0:
        return [1]
    else:
        row=[1]
        previous=nth_row_of_pascal_triangle(n-1)
        for i in range(len(previous)-1):
            row.append(previous[i]+previous[i+1])
        row.append(1)
        return row

#ladder fo resistors
def ladder_of_resistors(n,r):
    if(n==1):
        return r
    else:
        return 1/(1/r+1/(ladder_of_resistors(n-1,r)+r))


## 1 ##checking odd or even reducing size of problem by 1 unit
def check_even(n):
    


# print(ladder_of_resistors(2,2))
# for i in range(0,5):
#     print(nth_row_of_pascal_triangle(i))
# print(honours([1,2,3],2))
# print(recursive_selection_sort([4,1,5,1,7,6,2,9,0]))
# print(decimal_to_binary(32))
# print(decimal_to_anyb(10,6))
# print(check_palindrome("422454224"))