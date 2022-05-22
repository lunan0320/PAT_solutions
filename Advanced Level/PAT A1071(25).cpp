#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string,int> my_map;

//判断当前字符是否是有效字符 
bool check(char c){
	if(c >= '0' && c <= '9'){
		return true;
	}else if(c >= 'a' && c <= 'z'){
		return true;
	}else if (c >= 'A' && c <= 'Z'){ 
		return true;
	}else{
		return false;
	}
}

void select(){
	map<string,int>::iterator it = my_map.begin();
	int max = -1;
	string res;
	while(it != my_map.end()){
		if(it->second > max){
			max = it->second;
			res = it->first;
		}
		it++;
	}
	cout << res << " " << max << endl;
}

int main(){
	string input;
	
	//接收一行的输入 
	getline(cin,input);
	int len = input.length();
	int i = 0;
	while(i < len){
		//划分每个有效字符 
		string word = "";
		//当前字符是有效字符，则加入 
		while(i < len && check(input[i])){
			//大写字母转换为小写字符 
			if(input[i] >= 'A' && input[i] <= 'Z'){
				input[i] = input[i] + 32 ;
			}
			word += input[i];
			i++;
		}
		//对于每个有效字符 建立map映射 
		if(word != ""){
			//对于首次出现的单词 
			if(my_map.find(word) == my_map.end()){
				my_map[word] = 1;
			}else{
				my_map[word]++; 
			}
		} 
		//跳过连续的无效字符 
		while(i < len && !check(input[i])){
			i++;
		} 
	}
	select();
	return 0; 
} 

/*
测试样例：
Can1:"Can a can can a can?" It can!"


预期输出：
can 5 
*/
