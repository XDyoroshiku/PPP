#include "PPP/Window.h"
#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

double dsin(double d) { return sin(d); }    // chose the right sin() (§13.3)

int main(int /*argc*/, char* /*argv*/[])
{ 
    using namespace Graph_lib;                                          // our graphics facilities are in Graph_lib

    Application app;                                                    // start a Graphics/GUI application

    Point tl{ 900,500 };                                                // to become top left corner of window

    Simple_window win{ tl,600,400,"Canvas" };                           // make a simple window

    ////e.g.10_3
    //Polygon poly;                                                       // make a shape (a polygon)
    //poly.add(Point{ 300,200 });                                         // add a point
    //poly.add(Point{ 350,100 });                                         // add another point
    //poly.add(Point{ 400,200 });                                         // add a third point
    //poly.set_color(Color::red);                                         // adjust properties of poly
    //win.attach(poly);                                                   // connect poly to the window
    //win.wait_for_button();                                              // give control to the display engine

    //e.g.10_7
    Axis xa{ Axis::x, Point{20,300}, 280, 10, "x axis" };               // make an Axis
    // an Axis is a kind of Shape
    // Axis::x means horizontal
    // starting at (20,300)
    // 280 pixels long
    // with 10 "notches"
    // label the axis "x axis"
    win.attach(xa);                                                     // attach xa to the window, win
    win.set_label("X axis");                                            // re-label the window
    win.wait_for_button();                                              // display!

    Axis ya{ Axis::y, Point{20,300}, 280, 10, "y axis" };
    ya.set_color(Color::cyan);                                          // choose a color for the y axis
    ya.label.set_color(Color::dark_red);                                // choose a color for the text
    win.attach(ya);
    win.set_label("Y axis");
    win.wait_for_button();                                              // display!

    Function sine{ dsin,0,100,Point{20,150},1000,50,50 };               // sine curve
    // plot sin() in the range [0:100) with (0,0) at (20,150)
    // using 1000 points; scale x values *50, scale y values *50
    win.attach(sine);
    win.set_label("Sine");
    win.wait_for_button();

    sine.set_color(Color::blue);                                        // we changed our mind about sine’s color

    Polygon poly;                                                       // a polygon; a Polygon is a kind of Shape
    poly.add(Point{ 300,200 });                                         // three points make a triangle
    poly.add(Point{ 350,100 });
    poly.add(Point{ 400,200 });
    poly.set_color(Color::red);
    win.attach(poly);
    win.set_label("Triangle");
    win.wait_for_button();

    Rectangle r{ Point{200,200}, 100, 50 };                             // top left corner, width, height
    win.attach(r);
    win.set_label("Rectangle");
    win.wait_for_button();

    Closed_polyline poly_rect;
    poly_rect.add(Point{ 100,50 });
    poly_rect.add(Point{ 200,50 });
    poly_rect.add(Point{ 200,100 });
    poly_rect.add(Point{ 100,100 });
    win.set_label("Polyline");
    win.attach(poly_rect);
    win.wait_for_button();

    poly_rect.add(Point{ 50,75 });
    win.set_label("Polyline 2");
    win.wait_for_button();

    r.set_fill_color(Color::yellow);                                    // color the inside of the rectangle
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.set_label("Fill");
    win.wait_for_button();

    Text t{ Point{150,150}, "Hello, graphical world!" };
    win.attach(t);
    win.set_label("Text");
    win.wait_for_button();

    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.set_label("Bold text");
    win.wait_for_button();

    Image copter{ Point{100,50},"mars_copter.jpg" };
    win.attach(copter);
    win.set_label("Mars copter");
    win.wait_for_button();

    copter.move(100, 250);
    win.set_label("Move");
    win.wait_for_button();

    Circle c{ Point{100,200},50 };
    Ellipse e{ Point{100,200}, 75,25 };
    e.set_color(Color::dark_red);
    Mark m{ Point{100,200},'x' };
    m.set_color(Color::red);
    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes{ Point{100,20},oss.str() };
    Image scan{ Point{275,225},"scandinavia.jfif" };
    scan.scale(150, 200);
    win.attach(c);
    win.attach(m);
    win.attach(e);
    win.attach(sizes);
    win.attach(scan);
    win.set_label("Final!");
    win.wait_for_button();

}