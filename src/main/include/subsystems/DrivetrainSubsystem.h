// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <frc/ADXRS450_Gyro.h>
#include <frc/DoubleSolenoid.h>
#include <frc/Encoder.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class DrivetrainSubsystem : public frc2::SubsystemBase {
  using VictorSPX = ctre::phoenix::motorcontrol::can::WPI_VictorSPX;

public:
  frc::Encoder dtLeftEncoder, dtRightEncoder;
  frc::ADXRS450_Gyro driveGyro;

  enum GearShiftStatus { High, Low };
  static GearShiftStatus gearShiftStatus;

  DrivetrainSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

private:
  VictorSPX leftMotors[3]{drive_constants::leftMotorChannels[0],
                          drive_constants::leftMotorChannels[1],
                          drive_constants::leftMotorChannels[2]},
      rightMotors[3]{drive_constants::rightMotorChannels[0],
                     drive_constants::rightMotorChannels[1],
                     drive_constants::rightMotorChannels[2]};
  frc::DifferentialDrive m_drive;

  frc::DoubleSolenoid gearShiftSolenoid{drive_constants::gearShiftHighChannel,
    drive_constants::gearShiftLowChannel};

  frc::SpeedControllerGroup leftDriveMotors{leftMotors[0], leftMotors[1],
                                            leftMotors[2]};
  frc::SpeedControllerGroup rightDriveMotors{rightMotors[0], rightMotors[1],
                                             rightMotors[2]};
};
