#include<stdio.h>
#include<math.h>
#define PI 3.141

float getCircumference(float r)
{
	return 2*PI*r;
}

float getArea(float r)
{
	return PI*pow((double)r,2);
}

float getSphericalSurfaceArea(float r)
{
	return 4 * PI*pow((double)r, 2);
}

float getSphereVolume(float r)
{
	return 4 * PI*pow((double)r, 3)/3;
}

float getCylindricalVolume(float r, float h)
{
	return getArea(r)*h;
}

int main()
{
	float C1 = 0, Sa = 0, Sb = 0, Va = 0, Vb = 0;
	float r = 0, h = 0;

	// can not compile successfully
	//scanf_s("%f %f", &r, &h);

	// can compile successfully , but at vs2017,it is an error / warning
	scanf("%f %f", &r, &h);

	printf("C1=%.2f\n", getCircumference(r));

	printf("Sa=%.2f\n", getArea(r));

	printf("Sb=%.2f\n", getSphericalSurfaceArea(r));

	printf("Va=%.2f\n", getSphereVolume(r)); 
    // C1=9.42
// Sa=7.07
// Sb=28.26
// Va=14.13
// Vb=21.19

	printf("Vb=%.2f\n", getCylindricalVolume(r, h));


	return 0;
}