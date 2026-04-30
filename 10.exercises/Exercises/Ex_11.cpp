#include "10.exercises.h"
#include "PPP/Simple_window.h"
#include "PPP.h"


void Ex_11(Simple_window& win)
{
	win.resize(600, 400);

	// try this if you want to see clearer.
	//win.resize(1600, 1200);
	//constexpr int triangle_cx = 800;			
	//constexpr int triangle_cy = 600;
	//constexpr int triangle_r = 300;

	constexpr double pi = 3.1415926;
	constexpr int triangle_cx = 300;			// cx -> center_x;
	constexpr int triangle_cy = 200;

	Circle triangle_center{ Point { triangle_cx, triangle_cy }, 2 };
	triangle_center.set_fill_color(Color::black);
	win.attach(triangle_center);

	Polygon triangle;
	constexpr int triangle_r = 100;

	const double sin60 = sin(pi / 3);
	const double cos60 = cos(pi / 3);
	const int triangle_rsin60 = narrow_cast<int>(triangle_r * sin60);
	const int triangle_rcos60 = narrow_cast<int>(triangle_r * cos60);
	triangle.add(Point{ triangle_cx, triangle_cy - triangle_r });
	triangle.add(Point{ triangle_cx - triangle_rsin60, triangle_cy + triangle_rcos60 });
	triangle.add(Point{ triangle_cx + triangle_rsin60, triangle_cy + triangle_rcos60 });
	triangle.set_color(Color::red);
	triangle.set_style(Line_style(Line_style::solid, 2));
	win.attach(triangle);

	Polygon square;
	const int square_rsin45 = triangle_rsin60;
	const int square_rcos45 = square_rsin45;
	const int square_cx = triangle_cx;
	const int square_cy = triangle_cy - triangle_r + square_rcos45;
	square.add(Point{ square_cx - square_rsin45, square_cy - square_rcos45 });
	square.add(Point{ square_cx + square_rsin45, square_cy - square_rcos45 });
	square.add(Point{ square_cx + square_rsin45, square_cy + square_rcos45 });
	square.add(Point{ square_cx - square_rsin45, square_cy + square_rcos45 });
	square.set_color(Color::green);
	square.set_style(Line_style(Line_style::solid, 2));
	win.attach(square);

	Polygon pentagon;
	const double sin45 = sin(pi / 4);
	const double sin54 = sin(pi * 3 / 10);
	const double cos54 = cos(pi * 3 / 10);
	const double sin81 = sin(pi * 9 / 20);				// 81° == 180°- 45° - 54°
	const double square_r = square_rsin45 / sin45;

	// distance between the top point of pentagon and the center of the its inscribed square.
	// in triangle, (a / sina) == (b / sinb) == (c / sinc).
	const double d_pty_scy = square_r / sin54 * sin81;							
																				
	// locate the top point of the pentagon (pentagon_cx, pentagon_top_y). (call it point a here)
	const double pentagon_top_x = square_cx;
	const double pentagon_top_y = square_cy - d_pty_scy;		
	
	const double tan18 = tan(pi / 10);
	const double tan54 = tan(pi * 3 / 10);

	// the bottom left point of the square that touches the side of the pentagon.(call it point c here).
	const double square_bottom_left_x = square_cx - square_rsin45;
	const double square_bottom_left_y = square_cy + square_rcos45;					
	
	// the mid left point of the pentagon, assume it be (x, y).
	// get this point(x,y) by the two equation: 1.|x - ax|/|y - ay| = tan54; 2.|x - cx|/|y - cy| = tan18.
	// in here, the equations are: 1. (ax - x)/(y - ay) = tan54; 2. (cx - x) / (cy - y) = tan18.
	// eliminate x, we get: ax - cx = tan54 * y + tan18 * y - tan54 * ay - tan18 * cy.
	// so, y = (ax - cx + tan54 * ay + tan18 * cy) / (tan54 + tan18).
	const double pentagon_midleft_y = (pentagon_top_x - square_bottom_left_x + tan54 * pentagon_top_y + tan18 * square_bottom_left_y) / (tan54 + tan18);
	// by the equation: (cx - x)/(cy - y) = tan18, we get x = cx - tan18 * cy + tan18 * y.
	const double pentagon_midleft_x = square_bottom_left_x - tan18 * square_bottom_left_y + tan18 * pentagon_midleft_y;			

	// now we can calculate the center point of pentagon and the radius of its circumscribed circle.
	// the edge of the pentage = sqrt( (ax - x)² + (ay - y)²).
	const double pentagon_edge = sqrt(pow((pentagon_top_x - pentagon_midleft_x), 2) + pow((pentagon_top_y - pentagon_midleft_y), 2));
	const double sin36 = sin(pi / 5);
	const int pentagon_r = narrow_cast<int>((pentagon_edge / 2) / sin36);

	// center point of the pentagon: (pentagon_cx, pentagon_cy).
	const int pentagon_cx = square_cx;
	const int pentagon_cy = narrow_cast<int>(pentagon_top_y + pentagon_r);

	// add all five points of the pentagon use the form in function Discard_11() below;
	const double sin72 = sin(pi * 2 / 5);
	const double cos72 = cos(pi * 2 / 5);
	const double cos36 = cos(pi / 5);
	const int pentagon_rsin72 = narrow_cast<int>(pentagon_r * sin72);
	const int pentagon_rcos72 = narrow_cast<int>(pentagon_r * cos72);
	const int pentagon_rsin36 = narrow_cast<int>(pentagon_r * sin36);
	const int pentagon_rcos36 = narrow_cast<int>(pentagon_r * cos36);
	//const int pentagon_top_int_y = narrow_cast<int>(pentagon_cy - pentagon_r);
	pentagon.add(Point{ pentagon_cx, pentagon_cy - pentagon_r });
	pentagon.add(Point{ pentagon_cx - pentagon_rsin72, pentagon_cy - pentagon_rcos72 });
	pentagon.add(Point{ pentagon_cx - pentagon_rsin36, pentagon_cy + pentagon_rcos36 });
	pentagon.add(Point{ pentagon_cx + pentagon_rsin36, pentagon_cy + pentagon_rcos36 });
	pentagon.add(Point{ pentagon_cx + pentagon_rsin72, pentagon_cy - pentagon_rcos72 });
	pentagon.set_color(Color::blue);
	pentagon.set_style(Line_style(Line_style::solid, 2));
	win.attach(pentagon);

	// how can we draw a regular hexagon that enclose a pentagon and has the pentagon'points touch its sides?
	Polygon hexagon;
	const int hexagon_top_x = pentagon_cx;
	const int hexagon_top_y = pentagon_cy - pentagon_r;
	const int hexagon_upleft_x = pentagon_midleft_x;
	const int hexagon_r = narrow_cast<int>((hexagon_top_x - hexagon_upleft_x) / sin60);
	const int hexagon_cx = pentagon_cx;
	const int hexagon_cy = hexagon_top_y + hexagon_r;
	const int hexagon_rsin60 = narrow_cast<int>(hexagon_r * sin60);
	const int hexagon_rcos60 = narrow_cast<int>(hexagon_r * cos60);
	hexagon.add(Point{ hexagon_cx, hexagon_top_y });
	hexagon.add(Point{ hexagon_cx + hexagon_rsin60, hexagon_cy - hexagon_rcos60 });
	hexagon.add(Point{ hexagon_cx + hexagon_rsin60, hexagon_cy + hexagon_rcos60 });
	hexagon.add(Point{ hexagon_cx, hexagon_cy + hexagon_r });
	hexagon.add(Point{ hexagon_cx - hexagon_rsin60, hexagon_cy + hexagon_rcos60 });
	hexagon.add(Point{ hexagon_cx - hexagon_rsin60, hexagon_cy - hexagon_rcos60 });
	hexagon.set_color(Color::black);
	hexagon.set_style(Line_style(Line_style::solid, 2));
	win.attach(hexagon);

	//Circle circle{ Point{pentagon_cx, pentagon_cy}, pentagon_r };
	//circle.set_color(Color::cyan);
	//circle.set_style(Line_style(Line_style::solid, 2));
	//win.attach(circle);

	Text t1{ Point{30, 350}, "It looks like you can't put a regular pentagon" };
	Text t2{ Point{10, 375}, "in a regular hexagon with all points on its sides." };
	win.attach(t1);
	win.attach(t2);


	win.set_label("Ex_11");
	win.wait_for_button();
}


