#include "10.exercises.h"
#include "PPP/Simple_window.h"

void Ex_10(Simple_window& win)
{
	win.resize(1000, 630);

	// Headers meant for users (aka “user-facing headers”):
	Circle c1{ Point {30, 30}, 2 };
	c1.set_fill_color(Color::black);
	win.attach(c1);

	Text t1{ Point{40, 20}, "Headers meant for users(aka \"user-facing headers\"):" };
	t1.set_font(Font::screen);
	win.attach(t1);

	// Point.h
	Circle c2{ Point {60, 60}, 2 };
	c2.set_fill_color(Color::black);
	win.attach(c2);

	Text t2{ Point{70, 50}, "Point.h" };
	t2.set_font(Font::screen_bold);
	win.attach(t2);

	// Window.h
	Circle c3{ Point {60, 90}, 2 };
	c3.set_fill_color(Color::black);
	win.attach(c3);

	Text t3{ Point{70, 80}, "Window.h" };
	t3.set_font(Font::screen_bold);
	win.attach(t3);

	// Simple_window.h
	Circle c4{ Point {60, 120}, 2 };
	c4.set_fill_color(Color::black);
	win.attach(c4);

	Text t4{ Point{70, 110}, "Simple_window.h" };
	t4.set_font(Font::screen_bold);
	win.attach(t4);
	
	// Graph.h
	Circle c5{ Point {60, 150}, 2 };
	c5.set_fill_color(Color::black);
	win.attach(c5);

	Text t5{ Point{70, 140}, "Graph.h" };
	t5.set_font(Font::screen_bold);
	win.attach(t5);
	
	// GUI.h
	Circle c6{ Point {60, 180}, 2 };
	c6.set_fill_color(Color::black);
	win.attach(c6);

	Text t6{ Point{70, 170}, "GUI.h" };
	t6.set_font(Font::screen_bold);
	win.attach(t6);

	// To implement the facilities offered by those headers, a few more files are used.Implementation headers:
	Circle c7{ Point {30, 210}, 2 };
	c7.set_fill_color(Color::black);
	win.attach(c7);

	Text t7{ Point{40, 200}, "To implement the facilities offered by those headers, a few more files are used. Implementation headers:" };
	t7.set_font(Font::screen);
	win.attach(t7);

	// Qt headers
	Circle c8{ Point {60, 240}, 2 };
	c8.set_fill_color(Color::black);
	win.attach(c8);

	Text t8{ Point{70, 230}, "Qt headers" };
	t8.set_font(Font::screen_bold);
	win.attach(t8);
	
	// GUI_private.h
	Circle c9{ Point {60, 270}, 2 };
	c9.set_fill_color(Color::black);
	win.attach(c9);

	Text t9{ Point{70, 260}, "GUI_private.h" };
	t9.set_font(Font::screen_bold);
	win.attach(t9);
	
	// Image_private.h
	Circle c10{ Point {60, 300}, 2 };
	c10.set_fill_color(Color::black);
	win.attach(c10);

	Text t10{ Point{70, 290}, "Image_private.h" };
	t10.set_font(Font::screen_bold);
	win.attach(t10);
	
	// Colormap.h
	Circle c11{ Point {60, 330}, 2 };
	c11.set_fill_color(Color::black);
	win.attach(c11);

	Text t11{ Point{70, 320}, "Colormap.h" };
	t11.set_font(Font::screen_bold);
	win.attach(t11);
	
	// Code files:
	Circle c12{ Point {30, 360}, 2 };
	c12.set_fill_color(Color::black);
	win.attach(c12);

	Text t12{ Point{40, 350}, "Code files:" };
	t12.set_font(Font::screen);
	win.attach(t12);
	
	// Window.cpp
	Circle c13{ Point {60, 390}, 2 };
	c13.set_fill_color(Color::black);
	win.attach(c13);

	Text t13{ Point{70, 380}, "Window.cpp" };
	t13.set_font(Font::screen_bold);
	win.attach(t13);
	
	// Graph.cpp
	Circle c14{ Point {60, 420}, 2 };
	c14.set_fill_color(Color::black);
	win.attach(c14);

	Text t14{ Point{70, 410}, "Graph.cpp" };
	t14.set_font(Font::screen_bold);
	win.attach(t14);
	
	// GUI.cpp
	Circle c15{ Point {60, 450}, 2 };
	c15.set_fill_color(Color::black);
	win.attach(c15);

	Text t16{ Point{70, 440}, "GUI.cpp" };
	t16.set_font(Font::screen_bold);
	win.attach(t16);
	
	// GUI_private.cpp
	Circle c17{ Point {60, 480}, 2 };
	c17.set_fill_color(Color::black);
	win.attach(c17);

	Text t17{ Point{70, 470}, "GUI_private.cpp" };
	t17.set_font(Font::screen_bold);
	win.attach(t17);
	
	// Image_private.cpp
	Circle c18{ Point {60, 510}, 2 };
	c18.set_fill_color(Color::black);
	win.attach(c18);

	Text t19{ Point{70, 500}, "Image_private.cpp" };
	t19.set_font(Font::screen_bold);
	win.attach(t19);
	
	// Colormap.cpp
	Circle c20{ Point {60, 540}, 2 };
	c20.set_fill_color(Color::black);
	win.attach(c20);

	Text t20{ Point{70, 530}, "Colormap.cpp" };
	t20.set_font(Font::screen_bold);
	win.attach(t20);
	
	// Qt code
	Circle c21{ Point {60, 570}, 2 };
	c21.set_fill_color(Color::black);
	win.attach(c21);

	Text t21{ Point{70, 560}, "Qt code" };
	t21.set_font(Font::screen_bold);
	win.attach(t21);

	win.set_label("Ex_10");
	win.wait_for_button();
}