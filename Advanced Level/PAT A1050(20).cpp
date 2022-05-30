#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;


int main()
{	
	int HashTable[10001] = {0};
	char s1[10001];
	char s2[10001];
	cin.getline(s1,10001);
	cin.getline(s2,10001);
//	int k = 0;
//	while(getchar()!='\n'){
//		s1[k++] = getchar();
//	}
//	k = 0;
//	while(getchar()!='\n'){
//		s2[k++] = getchar();
//	}
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	for(int i = 0; i < len1; i++){
		HashTable[s1[i]]++;
	}
	for(int i= 0; i < len2; i++){
		HashTable[s2[i]] = 0;
	}
	for(int i = 0; i < len1;i++){
		if(HashTable[s1[i]] >= 1){
			printf("%c",s1[i]);
			HashTable[s1[i]]--;
		}
	}
	return 0;
}
 

