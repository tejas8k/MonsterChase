#pragma once

#include<stdio.h>
#include<stdlib.h>

namespace Engine {
	class Point2D
	{
	public:
		Point2D(int i_X, int i_Y) :
			m_x(i_X),
			m_y(i_Y)
		{}

	Point2D(): m_x(0), m_y(0)
	{}

		//getters
		int X() const {
			return m_x;
		}

		int Y() const {
			return m_y;
		}

		//setters
		void X(int i_X) {
			m_x = i_X;
		}

		void Y(int i_Y) {
			m_y = i_Y;
		}

		Point2D operator+(Point2D& addn);
		Point2D operator-(Point2D& subsn);
		Point2D operator*(int mult);
		Point2D operator/(int divi);
		Point2D operator-();

		Point2D operator+=(Point2D other);
		Point2D operator-=(Point2D other);
		Point2D operator*=(int other);
		Point2D operator/=(int other);
		bool operator==(Point2D other);
		bool operator!=(Point2D other);
		
	private:
		int m_x, m_y;
	};

	Point2D operator*(int first, Point2D& second);
}
