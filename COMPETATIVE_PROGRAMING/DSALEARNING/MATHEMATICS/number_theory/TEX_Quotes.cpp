#include<iostream>
using namespace std;

int main()
{
    string text;
    string buffer;
    do{
        getline(cin,buffer);
        text+=buffer;
    }while(buffer!="");
    cout<<text;
}