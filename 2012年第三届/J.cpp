#include<iostream>
using namespace std;

int main()
{
	int a[10000]={0,0,1,0,1,0,1,0,1}; //a[0]��Ϊ����ֵ
	for(int i=9;i<10000;i++) {
		a[i]=(a[i-1] && a[i-3] && a[i-7] && a[i-8]) ? 0 : 1; //״̬ת�Ʒ��� 
	}
	int n;
	cin>>n;
	while(n--) {
		int num;
		cin>>num;
		cout<<a[num]<<endl;
	}
	
	return 0;
}
