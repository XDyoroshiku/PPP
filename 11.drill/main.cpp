#pragma once
#include "PPP/Simple_window.h"
#include "PPP/Graph.h"
#include "PPP.h"

using namespace Graph_lib;

int main()
{
    try
    {
        Application app;

        // drill_1
        constexpr Point x{ 100,100 };

        Simple_window win{ x, 800, 1000, "drill_1" };

        // drill_2
        const int x_size = 800;
        const int y_size = 800;
        const int x_grid = 100;
        const int y_grid = 100;
        Lines grid;
        for (int x = 0; x <= x_size; x += x_grid)
            grid.add(Point(x, 0), Point(x, y_size));
        for (int y = 0; y <= y_size; y += x_grid)
            grid.add(Point(0, y), Point(x_size, y));
        win.attach(grid);
        win.set_label("drill_2");
        win.wait_for_button();

        // drill_3
        Vector_ref<Rectangle> rectangles;
        for (int x = 0; x <= x_size; x += x_grid)
        {
            rectangles.push_back(make_unique<Rectangle>(Point{x, x}, x_grid, x_grid ));
            rectangles[rectangles.size() - 1].set_fill_color(Color::red);
        }
        for (size_t i = 0; i < rectangles.size(); ++i)
            win.attach(rectangles[i]);
        win.set_label("drill_3");
        win.wait_for_button();

        // drill_4
        Image pat1{ Point{200, 0}, "pat.jpg" };
        Image pat2{ Point{400, 0}, "pat.jpg" };
        Image pat3{ Point{600, 0}, "pat.jpg" };

        win.attach(pat1);
        win.attach(pat2);
        win.attach(pat3);
        win.set_label("drill_4");
        win.wait_for_button();

        // drill_5
        Image scream_cat{ Point{-x_grid, 0}, "Scream Cat.jpg" };
        win.set_label("drill_5");
        win.attach(scream_cat);
        for (int y = 0; y < y_size; y += y_grid)
        {
            for (int x = 0; x < x_size; x += x_grid)
            {
                scream_cat.move(x_grid, 0);
                win.wait_for_button();
            }
            scream_cat.move(-x_size, y_grid);
        }
        win.wait_for_button();
    }
    catch (...)
    {
        cout << "something went wrong\n";
    }
}


