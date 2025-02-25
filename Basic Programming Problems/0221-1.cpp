#include<iostream>//1.對齊右邊 
using namespace std;
int main(){
	int height;
	cout<<"請輸入三角形高度=> ";
    cin>>height;
    cout<<endl;
	for(int i=1;i<=height;i++){
		for(int j=1;j<=height-i;j++){
			cout<<' ';
		}
		for(int j=1;j<=i;j++){
			cout<<'*';
		}
		cout<<endl;
	} 
	return 0;
}
