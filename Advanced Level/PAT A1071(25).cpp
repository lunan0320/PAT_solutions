#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string,int> my_map;

//�жϵ�ǰ�ַ��Ƿ�����Ч�ַ� 
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
	
	//����һ�е����� 
	getline(cin,input);
	int len = input.length();
	int i = 0;
	while(i < len){
		//����ÿ����Ч�ַ� 
		string word = "";
		//��ǰ�ַ�����Ч�ַ�������� 
		while(i < len && check(input[i])){
			//��д��ĸת��ΪСд�ַ� 
			if(input[i] >= 'A' && input[i] <= 'Z'){
				input[i] = input[i] + 32 ;
			}
			word += input[i];
			i++;
		}
		//����ÿ����Ч�ַ� ����mapӳ�� 
		if(word != ""){
			//�����״γ��ֵĵ��� 
			if(my_map.find(word) == my_map.end()){
				my_map[word] = 1;
			}else{
				my_map[word]++; 
			}
		} 
		//������������Ч�ַ� 
		while(i < len && !check(input[i])){
			i++;
		} 
	}
	select();
	return 0; 
} 

/*
����������
Can1:"Can a can can a can?" It can!"


Ԥ�������
can 5 
*/
