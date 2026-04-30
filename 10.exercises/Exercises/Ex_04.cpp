#include "10.exercises.h"
#include "PPP/Simple_window.h"

void Ex_04(Simple_window& win)
{
    win.resize(600, 400);

    Closed_polyline white_square;
    white_square.add(Point{ 150,50 });
    white_square.add(Point{ 450,50 });
    white_square.add(Point{ 450,350 });
    white_square.add(Point{ 150,350 });
    white_square.set_fill_color(Color::white);
    white_square.set_color(Color::black);
    win.attach(white_square);

    Closed_polyline red_square_1;
    red_square_1.add(Point{ 250,50 });
    red_square_1.add(Point{ 350,50 });
    red_square_1.add(Point{ 350,150 });
    red_square_1.add(Point{ 250,150 });
    red_square_1.set_fill_color(Color::red);
    red_square_1.set_color(Color::black);
    win.attach(red_square_1);

    Closed_polyline red_square_2;
    red_square_2.add(Point{ 150,150 });
    red_square_2.add(Point{ 250,150 });
    red_square_2.add(Point{ 250,250 });
    red_square_2.add(Point{ 150,250 });
    red_square_2.set_fill_color(Color::red);
    red_square_2.set_color(Color::black);
    win.attach(red_square_2);

    Closed_polyline red_square_3;
    red_square_3.add(Point{ 350,150});
    red_square_3.add(Point{ 450,150});
    red_square_3.add(Point{ 450,250 });
    red_square_3.add(Point{ 350,250 });
    red_square_3.set_fill_color(Color::red);
    red_square_3.set_color(Color::black);
    win.attach(red_square_3);

    Closed_polyline red_square_4;
    red_square_4.add(Point{ 250,250 });
    red_square_4.add(Point{ 350,250 });
    red_square_4.add(Point{ 350,350 });
    red_square_4.add(Point{ 250,350 });
    red_square_4.set_fill_color(Color::red);
    red_square_4.set_color(Color::black);
    win.attach(red_square_4);



    win.set_label("Ex_04");
    win.wait_for_button();
}