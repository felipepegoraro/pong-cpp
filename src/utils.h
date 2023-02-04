#ifndef UTILS_H
#define UTILS_H

#define  WIDTH 600
#define HEIGHT 400
#define   NAME "Pong"

#include <raylib.h>

struct Score {
	int match[2];
	const char *winner;
};

template <typename T>
struct Point { 
  T x;
  T y; 
};

double centerX(void);
double centerY(void);

#endif // !UTILS_H
