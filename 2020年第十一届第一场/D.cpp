#include<iostream>
#include<fstream>
#include<stack>
using namespace std;

int main()
{
	stack<int> s1,s2; //s1����ѭ����ȣ�s2����ѭ������ 
	fstream prog("prog.txt");
	string line;
	int ans=0,k=1; //kΪ��ǰ��ѭ������ 
	getline(prog,line); //������һ�� 
	while(getline(prog,line)) {
		int space,i; //spaceΪ������ 
		for(i=0;i<line.size();i++) {
			if(line[i] != ' ') {
				space=i/4;
				break;
			}
		}
		if(line[i]=='R') {
			int num=line[i+7]-'0';
//			if(s1.empty() || space>s1.top()) { //����ѭ�� 
//				k*=num;
//				s1.push(space);
//				s2.push(num);
//			}
//			else { //ѭ������ 
				while(!s1.empty() && space<=s1.top()) {
					k/=s2.top();
					s1.pop();
					s2.pop();
				}
				k*=num;
				s1.push(space);
				s2.push(num);
//			}
		}
		else {
			int num=line[i+8]-'0';
//			if(space>s1.top()) { //����ѭ�� 
//				ans+=num*k;
//			}
//			else { //ѭ������ 
				while(!s1.empty() && space<=s1.top()) {
					k/=s2.top();
					s1.pop();
					s2.pop();
				}
				ans+=num*k;
//			}
		}
	}
	prog.close();
	cout<<ans<<endl;
	
	return 0;
}
