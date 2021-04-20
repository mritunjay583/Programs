#include<bits/stdc++.h>
using namespace std;

string dial_pad[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

vector<string> v;

vector<string> keypad(int n){
    if(n/10==0){
        if(n==0 || n==1){
            v.push_back("");
            return v;
        }
        for(int i=0;i<dial_pad[n].size();i++){
            v.push_back(dial_pad[n].substr(i,1));
        }
        return v;
    }
    keypad(n/10);
    int size=v.size();
    string data=dial_pad[n%10];
    for(int i=0;i<data.size();i++){
        for(int j=0;j<size;j++){
            v.push_back(v[j]+data[i]);
        }
    }
    vector<string> q(v.begin()+size,v.end());
    v.clear();
    for(int i=0;i<q.size();i++){
        v.push_back(q[i]);
    }
    return v;

}
int main(){
    int n=34;
    vector<string> res=keypad(n);
    for(int i=0;i<res.size();i++){
    	cout<<res[0]<<" ";
	}
	cout<<endl;
}
