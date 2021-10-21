class PIDController {
public:
	PIDController(double KP, double KI, double KD, double tolerance);

	double calculate(double sensor, double target);
	void setKP(double KP);
	void setKI(double KI);
	void setKD(double KD);
private:
	double KP_, KI_, KD_;
	double tolerance_;
	double I_zone;
	double Normal_Min, Normal_Max;
	double integral = 0;
	double lastError = 0;
	double deltaTime;
	double initError = NULL;

	double P_Comp;
	double I_Comp;
	double D_Comp;

	double returnVal;
};

PIDController::PIDController(double KP, double KI, double KD, double tolerance) {
	KP_ = KP;
	KI_ = KI;
	KD_ = KD;
	tolerance_ = tolerance;
}

PIDController::calculate(double sensor, double target, double deltatime) {
	double error = sensor - target;
	//P
	P_Comp = KP_ * error;
	//I
	integral += (error + lastError)* deltaTime/2;
	I_Comp = KI_ * integral;
	//D
	D_Comp = KD_ * (error - lastError) / deltaTime;

	lastError = error;
	returnVal = P_Comp + I_Comp + D_Comp;
	returnVal = (abs(returnVal) < Normal_Min) ? Normal_Min : returnVal;
	returnVal = (abs(returnVal) > Normal_Max) ? Normal_Max : returnVal;
	
	return returnVal;
}