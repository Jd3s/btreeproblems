#include <bits/stdc++.h>
using namespace std;

int main() {
	int l;
	cin>>l;
	int n = pow(2,l-1);
	int sum = (n*(n+1))/2;
	cout<< l * sum;
}
