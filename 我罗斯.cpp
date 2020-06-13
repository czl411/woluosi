#include <iostream>
#include <string>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
using namespace std;

char model;//代表模式
int map[24][14]={0};
int map2[24][14]={0};
int score1=0,score2=0;
int game1=1,game2=0;//记录游戏状态

void SetPos(int i, int j)			//控制光标位置， 列， 行
{
	COORD pos={i,j};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void Setcolor(int color_num)			//设置颜色
{
	int n;
	switch(color_num)
	{
		case 0: n = 0x08; break;
		case 1: n = 0x0F; break;
		case 2: n = 0x0B; break;
		case 3: n = 0x0C; break;
		case 4: n = 0x0D; break;
        case 5: n = 0x0E; break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}

class Insertface{
public:
    void Welcome();
    void Drawmap();
};

void Insertface::Welcome()//描绘欢迎界面
{
    char x;//x为1->单人，x为2->双人
    int i;
    while(1){
        system("cls");
        cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
        for(i=1;i<21;i++){
            SetPos(0,i);cout<<"■";
            SetPos(48,i);cout<<"■";
        }
        cout<<endl<<"■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
        Setcolor(5); SetPos(20,5); cout<<"我罗斯方块"<<endl;
        Setcolor(1); SetPos(21,7); cout<<"模式选择"<<endl;
        SetPos(15,8); cout<<"(请输入数字选择模式)";
        SetPos(20,10); cout<<"1.单人模式";
        SetPos(20,11); cout<<"2.双人模式";
        SetPos(25,13); cin>>x;
        if(x=='1'||x=='2'){
            model=x;
            break;
        }
    }
    system("cls");
    cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
    for(i=1;i<21;i++){
        SetPos(0,i);cout<<"■";
        SetPos(48,i);cout<<"■";
    }
    cout<<endl<<"■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
    Setcolor(5); SetPos(20,4); cout<<"游戏规则";
    Setcolor(1); SetPos(6,6); cout<<"1.玩家通过控制方块的旋转和移动使方块";
    SetPos(8,7); cout<<"排列成完整的一行并消除";
    SetPos(6,9); cout<<"2.当一次消除一行时，得10分";
    SetPos(6,11); cout<<"3.当一次消除超过一行时，除第一行外，";
    SetPos(8,12); cout<<"剩余部分一行得15分";
    SetPos(6,14); cout<<"4.双人模式时，每次得分都会使对手最底";
    SetPos(8,15); cout<<"部增加“此次得分“/10行随机行";
    for(int abc=0;abc<7;abc++){
        SetPos(23,17);
        cout<<6-abc<<" s";
        Sleep(1000);
    }
    system("cls");
    cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
    for(i=1;i<21;i++){
        SetPos(0,i);cout<<"■";
        SetPos(48,i);cout<<"■";
    }
    cout<<endl<<"■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
    Setcolor(5); SetPos(21,5); cout<<"操作方法"<<endl;
    if(model=='1'){
        Setcolor(1); 
        SetPos(21,7); cout << "W - 旋转";
	    SetPos(21,9); cout<<"S - 加速下移";
	    SetPos(21,11); cout<<"A - 左移";
	    SetPos(21,13); cout<<"D - 右移";
    }
    if(model=='2'){
        Setcolor(1);
        SetPos(12,7); cout<<"Player 1          Player 2";
        SetPos(12,9); cout<<"W - 旋转          ↑ - 旋转";
	    SetPos(12,11); cout<<"S - 加速下移      ↓ - 加速下移";
	    SetPos(12,13); cout<<"A - 左移          ← - 左移";
	    SetPos(12,15); cout<<"D - 右移          → - 右移";
    }
    for(int abc=0;abc<6;abc++){
        SetPos(23,17);
        cout<<5-abc<<" s";
        Sleep(1000);
    }
}

void Insertface::Drawmap()//描绘初始地图
{
    int i;
    for(i=0;i<14;i++) map[23][i]=1;
    for(i=0;i<14;i++) map2[23][i]=1;
    system("cls");
    cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
    for(i=1;i<21;i++){
        SetPos(0,i);cout<<"■";
        SetPos(30,i); cout<<"■";
        SetPos(48,i);cout<<"■";
    }
    cout<<endl<<"■■■■■■■■■■■■■■■■■■■■■■■■■";
    SetPos(32,13); cout<<"■■■■■■■■■";
    SetPos(36,10); Setcolor(5); cout<<"下个图案";
    SetPos(36,15); cout<<"当前积分";
    SetPos(36,17);
    cout<<score1;
    if(model=='2'){
        Setcolor(1);
        SetPos(56,0); cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
        for(i=1;i<21;i++){
            SetPos(56,i);cout<<"■";
            SetPos(86,i); cout<<"■";
            SetPos(104,i);cout<<"■";
        }
        SetPos(56,21); cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■";
        SetPos(86,13); cout<<"■■■■■■■■■";
        SetPos(92,10); Setcolor(5); cout<<"下个图案";
        SetPos(92,15); cout<<"当前积分";
        SetPos(90,17); cout<<score2;
    }
    Setcolor(1);
    SetPos(0,23);
}

typedef struct Diamonds
{
    int space[4][4];
}Dia;

class fk {
public:
    Dia dia[7][4];
    void init_dia();//方块初始化 
    void draw_dia(int base, int space_c, int x, int y);//画方块 
    void redraw_dia(int base,int space_c,int x, int y);//消除原来方块
    bool judge(int base,int space_c,int x, int y,int f);  
    bool pd(int base,int space_c,int f,int flag,int x,int y);//判断其是否能左右或加速移动 
    bool collisionDetection(int base,int space_c, int f, int x, int y);//判断其是否能旋转
    void stop();//暂停 
    int map_clean(int x,int t);
};

void fk::stop()//暂停
{
	while(1)
	{
	if(GetAsyncKeyState('G')&0x8000) break;
	}
	return;
}

void fk::init_dia()//方块初始化
{
    int i, j, k, z;
    for (i = 0; i < 7; i++)
    {
        for (z = 0; z < 3; z++)
        {
            for (j = 0; j < 4; j++)
            {
                for (k = 0; k < 4; k++)
                {
                     dia[i][z].space[j][k]=0;
                }
            }
        }
    }
    int tmp[4][4];
    for (i = 0; i < 3; i++)
        dia[0][0].space[1][i] = 1;
    dia[0][0].space[2][1] = 1;

    for (i = 1; i < 4; i++)
        dia[1][0].space[i][1] = 1;
    dia[1][0].space[1][2] = 1;

    for (i = 1; i < 4; i++)
        dia[2][0].space[i][2] = 1;
    dia[2][0].space[1][1] = 1;

    for (i = 0; i < 2; i++)
    {
        dia[3][0].space[1][i] = 1;
        dia[3][0].space[2][i + 1] = 1;

        dia[4][0].space[1][i + 1] = 1;
        dia[4][0].space[2][i] = 1;

        dia[5][0].space[1][i + 1] = 1;
        dia[5][0].space[2][i + 1] = 1;
    }
    for (i = 0; i < 4; i++)
        dia[6][0].space[i][2] = 1;

    for (i = 0; i < 7; i++)
    {
        for (z = 0; z < 3; z++)
        {
            for (j = 0; j < 4; j++)
            {
                for (k = 0; k < 4; k++)
                {
                    tmp[j][k] = dia[i][z].space[j][k];
                }
            }
            for (j = 0; j < 4; j++)
            {
                for (k = 0; k < 4; k++)
                {
                    dia[i][z + 1].space[j][k] = tmp[4 - k - 1][j];
                }
            }
        }
    }
}

void fk::draw_dia(int base, int space_c, int x, int y)//画方块
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (dia[base][space_c].space[i][j] == 1&&x+i>0){
			    SetPos(2*(j+y),i+x);
			    cout<<"■";
            } 
        }
    }
}

