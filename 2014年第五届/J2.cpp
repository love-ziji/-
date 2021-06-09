#include<iostream>
#include<cstring>
using namespace std;
#define lowbit(x) x&(-x) //lowbit(x)=2^k,kΪx�Ķ������д����λ����λ������ĳ���

int maxh=-1,tree[1000001]; //��״�����±�Ϊ��ߣ�ԭ���鱣��ÿ����ߵ�С���Ѹ���

void update(int x,int val) { //������״����
	while(x <= maxh+1) {
		tree[x]+=val;
		x+=lowbit(x);
	}
}

int getsum(int x) { //ͨ����״�������ԭ����ǰx��ͣ����ＴΪС�ڵ���h[i]�����ݸ���
	int sum=0;
	while(x > 0) {
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}

int main()
{
	int n,h[100000];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>h[i];
		maxh=max(maxh,h[i]);
	}
	long long swap[100000];
	for(int i=0;i<n;i++) {
		update(h[i]+1,1); //Ϊʲô��h[i]+1����״�����±��1��ʼ����h[i]����Ϊ0
		swap[i]=i+1-getsum(h[i]+1); //������߱��������ݸ�����������������ܸ���-С�ڵ���������ݸ���
	}
	memset(tree,0,sizeof(tree));
	for(int i=n-1;i>=0;i--) {
		update(h[i]+1,1);
		swap[i]+=getsum(h[i]); //�����ұ߱���С�����ݸ���
	}
	long long res=0;
	for(int i=0;i<n;i++) {
		res+=(1+swap[i])*swap[i]/2;
	}
	cout<<res<<endl;
	
	return 0;
}
