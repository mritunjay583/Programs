#include<bits/stdc++.h>

using namespace std;

void print(int **arr,int r,int c)  ///printing matrix
{
    cout<<"--------------\n";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"--------------\n";
}

int findSum(int **arr,int si,int sj,int r,int c)
{
    int x,y,z;
    int temp=0;
    int m=INT_MIN;
    for(int i=si;i<r;i++)
    {
        temp=0;
        
        for(int j=sj;j<c;j++)
        {
            x=0;y=0;z=0;
            if((j+1)<c)
            {
                x=arr[si][j+1];
            }
            if((i+1)<r)
            {
                y=arr[i+1][sj];
            }
            if(((i+1)<r) && ((j+1)<c))
            {
                z=arr[i+1][j+1];
            }
            temp=arr[si][sj]-(x+y)+z;
            if(m<temp)
            {
                m=temp;
            }
        }
    }
    return m;

}
int _maximumRectangeSum(int **arr,int r,int c)
{
    int maxi=INT_MIN;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            int sum=findSum(arr,i,j,r,c);
            if(maxi<sum)
            {
                maxi=sum;
            }
        }
    }
    return maxi;
}

int maximumRectangeSum(int **arr,int r,int c)
{
    int **sumArr=new int*[r];
    for(int i=0;i<r;i++)
    {
        sumArr[i]=new int[c];
    }
    sumArr[r-1][c-1]=arr[r-1][c-1];
    for(int i=r-2;i>=0;i--)
    {
        sumArr[i][c-1]=arr[i][c-1]+sumArr[i+1][c-1];
    }
    for(int i=c-2;i>=0;i--)
    {
        sumArr[r-1][i]=arr[r-1][i]+sumArr[r-1][i+1];
    }
    for(int i=r-2;i>=0;i--)
    {
        for(int j=c-2;j>=0;j--)
        {
            sumArr[i][j]=sumArr[i+1][j]+sumArr[i][j+1]-sumArr[i+1][j+1]+arr[i][j];
        }
    }
    print(sumArr,r,c);
    return _maximumRectangeSum(sumArr,r,c);
}

int main()
{
    int r;
    int c;
    cin>>r>>c;
    int **arr=new int*[r];
    for(int i=0;i<r;i++)
    {
        arr[i]=new int[c];
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
        }
    }
    int res=maximumRectangeSum(arr,r,c);
    cout<<res<<endl;
}