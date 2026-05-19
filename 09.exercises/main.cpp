import exercises;
import std;

int main()
{
	try
	{
		//Ex_01();
		//Ex_02();
		//Ex_03();
		//Ex_04();
		//Ex_05();
		//Ex_06_08();
		//Ex_09();
		//Ex_10();
		//Ex_11();
		//Ex_12();
		//Ex_13();
		//Ex_14();
		//Ex_15();
		Ex_16();


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