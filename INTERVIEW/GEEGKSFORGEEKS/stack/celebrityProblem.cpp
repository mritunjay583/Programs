// https://www.geeksforgeeks.org/the-celebrity-problem/
#include <bits/stdc++.h> 
using namespace std; 

// Max # of persons in the party 
#define N 8 

// Person with 2 is celebrity 
bool MATRIX[N][N] = {{0, 0, 1, 0}, 
					{0, 0, 1, 0}, 
					{0, 0, 0, 0}, 
					{0, 0, 1, 0}}; 

bool knows(int a, int b) 
{ 
	return MATRIX[a][b]; 
} 

// Returns -1 if celebrity 
// is not present. If present, 
// returns id (value from 0 to n-1). 
//complexity of this problem is O(n^2) time and O(n) space
int findCelebrity_1(int n) 
{ 
	
	//degree array; 
	int indegree[n]={0},outdegree[n]={0}; 
	
	//query for all edges 
	for(int i=0; i<n; i++) 
	{ 
		for(int j=0; j<n; j++) 
		{ 
			int x = knows(i,j); 
			
			//set the degrees 
			outdegree[i]+=x; 
			indegree[j]+=x; 
		} 
	} 
	
	//find a person with indegree n-1 
	//and out degree 0 
	for(int i=0; i<n; i++) 
	if(indegree[i] == n-1 && outdegree[i] == 0) 
		return i; 
	
	return -1; 
} 

int findCelebrity_2(int n){

    stack<int> person;
    //intitially push all persons in stack
    for(int i=0;i<n;i++){
        person.push(i);
    }

    while(person.size()!=1){
        //pop two person from stack and check condition
        int x=person.top();person.pop();
        int y=person.top();person.pop();
        if(knows(x,y)){ // if x knows y then x cannot be celebrity
            person.push(y); //y can be celebrity
        }else{ //if x does not know y then y cannot be celebrity
            person.push(x); //x can be celebrity
        }
    }
    int celeb=person.top();
    for(int i=0;i<n;i++){
        if(celeb!=i){
            if(knows(celeb,i)==true || knows(i,celeb)==false){//checking celebrity for the last element of stack{celeb}
                return -1;
            }
        }
    }
    return celeb;

}
// Driver code 
int main() 
{ 
	int n = 4; 
	int id = findCelebrity_2(n); 
	id == -1 ? cout << "No celebrity" : 
			cout << "Celebrity ID " << id; 
	return 0; 
} 
