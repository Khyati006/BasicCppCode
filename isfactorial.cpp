// C++ implementation for
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to check if
// the given number is a
// factorial of any number
bool isFactorial(int n)
{
for (int i = 1;; i++) {
	if (n % i == 0) {
	n /= i;
    cout<<n;
	}
	else {
	break;
	}
}

if (n == 1) {
	return true;
}
else {
	return false;
}
}

// Driver Code
int main()
{
int n = 6;

bool ans = isFactorial(n);
if (ans == 1) {
	cout << "Yes\n";
}
else {
	cout << "No\n";
}

return 0;
}
