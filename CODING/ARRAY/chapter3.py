## Q2 ##implement power function for every integer

# def power_fun(b,n):
#     if(n==0):
#         return 1
#     if(n==-1):
#         return 1/b
#     if(n%2==0):
#         return power_fun(b,n//2)**2
#     else:
#         return b*power_fun(b,n//2)**2



# print(power_fun(10,-5))

########################################################

## Q3 ## matrix exponentiation

# import numpy as np
# def matrix_exp(matrix,n):
#     if(n==0):
#         return np.eye(matrix.shape[0],matrix.shape[1],dtype=int)
#     if (n==1):
#         return matrix
#     if(n%2)==0:
#         return np.dot(matrix_exp(matrix,n//2),matrix_exp(matrix,n//2))
#     else:
#         return np.dot(np.dot(matrix_exp(matrix,n//2)^2,matrix_exp(matrix,n//2)^2),matrix)



# mat=np.arange(4).reshape(2,2)
# print(mat)
# print(np.dot(mat,mat)) 
# print(matrix_exp(mat,2))

#################################

## Q4 #################################

# def slow_multiplication(a,b):
#     if(a==1 or b==1):
#         return max(a,b)
#     else:
#         return slow_multiplication(a-1,b-1)+a+(b-1)

# print(slow_multiplication(12,10))

## Q7 #####################################
# def number_of_digits(n):
#     if(n<10):
#         return 1
#     else:
#         return number_of_digits(n//10)+1


# print(number_of_digits(141412121))

## Q8 ##################################
# def binary_to_decimal(n):
#     if(n<2):
#         return n
#     else:
#         return binary_to_decimal(n//10)*2+n%10

# print(binary_to_decimal(100101))

## Q10 #####################
# def least_significant_bit_pos(n):
#     if n%10==1:
#         return 1
#     else:
#         return least_significant_bit_pos(n//10)+1
    

# print(least_significant_bit_pos(101100001010101010100100101011000000))

## Q12 ####################
# def no_of_vowels_in_string(s):
#     vowles=['a','e','i','o','u']
#     if len(s)==1:
#         if(s in vowles):
#             return 1
#         else:
#             return 0
#     x=0
#     if(s[0] in vowles):
#         x=1
#     else:
#         x=0

#     return no_of_vowels_in_string(s[1:])+x


# print(no_of_vowels_in_string("aejiokul"))

## Q 13 ######################################
#part 1 ### decrementing n by 1 unit#########
# def nCr1(n,r):
#     if(n==r):
#         return 1
#     return (nCr1(n-1,r)*n)//(n-r)

# print(nCr1(10,0))

# #part 2 ## decrementing r by 1 unit##
# def nCr2(n,r):
#     if(r==0):
#         return 1
#     else:
#         return ((nCr2(n,r-1))*(n-r+1))//r

# print(nCr2(10,2))

# ## part 3 ## decrementing n and r both
# def nCr3(n,r):
#     if(r>n):
#         raise Exception("cannot calculate if r>n")
#     if(n==r or r==0):
#         return 1
#     else:
#         return (nCr3(n-1,r-1)*n)//r

# print(nCr3(2,5))


# Q14 #################################################

# def find(pascal):
#     if(len(pascal)<2):
#         return pascal
#     if(len(pascal)==2):
#         return [sum(pascal)]
#     return [pascal[0]+pascal[1]]+find(pascal[1:])


# def nth_row_of_pascal_triangle(n):
#     if(n==1):
#         return [1]
#     else:
#         row=[1]
#         pascal=nth_row_of_pascal_triangle(n-1)
#         intermediate_pascal_value=find(pascal)
#         if(len(pascal)>1):
#             row+=intermediate_pascal_value
#         # for i in range(len(pascal)-1):
#         #     row.append(pascal[i]+pascal[i+1])
        
#         row.append(1)
#         return row

# for i in range(1,10):
#     print(nth_row_of_pascal_triangle(i))


######### Q15###########################
# def inserting_pos(n,x):
#     if len(str(n))==1:
#         if(x>n):
#             return 2
#         else:
#             return 1

#     if ((n%10) <= x):
#         return len(str(n))+1
#     else:
#         return inserting_pos(n//10,x)


# print(inserting_pos(1144455577777,6))   
#########################################
## Q16 ##################################
def inserting(n,x):
    if(len(str(n))==1):
        if(x>n):
            return int(str(n)+str(x))
        else:
            return int(str(x)+str(n))
    if((n%10)<=x):
        return int(str(n)+str(x))
    else:
        return int(str(inserting(n//10,x))+str(n%10))

print(inserting(114445557777,9))

## Q17 #########################

