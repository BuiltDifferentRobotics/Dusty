class PIDController {
public:
	PIDController(double KP, double KI, double KD, double tolerance);
	//
	double calculate(double sensor, double target);
	void setKP(double KP);
	void setKI(double KI);
	void setKD(double KD);
	void setTolerance(double Tolerance);
	void setI_zone(double I_zone);
	void setNormal_Min(double Normal_Min);
	void setNormal_Max(double Normal_Max);
	//
	double getKP();
	double getKI();
	double getKD();
	double getTolerance();
	double getI_zone();
	double getNormal_min();
	double getNormal_max();
private:
	double KP_, KI_, KD_;
	double tolerance_;
	double I_zone_;
	double Normal_Min_, Normal_Max_;
	//long lastTime, currTime;
};

//Implementation

//constructor
PIDController::PIDController(double KP, double KI, double KD, double tolerance) {
	KP_ = KP;
	KI_ = KI;
	KD_ = KD;
	tolerance_ = tolerance;
}

//setters
void PIDController::setKP (double KP) {
	KP_ = KP;
}
void PIDController::setKI(double KI) {
	KI_ = KI;
}
void PIDController::setKD(double KD) {
	KD_ = KD;
}
void PIDController::setTolerance(double Tolerance) {
	tolerance_ = Tolerance;
}
void PIDController::setI_zone(double I_zone) {
	I_zone_ = I_zone;
}
void PIDController::setNormal_Min(double Normal_Min) {
	Normal_Min_ = Normal_Min;
}
void PIDController::setNormal_Min(double Normal_Max) {
	Normal_Max_ = Normal_Max;
}

//getters
double PIDController::getKP() {
	return KP_;
}
double PIDController::getKI() {
	return KI_;
}
double PIDController::getKD() {
	return KD_;
}
double PIDController::getTolerance() {
	return tolerance_;
}
double PIDController::getI_zone() {
	return I_zone_;
}
double PIDController::getNormal_min() {
	return Normal_Min_;
}
double PIDController::getNormal_max() {
	return Normal_Max_;
}
