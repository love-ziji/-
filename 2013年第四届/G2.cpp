#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,i=0,a[10000];
	cin>>n;
	while(n--) {
		while(cin>>a[i++]) {
			if(cin.get() == '\n') { //ÿ�������Ի��з�'\n'���� 
				break;
			}
		}
	}
	sort(a,a+i);
	int x,y; //xΪ�Ϻ�ID��yΪ�غ�ID
	for(int j=0;j<i;j++) {
		if(a[j]+1 < a[j+1]) {
			x=a[j]+1;
		}
		if(a[j] == a[j+1]) {
			y=a[j];
		}
	}
	cout<<x<<' '<<y<<endl;
	
	return 0;
 } 
