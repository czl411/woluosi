 class Block 
 { 
 private: 
     int positionX[4], positionY[4];//方块的坐标 
     bool check;//检测方块是否结束进程  
     int val;//方块下落速度 
 public: 
 void roundBlock();//随机生成方块 
 bool collisionDetection();//检测是否碰撞到边框  
 void myLeft();//左移 
 void myRight();//右移 
 void myUp();//顺时针旋转90度 
 int myDown();//加速下落 
  void myadd();//增行
  void mycut();//消行
 }; 
