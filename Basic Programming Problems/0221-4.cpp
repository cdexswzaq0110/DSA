#include<iostream>//4.�ŤߤT���� 
using namespace std;
int main(){
	int height;
	cout<<"�п�J�T���ΰ���=> ";
    cin>>height;
    cout<<endl;
	for(int i=1;i<=height;i++){
		for(int j=1;j<=2*height-1;j++){
			if(i+j==height+1||j-i==height-1||i==height) //������B�k����B���� 
			   cout<<"*";
			else
			   cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
