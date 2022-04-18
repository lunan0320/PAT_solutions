#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

const int maxn = 2010;
const int INF = 100000000;

//����mapӳ�� 
map<string,int> string2int;
map<int,string> int2string;
map<string,int> Gang;

//����Ƿ񱻷���
bool visit[maxn] = {false};
 
//��������
int G[maxn][maxn] = {0},Weight[maxn] = {0};//����ͼ�͵�Ȩ
 

int N = 0,  K = 0, numPerson = 0; //����ͨ����������ֵ��������
 
//��stringת��Ϊint 
int changeString(string temp){
	if(string2int.find(temp) != string2int.end()){//�����id�Ѿ����ֹ� 
		return string2int[temp];
	}else{//���û�г��֣����½�һ��ӳ���ϵ 
		numPerson++;
		string2int[temp] = numPerson;
		int2string[numPerson] = temp;
		return numPerson; 
	}
}

void DFS(int nowVis, int& head,int& totalNum, int& totalWeight){
	//�ݹ���ֹ���� 
	if(visit[nowVis]){
		return;
	} 
	//���õ�ǰ�Ѿ����� �Լ�������+1 
	visit[nowVis] = true;
	totalNum ++;
	//�ж��Ƿ���Ҫ����head
	if(Weight[head] < Weight[nowVis]){
		head = nowVis;
	} 
	//������֮��ص�ÿ����� 
	for(int i = 1; i <= numPerson; i++){
		if(G[nowVis][i] > 0){ //��ʾ��nowVis��i����б� 
			//�������Gang����Ȩ�� 
			totalWeight += G[nowVis][i];
			//��¼֮��ɾ�������� 
			G[nowVis][i] = G[i][nowVis] = 0; 
			DFS(i,head,totalNum,totalWeight);
		} 
	}
}
void DFS_Traverse(){
	//�������е��� �˴�id�Ǵ�1��ʼ 
	for(int i = 1; i <= numPerson;i++){
		if(!visit[i]){
			int totalNum = 0, head = i, totalWeight = 0; //�������Gange����������ͷĿ����Ȩ�� 
			DFS(i,head,totalNum,totalWeight);
			//�ж��Ƿ��������Լ���ֵ������ ���ж�Ϊһ��Gange 
			if(totalNum > 2 && totalWeight > K){
				//����haed --> totalNum��ӳ���¼����
				// �˴�map�Զ�ʵ���˰�����ĸ������ 
				Gang[int2string[head]] = totalNum;
			}
		}
	}
} 


/*

����������
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10 

8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10 


*/
int main(){
	string str1,str2;
	int id1, id2;
	int w;
	scanf("%d%d",&N, &K);
	//���룬�Լ���ͼ������Ȩ 
	for (int i = 0; i < N;i++){
		cin >> str1 >> str2 >> w;
		id1 = changeString(str1);
		id2 = changeString(str2);
		G[id1][id2] += w;
		G[id2][id1] += w;
		Weight[id1] += w;
		Weight[id2] += w;
	}
	//��ȵݹ���� �ҵ�ÿ��Gang 
	DFS_Traverse();
	//���Gang���� 
	cout << Gang.size() << endl;
	//�õ�����ȥ����ÿ��Gang����Ϣ 
	map<string,int>::iterator it = Gang.begin();
	//������� 
	for(it;it!=Gang.end();it++){
		cout << it->first <<" "<< it->second << endl;
	} 
	return 0;
} 
