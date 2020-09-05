#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MIN 1
#define MAX n
using namespace std;
int main(){
	int n;
	cout<<"���������������"<<endl; 
	cin>>n;
	int p[n];
	int tic[n];//ͶƱ�� 
	int sta[n];//���״̬��0-���֣�1-��� 
	int c=0;//��¼�峤 
	srand(int(time(0)));
	for(int i=0;i<n;i++){
		p[i]=rand()%n;
//		if(i=0)continue;
		for(int j=0;j<i;j++){
			if(p[i]==p[j]){
				i--;
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(p[i]%2==0)p[i]=0;
		if(p[i]%2==1)p[i]=1;
	}//��ҹ��ӪΪ0����ҹΪ1 
	for(int i=0;i<n;i++){
		tic[i]=0;
	}
	cout<<"��һ�죺"<<endl<<"�������ͶƱѡȡ�峤��"<<endl; 
	for(int i=0,j;i<n;i++){
		cout<<"�����"<<i+1<<"ͶƱ"<<endl;
		cin>>j;
		tic[j-1]++;
	}
	for(int i=0;i<n;i++){
		 if(tic[i]>tic[c])c=i; 
	} 
	cout<<"�峤Ϊ���"<<c+1<<endl; 
	return 0;
}

