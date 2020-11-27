#include "vect.h"
#include <cmath>

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

	const double Rad_to_deg = 45.0 / atan(1.0);

	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}

	void Vector::set_ang()
	{
		if (x==0.0 && y == 0.0)
		{
			ang = 0.0;
		}
		else
		{
			ang = atan2(y, x);
		}
	}
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}
	void Vector::set_y()
	{
		y = mag * sin(ang);
	}
	//  metody publiczne 

	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1; 
			y = n2;
			set_mag();
			set_ang();
		}
		else if(form == POL)
		{
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else
		{
			cout << "niepoprawna warto�� trzeciego argumentu Vector() --";
			cout << "zeruje wektor\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	//zerowanie wartosci wektora dla zadanych wspolrzednych kartezjanskich RECT, albo dlabieguowych 

