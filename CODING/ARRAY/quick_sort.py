def partition(arr,piovt):
    pivot=arr[-1]
    i=-1
    j=0
    while(j<(len(arr)-1)):
        if(arr[j]<=pivot):
            i+=1
            arr[j],arr[i]=arr[i],arr[j]
        j+=1
    
    arr[i+1],arr[-1]=arr[-1],arr[i+1]
    return [arr,i+1]


def quicksort(arr,left,right):
    if left<right:
        return arr
    pivot=right
    arr,part=partition(arr,pivot)
    x=quicksort(arr,left,part-1)
    y=quicksort(arr,part+1,right)
    return x+y

# print(partition([4,2,6,9,8,7],7))
print(quicksort([4,2,6,9,8,7],0,6))
