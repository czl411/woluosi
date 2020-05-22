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
 }; 
int block00[4][4] = { { 10,0,0,0 },{ 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } };
int block01[4][4] = { { 11,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 } };
int block02[4][4] = { { 12,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 0,1,0,0 } };
int block03[4][4] = { { 13,0,0,0 },{ 0,1,0,0 },{ 1,1,0,0 },{ 0,1,0,0 } };
int block04[4][4] = { { 14,0,0,0 },{ 0,0,0,0 },{ 0,1,0,0 },{ 1,1,1,0 } };
int block05[4][4] = { { 15,0,0,0 },{ 0,1,0,0 },{ 0,1,1,0 },{ 0,1,0,0 } };
int block06[4][4] = { { 16,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 1,0,0,0 } };
int block07[4][4] = { { 17,0,0,0 },{ 1,1,0,0 },{ 0,1,0,0 },{ 0,1,0,0 } };
int block08[4][4] = { { 18,0,0,0 },{ 0,0,0,0 },{ 0,0,1,0 },{ 1,1,1,0 } };
int block09[4][4] = { { 19,0,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 0,1,1,0 } };
int block10[4][4] = { { 20,0,0,0 },{ 0,0,0,0 },{ 1,1,0,0 },{ 0,1,1,0 } };
int block11[4][4] = { { 21,0,0,0 },{ 0,0,1,0 },{ 0,1,1,0 },{ 0,1,0,0 } };
int block12[4][4] = { { 22,0,0,0 },{ 0,0,0,0 },{ 1,1,0,0 },{ 1,1,0,0 } };
int* roundBlock(){
    int num;
    num=rand()%13;
    switch(num){
        case 0:return block00;
        case 1:return block01;
        case 2:return block02;
        case 3:return block03;
        case 4:return block04;
        case 5:return block05;
        case 6:return block06;
        case 7:return block07;
        case 8:return block08;
        case 9:return block09;
        case 10:return block10;
        case 11:return block11;
        case 12:return block12;
    }
}
