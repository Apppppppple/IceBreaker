
#include "subsystems/SpinnerSubsystem.h"

SpinnerSubsystem::SpinnerSubsystem(){
}

void SpinnerSubsystem::Periodic() {
}

void SpinnerSubsystem::Spin(double speed){
    spinnerMotor.Set(ControlMode::PercentOutput, speed);
}

void SpinnerSubsystem::StopSpin(){
    SpinnerSubsystem::Spin(0);
}