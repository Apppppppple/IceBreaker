
#pragma once

#include <frc2/command/Command.h>

#include <frc/XboxController.h>
#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/DrivetrainSubsystem.h"
#include "commands/DefaultDrive.h"
#include "Constants.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  ExampleSubsystem m_subsystem;
  DrivetrainSubsystem drivetrainSubsystem;

  ExampleCommand m_autonomousCommand;

  frc::XboxController controller{ControllerConstants::ControllerPort};

  void ConfigureButtonBindings();
};
