//Given an array of both positive and negative integers,
// the task is to compute sum of minimum and maximum elements of all sub-array of size k.
// C++ program to find sum of all minimum and maximum
// elements Of Sub-array Size k.
#include<bits/stdc++.h>
using namespace std;

// Returns sum of min and max element of all subarrays
// of size k
int SumOfKsubArray(int arr[] , int n , int k)
{
	int sum = 0; // Initialize result

	// The queue will store indexes of useful elements
	// in every window
	// In deque 'G' we maintain decreasing order of
	// values from front to rear
	// In deque 'S' we maintain increasing order of
	// values from front to rear
	deque< int > S(k), G(k);

	// Process first window of size K
	int i = 0;
	for (i = 0; i < k; i++)
	{
		// Remove all previous greater elements
		// that are useless.
		while ( (!S.empty()) && arr[S.back()] >= arr[i])
			S.pop_back(); // Remove from rear

		// Remove all previous smaller that are elements
		// are useless.
		while ( (!G.empty()) && arr[G.back()] <= arr[i])
			G.pop_back(); // Remove from rear

		// Add current element at rear of both deque
		G.push_back(i);
		S.push_back(i);
	}

	// Process rest of the Array elements
	for ( ; i < n; i++ )
	{
		// Element at the front of the deque 'G' & 'S'
		// is the largest and smallest
		// element of previous window respectively
		sum += arr[S.front()] + arr[G.front()];

		// Remove all elements which are out of this
		// window
		while ( !S.empty() && S.front() <= i - k)
			S.pop_front();
		while ( !G.empty() && G.front() <= i - k)
			G.pop_front();

		// remove all previous greater element that are
		// useless
		while ( (!S.empty()) && arr[S.back()] >= arr[i])
			S.pop_back(); // Remove from rear

		// remove all previous smaller that are elements
		// are useless
		while ( (!G.empty()) && arr[G.back()] <= arr[i])
			G.pop_back(); // Remove from rear

		// Add current element at rear of both deque
		G.push_back(i);
		S.push_back(i);
	}

	// Sum of minimum and maximum element of last window
	sum += arr[S.front()] + arr[G.front()];

	return sum;
}

// Driver program to test above functions
int main()
{
	int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	cout << SumOfKsubArray(arr, n, k) ;
	return 0;
}


//Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.
// Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
// Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.
int tour(petrolPump p[],int n)
    {
       //Your code here
       int def=0;
       int balance=0;
       int start=0;
       
       for(int i=0;i<n;i++){
           balance+=p[i].petrol-p[i].distance;
           if(balance<0){
               def+=balance;
               start=i+1;
               balance=0;
           }
       }
       
       if(def+balance>=0)
       return start;
       
       else{
           return -1;
       }
    }

//Input: A = "aabc"
// Output: "a#bb"
// Explanation: For every character first non
// repeating character is as follow-
// "a" - first non-repeating character is 'a'
// "aa" - no non-repeating character so '#'
// "aab" - first non-repeating character is 'b'
// "aabc" - first non-repeating character is 'b'

string FirstNonRepeating(string A){
		    // Code here
		    //create the map and queue and compare with the front element of queue
		    unordered_map<char,int>count;
		    queue<int>q;
		    string ans="";
		    
		    for(int i=0;i<A.length();i++){
		        char ch=A[i];
		        
		        count[ch]++;
		        
		        q.push(ch);
		        
		        while(!q.empty()){
		            if(count[q.front()]>1){
		                q.pop();
		            }
		            else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        
		        if(q.empty()){
		            ans.push_back('#');
		        }
		        
		    }
		    return ans;}

// Given an integer K and a queue of integers,
//  we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    //create the stack and push the k element in the stack
    stack<int>s;
    for(int i=0;i<k;i++){
        int val=q.front();
        q.pop();
        s.push(val);
    }
    
    //pop the element from the stack and add into the queue
    while(!s.empty()){
        int val=s.top();
        s.pop();
        q.push(val);
    }
    
    //add the first element into the last
    
    int m=q.size()-k;
     while(m--){
         int val=q.front();
         q.pop();
         q.push(val);
     }
    
    return q;
}

//Given an array A[] of size N and a positive integer K,
// find the first negative integer for each and every window(contiguous subarray) of size K.

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
                                                 
        deque<long long int>dq;
        vector<long long int>ans;
        
        //1.process the first window of size k. and if num is negative add it into the queue.
        for(int i=0;i<K;i++){
            if(A[i]<0){
                dq.push_back(i);
            }
        }
        //store the ans in ans vec.
        if(dq.size()>0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        //process the remaing window
        for(int i=K;i<N;i++){
            //remove the first element in the window(from dq)
            if(!dq.empty()&& i-dq.front()>=K){
                dq.pop_front();
            }
            
            //add the next element of the window
            if(A[i]<0){
                dq.push_back(i);
            }
            
            //store the ans;
            if(dq.size()>0){
                ans.push_back(A[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
        
//Queue Reversal
queue<int> rev(queue<int> q)
{
    // add code here.
    stack<int>s;
    while(!q.empty()){
        int element=q.front();
        q.pop();
        s.push(element);
    }
    while(!s.empty()){
        int element=s.top();
        s.pop();
        q.push(element);
    }
    return q;
    
}

