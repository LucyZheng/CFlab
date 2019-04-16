#include <iostream>
#include <string>
using namespace std;
int main(){
	string str,newstr;
	cin>>str;
	for (int i=0;i<str.size();++i){
		int flag=1;
		for (int j=0;j<newstr.size();++j){
			if (str[i]==newstr[j])
				flag=0;
		}
		if (flag) newstr+=str[i];
	}
	for (int i=0;i<newstr.size();++i){
		for (int j=0;j<newstr.size()-i-1;++j){
			if (newstr[j]>newstr[j+1]){
				char tmp =newstr[j];
				newstr[j]=newstr[j+1];
				newstr[j+1]=tmp;
			}
		}
	}
	cout<<newstr<<endl;
}
