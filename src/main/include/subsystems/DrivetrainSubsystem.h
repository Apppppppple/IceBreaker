
#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/SpeedControllerGroup.h>
#include "ctre/Phoenix.h"
#include "Constants.h"


class DrivetrainSubsystem : public frc2::SubsystemBase {
 public:
  DrivetrainSubsystem();

  void Periodic() override;
  void Drive(double forward, double rotation);
  void StopDrive();


 private:
  WPI_VictorSPX leftDrive1{DriveConstants::leftMotor1Channel};
  WPI_VictorSPX leftDrive2{DriveConstants::leftMotor2Channel};
  WPI_VictorSPX rightDrive1{DriveConstants::rightMotor1Channel};
  WPI_VictorSPX rightDrive2{DriveConstants::rightMotor2Channel};

  frc::SpeedControllerGroup leftDriveMotors{leftDrive1, leftDrive2};
  frc::SpeedControllerGroup rightDriveMotors{rightDrive1, rightDrive2};
  
  frc::DifferentialDrive drivetrain{leftDriveMotors, rightDriveMotors};

};
