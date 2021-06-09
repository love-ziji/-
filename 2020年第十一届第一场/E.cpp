#include<iostream>
using namespace std;

int dp[1011][1011]; //dp[i][j]����һ����i�������ڶ�����j�����ķ�����

int main()
{
	for(int i=0;i<=1010;i++) {
		for(int j=0;j<=i;j++) { //j<=i��֤ͬһ�����±ߵı��ϱߵĴ󣨰���С�����˳��������
			if(i>=1 && j>=1) {
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			} else if(i>=1) {
				dp[i][j]=dp[i-1][j];
			} else if(j>=1) {
				dp[i][j]=dp[i][j-1];
			} else {
				dp[i][j]=1; //��ʼ��
			}
			dp[i][j]%=2020;
		}
	}
	cout<<dp[1010][1010]<<endl;
	 
	return 0;
}
