#include "10.exercises.h"
#include "PPP/Simple_window.h"

void Ex_03(Simple_window& win)
{
    win.resize(600, 400);

    Lines first_initial;
    first_initial.add(Point{ 150, 100 }, Point{ 150, 250 });
    first_initial.add(Point{ 150, 250 }, Point{ 243, 250 });
    first_initial.set_color(Color::red);
    win.attach(first_initial);

    Lines second_initial;
    second_initial.add(Point{ 450, 100 }, Point{ 450, 200 });
    second_initial.add(Point{ 450, 200 }, Point{ 403, 250 });
    second_initial.add(Point{ 403, 250 }, Point{ 356, 200 });
    second_initial.set_color(Color::dark_green);
    win.attach(second_initial);

    win.set_label("Ex_03");
    win.wait_for_button();
}