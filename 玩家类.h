 class Player 
 { 
 private: 
    int fraction;//用来存储得分 
    char key;//用来存储按键 
 public: 
 	void addition(); //对方增加一行 
 	void eliminateRow(HANDLE hOut, int map[21][12], int &val, int &fraction, int &checkpoint); 
 	//判断是否能消行并更新分值 
  void level();//难度调整
 }; 
