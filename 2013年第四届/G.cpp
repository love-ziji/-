#include<iostream>
using namespace std;

int main()
{
	int n,t,minNum=100000,maxNum=0,hash[100001]={0};
	cin>>n;
	while(n--) {
		while(cin>>t) {
			if(t<minNum) {
				minNum=t;
			}
			if(t>maxNum) {
				maxNum=t;
			}
			hash[t]++;
			if(cin.get() == '\n') { //ÿ�������Ի��з�'\n'���� 
				break;
			}
		}
	}
	int a,b; //aΪ�Ϻ�ID��bΪ�غ�ID 
	for(int i=minNum;i<=maxNum;i++) {
		if(hash[i] == 0) {
			a=i;
		}
		if(hash[i] >= 2) {
			b=i;
		}
	}
	cout<<a<<' '<<b<<endl;
	
	return 0;
}
