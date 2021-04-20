// https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/
// this question is just little variation of longest subarry
// with sum 0
#include<bits/stdc++.h>
using namespace std;

//time O(n) and space O(1)
int lengthOfLongestValidParenthesis_3(string str){
    int n=str.size();
    int mx_len=0;
    int left,right;
    left=right=0;
    //go from left to right
    for(int i=0;i<n;i++){
        if(str[i]=='('){
            left++;
        }else{
            right++;
        }
        if(left==right){
            mx_len=max(mx_len,2*right);
        }
        else if(right>left){
            left=right=0;
        }
    }

    //go from right to left
    left=right=0;
    for(int i=n-1;i>=0;i--){
        if(str[i]=='('){
            left++;
        }else{
            right++;
        }
        if(left==right){
            mx_len=max(mx_len,2*right);
        }
        else if(right>left){
            left=right=0;
        }
    }
    return mx_len;
}

//time O(n) and space o(n)
int lengthOfLongestValidParenthesis_2(string str){
    int n = str.length(); 
    // Create a stack and push -1 as initial index to it. 
    stack<int> stk; 
    stk.push(-1); 
    // Initialize result 
    int result = 0; 
    // Traverse all characters of given string 
    for (int i=0; i<n; i++) 
    { 
        // If opening bracket, push index of it 
        if (str[i] == '(') 
            stk.push(i); 
        else // If closing bracket, i.e.,str[i] = ')' 
        { 
            // Pop the previous opening bracket's index 
            stk.pop(); 
            // Check if this length formed with base of 
            // current valid substring is more than max  
            // so far 
            if (!stk.empty()) 
                result = max(result, i - stk.top()); 
            // If stack is empty. push current index as  
            // base for next valid substring (if any) 
            else stk.push(i); 
        } 
    } 
    return result; 
}

int lengthOfLongestValidParenthesis_1(string s){
    int mx=0;
    int cnt=0;
    unordered_map<int,int> ma;
    ma[0]=-1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
            cnt++;
        else if(s[i]==')')
            cnt--;
        if(cnt<0) // if there is only opening bracket at start then make count to 0;
        {
            cnt=0;
            ma.clear();
            ma[cnt]=i; // store the count and corresponding index
        }
        else if(ma.count(cnt)>0 && s[i]==')') // if count is already in map means count was 0 between ma[cnt] and i means there is valid parenthesis
        {
            mx=max(mx,i-ma[cnt]); // so update the mx variable to store longest parenthesis
        }
        else ma[cnt]=i; // and if cnt is not already in map then store it in map
    }                   // or if s[i]!=")" and count is already in map then update the value of ma[cnt];
    return mx;
    
}
int main()
 {
    string s="((()()())))";
    int res1=lengthOfLongestValidParenthesis_1(s);
    cout<<res1<<endl; 
    int res2=lengthOfLongestValidParenthesis_2(s);
    cout<<res2<<endl;      
     int res3=lengthOfLongestValidParenthesis_3(s);
    cout<<res3<<endl;   
    return 0;
}