import exercises;
import std;

int main()
{
	try
	{
		//Ex_01();
		//Ex_02();
		//Ex_03();
		Ex_04();


		return 0;
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
}