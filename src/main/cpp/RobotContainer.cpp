
#include "RobotContainer.h"

#include <frc/XboxController.h>
#include "commands/DefaultDrive.h"
#include "commands/SpinSpinnerCommand.h"

RobotContainer::RobotContainer(){
  ConfigureButtonBindings();

  drivetrainSubsystem.SetDefaultCommand(DefaultDrive(&drivetrainSubsystem,
                                [this] { return controller.GetX(frc::XboxController::kLeftHand); },
                                [this] { return -controller.GetY(frc::XboxController::kLeftHand); }));

  // create spinnerSubsystem default command!!
  
}

void RobotContainer::ConfigureButtonBindings() {
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  return nullptr;
}
