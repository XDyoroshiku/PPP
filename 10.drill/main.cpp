// Origin source:https://github.com/villevoutilainen/ProgrammingPrinciplesAndPracticeUsingQt

#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

using namespace Graph_lib;

double dcos(double d) { return cos(d); }
//double dtan(double d) { return tan(d); }

int main(int /*argc*/, char* /*argv*/[])
{
    Application app;

    Point tl{ 900, 500 };

    Simple_window win{ tl, 600, 400, "Canvas" };

    win.set_label("My window");
    win.wait_for_button();

    Axis xa{ Axis::x, Point{20,360}, 500, 20, "x axis" };
    win.attach(xa);
    win.set_label("X axis");
    win.wait_for_button();

    Axis ya{ Axis::y, Point{20,360}, 350, 14, "y axis" };
    win.attach(ya);
    win.set_label("Y axis");
    win.wait_for_button();

    xa.set_color(Color::dark_green);
    xa.label.set_color(Color::dark_green);
    ya.set_color(Color::dark_magenta);
    ya.label.set_color(Color::dark_magenta);
    win.wait_for_button();

    Function cosine{ dcos, 0, 100, Point{20, 150}, 1000, 50, 50 };
    cosine.set_color(Color::palette_index);
    win.attach(cosine);
    win.set_label("Consine");

    //Function tangent{ dtan, 0, 100, Point{20, 150}, 1000, 50, 50 };
    //win.attach(tangent);
    win.wait_for_button();

    Polygon poly;
    poly.add(Point{ 450, 20 });               // 1
    poly.add(Point{ 433, 68 });               // 2
    poly.add(Point{ 383, 68 });               // 3
    poly.add(Point{ 424, 99 });               // 4
    poly.add(Point{ 407, 147 });              // 5
    poly.add(Point{ 450, 117 });              // 6
    poly.add(Point{ 493, 147 });              // 7
    poly.add(Point{ 476, 99 });               // 8
    poly.add(Point{ 517, 68 });               // 9
    poly.add(Point{ 467, 68 });               // 10
    poly.set_color(Color::red);
    poly.set_fill_color(Color::yellow);
    poly.move(60, -10);
    win.attach(poly);
    win.set_label("Star");
    win.wait_for_button();

    Open_polyline poly_rect;
    poly_rect.add(Point{ 450, 20 });          // 1
    poly_rect.add(Point{ 407, 147 });         // 5
    poly_rect.add(Point{ 517, 68 });          // 9
    poly_rect.add(Point{ 383, 68 });          // 3
    poly_rect.add(Point{ 493, 147 });         // 7
    poly_rect.add(Point{ 450, 20 });          // 1
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_color(Color::red);
    poly_rect.move(60, 130);
    win.attach(poly_rect);
    win.set_label("Another star");
    win.wait_for_button();

    Text text{ Point{150, 20}, "Oh, it's a rainy day." };
    text.set_font(Font::helvetica);
    win.attach(text);
    win.set_label("Text");
    win.wait_for_button();

    text.set_font(Font::helvetica_bold);
    text.set_font_size(20);
    win.set_label("Bold text");
    win.wait_for_button();

    Image scream_cat{ Point{350, 50}, "The Cat Scream.png" };
    scream_cat.scale(100, 100);
    win.attach(scream_cat);
    win.set_label("Scream_cat");
    win.wait_for_button();

    scream_cat.move(100, 250);
    win.set_label("Move");
    win.wait_for_button();


    Circle c{ Point{100,200},50 };

    Ellipse e{ Point{100,200}, 25,75 };
    e.set_color(Color::dark_red);
    Ellipse e2{ Point{100,200}, 75,25 };
    e.set_color(Color::dark_red);

    Mark m{ Point{100,200},'+' };
    m.set_color(Color::red);
    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes{ Point{100,150},oss.str() };

    Image pat{ Point{275,225},"pat.jpg" };
    pat.scale(150, 200);

    win.attach(c);
    win.attach(m);
    win.attach(e);
    win.attach(e2);

    win.attach(sizes);
    win.attach(pat);
    win.set_label("Final!");
    win.wait_for_button();

}
