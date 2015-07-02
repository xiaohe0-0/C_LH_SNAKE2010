#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL.h"
#include "fun.h"

int main(int argc, char* argv[])
{
	SDL_Event event;
	gSnake[0].x = 3;
	gSnake[0].y = 3;
	gSnake[1].x = 2;
	gSnake[1].y = 3;
	int foodNum = 0;
	while (1)
	{	
		init();
		initImages();
		initNowMaps();
		initSnake();
		makeFood();
		while (1)
		{
			while (SDL_PollEvent(&event))/*判断键盘事件*/
			{
				if (event.type = SDL_KEYDOWN)
				{
					switch (event.key.keysym.sym)
					{
					case SDLK_ESCAPE:
						quitGame();
						exit(0);
						break;
					case SDLK_LEFT:
						moveLeft();
						break;
					case SDLK_RIGHT:
						moveRight();
						break;
					case SDLK_UP:
						moveUp();
						break;
					case SDLK_DOWN:
						moveDown();
						break;
					}
					
				}
			}
			if(judgeEat())                //判断是否遇到了食物
			{
				eatFood();				 //吃掉食物
				makeFood();
			}
			else if(judgeOver())          //游戏结束则显示退出画面
			{
				
				showOverFace();
			}
			else if (gLength ==PASSNUM)		  //过关
			{
				showPassFace();
			}
			else                          //如果没有遇到食物也不结束那么就自动移动
			{
				apply_surface((gFood.x) * 32,(gFood.y)*32,gOptimizedImage[0],screen);
				SDL_Flip(screen);
				autoMove();
				SDL_Delay(speed);
			}
		}
	}

	return 0;
}