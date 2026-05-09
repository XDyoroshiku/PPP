import _9;
import std;

int main()
{
	try
	{
		//_9_3();
		//_9_5();
		_9_9();
		//_9_10_1_try();
		//_9_10_1();
		//_9_10_6_try();
		//_9_11();
	}
	catch (std::exception& e)
	{
		std::cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...)
	{
		std::cerr << "Oops: unknown exception!" << '\n';
		return 2;
	}

	return 0;
}