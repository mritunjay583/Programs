// https://www.geeksforgeeks.org/find-all-unique-pairs-of-maximum-and-second-maximum-elements-over-all-sub-arrays-in-onlogn/ 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the set of pairs 
set<pair<int, int>> 
	pairs(vector<int>& arr) 
{ 
	stack<int> st; 
	set<pair<int, int>> pairs; 

	// Push first element into stack 
	st.push(arr[0]); 

	// For each element 'X' in arr, 
	// pop the stack while top Element 
	// is smaller than 'X' and form a pair. 
	// If the stack is not empty after 
	// the previous operation, create 
	// a pair. Push X into the stack. 

	for (int i = 1; i < arr.size(); ++i) { 
		while (!st.empty() && 
				arr[i] > st.top()) { 
			pairs.insert(make_pair(st.top(), 
									arr[i])); 
			st.pop(); 
		} 
		if (!st.empty()) { 
			pairs.insert(make_pair(min(st.top(), 
									arr[i]), 
								max(st.top(), 
									arr[i]))); 
		} 
		st.push(arr[i]); 
	} 
	return pairs; 
} 

int main() 
{ 
	vector<int> vec = { 1, 2, 6, 4, 5 }; 

	set<pair<int, int> > st = pairs(vec); 
	cout << "Total Number of valid pairs is :"
				<< (int)st.size() << "\n"; 
	for (auto& x : st) { 
		cout << "(" << x.first << ", "
					<< x.second << ") "; 
	} 
	return 0; 
} 