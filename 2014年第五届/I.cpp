#include<iostream>
using namespace std;

int n,m,k,sum=0,mapVal[50][50];

void dfs(int i,int j,int maxVal,int num) {
	if(i==n-1 && j==m-1) {
		if(num==k || maxVal<mapVal[i][j]&&num==k-1) { //�ߵ�����ʱ��������k������ �� ������k-1�������ҳ��ڸ����еı�����ֵ��С���������ⱦ����ֵ����
			sum++;
			sum%=1000000007;
		}
	}
	if(i < n-1) { //�ܹ������� 
		if(maxVal < mapVal[i][j]) {
			dfs(i+1,j,mapVal[i][j],num+1); //���𱦱������� 
		}
		dfs(i+1,j,maxVal,num); //�����𱦱������� 
	}
	if(j < m-1) { //�ܹ������� 
		if(maxVal < mapVal[i][j]) {
			dfs(i,j+1,mapVal[i][j],num+1); //���𱦱������� 
		}
		dfs(i,j+1,maxVal,num); //�����𱦱������� 
	}
}

int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>mapVal[i][j];
		}
	}
	dfs(0,0,-1,0);
	cout<<sum<<endl;
	
	return 0;
}
