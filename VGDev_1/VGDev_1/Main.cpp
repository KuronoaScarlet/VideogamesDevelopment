#include <iostream>
#include <stdlib.h>
#include <math.h>

class vec3
{
public:
	// Methods
	vec3() 
	{
		x = 0;
		y = 0;
		z = 0;
	}

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

	float DistanceTo(const vec3 Vec2)
	{
		float res1 = x - Vec2.x;
		float res2 = y - Vec2.y;
		float res3 = z - Vec2.z;

		float distance;

		return distance = sqrt((res1 * res1) + (res2 * res2) + (res3 * res3));
	}

	// Operators
	vec3 operator+ (const vec3& v) const
	{
		vec3 newVector;

		newVector.x = this->x + v.x;
		newVector.y = this->y + v.y;
		newVector.z = this->z + v.z;

		return newVector;
	}

	vec3 operator- (const vec3& v) const
	{
		vec3 newVector;

		newVector.x = this->x - v.x;
		newVector.y = this->y - v.y;
		newVector.z = this->z - v.z;

		return newVector;
	}

	vec3 operator= (const vec3& v) const
	{
		vec3 newVector;

		newVector.x = v.x;
		newVector.y = v.y;
		newVector.z = v.z;

		return newVector;
	}

	vec3 operator+= (const vec3& v)
	{
		this->x = this->x + v.x;
		this->y = this->y + v.y;
		this->z = this->z + v.z;

		return *this;
	}

	vec3 operator-= (const vec3& v)
	{
		this->x = this->x - v.x;
		this->y = this->y - v.y;
		this->z = this->z - v.z;

		return *this;
	}

	bool operator==(const vec3& v) const
	{
		return this->x == v.x &&
			   this->y == v.y && 
			   this->z == v.z ;
	}

	// Getters
	float GetX() { return x; }
	float GetY() { return y; }
	float GetZ() { return z; }

private:
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

	vec3 Vector2(2, 5, 7);

	std::cout << Vector1.DistanceTo(Vector2) << " u" << std::endl;

	system("pause");
	return 0;
}