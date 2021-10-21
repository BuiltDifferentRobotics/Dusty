class PIDController {
public:
	PIDController(KP, KI, KD, tolerance);

	double calculate(double sensor, double target);
	void setKP(double KP);
	void setKI(double KI);
	void setKD(double KD);
private:
	double KP_, KI_, KD_;
	double tolerance_;
	double I_zone;
	double Normal_Min, Normal_Max;
	long lastTime, currTime;
};

PIDController::PIDController(KP, KI, KD, tolerance) {
	KP_ = KP;
	KI_ = KI;
	KD_ = KD;
	tolerance_ = tolerance;
}

