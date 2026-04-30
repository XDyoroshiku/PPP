#include "10.exercises.h"
#include "PPP/Simple_window.h"
#include "PPP.h"

constexpr double pi = 3.1415926;
constexpr double pi_2 = pi * 2;
constexpr int c_x = 300;
constexpr int c_y = 200;
constexpr int scale = 150;

int sgn(double w);
Vector<Point> get_superellipse_points(const double&, const double&, const double&, const double&, const int&);
void superellipse_lines(const Vector<Point>&, Lines&);

void Ex_12(Simple_window& win)
{
    win.resize(600, 400);

    // in visaul studio, press CTRL+H and select the paragrah to be replaced and replace with ease.

    Lines se_1;
    superellipse_lines(get_superellipse_points(1, 1, 0.1, 0.1, 360), se_1);
    se_1.set_color(Color::red);
    se_1.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_1);

    Lines se_2;
    superellipse_lines(get_superellipse_points(1, 1, 0.2, 0.2, 360), se_2);
    se_2.set_color(Color::red);
    se_2.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_2);

    Lines se_3;
    superellipse_lines(get_superellipse_points(1, 1, 0.25, 0.25, 360), se_3);
    se_3.set_color(Color::red);
    se_3.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_3);

    Lines se_4;
    superellipse_lines(get_superellipse_points(1, 1, 0.3, 0.3, 360), se_4);
    se_4.set_color(Color::red);
    se_4.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_4);

    Lines se_5;
    superellipse_lines(get_superellipse_points(1, 1, 0.35, 0.35, 360), se_5);
    se_5.set_color(Color::yellow);
    se_5.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_5);

    Lines se_6;
    superellipse_lines(get_superellipse_points(1, 1, 0.4, 0.4, 360), se_6);
    se_6.set_color(Color::yellow);
    se_6.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_6);

    Lines se_7;
    superellipse_lines(get_superellipse_points(1, 1, 0.45, 0.45, 360), se_7);
    se_7.set_color(Color::yellow);
    se_7.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_7);

    Lines se_8;
    superellipse_lines(get_superellipse_points(1, 1, 0.5, 0.5, 360), se_8);
    se_8.set_color(Color::yellow);
    se_8.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_8);

    Lines se_9;
    superellipse_lines(get_superellipse_points(1, 1, 0.55, 0.55, 360), se_9);
    se_9.set_color(Color::green);
    se_9.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_9);

    Lines se_10;
    superellipse_lines(get_superellipse_points(1, 1, 0.6, 0.6, 360), se_10);
    se_10.set_color(Color::green);
    se_10.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_10);

    Lines se_11;
    superellipse_lines(get_superellipse_points(1, 1, 0.65, 0.65, 360), se_11);
    se_11.set_color(Color::green);
    se_11.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_11);

    Lines se_12;
    superellipse_lines(get_superellipse_points(1, 1, 0.7, 0.7, 360), se_12);
    se_12.set_color(Color::green);
    se_12.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_12);

    Lines se_13;
    superellipse_lines(get_superellipse_points(1, 1, 0.75, 0.75, 360), se_13);
    se_13.set_color(Color::cyan);
    se_13.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_13);

    Lines se_14;
    superellipse_lines(get_superellipse_points(1, 1, 0.8, 0.8, 360), se_14);
    se_14.set_color(Color::cyan);
    se_14.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_14);

    Lines se_15;
    superellipse_lines(get_superellipse_points(1, 1, 0.85, 0.85, 360), se_15);
    se_15.set_color(Color::cyan);
    se_15.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_15);

    Lines se_16;
    superellipse_lines(get_superellipse_points(1, 1, 0.9, 0.9, 360), se_16);
    se_16.set_color(Color::cyan);
    se_16.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_16);

    Lines se_17;
    superellipse_lines(get_superellipse_points(1, 1, 0.95, 0.95, 360), se_17);
    se_17.set_color(Color::blue);
    se_17.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_17);

    Lines se_18;
    superellipse_lines(get_superellipse_points(1, 1, 1, 1, 360), se_18);
    se_18.set_color(Color::blue);
    se_18.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_18);

    Lines se_19;
    superellipse_lines(get_superellipse_points(1, 1, 1.1, 1.1, 360), se_19);
    se_19.set_color(Color::blue);
    se_19.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_19);

    Lines se_20;
    superellipse_lines(get_superellipse_points(1, 1, 1.2, 1.2, 360), se_20);
    se_20.set_color(Color::blue);
    se_20.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_20);

    Lines se_21;
    superellipse_lines(get_superellipse_points(1, 1, 1.4, 1.4, 360), se_21);
    se_21.set_color(Color::magenta);
    se_21.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_21);

    Lines se_22;
    superellipse_lines(get_superellipse_points(1, 1, 1.6, 1.6, 360), se_22);
    se_22.set_color(Color::magenta);
    se_22.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_22);

    Lines se_23;
    superellipse_lines(get_superellipse_points(1, 1, 1.8, 1.8, 360), se_23);
    se_23.set_color(Color::magenta);
    se_23.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_23);

    Lines se_24;
    superellipse_lines(get_superellipse_points(1, 1, 2, 2, 360), se_24);
    se_24.set_color(Color::magenta);
    se_24.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_24);

    Lines se_25;
    superellipse_lines(get_superellipse_points(1, 1, 2.3, 2.3, 360), se_25);
    se_25.set_color(Color::dark_red);
    se_25.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_25);

    Lines se_26;
    superellipse_lines(get_superellipse_points(1, 1, 2.4, 2.4, 360), se_26);
    se_26.set_color(Color::dark_red);
    se_26.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_26);

    Lines se_27;
    superellipse_lines(get_superellipse_points(1, 1, 2.7, 2.7, 360), se_27);
    se_27.set_color(Color::dark_red);
    se_27.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_27);

    Lines se_28;
    superellipse_lines(get_superellipse_points(1, 1, 3, 3, 360), se_28);
    se_28.set_color(Color::dark_red);
    se_28.set_style(Line_style(Line_style::solid, 2));
    win.attach(se_28);


    win.set_label("Ex_12");
    win.wait_for_button();
}


