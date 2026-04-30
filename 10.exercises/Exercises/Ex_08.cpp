#include "10.exercises.h"
#include "PPP/Simple_window.h"

void Ex_08(Simple_window& win)
{
	win.resize(600, 400);

	Circle c1{ Point{300, 150}, 80 };
	Circle c2{ Point{200, 250}, 80 };
	Circle c3{ Point{400, 250}, 80 };
	Circle c4{ Point{100, 150}, 80 };
	Circle c5{ Point{500, 150}, 80 };

	c1.set_color(Color::black);
	c2.set_color(Color::yellow);
	c3.set_color(Color::green);
	c4.set_color(Color::blue);
	c5.set_color(Color::red);

	c1.set_style(Line_style(Line_style::solid, 10));
	c2.set_style(Line_style(Line_style::solid, 10));
	c3.set_style(Line_style(Line_style::solid, 10));
	c4.set_style(Line_style(Line_style::solid, 10));
	c5.set_style(Line_style(Line_style::solid, 10));

	win.attach(c1);
	win.attach(c2);
	win.attach(c3);
	win.attach(c4);
	win.attach(c5);

	win.set_label("Ex_08");
	win.wait_for_button();
}