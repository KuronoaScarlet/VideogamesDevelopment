#include <iostream>
#include <stdlib.h>
#include <math.h>

class vec3
{
public:
	vec3() {}

	vec3(float a, float b, float c)
	{
		x = a;
		y = b;
		z = c;
	}
	~vec3() {}

	void Normalize() 
	{
		float res1 = x / sqrt((x * x) + (y * y) + (z * z));
		float res2 = y / sqrt((x * x) + (y * y) + (z * z));
		float res3 = z / sqrt((x * x) + (y * y) + (z * z));

		x = res1;
		y = res2;
		z = res3;
	}

	void Zero()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	bool IsZero()
	{
		return x == 0 &&
			   y == 0 && 
			   z == 0 ;
	}

	float DistanceTo(const vec3* Vec2)
	{

	}

	//Getters
	float GetX() { return x; }
	float GetY() { return y; }
	float GetZ() { return z; }

protected:
	float x, y, z;
};

int main()
{
	vec3 Vector1(1, 2, 3);
	Vector1.Normalize();
	std::cout << Vector1.GetX() << std::endl << Vector1.GetY() << std::endl << Vector1.GetZ() << std::endl;
	Vector1.Zero();
	std::cout << Vector1.GetX() << std::endl << Vector1.GetY() << std::endl << Vector1.GetZ() << std::endl;
	bool Zero;
	Zero = Vector1.IsZero();
	if (Zero == true)
	{
		std::cout << "True" << std::endl;
	}
	else
	{
		std::cout << "False" << std::endl;
	}

	system("pause");
	return 0;
}