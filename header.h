#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include<time.h>
#include<strings.h>
#include"jpeg.c"
#include"gif.c"
#include"pdf.c"
#include"apna.c"
#include"function.h"
#include"welcome.c"
#include"go_back_main_menu.c"
#define KNRM  "\x1B[0m" 	//NORMAL
#define KRED  "\x1B[31m" 	//RED
#define KGRN  "\x1B[32m"	//GREEN
#define KYEL  "\x1B[33m"	//YELLOW	
#define KBLU  "\x1B[34m"	//BLUE
#define KMAG  "\x1B[35m"	//MAGENTZ
#define KCYN  "\x1B[36m" 	
#define KWHT  "\x1B[37m"
#define BLINK "\x1b[6m"		//BLINKING CURSOR		
#define CLEAR "\x1B[2J"		//CLEAR SCREEN
