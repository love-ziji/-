#include<iostream>
using namespace std;

int main()
{
	unsigned long long a[100]={0,1};
	for(int i=2;i<100;i++) {
		a[i]=a[i-1]+a[i-2];
		cout<<i<<' '<<a[i]<<endl; //a[94]Խ��
	}
	unsigned long long x=a[88],y=a[89];
	// ģ�������������������Ȼ������������10��������
	for(int i=1;i<=102;i++) {
		cout<<x/y;
		x=(x%y)*10; //��10���ܵ���Խ�磬���Ե�x=a[88],y=a[89]����ֻ�ܾ�ȷ��С�����36λ
	}
	
	return 0;
}
