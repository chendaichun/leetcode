#include<iostream>
#include<vector>
using namespace std;
int trap(vector<int> water)
{
	int m = 0;
	int n = 0;
	int max = 0;
	int sum = 0;
	for (int i = 0; i < water.size()-1; i++) {
		if (water[i + 1] > water[i]) {
			n = i + 1;
			int max = min(water[m], water[n]);
			for (int j = m + 1; j < n; j++) {
				if (max > water[j]) {
					sum += max - water[j];
					water[j] = max;
				}
				
			}
			if (water[n] >= water[m])m = n;
		}
	}
	return sum;
}


int trap1(vector<int> water)
{
	int size = water.size();
	int sum = 0;
	vector<int> leftmax(size, 0);
	vector<int> rightmax(size, 0);
	int max = water[0];
	for (int i = 0; i < size; i++) {
		if (water[i] < max)leftmax[i] = max - water[i];
		else max = water[i];
	}
	max = water[size-1];
	for (int i = size - 1; i >= 0; i--) {
		if (water[i] < max)rightmax[i] = max - water[i];
		else max = water[i];
	}
	for (int i = 0; i < size ; i++) {
		if (leftmax[i] < rightmax[i])sum += leftmax[i];
		else sum += rightmax[i];
	}
	return sum;
}

