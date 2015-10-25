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
		//도착시간이 된 고객을 대기줄에 새운다.
		while (customerList->get(0) != nullptr && customerList->get(0)->GetArrivalTime() == currentTime)
		{
			waitLine->enQueue(customerList->deQueue());
		}

		//티케팅을 완료한 고객을 내보낸다.
		counter->releaseCustomer(currentTime, trainLine);


		//기차가 오면 trainLine에 있는 고객을 기차에 태우고 파일로 결과를 저장한다.
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
			//기차에 타지 못하면 대기시간 +1
			for (int i = 0; i < trainLine->size(); i++)
			{
				if (trainLine->get(i) != nullptr)
				{
					trainLine->get(i)->increaseWaitingTime();
				}
			}
		}

		//남아있는 카운터에 고객을 들여보낸다.
		while (counter->getAvailableClerk() != nullptr)
		{
			//카운터가 비었어도 대기줄에 고객이 없으면 통과
			if (waitLine->get(0) == nullptr)
			{
				break;
			}
			strategy->getNextCustomer(waitLine, currentTime, counter);
		}

		//카운터에 들어가지 못한 고객의 대기시간을 +1 한다.
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
	outFile.width(10); outFile.fill(); outFile << "고객명";
	outFile.width(20); outFile.fill(); outFile << "기차역 도착시간";
	outFile.width(10); outFile.fill(); outFile << "대기시간";
	outFile.width(20); outFile.fill(); outFile << "기차 탑승시간";
	outFile.width(20); outFile.fill(); outFile << "목적지 도착시간";
	outFile << endl;
}