int sgn(double w)
{
    if (w < 0) return -1;
    else if (w > 0) return 1;
    else return 0;
}

Vector<Point> get_superellipse_points(const double& a, const double& b, const double& m, const double& n, const int& N)
// The superellipse formula: |x/a|^m + |y/b|^n = 1; 
// or: x = |cosθ|^(2/m) * a * sgn(cosθ), y = |sinθ|^(2/n) * b * sgn(cosθ).
{
    if (m == 0 || n == 0)
        throw runtime_error("m or n can't be 0");

    Vector<Point> points;
    const double add_θ = pi * 2 / N;
    double x = 0;
    double y = 0;
    int x_scale = 0;
    int y_scale = 0;
    double cosθ = 0;
    double sinθ = 0;
    for (double θ = 0; θ < pi_2; θ += add_θ)
    {
        cosθ = cos(θ);
        sinθ = sin(θ);
        x = pow(fabs(cosθ), 2 / m) * a * sgn(cosθ);
        y = pow(fabs(sinθ), 2 / n) * b * sgn(sinθ);
        x_scale = narrow_cast<int>(x * scale);
        y_scale = narrow_cast<int>(y * scale);
        points.push_back(Point{ c_x + x_scale, c_y + y_scale });
        x, y, x_scale, y_scale, cosθ, sinθ = 0;
    }
    return points;
}

void superellipse_lines(const Vector<Point>& points, Lines& lines)
{
    size_t size = points.size();
    for (size_t i = 0; i < size - 1; ++i)
    {
        lines.add(points[i], points[i + 1]);
    }
}