#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>

#define DBG 1
//#define DEBUG(arg) printf("%s[DEBUG] %s%s\n","\033[1;36m",arg,"\033[0m")
//#define ERROR(arg) printf("%s[ERROR] %s%s\n","\033[1;31m",arg,"\033[0m")
#define DEBUG(arg) printf("[DEBUG] %s\n",arg)
#define ERROR(arg) printf("[ERROR] %s\n",arg)
#define FRAMES_B4_DETECT 50

#endif // INCLUDES_H
