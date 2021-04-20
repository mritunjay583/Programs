
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