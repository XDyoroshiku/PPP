#include "10.exercises.h"
#include "PPP/Simple_window.h"

void Ex_07(Simple_window& win)
{
	win.resize(600, 400);

	Rectangle body{ Point{150, 180}, 300, 200 };
	body.set_fill_color(Color::yellow);
	win.attach(body);

	Rectangle door{ Point{265, 260}, 70, 120 };
	door.set_fill_color(Color::cyan);
	win.attach(door);

	Polygon roof;
	roof.add(Point{ 100, 180 });
	roof.add(Point{ 500, 180 });
	roof.add(Point{ 300, 80 });
	roof.set_fill_color(Color::red);
	win.attach(roof);

	Rectangle window_1{ Point{175, 230}, 50, 50 };
	Rectangle window_2{ Point{375, 230}, 50, 50 };
	window_1.set_fill_color(Color::blue);
	window_2.set_fill_color(Color::blue);
	win.attach(window_1);
	win.attach(window_2);

	Polygon chimney;
	chimney.add(Point{ 440, 150 });
	chimney.add(Point{ 440, 90 });
	chimney.add(Point{ 410, 90 });
	chimney.add(Point{ 410, 135 });
	chimney.set_fill_color(Color::black);
	win.attach(chimney);

	Ellipse smoke_1{ Point{425, 80}, 10, 5 };
	win.attach(smoke_1);

	Ellipse smoke_2{ Point{450, 65}, 20, 10 };
	win.attach(smoke_2);

	Ellipse smoke_3{ Point{475, 35}, 25, 15 };
	win.attach(smoke_3);

	win.set_label("Ex_07");
	win.wait_for_button();
}