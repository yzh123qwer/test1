#include"MinDistance.h"
void main(void)
{
	struct Point the_points[4];
	GetPoints(the_points, 4);
	printf("min distance = %lf", MinDist(the_points, 4));
	return;
}