void Discard_11(Simple_window& win)
{
	constexpr double pi = 3.1415926;
	constexpr int r = 150;
	constexpr int center_x = 300;
	constexpr int center_y = 200;
	Point center{ center_x, center_y };

	Circle circle{ center, r };
	circle.set_style(Line_style(Line_style::solid, 2));
	win.attach(circle);

	Circle circle_center{ Point {center_x, center_y}, 2 };
	circle_center.set_fill_color(Color::black);
	win.attach(circle_center);

	Polygon triangle;
	const double sin60 = sin(pi / 3);
	const double cos60 = cos(pi / 3);
	const int r_sin60 = narrow_cast<int>(r * sin60);
	const int r_cos60 = narrow_cast<int>(r * cos60);
	triangle.add(Point{ center_x, center_y - r } );
	triangle.add(Point{ center_x - r_sin60 , center_y + r_cos60 });
	triangle.add(Point{ center_x + r_sin60 , center_y + r_cos60 });
	triangle.set_color(Color::red);
	triangle.set_style(Line_style(Line_style::solid, 2));
	win.attach(triangle);

	Polygon square;
	const double sin45 = sin(pi / 4);
	const int r_sin45 = narrow_cast<int>(r * sin45);
	square.add(Point{ center_x - r_sin45, center_y - r_sin45 });
	square.add(Point{ center_x + r_sin45, center_y - r_sin45 });
	square.add(Point{ center_x + r_sin45, center_y + r_sin45 });
	square.add(Point{ center_x - r_sin45, center_y + r_sin45 });
	square.set_color(Color::green);
	square.set_style(Line_style(Line_style::solid, 2));
	win.attach(square);

	Polygon pentagon;
	const double sin72 = sin(2 * pi / 5);
	const double cos72 = cos(2 * pi / 5);
	const double sin36 = sin(2 * pi / 10);
	const double cos36 = cos(2 * pi / 10);
	const int r_sin72 = narrow_cast<int>(r * sin72);
	const int r_cos72 = narrow_cast<int>(r * cos72);
	const int r_sin36 = narrow_cast<int>(r * sin36);
	const int r_cos36 = narrow_cast<int>(r * cos36);
	pentagon.add(Point{ center_x, center_y - r });
	pentagon.add(Point{ center_x - r_sin72, center_y - r_cos72 });
	pentagon.add(Point{ center_x - r_sin36, center_y + r_cos36 });
	pentagon.add(Point{ center_x + r_sin36, center_y + r_cos36 });
	pentagon.add(Point{ center_x + r_sin72, center_y - r_cos72 });
	pentagon.set_color(Color::blue);
	pentagon.set_style(Line_style(Line_style::solid, 2));
	win.attach(pentagon);

	Polygon hexagon;
	const double sin30 = sin(2 * pi / 12);
	const double cos30 = cos(2 * pi / 12);
	const int r_sin30 = narrow_cast<int>(r * sin30);
	const int r_cos30 = narrow_cast<int>(r * cos30);
	hexagon.add(Point{ center_x, center_y - r });
	hexagon.add(Point{ center_x - r_cos30, center_y - r_sin30 });
	hexagon.add(Point{ center_x - r_cos30, center_y + r_sin30 });
	hexagon.add(Point{ center_x, center_y + r });
	hexagon.add(Point{ center_x + r_cos30, center_y + r_sin30 });
	hexagon.add(Point{ center_x + r_cos30, center_y - r_sin30 });
	hexagon.set_color(Color::black);
	hexagon.set_style(Line_style(Line_style::solid, 2));
	win.attach(hexagon);


	win.set_label("Discard: 11");
	win.wait_for_button();
}