#include<iostream>//4.空心三角形 
using namespace std;
int main(){
	int height;
	cout<<"請輸入三角形高度=> ";
    cin>>height;
    cout<<endl;
	for(int i=1;i<=height;i++){
		for(int j=1;j<=2*height-1;j++){
			if(i+j==height+1||j-i==height-1||i==height) //左斜邊、右斜邊、底邊 
			   cout<<"*";
			else
			   cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
