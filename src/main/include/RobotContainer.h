
#pragma once

#include <frc2/command/Command.h>

#include <frc/XboxController.h>
#include "subsystems/DrivetrainSubsystem.h"
#include "subsystems/SpinnerSubsystem.h"
#include "commands/DefaultDrive.h"
#include "Constants.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  DrivetrainSubsystem drivetrainSubsystem;
  SpinnerSubsystem spinnerSubsystem;
  frc::XboxController controller{ControllerConstants::ControllerPort};
  

  void ConfigureButtonBindings();
};
