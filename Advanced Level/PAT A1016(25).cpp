#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1001;

int N;

int fee[24] = {0};

struct record{
	char name[25];
	int month,dd,hh,mm;
	bool status;  //表示online或者off line 
}rec[maxn];

bool cmp(record a,record b){
	int s = strcmp(a.name,b.name);
	if(s != 0){
		return s < 0;
	}
	if(a.month != b.month){
		return a.month < b.month;
	}else if(a.dd != b.dd){
		return a.dd < b.dd;
	}else if(a.hh != b.hh){
		return a.hh < b.hh;
	}else return a.mm < b.mm;
}

void get_ans(int on,int off,int& time,int& money){
	record temp = rec[on];
	while(temp.dd < rec[off].dd || temp.hh < rec[off].hh || temp.mm < rec[off].mm){
		time++;
		money += fee[temp.hh];
		temp.mm++;
		if(temp.mm >= 60){
			temp.hh ++;
			temp.mm = 0;
			if(temp.hh >= 24){
				temp.hh = 0;
				temp.dd++;
			}
		}
	}
}
int main(){
	for(int i = 0; i < 24; i++){
		scanf("%d",&fee[i]);
	}
	scanf("%d",&N);
	char temp[10];
	for(int i = 0; i < N; i++){
		scanf("%s",rec[i].name);
		scanf("%d:%d:%d:%d",&rec[i].month,&rec[i].dd,&rec[i].hh,&rec[i].mm);
		scanf("%s",temp);
		if(strcmp(temp,"on-line") == 0){
			rec[i].status = true;
		}else{
			rec[i].status = false;
		}
	}
	
	sort(rec,rec+N,cmp);
	int on = 0, off,next;
	//遍历一个人的所有记录 
	while(on < N){
		//表示该用户是否需要输出 
		int need = 0;
		next = on;
		while(next < N && strcmp(rec[next].name,rec[on].name) == 0){
			if(need == 0 && rec[next].status == true){
				need = 1;//找到on 
			}else if (need == 1 && rec[next].status == false){
				need = 2; //找到off 
			}
			next++;
		} 
		//没有配对的 
		if(need < 2){
			on = next;
			continue;
		}
		int allMoney = 0;
		printf("%s %02d\n",rec[on].name,rec[on].month);
		//寻找该用户的配对 
		while(on < next){
			while(on < next - 1 && !(rec[on].status == true && rec[on+1].status == false)){
				on++;
			}
			off = on + 1;
			if(off == next){
				on = next; 
				break;
			}
			printf("%02d:%02d:%02d ",rec[on].dd,rec[on].hh,rec[on].mm);
			printf("%02d:%02d:%02d ",rec[off].dd,rec[off].hh,rec[off].mm);
			int time = 0,money = 0;
			get_ans(on,off,time,money);
			allMoney += money;
			printf("%d $%.2f\n",time,money/100.0);
			on = off+1;
		} 
		printf("Total amount: $%.2f\n",allMoney/100.0);
	}
	return 0;
}
