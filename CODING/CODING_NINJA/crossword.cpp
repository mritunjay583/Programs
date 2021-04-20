#include<bits/stdc++.h>

using namespace std;

//size of crossboard   n*n

const int n=10;

//// printing crossword

void print(char crossword[n][n])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<crossword[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
}

//checking if a string can be placed vertically

bool isValidVertical(char crossword[n][n],int x,int y,string s)
{
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(crossword[x+i][y]=='-' || crossword[x+i][y]==s[i])
        {
            cnt++;
        }
    }
    if(cnt==s.size())
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

//checking if a string can be placed Horizontally

bool isValidHorizontal(char crossword[n][n],int x,int y,string s)
{
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(crossword[x][y+i]=='-' || crossword[x][y+i]==s[i])
        {
            cnt++;
        }
    }
    if(cnt==s.size())
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

//place string horizontally

void setHorizontal(char crossboard[n][n],int x,int y,string s,bool arr[])
{
    for(int i=0;i<s.size();i++)
    {
        if(crossboard[x][y+i]=='-')
        arr[i]=true;
        else
        arr[i]=false;
        crossboard[x][y+i]=s[i];
    }
}

//place string vertically

void setVertical(char crossboard[n][n],int x,int y,string s,bool arr[])
{
    for(int i=0;i<s.size();i++)
    {
        if(crossboard[x+i][y]=='-')
        arr[i]=true;
        else
        arr[i]=false;
        crossboard[x+i][y]=s[i];
    }
}

//resetting vertically

void resetVertical(char crossboard[n][n],int x,int y,string s,bool a[])
{
    for(int i=0;i<s.size();i++)
    {
        if(a[i]==true)
        crossboard[x+i][y]='-';
    }
}

//resetting horizontally

void resetHorizontal(char crossboard[n][n],int x,int y,string s,bool a[])
{
    for(int i=0;i<s.size();i++)
    {
        if(a[i]==true)
        crossboard[x][y+i]='-';
    }
}

//function to solve cross board

bool cross(char crossword[n][n],string *s,int index,int size)
{
    if(size==index)
    {
        return true;
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(isValidHorizontal(crossword,i,j,s[index]))
            {
                bool arr[s[index].size()];
                setHorizontal(crossword,i,j,s[index],arr);
                if(cross(crossword,s,index+1,size))
                return true;
                else
                resetHorizontal(crossword,i,j,s[index],arr);
                
            }
            if(isValidVertical(crossword,i,j,s[index]))
            {
                bool arr[s[index].size()];
                setVertical(crossword,i,j,s[index],arr);
                if(cross(crossword,s,index+1,size))
                return true;
                else
                resetVertical(crossword,i,j,s[index],arr);
            }
        }
    }
    return false;
    
}

// main function 

int main()
{
    char crossword[n][n]={{'+','-','+','+','+','+','+','+','+','+'},
                            {'+','-','+','+','-','+','+','+','+','+'},
                            {'+','-','-','-','-','-','-','-','+','+'},
                            {'+','-','+','+','-','+','+','+','+','+'},
                            {'+','-','+','+','-','+','+','+','+','+'},
                            {'+','-','+','+','-','+','+','+','+','+'},
                            {'+','+','+','+','-','+','+','+','+','+'},
                            {'+','+','+','+','-','+','+','+','+','+'},
                            {'+','+','+','+','+','+','+','+','+','+'},
                            {'-','-','-','-','-','-','-','-','-','-'}};
    
    string words[]={"NIGERIA","CANADA","TELAVIV","CALIFORNIA"};
    cross(crossword,words,0,4);
    print(crossword);
}