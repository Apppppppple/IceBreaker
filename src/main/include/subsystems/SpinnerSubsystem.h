#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include "Constants.h"

class SpinnerSubsystem : public frc2::SubsystemBase {
 public:
  SpinnerSubsystem();

  void Periodic() override;
  void Spin(double speed);
  void StopSpin();

 private:
  WPI_VictorSPX spinnerMotor{SpinnerConstants::spinnerMotor};

};
