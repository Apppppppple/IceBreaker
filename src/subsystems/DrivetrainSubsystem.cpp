// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DrivetrainSubsystem.h"

#include <frc/SpeedControllerGroup.h>

#include "Constants.h"
#include "frc/drive/DifferentialDrive.h"

DrivetrainSubsystem::DrivetrainSubsystem() {
  leftDriveMotors.SetInverted(true);
  rightDriveMotors.SetInverted(true);
  // m_drive = frc::DifferentialDrive(m_left, m)


  // Implementation of subsystem constructor goes here.
}

void DrivetrainSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void DrivetrainSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