void fk::redraw_dia(int base,int space_c,int x, int y)//消除原来方块
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (dia[base][space_c].space[i][j] == 1&&x+i>0){
			    SetPos(2*(j+y),i+x);
			    cout<<"  ";
            } 
        }
    }
}

bool fk::judge(int base,int space_c,int x, int y,int f)//判断方块是否已经到达底部
{
    int i, j,m,n;
    if(f==1)
    {
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (dia[base][space_c].space[i][j] == 1&&map[x+i+3][y-1+j]==1){ 
                for(n=0;n<4;n++){
                    for(m=0;m<4;m++) if (dia[base][space_c].space[n][m] == 1) map[x+2+n][y-1+m]=1;
                }
                return 1;
            }
        }
    }
    return 0;	
	}
    else 
    {
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (dia[base][space_c].space[i][j] == 1&&map2[x+i+1][y-1+j]==1){ 
                for(n=0;n<4;n++){
                    for(m=0;m<4;m++) if (dia[base][space_c].space[n][m] == 1) map2[x+n][y-1+m]=1;
                }
                return 1;
            }
        }
    }
    return 0;
	}
}

bool fk::pd(int base,int space_c,int f,int flag,int x,int y)//判断其是否能左右移动
{
	int i,j,f1=-1,f2=-1;
	if(flag==1)
	{
	if(f==1)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			if(dia[base][space_c].space[j][i]==1)
			{
				if(y+i>1) 
				{
					f1=1;
					break;
				}
				else
				{
					f1=0;
					break;
				 } 
			}
			if(f1!=-1) break;
		}
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(dia[base][space_c].space[j][i] == 1)
				{
					if(map[x+j+3][y-1+i-1]==1)
					f2=0;
				}
			}
		}
		if(f2!=0) f2=1;
	}
	else if(f==2)
	{
		for(i=3;i>-1;i--)
		{
			for(j=0;j<4;j++)
			if(dia[base][space_c].space[j][i]==1)
			{
				if(y+i<14) 
				{
					f1=1;
					break;
				}
				else 
				{
					f1=0;
					break;
				}
			}
			if(f1!=-1) break;
		}
		for(i=3;i>-1;i--)
		{
			for(j=0;j<4;j++)
			{
				if(dia[base][space_c].space[j][i] == 1)
				{
					if(map[x+j+3][y+i]==1)
					f2=0;
				}
			}
		}
		if(f2!=0) f2=1;
	}	
	}
	else 
	{
	if(f==1)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			if(dia[base][space_c].space[j][i]==1)
			{
				if(y+i-28>1) 
				{
					f1=1;
					break;
				}
				else
				{
					f1=0;
					break;
				 } 
			}
			if(f1!=-1) break;
		}
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(dia[base][space_c].space[j][i] == 1)
				{
					if(map2[x+j+1][y-1+i-1]==1)
					f2=0;
				}
			}
		}
		if(f2!=0) f2=1;
	}
	else {
		for(i=3;i>-1;i--)
		{
			for(j=0;j<4;j++)
			{
				if(dia[base][space_c].space[j][i] == 1)
				{
					if(map2[x+j+1][y+i]==1)
					f2=0;
				}
			}
		}
		if(f2!=0) f2=1;
		for(i=3;i>-1;i--)
		{
			for(j=0;j<4;j++)
			if(dia[base][space_c].space[j][i]==1)
			{
				if(y+i-28<14) 
				{
					f1=1;
					break;
				}
				else 
				{
					f1=0;
					break;
				}
			}
			if(f1!=-1) break;
		}
	}	
	}
	if(f2==1&&f1==1) return true;
	return false;	
} 

