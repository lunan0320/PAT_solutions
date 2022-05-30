	#include <cstdio>
	#include <algorithm>
	#include <cstring>
	
	using namespace std;
	
	const int max_problems = 10;
	const int maxn = 10001;
	const int min_score = -1;
	//人数，问题数，提交数量 
	int N, K, M;
	struct student{
		int id;
		int scores[max_problems];
		int perfect_num;
		int total_score;
		bool flag;  //表示是否需要打印 
		student(){
			flag = false;
			total_score = 0;
			perfect_num = 0;
			fill(scores,scores+max_problems,min_score);
		}
		
	}stu[maxn]; 
	
	int perfect[max_problems];
	
	
	bool cmp(student a,student b){
		if(a.total_score != b.total_score){
			return a.total_score > b.total_score;
		}else if(a.perfect_num != b.perfect_num){
			return a.perfect_num > b.perfect_num;
		}else return a.id < b.id;
	}
	
	int main(){
		scanf("%d%d%d",&N,&K,&M);
		for(int i = 1; i<= K;i++){
			scanf("%d",&perfect[i]);
		} 
		for(int i = 1; i <= N; i++){
			stu[i].id = i;
		}
		for(int i = 0; i < M; i++){
			int id,problem_id,problem_score;
			scanf("%d %d %d",&id,&problem_id,&problem_score);
			//取成绩的最大值 
			stu[id].id = id;
			if(problem_score!=-1){
				stu[id].flag = true;
			} 
			if(stu[id].scores[problem_id] == min_score && problem_score == -1){
				stu[id].scores[problem_id] =0;
			}
			if(problem_score == perfect[problem_id] && stu[id].scores[problem_id] < perfect[problem_id]){
				stu[id].perfect_num ++;
			}
			if(problem_score > stu[id].scores[problem_id] ){
				stu[id].scores[problem_id] = problem_score;
			}
	
		}
	
		//设置总分，perfect_num 
		for(int i = 1; i<= maxn;i++){
			for(int j = 1; j <=K;j++){
				if(stu[i].scores[j] != min_score ){
					stu[i].total_score += stu[i].scores[j];
			
				}
			}
		} 
	
		sort(stu+1,stu+N+1,cmp);
		int r = 1;  //初始排名  
		for(int i = 1; i<= N; i++){
			if(stu[i].flag){
				if(i > 1&& stu[i].total_score != stu[i-1].total_score){
					r = i;
				}
				printf("%d %05d %d",r,stu[i].id,stu[i].total_score);
				for(int j = 1; j <= K;j++){
					if(stu[i].scores[j] != min_score ){
						printf(" %d",stu[i].scores[j]);
					}else{
						printf(" -");
					}
				}			
				printf("\n");
			}
		}
		return 0;
	}
	

