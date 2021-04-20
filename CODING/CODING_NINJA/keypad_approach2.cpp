#include<bits/stdc++.h>

using namespace std;

string dial_pad[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void print_keypad_combination(int n,string output){
    if(n==0){
        cout<<output<<endl;
        return;
    }
    int temp=n%10;
    for(int i=0;i<dial_pad[temp].size();i++){
        print_keypad_combination(n/10,output+dial_pad[temp][i]);
    }
}

int main(){
    int n=34;
    print_keypad_combination(n,"");
}
