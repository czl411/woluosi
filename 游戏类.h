 class Game 
 { 
 private: 
 	bool check;//检测游戏是否结束进程 
  
 public: 
 int score;//用于计分
 void myStop(HANDLE hOut, int block[4][4]);//游戏暂停 
 void gameOver(HANDLE hOut, int block[4][4], int map[21][12]);//游戏结束 
 }; 
