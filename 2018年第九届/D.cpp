#include<iostream>
using namespace std;

int main()
{
	int phone=3,floor=1000,dp[4][1001];
	for(int i=1;i<=phone;i++) {
		for(int j=1;j<=floor;j++) {
			dp[i][j]=j; //��ʼ��Ϊ���� 
		}
	}
	for(int i=2;i<=phone;i++) {
		for(int j=1;j<=floor;j++) {
			for(int k=1;k<j;k++) {
				dp[i][j]=min(dp[i][j],max(dp[i-1][k-1],dp[i][j-k])+1); //״̬ת�Ʒ��� 
			}
		}
	}
	cout<<dp[3][1000]<<endl;
	
	return 0;
}
