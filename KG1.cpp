#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;
////Простейшим алгоритмом растрирования отрезка
//
//void line(int x1, int y1, int x2, int y2)
//{
//    HDC hdc = GetDC(GetConsoleWindow());
//    
//    int dx = x2 - x1;
//    int dy = y2 - y1;
//    float k = dy / dx;
//    
//    int x = x1;
//    int y = y1;
//    
//    while (x <= x2)
//    {
//        SetPixel(hdc, x, y, RGB(242, 243, 244));
//        y = (int)k * x;
//        x++;
//    }
//}
//
//int main()
//{
//    line(100, 100, 500, 500);
//    cin.get();
//    return 0;
//}

//Брезенхема 

//void bresenham(int x1, int y1, int x2, int y2)
//{
//	HDC hdc = GetDC(GetConsoleWindow());
//	int x, y;
//	int dx = x2 - x1;
//	int dy = y2 - y1;
//	int d = dy * 2 - dx;
//	int d1 = dy * 2;
//	int d2 = (dy - dx) * 2;
//	x = x1; y = y1;
//	//SetPixel(hdc, x, y, RGB(255, 0, 0));
//	x2--;
//	while (x < x2)
//	{
//		x++;
//		if (d < 0) d += d1;
//		else
//		{
//			y++;
//			d += d2;
//		}
//		SetPixel(hdc, x, y, RGB(0, 255, 0));
//	}
//}
//
//int main()
//{
//	bresenham(100, 100, 500, 500);
//	cin.get();
//	return 0;
//}


//второе задание
void drawLine(int x1, int y1, int x2, int y2, int r, int g, int b) {
	HDC hdc = GetDC(GetConsoleWindow());
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	int error = deltaX - deltaY;
	SetPixel(hdc, x2, y2, RGB(r, g, b));
	while (x1 != x2 || y1 != y2)
	{
		int error2 = error * 2;
		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
		if (GetPixel(hdc, x1, y1) == RGB(0, 0, 255) and (r != 0 or g != 0 or b != 255))
		{
			SetPixel(hdc, x1, y1, RGB(255, 0, 255));
		}
		else SetPixel(hdc, x1, y1, RGB(r, g, b));
	}
}


void drawCircle(int x0, int y0, int radius, int r, int g, int b) {
	HDC hdc = GetDC(GetConsoleWindow());
	int x = 0;
	int y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;
	while (y >= 0) {
		SetPixel(hdc, x0 + x, y0 + y, RGB(r, g, b));
		SetPixel(hdc, x0 + x, y0 - y, RGB(r, g, b));
		SetPixel(hdc, x0 - x, y0 + y - 1, RGB(r, g, b));
		SetPixel(hdc, x0 - x, y0 - y - 1, RGB(r, g, b));

		drawLine(x0 - x, y0 - y, x0 + x, y0 - y, r, g, b);
		drawLine(x0 - x, y0 + y + 1, x0 + x, y0 + y + 1, r, g, b);
		//drawLine(x0 - x, y0 + y, x0 - x, y0 + y, r, g, b);
		//drawLine(x0, y0, x0 + x, y0 - y, r, g, b);
		//drawLine(x0, y0, x0 - x, y0 + y, r, g, b);
		//drawLine(x0, y0, x0 - x, y0 - y, r, g, b);

		error = 2 * (delta + y) - 1;
		if (delta < 0 && error <= 0) {
			x++;
			delta += 2 * x + 1;
			continue;
		}
		error = 2 * (delta - x) - 1;
		if (delta > 0 && error > 0) {
			y--;
			delta += 1 - 2 * y;
			continue;
		}
		x++;
		delta += 2 * (x - y);
		y--;
	}
}



int main()
{
	HDC hdc = GetDC(GetConsoleWindow());
	drawCircle(320, 120, 100, 0, 0, 255);
	drawCircle(480, 120, 100, 255, 0, 0);
	//drawCircle(160, 120, 100, 255, 0, 0);
	cin.get();
	return 0;
}