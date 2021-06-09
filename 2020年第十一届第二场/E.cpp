#include<iostream>
using namespace std;

int e[8][8]; //i��������j�������Ƿ����� 
int vis[8];
int p[8];
int ans;

int find(int x) {
	return p[x] == x ? p[x] : (p[x]=find(p[x]));
}

void merge(int x,int y) {
	int px=find(x);
	int py=find(y);
	if(px!=py) {
		p[px]=py;
	}
}

void dfs(int n) {
	if(n==8){
		for(int i=1;i<8;i++) {
			p[i]=i;
		}
		for(int i=1;i<8;i++) {
			for(int j=1;j<8;j++) {
				if(e[i][j] && vis[i] && vis[j]) { //�������ķ���Ķ����ܺϲ�
					merge(i,j);
				}
			}
		}
		int cnt=0;
		for(int i=1;i<8;i++) {
			if(vis[i] && p[i]==i) { //���������ķ���Ķ����ܵĿ���
				cnt++;
			}
		}
		if(cnt==1) { //���з���Ķ���������һƬ
			ans++;
		}
		return;
	}
	vis[n]=1;
	dfs(n+1);
	vis[n]=0;
	dfs(n+1);
}

int main()
{
	e[1][2]=e[1][6]=1;
	e[2][1]=e[2][3]=e[2][7]=1;
	e[3][2]=e[3][4]=e[3][7]=1;
	e[4][3]=e[4][5]=1;
	e[5][4]=e[5][6]=e[5][7]=1;
	e[6][1]=e[6][5]=e[6][7]=1;
	e[7][2]=e[7][3]=e[7][5]=e[7][6]=1;
	dfs(1);
	cout<<ans<<endl;
	
	return 0;
}
