#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

int main()
{
	std::vector<std::string> names;

<<<<<<< HEAD
	names.push_back("�ۿ���");
	names.push_back("���¿�");
	names.push_back("�����");
	names.push_back("����ȣ");
	names.push_back("������");
	names.push_back("�̵���");
=======
	names.push_back("wonseok");
	names.push_back("taewoo");
	names.push_back("huisoo");
	names.push_back("taeho");
	names.push_back("jinwook");
	names.push_back("dohyung");
	names.push_back("koo");
>>>>>>> bfdfd02b627420b3b8bbaacb7481bc827e0ed651

	int mode = names.size();
	int team = 1;
	while (!names.empty())
	{
		srand((unsigned int)time(NULL));
		int index = rand() % mode;

		if (mode % 2 == 0)
		{
			std::cout << "---------------team" << team << "-----------------" << std::endl;
			team++;
		}
		std::cout << names[index] << std::endl;
		names.erase(names.begin() + index);

		mode--;
	}

	getchar();

	return 0;
}
