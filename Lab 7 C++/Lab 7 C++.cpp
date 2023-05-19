#include "Classes.h"
#include <iostream>
using namespace std;



int main()
{
	again:
	cout << "Enter the coordinates of the first point: " << endl;
	double x1, y1;
	cin >> x1 >> y1;
	cout << "Enter the coordinates of the second point: " << endl;
	double x2, y2;
	cin >> x2 >> y2;
	cout << "Enter the coordinates of the third point: " << endl;
	double x3, y3;
	cin >> x3 >> y3;
	Point<double> X(x1, y1);
	Point<double> Y(x2, y2);
	Point<double> Z(x3, y3);
	Triangular<double> Tr(X, Y, Z);
	//cout<<"Enter the desired data type: "<<endl;
	//cout<<"1. int"<<endl;
	//cout<<"2. double"<<endl;
	//cout<<"3. float"<<endl;
	//int choice;
	//Triangular<double> Tr;
	//cin>>choice;
	//switch (choice)
	//{
	//case 1:
	//{
	//	Point<int> X(x1, y1);
	//	Point<int> Y(x2, y2);
	//	Point<int> Z(x3, y3);
	//	Triangular<int> Tr(X, Y, Z);
	//	break;
	//}
	//case 2:
	//{
	//	Point<double> X(x1, y1);
	//	Point<double> Y(x2, y2);
	//	Point<double> Z(x3, y3);
	//	Triangular<double> Tr(X, Y, Z);
	//	break;
	//}
	//case 3:
	//{
	//	Point<float> X(x1, y1);
	//	Point<float> Y(x2, y2);
	//	Point<float> Z(x3, y3);
	//	Triangular<float> Tr(X, Y, Z);
	//	break;
	//}
	//default:
	//{
	//	cout<<"Invalid input!"<<endl;
	//	goto again;
	//}
	//}
	if (!Tr.IsTriangular())
	{
		system("cls");
		cout<<"The points you entered do not form a triangle!"<<endl;
		goto again;
	}
	system("cls");
	cout << "The coordinates of the triangle are: " << endl;
	cout << "X: " << Tr.X.x << ";" << Tr.X.y << endl;
	cout << "Y: " << Tr.Y.x << ";" << Tr.Y.y << endl;
	cout << "Z: " << Tr.Z.x << ";" << Tr.Z.y << endl;

	while(true)
	{
		cout << "Enter 1 to calculate the length of the sides of the triangle." << endl;
		cout << "Enter 2 to calculate the perimeter of the triangle." << endl;
		cout << "Enter 3 to calculate the area of the triangle." << endl;
		cout << "Enter 4 to find out the type of the triangular." << endl;
		cout << "Enter 5 to change some coordinates." << endl;
		cout << "Enter 6 to exit." << endl;
		int choice2;
		cin >> choice2;
		switch (choice2)
		{
		case 1:
		{
			Tr.Length();
			break;
		}
		case 2:
		{
			cout << "The perimeter of the triangle is: " << Tr.Perimeter() << endl;
			break;
		}
		case 3:
		{
			cout << "The area of the triangle is: " << Tr.Area() << endl;
			break;
		}
		case 4:
		{
			Tr.TypeOfTriangular();
			break;
		}
		case 5:
		{
			cout << "Enter which coordinates you want to change" << endl;
			cout << "1. X" << endl;
			cout << "2. Y" << endl;
			cout << "3. Z" << endl;
			int choice3;
			cin >> choice3;
			switch (choice3)
			{
			case 1:
			{
				back1:
				cout << "Enter the new coordinates of the X: " << endl;
				double x, y;
				cin >> x >> y;
				Tr.SetX(x, y);
				if (!Tr.IsTriangular())
					goto back1;
				break;
			}
			case 2:
			{
				back2:
				cout << "Enter the new coordinates of the Y: " << endl;
				double x, y;
				cin >> x >> y;
				Tr.SetY(x, y);
				if (!Tr.IsTriangular())
					goto back2;
				break;
			}
			case 3:
			{
				back3:
				cout << "Enter the new coordinates of the Z: " << endl;
				double x, y;
				cin >> x >> y;
				Tr.SetZ(x, y);
				if (!Tr.IsTriangular())
					goto back3;
				break;
			}
			}
			cout << "The coordinates of the triangle are: " << endl;
			cout << "X: " << Tr.X.x << ";" << Tr.X.y << endl;
			cout << "Y: " << Tr.Y.x << ";" << Tr.Y.y << endl;
			cout << "Z: " << Tr.Z.x << ";" << Tr.Z.y << endl;
			break;
		}
		case 6:
		{
			return 0;
		}
		default:
		{
			cout<<"Invalid input!"<<endl;
			break;
		}
		}
	}

}