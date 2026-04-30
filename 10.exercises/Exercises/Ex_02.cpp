#include "10.exercises.h"
#include "PPP/Simple_window.h"

void Ex_02(Simple_window& win)
{
    win.resize(600, 400);

    Rectangle r{ Point {200, 150}, 200, 100 };
    win.attach(r);

    Text t{ Point{250, 175}, "Howdy!" };
    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.attach(t);

    win.set_label("Ex_02");
    win.wait_for_button();
}