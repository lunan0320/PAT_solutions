#include <cstdio>
#include <algorithm>

using namespace std;

double Cmax,D,Davg;
int N;

const int maxn = 501;

struct Station{
	double price;
	double pos;
}station[maxn];

bool cmp(Station a,Station b){
	return a.pos < b.pos;
}


int main(){
	scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N);
	for(int i = 0; i < N; i++){
		scanf("%lf %lf",&station[i].price,&station[i].pos);
	}
	station[N].pos = D;
	station[N].price = 0;
	
	sort(station,station+N,cmp);
	
	if(station[0].pos != 0){
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	
	
	int now = 0;// ��ʾ��ǰ���ĸ�����վ
	
	double add_gas = 0; //���������վ�Ӷ��� 
	double left_gas = 0; //��ǰʣ�� 
	double total_sum = 0;
	//��һ���ͼ۸��͵�
	bool flag = false; 
	double now_pos = 0;
	double MAX = Davg * Cmax;
	double needTank = 0; 
	while(now < N){
		int k  = -1; //���뵱ǰ����վ����Ҽ۸����
		double priceMin = 100000000;
		//��һ���ͼ۸��ͻ�����͵���һ��վ 
		for(int i = now+1; i <= N && (station[i].pos - station[now].pos)<= MAX; i++){
			if(station[i].price < priceMin){
				
				k = i;
				priceMin = station[i].price;
				if(priceMin < station[now].price){
					break;
				}
			}
		} 
		if(k==-1){
			break;
		}
		//�Ҹ��͵�ʱ��
		double need = (station[k].pos - station[now].pos) / Davg;
		if(priceMin < station[now].price){
			if(needTank < need){
				total_sum += (need - needTank) * station[now].price;
				needTank = 0;
			}else{
				needTank -= need;
			}
		}else{
			//û�и��͵�
			total_sum +=(Cmax - needTank) * station[now].price;
			needTank = Cmax - need;
		}	
		now = k;	
	}
	if(now == N){
		printf("%.2f\n",total_sum);
	}else{
		printf("The maximum travel distance = %.2f\n",station[now].pos + MAX);
	}
	

	return 0;
}
