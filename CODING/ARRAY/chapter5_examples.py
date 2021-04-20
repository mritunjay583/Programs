##################################################################
# 5.1.1 Does a nonnegative integer contain a particular digit?
##################################################################
# def check(n,d):
#     if (d//10)!=0 or d<0:
#         raise Exception("enter a unit digit positive number")
#     if(n//10)==0:
#         return False
#     if(n%10==d):
#         return True
#     else:
#         return check(n//10,d)

# print(check(12314112423,8))


#########################################################################
###### linear search ###############
###########################################################################
# def linear_search(arr,x):
#     if(len(arr)==1):
#         if(arr[0]==x):
#             return True
#         else:
#             return False
#     if(arr[0]==x):
#         return True
#     return linear_search(arr[1:],x)     

# print(linear_search([1,4,23,1,5,2,3,4,6,7],23))


#####################################################################################
### 5.1.4 example ##partioning algorithm #########
######################################################################################

# def get_less_than_equal_to(arr,x):
#     if(len(arr)==0):
#         return []
#     elif(arr[0] <= x):
#         return [arr[0]] + get_less_than_equal_to(arr[1:],x)
#     else:
#         return get_less_than_equal_to(arr[1:],x)

# def get_greater_than(arr,x):
#     if(len(arr)==0):
#         return []
#     elif(arr[0] > x):
#         return [arr[0]] + get_greater_than(arr[1:],x)
#     else:
#         return get_greater_than(arr[1:],x)
    
# def partition(arr,x):
#     if x not in arr:
#         raise Exception("{} is not in list ".format(x))
#     return get_less_than_equal_to(arr,x)+[x]+get_greater_than(arr,x)

# print(partition([6,4,1,7,4,7,3,6,5,6],2))



############################################################################
###5.4.2 Hoare’s partitioning method ###################################
#############################################################################
# def hoare_partition(arr):   # will return index which will partiotion partitioned 
#     lower=0
#     upper=len(arr)-1
#     mid=(lower+upper)//2
    
#     arr[lower],arr[mid]=arr[mid],arr[lower]

#     left=lower+1
#     right=upper
#     pivot=arr[mid]
    
#     while True:
#         while(arr[left]<=pivot):
#             left+=1
        
#         while(arr[right]>pivot):
#             right-=1
        
#         if(left > right):
#             break

#         arr[left],arr[right]=arr[right],arr[left]


#     arr[right],arr[lower]=arr[lower],arr[right]
#     return right

# print(hoare_partition([3,1,7,2,9,8]))


# ###################################################################################
# ###5.13 Alternative recursive version of Hoare’s partitioning scheme. #########
# ###################################################################################

# def quick_select(arr,lower,upper,k):
#     if(lower==upper):
#         return arr[lower]
#     else:
#         pivot_index=hoare_partition(arr[lower:upper])
#         if(pivot_index==k-1):
#             return arr[pivot_index]
#         if(pivot_index<k-1):
#             return quick_select(arr,pivot_index+1,upper,k)
#         else:
#             return quick_select(arr,lower,pivot_index-1,k)

# print(quick_select([3,1,7,2,9,8],0,6,1))



#############################################################################
################NEWTON BISECTION METHOD ###################################
################FINDING ROOTS OF x**2-2=0####################################

# def f(x):
#     return x*x-2


# def bisection_method(a,b,f,epsilon):
#     z=(a+b)/2
    
#     if (f(z)==0 or (b-a)<=2*epsilon):
#         return z
#     elif(f(a)>0 and f(z)<0) or (f(a)<0 and f(z)>0):
#         return bisection_method(a,z,f,epsilon)
#     else:
#         return bisection_method(z,b,f,epsilon)

# print(bisection_method(0,4,f,10**(-10)))


#################################################################################
########COUNTING SORT (RECURSIVE) #########################################################
## sorting numbers of range in [0,k] ############################################
####complexity O(n+k) ############################################################
def frequency_array(a,b):
    if(len(a)==1):
        b[a[0]]+=1
        return b
    else:
        b[a[0]]+=1
    return frequency_array(a[1:],b)

def sorted_array(b):
    if(len(b)==1):
        return [len(b)-1]*b[0]
    else:
        if(b[-1]==0):
            return sorted_array(b[:-1])
        elif(b[-1]==1):
            return sorted_array(b[:-1]) + [len(b)-1]
        else:
            return sorted_array(b[:-1]+[b[-1]-1]) + [len(b)-1]

def counting_sort(a):
    b=[0 for i in range(0,max(a)+1)]
    b=frequency_array(a,b)
    c=sorted_array(b)
    return c

data=[0,10,2,14,50,0,0,14,12,54,12,43,100]
sorted_data=counting_sort(data)
print(data)
print(sorted_data)