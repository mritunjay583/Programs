#include<bits/stdc++.h>

using namespace std;

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
////////////////////////////////////////////////////////////
////////////////////METHOD 1////////////////////////
void reversed(int arr[],int begin,int end){
    if(begin>=end){
        return;
    }
    else{
        swap(arr[begin],arr[end-1]);
        reversed(arr,begin+1,end-1);
    }
}
void rotation1(int arr[],int size,int x){
    reversed(arr,0,x);
    reversed(arr,x,size);
    reversed(arr,0,size);
}
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/////////METHOD 2//////////////////////////////////////////
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
    
}

void rotation2(int arr[],int size,int x){
  int d=gcd(size,x);
  int temp;
  int j;
  for(int i=0;i<d;i++){
      temp=arr[i];
      j=i;
      while (1) { 
            int k = j + x; 
            if (k >= size) 
                k = k - size; 
  
            if (k == i) 
                break; 
  
            arr[j] = arr[k]; 
            j = k; 
        } 
        arr[j] = temp;
    //   print(arr,size);
  }


}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int x=5;    
    print(arr,size);
    rotation2(arr,size,x%size);
    print(arr,size);
}