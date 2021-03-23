char AIGenNextMove(int b[4][4]) {
	char move ; //move = 'w', 's', 'a', or 'd'
	/*Your code goes here*/
	char cc[4]={'w','s','a','d'};
	int s[4]={-1};
	char c;
	int tmp[4][4];
	int tmp1[4][4];
	int judge[4]={0};
	for(int j=0;j<3000;j++){
		score=0;
		same(tmp,b);
		same(tmp1,tmp);
		UpdateBoard(tmp, cc[j%4]);  
		if (!AreEqual(tmp, b)) {
			AddNewNumber(tmp);
			for(int i=0;i<3000;i++){
				same (tmp1,tmp);
				c=cc[rand()%4];
				UpdateBoard(tmp, c);  
				if (!AreEqual(tmp, tmp1)){
					AddNewNumber(tmp);
				}
				if(IsGameOver(tmp))
					break;
			}
			judge[j%4]+=score;
		}
	}
	int max=0;
	for(int i=0;i<4;i++){
		if(judge[i]>max){
			move=cc[i];
			max=judge[i];
		}
	} 
	return move;
}
