#include "PPP/Simple_window.h"
#include "PPP/Graph.h"
#include "10.exercises.h"
#include "PPP.h"

using namespace Graph_lib;

int main(int /*argc*/, char* /*argv*/[])
{
    try
    {
        Application app;
        Simple_window win({ 900, 500 }, 600, 400, "Canvas");

        Ex_01(win);
        Ex_02(win);
        Ex_03(win);
        Ex_04(win);
        Ex_05(win);
        Ex_06(win);
        Ex_07(win);
        Ex_08(win);
        Ex_09(win);
        Ex_10(win);
        Ex_11(win);
        Discard_11(win);
        Ex_12(win);

        Text t{ Point{200, 150}, "The End!" };
        t.set_font(Font::courier_bold);
        t.set_font_size(40);
        win.attach(t);
        win.set_label("The End!");
        win.wait_for_button();
    }
    catch (exception &e)
    {
        cerr << "error: " << e.what() << '\n';
        system("pause");
    }
}


