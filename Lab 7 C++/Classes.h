#pragma once
#include <iostream>
#include <cmath>
using namespace std;

template <typename T>

class Point
{
public:
	T x;
	T y;
	Point(T x, T y)
	{
		this->x = x;
		this->y = y;
	}
	Point()
	{
		this->x = T();
		this->y = T();
	}
};
template <typename T>
class Triangular
{
public:
	Point<T> X;
	Point<T> Y;
	Point<T> Z;
	double XY;
	double YZ;
	double XZ;
	Triangular(Point<T> X, Point<T> Y, Point<T> Z)
	{
		this->X = X;
		this->Y = Y;
		this->Z = Z;
		XY = round(sqrt(pow((X.x - Y.x), 2) + pow((X.y - Y.y), 2)));
		YZ = round(sqrt(pow((Y.x - Z.x), 2) + pow((Y.y - Z.y), 2)));
		XZ = round(sqrt(pow((X.x - Z.x), 2) + pow((X.y - Z.y), 2)));
	}
	Triangular()
	{
		this->X = Point<T>();
		this->Y = Point<T>();
		this->Z = Point<T>();
	}
	double Length()
	{
		this->XY = round(sqrt(pow((X.x - Y.x), 2) + pow((X.y - Y.y), 2)));
		this->YZ = round(sqrt(pow((Y.x - Z.x), 2) + pow((Y.y - Z.y), 2)));
		this->XZ = round(sqrt(pow((X.x - Z.x), 2) + pow((X.y - Z.y), 2)));
		cout << "The length of the sides of the triangle are: " << endl;
		cout << "XY = " << this->XY << endl;
		cout << "YZ = " << this->YZ << endl;
		cout << "XZ = " << this->XZ << endl;
		return 0;
	}
	double Perimeter()
	{
		return this->XY + this->YZ + this->XZ;
	}
	double Area()
	{
		double p = this->Perimeter() / 2;
		return sqrt(p * (p - this->XY) * (p - this->YZ) * (p - this->XZ));
	}
	bool IsTriangular()
	{
		XY = round(sqrt(pow((X.x - Y.x), 2) + pow((X.y - Y.y), 2)));
		YZ = round(sqrt(pow((Y.x - Z.x), 2) + pow((Y.y - Z.y), 2)));
		XZ = round(sqrt(pow((X.x - Z.x), 2) + pow((X.y - Z.y), 2)));
		if (this->XY + this->YZ > this->XZ && this->XY + this->XZ > this->YZ && this->YZ + this->XZ > this->XY)
		{
			return true;
		}
		return false;
	}
	void TypeOfTriangular()
	{
		if (XY == YZ && YZ == XZ)
		{
			cout << "Your triangle is equilateral" << endl;
		}
		else if (XY == YZ || YZ == XZ || XY == XZ)
		{
			if (IsRectangular())
			{
				cout << "Your triangle is right and isosceles" << endl;
			}
			else
			{
				cout << "Your triangle is isosceles" << endl;
			}
		}
		else
		{
			if (IsRectangular())
			{
				cout << "Your triangle is right and versatile" << endl;
			}
			else
			{
				cout << "Your triangle is versatile" << endl;
			}
		}
	}
	bool IsRectangular()
	{
		Point <double> vA = { Y.x - X.x, Y.y - X.y };
		Point <double> vB = { Z.x - Y.x, Z.y - Y.y };
		Point <double> vC = { Z.x - X.x, Z.y - X.y };
		int AB = vA.x * vB.x + vA.y * vB.y;
		int AC = vA.x * vC.x + vA.y * vC.y;
		int BC = vB.x * vC.x + vB.y * vC.y;
		double aAB = round((acos(AB / (XY * YZ)))*57.296);
		double aAC = round((acos(AC / (XY * XZ)))*57.296);
		double aBC = round((acos(BC / (YZ * XZ)))*57.296);
		if (aAB == 90 || aAC == 90 || aBC == 90)
		{
			return true;
		}
		return false;
	}
	void SetX(double x, double y)
	{
		X.x = x;
		X.y = y;
	}
	void SetY(double x, double y)
	{
		Y.x = x;
		Y.y = y;
	}
	void SetZ(double x, double y)
	{
		Z.x = x;
		Z.y = y;
	}
};
