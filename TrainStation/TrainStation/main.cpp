
#include "stdafx.h"
#include "TrainStation.h"


int _tmain(int argc, _TCHAR* argv[])
{
	TrainStation* ts = TrainStation::getInstance();

	ts->openTrainStation();
	//ts->printCustomerList();

	ts->startTrainStation("fifo");

	//getchar();
	return 0;
}

