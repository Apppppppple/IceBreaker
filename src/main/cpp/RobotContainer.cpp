// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/XboxController.h>
#include "commands/DefaultDrive.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  drivetrainSubsystem.SetDefaultCommand(DefaultDrive(&drivetrainSubsystem,
                                [this] { return controller.GetY(frc::XboxController::kLeftHand); },
                                [this] { return controller.GetX(frc::XboxController::kLeftHand); }));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
