#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MIN 1
#define MAX n
using namespace std;
int main(){
	int n;
	cout<<"请输入玩家人数："<<endl; 
	cin>>n;
	int p[n];//0-红夜阵营，1-黑夜阵营 
	float tic[n];//投票数 
	int sta[n];//玩家状态：0-出局，1-存活 
	int c=0,d=0,e;//c-记录村长，d-记录得票最多者 
	int R,B;//R-红夜阵营存活玩家数，B-黑夜阵营存活玩家数 
	int night;//0-红夜，1-黑夜 
	int Direction;//0-向左，1-向右
	int eye,ce=0,f;//eye-睁眼人数，ce为0表示偶数，为1表示奇数 ，f-计数 
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
		sta[i]=1;
	}//红夜阵营为0；黑夜为1 
	for(int i=0;i<n;i++){
		tic[i]=0;
	}
	cout<<"第一天："<<endl<<"玩家依次投票选取村长："<<endl; 
	loop1:
	for(int i=0,j;i<n;i++){
		cout<<"请玩家"<<i+1<<"投票"<<endl;
		cin>>j;
		tic[j-1]++;
	}
	for(int i=0;i<n;i++){
		 if(tic[i]>tic[c])c=i; 
	} 
	for(int i=c+1;i<n;i++){
		if(tic[i]==tic[c]){
			cout<<"票最多者人数相同，请重新投票。"<<endl;
			goto loop1; 
		}
	}
	for(int i=0;i<n;i++){
		tic[i]=0;
	}//清票 
	cout<<"村长为玩家"<<c+1<<endl; 
	while(1){
		//白天-（判断村长是否存活-选新村长） 
		cout<<"白天"<<endl; 
		if(c==d){
			cout<<"村长已被放逐，请村长指定下一位村长为玩家："<<endl;
			cin>>e;
			c=e-1;
		}
		cout<<"村长决定发言方向："<<endl<<"输入：0-表示向左开始发言；1-表示向右开始发言"<<endl;
		cin>>Direction;
		d=0;
		loop2://发言-投票
		for(int i=0;i<n;i++){
			tic[i]=0;
		}//清票 
		if(Direction==1){
			for(int i=c+1;;i++){
				if(i==n)i=0;
				if(sta[i]==0){
					cout<<"玩家"<<i+1<<"已被放逐"<<endl;
					continue;
				}
				//玩家发言 
				cout<<"轮到玩家"<<i+1<<"发言："<<endl;
				if(i==c)break;
			} 
			for(int i=c+1,j;;i++){
				if(i==n)i=0;
				if(sta[i]==0){
					cout<<"玩家"<<i+1<<"已被放逐"<<endl;
					continue;
				}
				cout<<"请玩家"<<i+1<<"投票"<<endl;
				cin>>j;
				if(i==c&&ce==1){
					if(n%2==0)tic[j-1]+=1.5;
					if(n%2==1)tic[j-1]+=0.5;
					if(i==c)break;
				}
				tic[j-1]++;
				if(i==c)break;
			}
			for(int i=0;i<n;i++){								//放逐 
				if(sta[i]==0)continue;
				if(tic[i]>tic[d])d=i; 
			}
			if(d!=n-1){
				for(int i=d+1;i<n;i++){
					if(tic[i]==tic[d]){//重新开始投票
						goto loop2;
					}
				sta[d]=0;
				}
			}
			if(d==n-1)sta[d]=0;
			R=0,B=0;
			for(int i=0;i<n;i++){
				if(p[i]==0&&sta[i]==1)R++;
				if(p[i]==1&&sta[i]==1)B++;
			}
			cout<<"红夜存活玩家数："<<R<<endl<<"黑夜存活玩家数："<<B<<endl;
			if(R==0){
				cout<<"黑夜阵营玩家胜利！"<<endl;
				return 0;
			}
			if(R==0){
				cout<<"黑夜阵营玩家胜利！"<<endl;
				return 0;
			}
			
			//夜晚
			eye=0;
			night=rand()%2;
			if(night==0)cout<<"红夜降临。"<<endl<<"玩家睁眼阶段："<<endl;
			if(night==1)cout<<"黑夜降临。"<<endl<<"玩家睁眼阶段："<<endl;
			for(int i=c+1;;i++){
				if(i==n)i=0;
				if(sta[i]==0){
					cout<<"玩家"<<i+1<<"已被放逐"<<endl;
					continue;
				}
				cout<<"玩家"<<i+1<<"是否睁眼：（0-不睁眼，1-睁眼）"<<endl;
				cin>>f;
				if(night==0&&p[i]==0&&f==1)eye++; 
				if(night==1&&p[i]==1&&f==1)eye++;
				if(i==c)break; 
			}
			if(eye%2==0)ce=0;
			if(eye%2==0)ce=1;
		
		}
		
		if(Direction==0){
			for(int i=c-1;;i--){
				if(i==-1)i=n-1;
				if(sta[i]==0){
					cout<<"玩家"<<i+1<<"已被放逐"<<endl;
					continue;
				}
				//玩家发言 
				cout<<"轮到玩家"<<i+1<<"发言："<<endl;
				if(i==c)break;
			} 
			for(int i=c-1,j;;i--){
				if(i==-1)i=n-1;
				if(sta[i]==0){
					cout<<"玩家"<<i+1<<"已被放逐"<<endl;
					continue;
				}
				cout<<"请玩家"<<i+1<<"投票"<<endl;
				cin>>j;
				if(i==c&&ce==1){
					if(n%2==0)tic[j-1]+=1.5;
					if(n%2==1)tic[j-1]+=0.5;
					break;
				}
				tic[j-1]++;
				if(i==c)break;
			}
			for(int i=0;i<n;i++){
				if(sta[i]==0)continue;
				if(tic[i]>tic[d])d=i; 
			}
			if(d!=n-1){
				for(int i=d+1;i<n;i++){
					if(tic[i]==tic[d]){//重新开始投票
						goto loop2;
					}
				sta[d]=0;
				}
			}
			if(d==n-1)sta[d]=0;
			R=0,B=0;
			for(int i=0;i<n;i++){
				if(p[i]==0&&sta[i]==1)R++;
				if(p[i]==1&&sta[i]==1)B++;
			}
			cout<<"红夜存活玩家数："<<R<<endl<<"黑夜存活玩家数："<<B<<endl;
			if(R==0){
				cout<<"黑夜阵营玩家胜利！"<<endl;
				return 0;
			}
			if(R==0){
				cout<<"黑夜阵营玩家胜利！"<<endl;
				return 0;
			}
			
			//夜晚
			eye=0;
			night=rand()%2;
			if(night==0)cout<<"红夜降临。"<<endl<<"玩家睁眼阶段："<<endl;
			if(night==1)cout<<"黑夜降临。"<<endl<<"玩家睁眼阶段："<<endl;
			for(int i=c-1;;i--){											//睁眼 
				if(i==-1)i=n-1;
				if(sta[i]==0){
					cout<<"玩家"<<i+1<<"已被放逐"<<endl;
					continue;
				}
				cout<<"玩家"<<i+1<<"是否睁眼：（0-不睁眼，1-睁眼）"<<endl;
				cin>>f;
				if(night==0&&p[i]==0&&f==1)eye++; 
				if(night==1&&p[i]==1&&f==1)eye++; 
				if(i==c)break;
			}
			if(eye%2==0)ce=0;
			if(eye%2==0)ce=1;
		
		}
		
		
	}
	return 0;
}
