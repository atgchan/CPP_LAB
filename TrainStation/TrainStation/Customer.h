#pragma once
class Customer
{
public:
	Customer();
	~Customer();
	void SetCustomerName(string s);
	void SetArrivalTime(int i);
	void SetCounterTime(int i);
	void SetDepartName(string s);
	void SetDestiName(string s);
	void SetTravellingTime(int i);

	string GetCustomerName();
	int GetArrivalTime();
	int GetCounterTime();
	string GetDepartName();
	string GetDestiName();
	int GetTravellingTime();
	int GetEnterCounterTime();

	void PrintStatus();
	void increaseWaitingTime();
	void RecordStatus(int currentTime);
	void SetEnterCounterTime(int currentTime);
	void SetLeavingTime(int currentTime);

private:
	string customerName;
	int arrivalTime;
	int counterTime;
	string departName;
	string destiName;
	int travellingTime;

	int enterCounterTime;
	int waitingTime;
	int leavingTime;
};