bool fk::collisionDetection(int base, int space_c, int f, int x, int y)//判断其是否能旋转
{
	if(f==1)
	{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (dia[base][space_c].space[i][j]==1 )
			{
				if(y+j<1||y+j>14)
				return false;
				if(map[x+i+3][y-1+j]==1)
				return false;
			}
		}
	}
	return true;	
	}
	else 
	{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (dia[base][space_c].space[i][j]==1 )
			{
				if(y+j-28<1||y+j-28>14)
				return false;
				if(map2[x+i+3][y-1+j]==1)
				return false;
			}
		}
	}
	return true;	
	}
}
void hidden_cursor()
{
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(hOut,&cci);
  cci.bVisible=0;
  SetConsoleCursorInfo(hOut,&cci);
}//隐藏光标

void map_draw(int f)//在地图中显示当前地图内的情况
{
    int i,j;
    Setcolor(3);
    if(f==1)
    {
    for(i=0;i<20;i++){
        for(j=0;j<14;j++){
            if(map[i+3][j]==1){
                SetPos(2*(j+1),i+1);
                cout<<"■";
            }
        }
    }
	}
    else
    {
    for(i=0;i<20;i++){
        for(j=0;j<14;j++){
            if(map2[i+3][j]==1){
                SetPos(2*(j+29),i+1);
                cout<<"■";
            }
        }
    }
	}
	Setcolor(1);
}

