#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	double a[3];
	a[0]=0.1*0.2*0.3+0.1*0.8*0.5; //�׶���
	a[1]=0.3*0.4*0.1+0.3*0.6*0.5; //�׶Ա�
	a[2]=0.5*0.7*0.1+0.5*0.3*0.3; //�׶Զ�
	double sum=0;
	srand(time(0)); //��ʱ��Ϊ����
	for(int i=0;i<100000;i++) {
		int n=rand()%3; //���������
		sum+=a[n];
	}
	cout<<sum/100000;
	
	return 0;
}
