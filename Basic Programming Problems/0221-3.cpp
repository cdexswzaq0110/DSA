#include<iostream>//3.��ӥ��k��� 
using namespace std;
int main(){
	int h;
	cout<<"�п�J�T���ΰ���=> ";
    cin>>h;
    cout<<endl;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=h-i;j++){
			cout<<' ';
		}
		for(int j=1;j<=2*i-1;j++){
			cout<<'*';
		}
		for(int j=1;j<=h-i;j++){
			cout<<' ';
			cout<<' ';
		}
		for(int j=1;j<=2*i-1;j++){
			cout<<'*';
		}
		cout<<endl;
	} 
	return 0;
}
