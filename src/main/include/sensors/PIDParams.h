struct PIDParams {
public:
    PIDParams() = delete; // If you do not provide values at creation, it's probably a bug.
    double kp, ki, kd, posTolerance, velTolerance, setpoint;
};
