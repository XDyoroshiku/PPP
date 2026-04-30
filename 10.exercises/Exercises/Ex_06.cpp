#include "10.exercises.h"
#include "PPP/Simple_window.h"

void Ex_06(Simple_window& win)
{
    int window_width = x_max() * 3;
    int window_height = y_max() * 3;
    win.resize(window_width, window_height);

    Circle c(Point{ 100, 100 }, x_max());
    c.set_fill_color(Color::yellow);
    win.attach(c);

    Circle c2(Point{ 2 * x_max(), 2 * y_max() }, x_max());
    c2.set_fill_color(Color::green);
    win.attach(c2);

    win.set_label("Ex_06");
    win.wait_for_button();
}