#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

//Ϊ�գ���ʾû�г���
//Ϊ1��ʾ���ֻ����Ѿ���ӡ

int main()
{
	char s[81],r[81];
	bool map[200]={0};
	cin>>s>>r; 
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='a'&&s[i]<='z')s[i]=s[i]-32;
		if(map[s[i]]==false){
			map[s[i]]=true;
		}
	}
	for(int i=0;i < strlen(r);i++){
		if(r[i]>='a'&&r[i]<='z')r[i]=r[i]-32;
		if(map[r[i]]==true){
			map[r[i]]=false;
		}
	}
	for(int i=0;i<strlen(s);i++){
		if(map[s[i]]==true){
			map[s[i]]=false;
			cout<<s[i];
		}		
	}	
	return 0;
}
 

