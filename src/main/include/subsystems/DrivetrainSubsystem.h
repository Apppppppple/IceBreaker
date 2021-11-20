
#pragma once

#include <frc/drive/DifferentialDrive.h>
#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include <frc/SpeedController.h>
#include <frc/PIDOutput.h>




class DrivetrainSubsystem : public frc2::SubsystemBase {
 public:
  DrivetrainSubsystem();

  void Periodic() override;
  void Drive(double forward, double rotation);
  void StopDrive();

 private:
  WPI_VictorSPX leftDrive1;
  WPI_VictorSPX leftDrive2;
  WPI_VictorSPX rightDrive1;
  WPI_VictorSPX rightDrive2;

  frc::SpeedController leftDriveMotors{leftDrive1, leftDrive2};
  frc::SpeedController rightDriveMotors{rightDrive1, rightDrive2};
  frc::SpeedController::SetInverted(rightDriveMotors);
  frc::DifferentialDrive drive{leftDriveMotors, rightDriveMotors};

};
