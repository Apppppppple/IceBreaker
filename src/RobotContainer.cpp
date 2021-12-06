// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "RobotContainer.h"

#include <frc2/command/Command.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"
#include "sensors/Limelight.h"
#include "sensors/PIDParams.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // drivetrainSubsystem = new DrivetrainSubsystem();
  // intakeSubsystem = new IntakeSubsystem();
  // climberSubsystem = new ClimberSubsystem();
  // conveyorSubsystem = new ConveyorSubsystem();
  // shooterSubsystem = new ShooterSubsystem();

  limelight = Limelight();
  // Default position 3 (start line)
  limelight.SetPipeline(3);

  PIDParams autoHeadingParams{
      limelight_constants::kpAimAuto(),
      limelight_constants::kiAimAuto(),
      limelight_constants::kdAimAuto(),
      limelight_constants::headingPositionTolerance(),
      limelight_constants::headingVelocityTolerance(),
  };

  PIDParams autoDistanceParams{
      limelight_constants::kpDistanceAuto(),
      limelight_constants::kiDistanceAuto(),
      limelight_constants::kdDistanceAuto(),
      limelight_constants::distancePositionTolerance(),
      limelight_constants::distanceVelocityTolerance(),
  };

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command *RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
