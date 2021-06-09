#include<iostream>
#include<cstring>
using namespace std;

int n,m,k,mapVal[50][50],dp[50][50][13][13]; 

int dfs(int i,int j,int maxVal,int num) {
	if(dp[i][j][maxVal+1][num] != -1) { //��������-1�����ʾ��������
		return dp[i][j][maxVal+1][num];
	}
	if(i==n-1 && j==m-1) {
		if(num==k || maxVal<mapVal[i][j]&&num==k-1) {
			return dp[i][j][maxVal+1][num]=1;
		} else {
			return dp[i][j][maxVal+1][num]=0;
		}
	}
	long long sum=0;
	if(i < n-1) {
		if(maxVal < mapVal[i][j]) {
			sum+=dfs(i+1,j,mapVal[i][j],num+1);
		}
		sum+=dfs(i+1,j,maxVal,num);
	}
	if(j < m-1) {
		if(maxVal < mapVal[i][j]) {
			sum+=dfs(i,j+1,mapVal[i][j],num+1);
		}
		sum+=dfs(i,j+1,maxVal,num);
	}
	//������ֵ����Ϊ0�������������б���������ֵ��ʼֵΪ-1
	//�����±���СֵΪ0��������maxVal+1
	return dp[i][j][maxVal+1][num]=sum%1000000007;
}

int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>mapVal[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<dfs(0,0,-1,0)<<endl;
	
	return 0;
}
