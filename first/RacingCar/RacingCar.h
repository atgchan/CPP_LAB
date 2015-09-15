#ifndef __RACING_H_
#define __RACING_H_

namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		SPEED_STEP = 10,
		BREAK_STEP = 10,
		FUEL_STEP = 2
	};
}

class RacingCar
{
public:
	RacingCar()
	{
		cout << "Create Car" << endl;
	}
	~RacingCar()
	{
		cout << "Delete Car" << endl;
	}

private:
	char gameID[CAR_CONST::ID_LEN];
	int fuelGuage;
	int curSpeed;
public:
	void InitMember(char* ID, int fuel);
	void ShowCurrentState();
	void Accel();
	void Break();
};

#endif
