// https://practice.geeksforgeeks.org/problems/overlapping-intervals/0
#include<bits/stdc++.h>
using namespace std;


int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<pair<int,bool> > input;
        //storing [a,b] like
        //(a,false) and (b,true)  
        //false stands for (
        //and true means )
        //i am doing this to make this question similar to valid parenthesis problem  ---   ((((())))(())
        //ex:   [1 3] ,  [2 4] , [6 8] , [9 10] this data will be stored like
                    // (   (   )   )   (  )  (   )
                    // 1   2   3   4   6  8  9  10
                    //now the answer will be [1,4] , [6,8] , [9,10]
                    // (    )   (   )   (   )
                    // 1    4   6   8   9   10
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            input.push_back(make_pair(x,false));
            cin>>x;
            input.push_back(make_pair(x,true));
        }

        //sorting data in decrasing order
        sort(input.begin(),input.end());
        //using stack because this problem is similar to valid parenthesis problem
        stack<pair<int,bool> > st;
        //storing the result in form of [a,b] so i am using vector pair
        vector<pair<int,int> > res;

        for(int i=0;i<input.size();i++){
            //if there is close bracket
            if(input[i].second==true){
                //if stack is not empty and top of stack is open bracket
                if(st.size()>0 && st.top().second==false){
                    //is size of stack is 1 then we got an interval : means first longest valid parenthesis
                    if(st.size()==1){
                        //so storing the result 
                        res.push_back(make_pair(st.top().first,input[i].first));
                    }
                    //pop the element from stack
                    st.pop();
                }else{//if stack is empty or top of stack is not open bracket then push the element
                    st.push(input[i]);
                }
            }
            else{//if given element is open bracket then push it in stack
                    st.push(input[i]);
                }
        }

        //printing result
        cout<<"merged interval : ";
        for(auto x:res)cout<<x.first<<" "<<x.second<<" ";cout<<endl; 
        
    }
	return 0;
}
///input format

// 2
// 4
// 1 3 2 4 6 8 9 10
// 4
// 6 8 1 9 2 4 4 7