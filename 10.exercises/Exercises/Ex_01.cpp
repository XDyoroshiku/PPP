#include "10.exercises.h"
#include "PPP/Simple_window.h"

void Ex_01(Simple_window& win)
{
    win.resize(600, 400);

    Rectangle r{ Point {100, 175}, 100, 50 };
    r.set_color(Color::blue);
    win.attach(r);

    Polygon poly;
    poly.add(Point{ 400, 175 });
    poly.add(Point{ 500, 175 });
    poly.add(Point{ 500, 225 });
    poly.add(Point{ 400, 225 });
    poly.set_color(Color::red);
    win.attach(poly);

    win.set_label("Ex_01");
    win.wait_for_button();
}