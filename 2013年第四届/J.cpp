#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,maxNum,minNum,sum=0,arr[50000];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	for(int i=0;i<n-1;i++) {
		maxNum=arr[i];
		minNum=arr[i];
		for(int j=i+1;j<n;j++) {
			if(arr[j] > maxNum) {
				maxNum=arr[j];
			}
			if(arr[j] < minNum) {
				minNum=arr[j];
			}
			if(maxNum-minNum == j-i) { 
				sum++;
			}
		}
	}
	cout<<sum+n<<endl; //��L=R��������[L, R]Ϊ�������� 
	
	return 0;
}
