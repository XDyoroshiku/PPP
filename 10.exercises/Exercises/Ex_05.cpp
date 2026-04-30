#include "10.exercises.h"
#include "PPP/Simple_window.h"

void Ex_05(Simple_window& win)
{
    win.resize(x_max(), y_max());

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes{ Point{100,20},oss.str() };
    win.attach(sizes);

    constexpr int p_x = 100;
    constexpr int p_y = 100;
    Point p{ p_x, p_y };
    int r_width = x_max() / 3 * 2;
    int r_height = y_max() / 4 * 3;
    Rectangle r{ p, r_width, r_height };
    r.set_color(Color::blue);
    win.attach(r);

    constexpr int inch = 27;
    constexpr int p2_x = p_x - inch;
    constexpr int p2_y = p_y - inch;
    int frame_width = r_width + 2 * inch;
    int frame_height = r_height + 2 * inch;
    Closed_polyline poly_rect;
    poly_rect.add(Point{ p2_x, p2_y });
    poly_rect.add(Point{ p2_x + frame_width, p2_y });
    poly_rect.add(Point{ p2_x + frame_width, p2_y + frame_height });
    poly_rect.add(Point{ p2_x, p2_y + frame_height });
    poly_rect.set_color(Color::red);
    win.attach(poly_rect);

    win.set_label("Ex_05");
    win.wait_for_button();
}