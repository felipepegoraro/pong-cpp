#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct {
	int x;
	int y;
} bulletSpeed;

typedef struct {
	double x;
	double y;
} bulletPos;

class Bullet {
	public:
		int radius;
		bulletSpeed speed;
		bulletPos position;

		void bulletInicialization(Bullet *);
		void bulletChangeSpeed(Bullet *, double, double);
};

#endif // !STRUCTURES_H
