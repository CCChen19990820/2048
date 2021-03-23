#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void primap();
void prinum();
int newnum();
void put_onmap(int next,int map[][4]);
void prinum();
void moving(char c);
void move_up();
void move_down();
void move_right();
void move_left();
void plus_up();
void plus_down();
void plus_right();
void plus_left();

int new1,open=1;
int map[4][4]={0};
char input;
int main(){
	srand(time(NULL));
	new1=newnum();
	put_onmap(new1,map);
	new1=newnum();
	put_onmap(new1,map);
	primap();
	while(1){
		open=1;
		//input=getchar();
//		if(input!='w'&&input!='s'&&input!='a'&&input!='d'){
//			continue;
//		}
		system("clear");
		//moving(input);
		int xxx=(rand()%2);
		if(xxx==0)
			moving('a');
		if(xxx==1)
			moving('s');
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(map[j][i]==0)
					open=0;
			}
		}
		if(open==0){
			new1=newnum();
			put_onmap(new1,map);	
		}
		else{
			open=0;
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					if(map[i][j]==map[i-1][j]||map[i][j]==map[i+1][j]||map[i][j]==map[i][j-1]||map[i][j]==map[i][j+1]){
						open=1;
						break;
					}
				}
			}
			if(open==1)
				printf("You can't move this direction!\n");
			if(open==0){
				printf("QQ, Loser!!\n");
				primap();
				break;
			}
		}
		primap();
	}
	return 0;
}
void moving(char c){
	if(c=='w'){
		move_up();
		plus_up();
		move_up();
	}
	if(c=='s'){
		move_down();
		plus_down();
		move_down();
	}
	if(c=='a'){
		move_left();
		plus_left();
		move_left();
	}
	if(c=='d'){
		move_right();
		plus_right();
		move_right();
	}
	return;
}

void move_up(){
	for(int i=1;i<4;i++){
		for(int j=0;j<4;j++){
			if(map[i][j]!=0){
				for(int k=0;k<i;k++){
					if(map[k][j]==0){
						map[k][j]=map[i][j];
						map[i][j]=0;
						break;
					}
				}
			}
		}
	}
	return;
}
void move_down(){
	for(int i=2;i>=0;i--){
		for(int j=0;j<4;j++){
			if(map[i][j]!=0){
				for(int k=3;k>i;k--){
					if(map[k][j]==0){
						map[k][j]=map[i][j];
						map[i][j]=0;
						break;
					}
				}
			}
		}
	}
	return;
}
void move_right(){
	for(int i=2;i>=0;i--){
		for(int j=0;j<4;j++){
			if(map[j][i]!=0){
				for(int k=3;k>i;k--){
					if(map[j][k]==0){
						map[j][k]=map[j][i];
						map[j][i]=0;
						break;
					}
				}
			}
		}
	}
	return;
}
void move_left(){
	for(int i=1;i<4;i++){
		for(int j=0;j<4;j++){
			if(map[j][i]!=0){
				for(int k=0;k<i;k++){
					if(map[j][k]==0){
						map[j][k]=map[j][i];
						map[j][i]=0;
						break;
					}
				}
			}
		}
	}
	return;
}

void plus_up(){
	for(int i=1;i<4;i++){
		for(int j=0;j<4;j++){
			if(map[i][j]==map[i-1][j]){
				map[i-1][j]*=2;
				map[i][j]=0;
			}
		}
	}
	return;
}
void plus_down(){
	for(int i=2;i>=0;i--){
		for(int j=0;j<4;j++){
			if(map[i][j]==map[i+1][j]){
				map[i+1][j]*=2;
				map[i][j]=0;
			}
		}
	}
	return;
}
void plus_right(){
	for(int i=2;i>=0;i--){
		for(int j=0;j<4;j++){
			if(map[j][i]==map[j][i+1]){
				map[j][i+1]*=2;
				map[j][i]=0;
			}
		}
	}
	return;
}
void plus_left(){
	for(int i=1;i<4;i++){
		for(int j=0;j<4;j++){
			if(map[j][i]==map[j][i-1]){
				map[j][i-1]*=2;
				map[j][i]=0;
			}	
		}
	}
	return;
}

void
primap(){
	printf("* * * * * * * * * * * * *\n");
	printf("*     *     *     *     *\n");
	prinum(map[0][0]);prinum(map[0][1]);
	prinum(map[0][2]);prinum(map[0][3]);printf("*\n");
	printf("*     *     *     *     *\n");
	printf("* * * * * * * * * * * * *\n");
	printf("*     *     *     *     *\n");
	prinum(map[1][0]);prinum(map[1][1]);
	prinum(map[1][2]);prinum(map[1][3]);printf("*\n");
	printf("*     *     *     *     *\n");
	printf("* * * * * * * * * * * * *\n");
	printf("*     *     *     *     *\n");
	prinum(map[2][0]);prinum(map[2][1]);
	prinum(map[2][2]);prinum(map[2][3]);printf("*\n");
	printf("*     *     *     *     *\n");
	printf("* * * * * * * * * * * * *\n");
	printf("*     *     *     *     *\n");
	prinum(map[3][0]);prinum(map[3][1]);
	prinum(map[3][2]);prinum(map[3][3]);printf("*\n");
	printf("*     *     *     *     *\n");
	printf("* * * * * * * * * * * * *\n");
	return;
}

int newnum(){
	int new1;
	new1=(rand()%10);
	if(new1==9)
		return 4;
	else
		return 2;
}
void put_onmap(int next,int map[][4]){
	int x,y,stop=0;
	while(1){
		x=(rand()%4);
		y=(rand()%4);
		if(map[y][x]==0){
			map[y][x]=next;
			break;
		}
	}
	return;
}
void prinum(int n){
	if(n==0)
		printf("*     ");
	if(n>0&&n<10)
		printf("*  %d  ",n);
	if(n>10&&n<100)
		printf("*  %d ",n);
	if(n>100&&n<1000)
		printf("* %d ",n);
	if(n>1000)
		printf("* %d",n);
}