int fk::map_clean(int x,int t)//判断地图中是否有完整行，并进行消除计分
{
	int i,j,clean,n,m,number=0;
    int k,l;
	if(t==1)
	{
    for(i=-1;i<4;i++){
        clean=0;
        if(i+x>0&&i+x<20){
		    for(j=0;j<14;j++) clean=clean+map[i+x+3][j];
		}
        if(clean==14){
            for(n=i+x;n>=0;n--){
                for(m=0;m<14;m++) map[n+3][m]=map[n+2][m];
            }
            if(number==0) number+=10;
            else number+=15;
        }
    }
    if(number!=0){
        for(k=0;k<20;k++){
            for(l=0;l<14;l++){
                SetPos(2*(l+1),k+1);
                cout<<"  ";
			}
		}
	}
    for(i=0;i<20;i++){
        for(j=0;j<14;j++){
            if(map2[i+3][j]==1){
                SetPos(2*(j+29),i+1);
                cout<<"  ";
            }
        }
    }
    for(i=0;i<number/10;i++){	
        for(j=0;j<19;j++){
            for(m=0;m<14;m++) map2[j+3][m]=map2[j+4][m];
        }  
		if(game2==1) for(m=0;m<14;m++) map2[22][m]=rand()%2;
		else break;   
    }
    map_draw(2);
    int judge=0;
    for(i=0;i<14;i++) judge+=map2[3][i];
    if(judge>0) game2=0;
    map_draw(1);
    return number;	
	}
    else 
    {
    for(i=-1;i<4;i++){
        clean=0;
        if(i+x>0&&i+x<20){
            for(j=0;j<14;j++) clean=clean+map2[i+x+3][j];
        }
        cout<<endl;
        if(clean==14){
            for(n=i+x;n>=0;n--){
                for(m=0;m<14;m++) map2[n+3][m]=map2[n+2][m];
            }
            if(number==0) number+=10;
            else number+=15;
        }
	}
    if(number!=0){
        for(k=0;k<20;k++){
            for(l=0;l<14;l++){
                SetPos(2*(l+29),k+1);
                cout<<"  ";
			}
	    }
    }
    for(i=0;i<20;i++){
        for(j=0;j<14;j++){
            if(map[i+3][j]==1){
                SetPos(2*(j+1),i+1);
                cout<<"  ";
            }
        }
    }
    for(i=0;i<number/10;i++){
        for(j=0;j<19;j++){
            for(m=0;m<14;m++) map[j+3][m]=map[j+4][m];
        }
        if(game1==1)
        for(m=0;m<14;m++) map[22][m]=rand()%2;
        else break;
    }
    map_draw(1);
    int judge=0;
    for(i=0;i<14;i++) judge+=map[3][i];
    if(judge>0) game1=0;
    map_draw(2);
    return number;
	}
}

