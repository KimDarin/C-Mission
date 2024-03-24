#include <iostream>
#include <cmath>
#define SQUARE(x)  (x) * (x)                       //제곱
#define ABS(y)    (((y) < 0)   ? -(y) : (y))       //절댓값
#define MIN(x, y) (((x) > (y)) ? (y) : (x))
#define MAX(x, y) (((x) < (y)) ? (y) : (x))


class Shape			//도형의 기본 클래스
{
public:
	int x, y;		//좌표 (x,y)
	Shape(int x = 0, int y = 0) : x(x), y(y) {}		//생성자 -> 기본값(0,0)으로 설정
	virtual ~Shape() {}		//소멸자

	virtual double Area() = 0;
};

class Circle : public Shape
{
private:
	int r;		//원의 반지름
public:
	Circle(int x, int y, int r) : Shape(x, y), r(r) {}		//원점과 반지름

	double Area()	override
	{
		return 3.14 * SQUARE(r);
	}
};

class Rectangle : public Shape		//두 개의 좌표로 사각형 구현
{
private:
	int x2, y2;
	double w, h;
public:
	Rectangle(int x1, int y1, int x2, int y2)
		: Shape(x1, y1), x2(x2), y2(y2)			//(x1,y1) 좌표1, (x2, y2) 좌표2 
	{
		w = ABS(x2 - x1);	//너비
		h = ABS(y2 - y1);	//높이
	}
	double Area() override	//사각형의 넓이 구하는 함수
	{
		return w * h;
	}
};

class Triangle : public Shape
{
private:
	int x2, y2;
	int x3, y3;
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : Shape(x1, y1), x2(x2), y2(y2), x3(x3), y3(y3) {}
	double Area() override
	{
		return 0.5 * ABS((x * (y2 - y3) + x2 * (y3 - y) + x3 * (y - y2)));
		//삼각형의 세 변의 길이를 알 때 넓이를 구할 수 있는 헤론의 공식
	}
};

int main()
{
	Circle cir(5, 5, 10);					//원점(5,5)와 반지름 10 => 넓이: 314
	Rectangle rect(1, 2, 5, 7);				//(1,5)와 (2,7)로 이루어지는 사각형 => 넓이: 20
	Triangle tri(1, 1, 7, 1, 7, 11);		//세 꼭지점 (1,1), (1,7), (7,11)로 이루어지는 삼각형 => 넓이: 30

	Shape* shapes[] = { &cir, &rect, &tri };
	//객체를 가르키는 포인터를 사용하여 가상함수 호출

	for (int i = 0; i < 3; i++)
	{
		printf("면적: %.2f\n", shapes[i]->Area());
	}

	printf("circle area: %.2f\n", cir.circlearea());
	printf("rectangle area: %.2f\n", rect.rectanglearea());
	printf("triangle area: %.2f\n", tri.trianglearea());
}