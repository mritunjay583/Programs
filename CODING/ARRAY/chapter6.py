################6.1 IS A LIST SORTED IN ASCENDING ORDER?##################
##########################################################################
# def issorted(arr):
#     if(len(arr)<=1):
#         return True
#     else:
#         return issorted(arr[:len(arr)//2]) and arr[len(arr)//2-1] <= arr[len(arr)//2] and issorted(arr[len(arr)//2:])
  
# print(issorted([1,2,3,4,1,6,7,8,9,10]))

#############################################################################
####################6.2.1 The merge sort algorithm###########################
#############################################################################
# def merge(a,b):
#     if a==[]:
#         return b
#     if b==[]:
#         return a
#     if(a[0]<b[0]):
#         return [a[0]]+merge(a[1:],b)
#     else:
#         return [b[0]]+merge(a,b[1:])


# def mergeSort(arr):
#     if(len(arr)<=1):
#         return arr
#     left=mergeSort(arr[:len(arr)//2])
#     right=mergeSort(arr[len(arr)//2:])
#     return merge(left,right)

# print(mergeSort([4,10,2,6,8,3,5,9,6,3,0]))


###############################################################
########6.3 MAJORITY ELEMENT IN A LIST#########################
###############################################################
##A list is said to have a “majority element” if more than half of its entries
##are identical. ########

