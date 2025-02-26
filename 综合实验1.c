#include <stdio.h>				//调用stdio库
#include <stdlib.h>				//调用stdlib库
#include <time.h>				//调用time库

int main(){						//定义主函数
	int x,y;					//定义整型变量x，y
	int a,a1;					//定义整型变量a，a1
	char flag,flag2;			//定义字符型变量flag，flag2
	printf("请输入x坐标：");	//输出提示输入语句
	scanf("%d",&x);				//得到x坐标值
	printf("请输入y坐标：");	//输出提示输入语句
	scanf("%d",&y);				//得到y坐标值
	if ((x == 155 && 160 <= y && y <= 481) || (x == 457 && 160 <= y && y <= 481) || (y == 160 && 0 <= x && x <= 779) || (y == 481 && 0 <= x && x <= 779)){	//判断x，y的值是否在电网处
		printf("你落在了区域边界电网上！\n");				//如果坐标x，y满足落在电网处则输出对应语句
		flag = 1;								  			//令flag=1，为下面的switch-case做准备
	}else if (0 <= x && x <= 779 && 0 <= y && y <= 160){	//判断x，y是否在C区
		printf("你正在C区，小心敌人埋伏！\n");				//如果坐标x，y满足落在C区则输出对应语句
		flag = 67;											//flag值存C的ASCⅡ码值
	}else if (0 <= x && x <= 155 && 160 <= y && y <= 481){	//判断x，y是否在B区
		printf("你正在B区，小心有陷阱！\n");				//如果坐标x，y满足落在B区则输出对应语句
		flag = 66;											//flag值存B的ASCⅡ码值
	}else if (155 <= x && x <= 457 && 160 <= y && y <= 481){//判断x，y是否在O区
		printf("你正在O区，快去解救人质！\n");				//如果坐标x，y满足落在O区则输出对应语句
		flag = 79;											//flag值存O的ASCⅡ码值
	}else if (457 <= x && x <= 779 && 160 <= y && y <= 481){//判断x，y是否在D区
		printf("你正在D区，可以补充武器！\n");				//如果坐标x，y满足落在D区则输出对应语句
		flag = 68;											//flag值存D的ASCⅡ码值
	}else if (0 <= x && x <= 779 && 481 <= y && y <= 562){	//判断x，y是否在A区
		printf("你正在A区，小心地雷！\n");					//如果坐标x，y满足落在A区则输出对应语句
		flag = 65;											//flag值存A的ASCⅡ码值
	}else{													
		printf("你落在了任务区外！\n");						//否则为落在任务区外面
		flag = 1;											//flag值存1
	}															
	printf("\n");											//换一行，显得美观
	switch (flag) {											//使用switch-case语句，判断值为flag的值
	case 1:													//如果flag值为1
		printf("任务失败！");								//输出任务失败语句
		break;												//跳出switch-case语句
	case 79:												//如果flag值为79，表示现在在O区
		printf("任务完成，救出人质！");						//输出对应语句
		break;												//跳出switch-case语句
	case 65:												//如果flag值为65，表示现在在A区
		printf("你正在A区，遇到了A区守卫，转动赌盘进入O区开始解救人质……\n");	//输出在A区的提示语句
		do{													//使用do-while循环
			fflush(stdin);									//清空缓冲区
			printf("请按W键产生你的赌盘数字：");			//输出提示输入语句
			flag2 = getchar();								//用getchar将输入的字符存给flag2
			if (flag2 == 87 || flag2 == 119){				//如果输入的flag2满足W/w
				srand((unsigned)time(NULL));				//当前运行时钟作为种子值初始化随机数
				printf("你的赌盘数字为：");					//输出语句
				a=rand() % 100;								//得到随机数，存给a，范围为0-99
				printf("%d\n", a);							//输出a
			}
		}while(flag2 != 87 && flag2 != 119);				//如果输入的字符不满足W/w则循环直到输入正确
		do{													//使用do-while循环
			fflush(stdin);									//清空缓冲区
			printf("请按G键产生守卫的赌盘数字：");			//输出提示输入语句
			flag2 = getchar();								//用getchar将输入的字符存给flag2
			if (flag2 == 71 || flag2 == 103){				//如果输入的flag2满足G/g
				srand((unsigned)time(NULL));				//当前运行时钟作为种子值初始化随机数
				printf("守卫的赌盘数字为：");				//输出语句
				a1=(rand()%10 + 80);						//得到随机数，存给a1，范围为80-89
				printf("%d\n", a1);							//输出a1
			}
		}while(flag2 != 71 && flag2 != 103);				//如果输入的字符不满足W/w则循环直到输入正确
		if (a > a1){										//如果a>a1，则说明可以进入O区
			printf("成功进入人质O区，解救人质成功！");		//输出语句
		}else{
			printf("地雷爆炸，任务失败！");					//否则输出失败语句
		}
		break;												//跳出switch-case语句
	case 66:												//如果flag值为66，表示现在在B区
		printf("你正在B区，遇到了B区守卫，转动赌盘进入O区开始解救人质……\n");	//输出在B区的提示语句
		do{													//使用do-while循环
			fflush(stdin);									//清空缓冲区
			printf("请按W键产生你的赌盘数字：");			//输出提示输入语句
			flag2 = getchar();								//用getchar将输入的字符存给flag2
			if (flag2 == 87 || flag2 == 119){				//如果输入的flag2满足W/w
				srand((unsigned)time(NULL));				//当前运行时钟作为种子值初始化随机数
				printf("你的赌盘数字为：");					//输出语句
				a=rand() % 100;								//得到随机数，存给a，范围为0-99
				printf("%d\n", a);							//输出a
			}												
		}while(flag2 != 87 && flag2 != 119);				//如果输入的字符不满足W/w则循环直到输入正确
		do{													//使用do-while循环
			fflush(stdin);									//清空缓冲区
			printf("请按G键产生守卫的赌盘数字：");			//输出提示输入语句
			flag2 = getchar();								//用getchar将输入的字符存给flag2
			if (flag2 == 71 || flag2 == 103){				//如果输入的flag2满足G/g
				srand((unsigned)time(NULL));				//当前运行时钟作为种子值初始化随机数
				printf("守卫的赌盘数字为：");				//输出语句
				a1=(rand()%11 + 45);						//得到随机数，存给a1，范围为45-55
				printf("%d\n", a1);							//输出a1
			}
		}while(flag2 != 71 && flag2 != 103);				//如果输入的字符不满足W/w则循环直到输入正确
		if (a > a1){										//如果a>a1，则说明可以进入O区
			printf("成功进入人质O区，解救人质成功！");		//输出语句
		}else{												
			printf("掉入陷阱，任务失败！");					//否则输出失败语句
		}
		break;												//跳出switch-case语句
	case 67:												//如果flag值为67，表示现在在C区
		printf("你正在C区，遇到了C区守卫，转动赌盘进入O区开始解救人质……\n");	//输出在C区的提示语句
		do{													//使用do-while循环
			fflush(stdin);									//清空缓冲区
			printf("请按W键产生你的赌盘数字：");			//输出提示输入语句
			flag2 = getchar();								//用getchar将输入的字符存给flag2
			if (flag2 == 87 || flag2 == 119){				//如果输入的flag2满足W/w
				srand((unsigned)time(NULL));				//当前运行时钟作为种子值初始化随机数
				printf("你的赌盘数字为：");					//输出语句
				a=rand() % 100;								//得到随机数，存给a，范围为0-99
				printf("%d\n", a);							//输出a
			}
		}while(flag2 != 87 && flag2 != 119);				//如果输入的字符不满足W/w则循环直到输入正确
		do{													//使用do-while循环
			fflush(stdin);									//清空缓冲区
			printf("请按G键产生守卫的赌盘数字：");			//输出提示输入语句
			flag2 = getchar();								//用getchar将输入的字符存给flag2
			if (flag2 == 71 || flag2 == 103){				//如果输入的flag2满足G/g
				srand((unsigned)time(NULL));				//当前运行时钟作为种子值初始化随机数
				printf("守卫的赌盘数字为：");				//输出语句
				a1=(rand()%10 + 60);						//得到随机数，存给a1，范围为60-69
				printf("%d\n", a1);							//输出a1
			}
		}while(flag2 != 71 && flag2 != 103);				//如果输入的字符不满足W/w则循环直到输入正确
		if (a > a1){										//如果a>a1，则说明可以进入O区
			printf("成功进入人质O区，解救人质成功！");		//输出语句
		}else{												
			printf("遭到伏击，任务失败！");					//否则输出失败语句
		}		
		break;												//跳出switch-case语句
	case 68:												//如果flag值为68，表示现在在D区
		printf("你正在D区，遇到了D区守卫，转动赌盘进入O区开始解救人质……\n");	//输出在D区的提示语句
		do{													//使用do-while循环
			fflush(stdin);									//清空缓冲区
			printf("请按W键产生你的赌盘数字：");			//输出提示输入语句	
			flag2 = getchar();								//用getchar将输入的字符存给flag2		
			if (flag2 == 97 || flag2 == 119){				//如果输入的flag2满足W/w			
				srand((unsigned)time(NULL));				//当前运行时钟作为种子值初始化随机数
				printf("你的赌盘数字为：");					//输出语句
				a=rand() % 100;								//得到随机数，存给a，范围为0-99
				printf("%d\n", a);							//输出a
			}			
		}while(flag2 != 97 && flag2 != 119);				//如果输入的字符不满足W/w则循环直到输入正确
		do{													//使用do-while循环
			fflush(stdin);									//清空缓冲区
			printf("请按G键产生守卫的赌盘数字：");			//输出提示输入语句
			flag2 = getchar();								//用getchar将输入的字符存给flag2
			if (flag2 == 71 || flag2 == 103){				//如果输入的flag2满足G/g
				srand((unsigned)time(NULL));				//当前运行时钟作为种子值初始化随机数
				printf("守卫的赌盘数字为：");				//输出语句
				a1=(rand()%10 + 10);						//得到随机数，存给a1，范围为10-19
				printf("%d\n", a1);							//输出a1
			}	
		}while(flag2 != 71 && flag2 != 103);				//如果输入的字符不满足W/w则循环直到输入正确
		if (a > a1){										//如果a>a1，则说明可以进入O区
			printf("成功进入人质O区，解救人质成功！");		//输出语句
		}else{
			printf("武器丢失，任务失败！");					//否则输出失败语句
		}
		break;												//跳出switch-case语句
	}
	return 0;												//若程序正常运行则返回0
}
