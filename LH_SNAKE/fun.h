#ifndef _FUN_H_
#define _FUN_H_

/*定义常量*/
#define PASSNUM 30				//定义过关的食物数量
#define IMGNUM 20				//定义屏幕中主要放置游戏背景的小图片的个数
#define KSCREEN_WIDTH IMGNUM * 32		//屏幕的宽度
#define KSCREEN_HEIGHT (IMGNUM+1) * 32		//屏幕的高度
#define KSCREEN_BPP 32			//屏幕的刷新频率
#define speed 160


/*定义游戏中用到的坐标*/
typedef struct LOCATION
{
	int x;
	int y;
}TBLOCK;							

/*关于蛇的*/
extern TBLOCK gSnake[PASSNUM];				//记录蛇身体的各个图块的坐标
extern short possition[PASSNUM];				//记录蛇各部分的位置
extern int gLength;					//记录蛇的长度
extern int gDirection;					//蛇的方向 1:右,2:上,3:左，4:下

/*关于食物*/
extern TBLOCK gFood;					//记录食物的坐标
extern int foodNum;					//记录食物的数量


/*关于屏幕*/
//SDL_Surface *image = NULL;
extern SDL_Surface *screen;					//屏幕图块指针
extern SDL_Surface *gOptimizedImage[27];	//游戏中所有图片
extern short gStaticMap[IMGNUM + 1][IMGNUM];		//游戏的地图
void score(int num);						//记录分数

/*文字信息*/
extern TTF_Font *overTxt;				
extern SDL_Surface * gameFace;
extern SDL_Surface *Txt;



/************************************************************************/
/* 函数                                                                 */
/************************************************************************/

int init(void);								//SDL初始化
void initImages(void);						//图片初始化
void grass(void);						//草地覆盖函数
void initNowMaps(void);						//显示背景图片
int judgeOver(void);						//判断结束函数
void quitGame(void);						//退出游戏
void showOverFace(void);					//显示结束画面
void showPassFace(void);					//显示过关画面
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );


/*蛇的函数*/
void snakePic(short *possition);			//身体各部位图片
void initSnake(void);						//显示小蛇
void moveLeft(void);						//左移
void moveDown(void);						//下移
void moveRight(void);						//右移
void moveUp(void);							//上移
void autoMove(void);						//自动移动

/*食物函数*/
void makeFood(void);						//随即产生食物
int judgeEat(void);							//判断吃到食物？
//void distFood(void);						//销毁食物
void eatFood(void);							//吃掉食物 蛇身变长

#endif _FUN_H_