#include"function.h"
int main()
{
	int skaicius = 100;
	for (int i = 0; i < 5; i++)
	{
		std::ofstream out("mokiniai" + std::to_string(i + 1) + ".txt");
		generavimas(out, skaicius);
		out.close();
		skaicius *= 10;
	}
}
