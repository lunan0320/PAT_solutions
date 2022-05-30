#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

map<char,int> beads;

int main()
{
	char s[1001];
	char r[1001];
	cin >> s >> r;
	int len1 = strlen(s);
	int len2 = strlen(r);
	for(int i = 0; i < len1; i++){
		if(beads.find(s[i]) != beads.end()){
			beads[s[i]] ++;
		}else{
			beads[s[i]] = 1;
		}
	} 
	int absent = 0;
	int over = 0;
	for(int i = 0; i < len2; i++){
		if(beads.find(r[i]) == beads.end() || beads[r[i]] == 0){
			absent++;
		}else{
			beads[r[i]]--;
		}
	}
	if(absent != 0){
		printf("No %d\n",absent);
	}else{
		map<char,int>::iterator it = beads.begin();
		for(;it != beads.end(); it++){
			over += it->second;
		}
		printf("Yes %d\n",over);
	}
	return 0;
}
 

