#pragma once
#include <iostream>

using namespace std;

class Solution{
public:
	double quickMul(double x, long long N){
		if(0 == N){
			return 1.0;
		}

		double y = quickMul(x, N/2);
		return N % 2 == 0 ? y * y : y * y * x;
	}

	double myPow(double x, int n){
		long long N = n;
		return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
	}

};
