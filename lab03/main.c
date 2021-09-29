/*
 * find cylinder volume: V = height * PI * r * r
 *
 * input data:
 * 	-- height, unsigned int
 * 	-- radius, 
 * 	-- PI
 * 	#define PI 3.14
 *
 *
 * */

int main()
{
	#define PI 3.14f
	unsigned int height = 5;
	unsigned int radius = 25;
	float volume = height * PI * radius * radius;

	return 0;
}
