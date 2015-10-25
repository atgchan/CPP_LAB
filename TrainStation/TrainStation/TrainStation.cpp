#include "stdafx.h"
#include "TrainStation.h"
#include "Customer.h"
#include "strategyFIFO.h"
#include <fstream>

TrainStation* TrainStation::inst;

TrainStation::TrainStation()
	:currentTime(0)
{
	counter = new Counter(3);
	customerList = new Queue<Customer>(100);
	waitLine = new Queue<Customer>(100);
	trainLine = new Queue<Customer>(100);
}

TrainStation::~TrainStation()
{
	delete counter;
	delete customerList;
	delete waitLine;
	delete trainLine;
}

void TrainStation::openTrainStation()
{
	ifstream customerInfo;
	customerInfo.open("info.txt");
	char output[100];
	if (customerInfo.is_open())
	{
		int customerCount = 0;
		int totalCount = 0;
		Customer* customer;

		while (!customerInfo.eof())
		{
			customerInfo >> output;
			if (totalCount % 7 == 0)
			{
				customer = new Customer();
				customerCount++;
			}
			else if (totalCount % 7 == 1)
			{
				customer->SetCustomerName(output);
			}
			else if (totalCount % 7 == 2)
			{
				customer->SetArrivalTime(atoi(output));
			}
			else if (totalCount % 7 == 3)
			{
				customer->SetCounterTime(atoi(output));
			}
			else if (totalCount % 7 == 4)
			{
				customer->SetDepartName(output);
			}
			else if (totalCount % 7 == 5)
			{
				customer->SetDestiName(output);
			}
			else if (totalCount % 7 == 6)
			{
				customer->SetTravellingTime(atoi(output));
			}

			totalCount++;

			if (totalCount % 7 == 0)
			{
				customerList->enQueue(customer);
			}
		}
	}
	customerInfo.close();
}

void TrainStation::printCustomerList()
{
	for (int i = 0; i < customerList->size(); i++)
	{
		customerList->get(i)->PrintStatus();
	}
}

void TrainStation::startTrainStation(string st)
{
	if (st.compare("fifo"))
	{
		strategy = new strategyFIFO();
	}
	else
	{
		strategy = new strategyFIFO();
	}

	PrintFileHead();

	while (currentTime < 100)
	{
		//�����ð��� �� ���� ����ٿ� �����.
		while (customerList->get(0) != nullptr && customerList->get(0)->GetArrivalTime() == currentTime)
		{
			waitLine->enQueue(customerList->deQueue());
		}

		//Ƽ������ �Ϸ��� ���� ��������.
		counter->releaseCustomer(currentTime, trainLine);


		//������ ���� trainLine�� �ִ� ���� ������ �¿�� ���Ϸ� ����� �����Ѵ�.
		if (currentTime % 3 == 2)
		{
			for (int i = 0; i < trainLine->size(); i++)
			{
				if (trainLine->get(0) != nullptr)
				{
					trainLine->get(0)->RecordStatus(currentTime);
					trainLine->deQueue();
				}
			}
		}
		else
		{
			//������ Ÿ�� ���ϸ� ���ð� +1
			for (int i = 0; i < trainLine->size(); i++)
			{
				if (trainLine->get(i) != nullptr)
				{
					trainLine->get(i)->increaseWaitingTime();
				}
			}
		}

		//�����ִ� ī���Ϳ� ���� �鿩������.
		while (counter->getAvailableClerk() != nullptr)
		{
			//ī���Ͱ� ���� ����ٿ� ���� ������ ���
			if (waitLine->get(0) == nullptr)
			{
				break;
			}
			strategy->getNextCustomer(waitLine, currentTime, counter);
		}

		//ī���Ϳ� ���� ���� ���� ���ð��� +1 �Ѵ�.
		for (int i = 0; i < waitLine->size(); i++)
		{
			if (waitLine->get(i) != nullptr)
			{
				waitLine->get(i)->increaseWaitingTime();
			}
		}

		currentTime++;
	}
}

void TrainStation::PrintFileHead()
{
	ofstream outFile("result.txt", ios::app);
	outFile.width(10); outFile.fill(); outFile << "����";
	outFile.width(20); outFile.fill(); outFile << "������ �����ð�";
	outFile.width(10); outFile.fill(); outFile << "���ð�";
	outFile.width(20); outFile.fill(); outFile << "���� ž�½ð�";
	outFile.width(20); outFile.fill(); outFile << "������ �����ð�";
	outFile << endl;
}
