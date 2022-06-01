#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10010;

int N;


bool cmp(string a,string b){
	return a+b < b+a;
}
string arr[maxn];


int main(){
	scanf("%d",&N);
	string s;
	for(int i = 0; i < N;i++){
		cin >> s;
		arr[i] = s;
	}
	sort(arr,arr+N,cmp);
	string ans = "";
	for(int i = 0; i < N;i++){
		ans += arr[i];
	}
	while(ans[0] == '0' && ans.length() > 0){
		ans = ans.substr(1);
	}
	if(ans.length() ==0){
		cout << "0" << endl;
	}else{
		cout << ans << endl;
	}
	return 0;
}
