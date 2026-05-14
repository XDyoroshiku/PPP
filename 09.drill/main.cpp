import drill;
import std;

int main()
{
	try
	{
		//Test_output();
		//Dr_08();
		//Dr_09();
		//Dr_10();
		//Dr_11();
		Dr_12_17();

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