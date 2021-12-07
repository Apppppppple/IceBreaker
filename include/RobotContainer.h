// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc2/command/Command.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"
#include "sensors/Limelight.h"
#include "subsystems/DrivetrainSubsystem.h"
#include "subsystems/ExampleSubsystem.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
public:
  RobotContainer();

  frc2::Command *GetAutonomousCommand();

  double GetLeftY();
  double GetLeftX();
  double GetRightY();
  double GetRightX();

private:
  // The robot's subsystems and commands are defined here...
  DrivetrainSubsystem driveTrain;
  // ExampleCommand m_autonomousCommand;

  frc2::SequentialCommandGroup autoShootAndCollect;
  frc2::SequentialCommandGroup autoShootOnly;
  frc2::ParallelRaceGroup autoDriveOnly;

  frc::Joystick leftJoy{oi_constants::leftJoystick},
      rightJoy{oi_constants::rightJoystick};
  frc::XboxController xboxController{oi_constants::xboxController};

  Limelight limelight;

  void ConfigureButtonBindings();
};
