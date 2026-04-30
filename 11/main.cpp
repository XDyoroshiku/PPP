#pragma once
#include "PPP/Simple_window.h"
#include "PPP/Graph.h"
#include "PPP.h"

using namespace Graph_lib;


int main()
//  draw two lines
{
    try
    {
        Application app;

        constexpr Point x{ 100,100 };

        //// 11_2
        //// two lines
        //Simple_window win{ x,600,400,"two lines" };
        //Line horizontal{ x,Point{200,100} };                              // make a horizontal line
        //Line vertical{ Point{150,50},Point{150,150} };              // make a vertical line

        //win.attach(horizontal);                                                  // attach the lines to the window
        //win.attach(vertical);
        //win.set_label("two lines");
        //win.wait_for_button();                                                   // display!

        //// 11_3
        //// lines
        //constexpr Point x2{ 100 + 600, 100 };
        //Simple_window win2{ x2, 600,400, "lines" };
        //Lines y;
        //y.add(Point{ 100,100 }, Point{ 200,100 });               // first line: horizontal
        //y.add(Point{ 150,50 }, Point{ 150,150 });                 // second line: vertical
        //win2.attach(y);
        //win2.wait_for_button();

        ////grid
        //constexpr Point x3{ 100, 100 + 400 };
        //Simple_window win3{ x3, 600,400, "Grid" };
        //int x_size = win3.x_max();              // get the size of our window
        //int y_size = win3.y_max();
        //int x_grid = 80;
        //int y_grid = 40;

        //Lines grid;
        //for (int x = x_grid; x < x_size; x += x_grid)
        //    grid.add(Point{ x, 0 }, Point{ x, y_size });                // vertical line
        //for (int y = y_grid; y < y_size; y += y_grid)
        //    grid.add(Point{ 0, y }, Point{ x_size, y });                // horizontal line
        //win3.attach(grid);
        //win3.wait_for_button();                                                   // display!

        //// 11_4
        //// set the color of the grid.
        //grid.set_color(Color::red);
        //win3.set_label("Red grid");
        //win3.wait_for_button();

        //// 11_5
        //grid.set_style(Line_style::dot);
        //win3.set_label("Red dotted grid");
        //win3.wait_for_button();

        //grid.set_style(Line_style{ Line_style::dash, 2 });
        //win3.set_label("Red fat dashed grid");
        //win3.wait_for_button();

        //// Try this
        //constexpr Point x4{ 100 + 600, 100 + 400};
        //Simple_window win_try{ x4, 600, 400, "Try This" };
        //int x_size_try = win_try.x_max();              // get the size of our window
        //int y_size_try = win_try.y_max();
        //int x_grid_try = 40;
        //int y_grid_try = 60;
        //Lines grid_try;
        //for (int x = x_grid_try; x < x_size_try; x += x_grid_try)
        //    grid_try.add(Point{ x, 0 }, Point{ x, y_size_try });                // vertical line
        //for (int y = y_grid_try; y < y_size_try; y += y_grid_try)
        //    grid_try.add(Point{ 0, y }, Point{ x_size_try, y });                // horizontal line
        //grid_try.set_color(99);
        //grid_try.set_style(Line_style::dashdot);
        //win_try.attach(grid_try);
        //win_try.wait_for_button();


        //// continuing with 11.2
        //horizontal.set_color(Color::red);
        //vertical.set_color(Color::green);
        //win.set_label("Two lines colored");
        //win.wait_for_button();


        //// 11_6
        //Simple_window win6{ x, 600, 400, "Open polyline" };
        //Open_polyline opl = { {100, 100}, {150, 200}, {250, 250}, {300, 200} };
        //win6.attach(opl);
        //win6.wait_for_button();


        //Simple_window win7{ x, 600, 400, "Closed polyline" };
        //Closed_polyline cpl = { {100, 100}, {150, 200}, {250, 250}, {300, 200} };
        //win7.attach(cpl);
        //win7.wait_for_button();


        //Simple_window win8{ x, 600, 400, "Marked polyline" };
        //Marked_polyline mpl{ "1234", {{100, 100}, {150, 200}, {250, 250}, {300, 200}} };
        //win8.attach(mpl);
        //win8.wait_for_button();


        //Simple_window win9{ x, 600, 400, "Marked polyline" };
        //Marks pp{ "x", {{100, 100}, {150, 200}, {250, 250}, {300, 200}} };
        //win9.attach(pp);
        //win9.wait_for_button();


        //// 11_7
        //Simple_window win10{ x, 600, 400, "Closed polyline crossing" };
        //Closed_polyline cplc = { {100, 100}, {150, 200}, {250, 250}, {300, 200} };
        //cplc.add(Point{ 100, 250 });
        //win10.attach(cplc);
        //win10.wait_for_button();


        //Simple_window win11{ x, 600, 400, "Polygon" };
        //Closed_polyline poly = { {100, 100}, {150, 200}, {250, 250}, {300, 200} };
        //win11.attach(poly);
        //win11.wait_for_button();


        //Simple_window win12{ x, 600, 400, "Rectangles" };
        //Rectangle rect00{ Point{150,100},200,100 };
        //Rectangle rect11{ Point{50,50},Point{250,150} };
        //Rectangle rect12{ Point{50,150},Point{250,250} };               // just below rect11
        //Rectangle rect21{ Point{250,50},200,100 };                          // just to the right of rect11
        //Rectangle rect22{ Point{250,150},200,100 };                        // just below rect21

        //rect00.set_fill_color(Color::yellow);
        //rect11.set_fill_color(Color::blue);
        //rect12.set_fill_color(Color::red);
        //rect21.set_fill_color(Color::green);

        //win12.attach(rect00);
        //win12.attach(rect11);
        //win12.attach(rect12);
        //win12.attach(rect21);
        //win12.attach(rect22);

        //win12.wait_for_button();

        //rect11.move(400, 0);
        //rect11.set_fill_color(Color::white);
        //win12.set_label("Rectangles - white moved");
        //win12.wait_for_button();

        //win12.put_on_top(rect00);
        //win12.wait_for_button();

        //rect00.set_color(Color::invisible);
        //rect11.set_color(Color::invisible);
        //rect12.set_color(Color::invisible);
        //rect21.set_color(Color::invisible);
        //rect22.set_color(Color::invisible);
        //win12.set_label("Rectangles - no edge lines");
        //win12.wait_for_button();


        //Simple_window win13(x, 600, 400, "Palette");
        //Vector_ref<Rectangle> vr;
        //const int max = 32;           // number of columns
        //const int side = 18;           // size of color rectangle
        //const int left = 10;            // left edge
        //const int top = 100;          // top edge
        //int color_index = 0;
        //for (int i = 0; i < max; ++i) {                // all columns
        //    for (int j = 0; j < 8; ++j) {            // 8 rows in each column
        //        vr.push_back(make_unique<Rectangle>(Point{ i * side + left,j * side + top }, side, side));
        //        int subscript = int(vr.size() - 1);
        //        vr[subscript].set_fill_color(color_index);
        //        ++color_index;                   // move to the next color
        //        win13.attach(vr[subscript]);
        //    }
        //}
        //win13.wait_for_button();

        //Simple_window win14(x, 600, 400, "Circles");
        //Circle c1{ Point{100,200},50 };
        //Circle c2{ Point{150,200},100 };
        ////c2.set_fill_color(Color::red);
        //win14.put_on_top(c1);
        //Circle c3{ Point{200,200},150 };
        //win14.attach(c1);
        //win14.attach(c2);
        //win14.attach(c3);
        //win14.wait_for_button();

        //Simple_window win15(x, 600, 400, "Elipses");
        //Ellipse e1{ Point{200,200},50,50 };
        //Ellipse e2{ Point{200,200},100,50 };
        //Ellipse e3{ Point{200,200},100,150 };
        //win15.attach(e1);
        //win15.attach(e2);
        //win15.attach(e3);
        //win15.wait_for_button();

        // 11_8
        //Simple_window win16{ x, 600, 400, "Text" };
        //Closed_polyline cplc = { {100, 100}, {150, 200}, {250, 250}, {300, 200} };
        //cplc.add(Point{ 100, 250 });
        //Text t{ Point{150,200},"A closed polyline that isn't a polygon" };
        //t.set_color(Color::blue);
        //win16.attach(cplc);
        //win16.attach(t);
        //win16.wait_for_button();

        //t.set_font(Font::helvetica_bold_italic);
        //t.set_color(Color::blue);
        //win16.wait_for_button();

        // 11_9
        //Simple_window win17{ x, 600, 400, "Text" };
        //Circle c1{ Point{100,200},50 };
        //Circle c2{ Point{150,200},100 };
        //Circle c3{ Point{200,200},150 };

        //Mark m1{ Point{100,200},'x' };
        //Mark m2{ Point{150,200},'y' };
        //Mark m3{ Point{200,200},'z' };

        //c1.set_color(Color::blue);
        //c2.set_color(Color::red);
        //c3.set_color(Color::green);

        //m1.set_mark_color(Color::blue);
        //m2.set_mark_color(Color::red);
        //m3.set_mark_color(Color::green);

        //win17.attach(c1);
        //win17.attach(c2);
        //win17.attach(c3);
        //win17.attach(m1);
        //win17.attach(m2);
        //win17.attach(m3);
        //win17.wait_for_button();

        // 11_10
        Simple_window win18{ x, 600, 400, "Hurricane path and photo" };

        Image path{ Point{0,0},"hurricane_path.gif" };
        path.set_mask(Point{ 250,0 }, 600, 400);    // select likely landfall

        Image hurricane{ Point{350,0},"hurricane.jpg" };
        hurricane.scale(300, 200);

        win18.attach(path);
        win18.attach(hurricane);
        win18.wait_for_button();

    }
    catch (...)
    {
        cout << "something went wrong\n";
    }
}


