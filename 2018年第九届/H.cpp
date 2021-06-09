#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int N=100001;

// ���ӽṹ�壬�������ӵ�id���յ����޵����� 
typedef struct {
	int id,num;
} Log;

bool compare(Log a,Log b) {
	return a.num>b.num;
}

int main()
{
	int n,d,k;
	Log log[N];
	for(int i=0;i<N;i++) {
		log[i].id=i;
		log[i].num=0;
	}
	vector< vector<int> > time(N); //����ÿ�������յ��޵�ʱ�� 
	set<int> ans; //��������id��ʹ��set�Զ����� 
	cin>>n>>d>>k;
	int ts,id,maxid=0;
	for(int i=0;i<n;i++) {
		cin>>ts>>id;
		if(id > maxid) {
			maxid=id;
		}
		log[id].num++;
		time[id].push_back(ts);
	}
	sort(log,log+maxid+1,compare); //���յ����޵��������������� 
	for(int i=0;i<=maxid && log[i].num>=k;i++) {
		int f=0;
		sort(time[log[i].id].begin(),time[log[i].id].end()); //���յ��޵�ʱ������ 
		for(int j=0;j<time[log[i].id].size();j++) {
			int q=j;
			while(time[log[i].id][q]-time[log[i].id][j]<d && q<time[log[i].id].size()) {
				if(q-j+1>=k) { //�ж��Ƿ������� 
					ans.insert(log[i].id);
					f=1;
					break;
				}
				q++;
			}
			if(f) {
				break;
			}
		}
	}
	for(set<int>::iterator it=ans.begin();it!=ans.end();it++) {
		cout<<*it<<'\n'; //��'\n'����endl���Ч�� 
	}
	
	return 0;
}
