#include<stdio.h>
#include<math.h>

int reverse(int n)
{
    int rem;
    int val=0;
    while(n)
    {
        rem=n%10;
        val=val*10+rem;
        n=n/10;
    }
    return val;

}
int main()
{
    int x;
    int res;
    float f;
    scanf("%f",&f);
    x=floor(f);
    printf("Integral part of %f is %d\n",f,x);
    res=reverse(x);
    printf("reverse of %d is %d ",x,res);
}