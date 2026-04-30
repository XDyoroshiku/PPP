#include "10.exercises.h"
#include "PPP/Simple_window.h"

void Ex_09(Simple_window& win)
{
	win.resize(600, 400);

	Image mmc{ Point{150, 50}, "mmc.gif" };
	mmc.scale(300, 300);
	win.attach(mmc);

	Text t{ Point{200, 50}, "Overelaborate" };
	t.set_font_size(25);
	t.set_font(Font::helvetica_bold);
	win.attach(t);

	win.set_label("Ex_09: Overelaborate");
	win.wait_for_button();
}