class Game{
	public:
		void game();
};
void Game::game()
{
	Game kk;
	Insertface face;
    face.Welcome();
    face.Drawmap();
	int g1,g2,i,j,g_over,t=0;
    fk b;
    if(model=='2') game2=1;
    int x=-1,y=6,x2=-1,y2=34;
    int nn,space_c,n,m;
    int nn2,space_c2,n2,m2;
    b.init_dia();
    srand(time(0));
    nn = rand() % 7; 
	space_c = rand() % 4;
    nn2=rand()%7; 
	space_c2=rand()%4;
    n=rand()%7;
	m=rand()%4;
    n2=rand()%7; 
	m2=rand()%4;
    while(1){
    		b.draw_dia(n,m,2,18);
   	        b.draw_dia(nn,space_c,x,y);
   	    if(game2==1)
   	    {
   	    	b.draw_dia(n2,m2,2,46);
   	        b.draw_dia(nn2,space_c2,x2,y2);
   	        g2=1;
		}
        t=5;g1=1;
        while(--t){
        	if(game1==1){
        		b.redraw_dia(n,m,2,18);
				b.draw_dia(n,m,2,18);
			}
			if(game2==1){
				b.redraw_dia(n2,m2,2,46);
			    b.draw_dia(n2,m2,2,46);
			}
            if(game1==1&&GetAsyncKeyState('A')&0x41&&b.pd(nn,space_c,1,1,x,y)){
				b.redraw_dia(nn,space_c,x,y--);
				b.draw_dia(nn,space_c,x,y);
			}
            if(game2==1&&GetAsyncKeyState(VK_LEFT)&0x25&&b.pd(nn2,space_c2,1,2,x2,y2)){
				b.redraw_dia(nn2,space_c2,x2,y2--);
				b.draw_dia(nn2,space_c2,x2,y2);
			}
            if(game1==1&&GetAsyncKeyState('D')&0x8000&&b.pd(nn,space_c,2,1,x,y)){
				b.redraw_dia(nn,space_c,x,y++);
            	b.draw_dia(nn,space_c,x,y);
			}
            if(game2==1&&GetAsyncKeyState(VK_RIGHT)&0x27&&b.pd(nn2,space_c2,2,2,x2,y2)){
				b.redraw_dia(nn2,space_c2,x2,y2++);
            	b.draw_dia(nn2,space_c2,x2,y2);
			}
			if(game1==1&&GetAsyncKeyState('S')&0x53&&b.judge(nn,space_c,x,y,1)==0){
				b.redraw_dia(nn,space_c,x++,y);
            	b.draw_dia(nn,space_c,x,y);
			} 
            if(game2==1&&(GetAsyncKeyState(VK_DOWN)&0x8000)&&b.judge(nn2,space_c2,x2,y2,2)==0){
				b.redraw_dia(nn2,space_c2,x2++,y2);
            	b.draw_dia(nn2,space_c2,x2,y2);
			}
            if(game1==1&&GetAsyncKeyState('W')&0x57&&b.collisionDetection(nn,(space_c+1)%4,1,x,y)==1){
			    b.redraw_dia(nn,space_c,x,y);
			    space_c++;
			    space_c%=4;
				b.draw_dia(nn,space_c,x,y);
			}
            if(game2==1&&GetAsyncKeyState(VK_UP)&0x8000&&b.collisionDetection(nn2,(space_c2+1)%4,2,x2,y2)==1){
			    b.redraw_dia(nn2,space_c2,x2,y2);
			    space_c2++;
			    space_c2%=4;
				b.draw_dia(nn2,space_c2,x2,y2);
			}
			if(GetAsyncKeyState(VK_SPACE)&0x8000){
				b.stop();
			}
			if(GetAsyncKeyState(VK_ESCAPE)&0x8000){
				system("cls");
				exit(0);
			}
            Sleep(120);
		}
        if(game1==1&&b.judge(nn,space_c,x,y,1)){
            b.redraw_dia(n,m,2,18);
            map_draw(1);
            score1+=b.map_clean(x,1);
            x=-1;y=6;
            nn=n;
            space_c=m;
            n=rand()%7;m=rand()%4;
            SetPos(36,17);
            cout<<score1;
            g_over=0;
            for(i=0;i<14;i++) g_over+=map[3][i];
            if(g_over>0) game1=0;
            g1=0;
            if(game1+game2==0) break;
        }
        if(game2==1&&b.judge(nn2,space_c2,x2,y2,2)){
            b.redraw_dia(n2,m2,2,46);
            map_draw(2);
            score2+=b.map_clean(x2,2);
            x2=-1;y2=34;
            nn2=n2;
            space_c2=m2;
            n2=rand()%7;
			m2=rand()%4;
            SetPos(90,17);
            cout<<score2;
            g_over=0;
            for(i=0;i<14;i++) g_over+=map2[3][i];
            if(g_over>0) game2=0;
            g2=0;
            if(game1+game2==0) break;
        }
        if(game1==1&&g1==1){
            b.redraw_dia(n,m,2,18);
		    b.draw_dia(n,m,2,18);
            b.redraw_dia(nn,space_c,x++,y);
            b.draw_dia(nn,space_c,x,y);	
        }
        if(game2==1&&g2==1){
            b.redraw_dia(n2,m2,2,46);
		    b.draw_dia(n2,m2,2,46);
            b.redraw_dia(nn2,space_c2,x2++,y2);
            b.draw_dia(nn2,space_c2,x2,y2);	
        }
	}
	if(game1+game2==0) system("cls");
    cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
    for(i=1;i<21;i++){
        SetPos(0,i);cout<<"■";
        SetPos(48,i);cout<<"■";
    }
    cout<<endl<<"■■■■■■■■■■■■■■■■■■■■■■■■■";
    SetPos(36,17);
    cout<<score1;
    if(model=='2'){
        Setcolor(1);
        SetPos(56,0); cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
        for(i=1;i<21;i++){
            SetPos(56,i);cout<<"■";
            SetPos(104,i);cout<<"■";
        }
        SetPos(56,21); cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■";
    }
    if(model=='2')
    {
    	if(score1>score2)
    	{
    		SetPos(16,8); cout<<"You Win!";
            SetPos(72,8); cout<<"You Lose";
		}
        else if(score1<score2)
        {
        	SetPos(16,8); cout<<"You Lose";
            SetPos(72,8); cout<<"You Win!";
		}
		else 
		{
			SetPos(16,8); cout<<"平局";
            SetPos(72,8); cout<<"平局";
		}
        SetPos(16,10); cout<<"你的分数："<<score1;
        SetPos(16,12); cout<<"对手分数："<<score2;
        SetPos(72,10); cout<<"你的分数："<<score2;
        SetPos(72,12); cout<<"对手分数："<<score1;
	}
    else 
    {
    	SetPos(16,10); cout<<"你的分数为："<<score1;
	} 
}

int main(){
    hidden_cursor();
    Game a;
    a.game();
    SetPos(0,23);
    system("pause");
    return 0;
}
