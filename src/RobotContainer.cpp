// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "RobotContainer.h"

#include <frc2/command/Command.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"
#include "sensors/Limelight.h"
#include "sensors/PIDParams.h"
#include "subsystems/DrivetrainSubsystem.h"

RobotContainer::RobotContainer() {
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

  // AutoShootAndCollect =
  //   new SequentialCommandGroup(
  //     new LimelightInitCommand(shooterSubsystem),
  //     new LimelightDriveToDistanceCommand(drivetrainSubsystem, limelight,
  //     autoDistanceParams), new
  //     LimelightDriveToHeadingCommand(drivetrainSubsystem, limelight,
  //     autoHeadingParams), new LimelightEndCommand(), new ParallelRaceGroup(
  //       new ShootCommand(shooterSubsystem, conveyorSubsystem),
  //       new ConveyorShootBallCommand(conveyorSubsystem, shooterSubsystem),
  //       new WaitCommand(4)),
  //     new AutoTurnAngleCommand(drivetrainSubsystem, 45),
  //     new ParallelRaceGroup(
  //       new AutoDriveDistanceCommand(drivetrainSubsystem, intakeSubsystem,
  //       36), new WaitCommand(5))
  //   );

  // AutoShootOnly =
  //   new SequentialCommandGroup(
  //     new LimelightInitCommand(shooterSubsystem),
  //     new LimelightDriveToDistanceCommand(drivetrainSubsystem, limelight,
  //     autoDistanceParams), new
  //     LimelightDriveToHeadingCommand(drivetrainSubsystem, limelight,
  //     autoHeadingParams), new LimelightEndCommand(), new ParallelRaceGroup(
  //       new ShootCommand(shooterSubsystem, conveyorSubsystem),
  //       new ConveyorShootBallCommand(conveyorSubsystem, shooterSubsystem),
  //       new WaitCommand(4))
  //   );

  // AutoDriveOnly =
  //   new ParallelRaceGroup(
  //     new RunCommand(() -> drivetrainSubsystem.drive(0.6, 0.6),
  //     drivetrainSubsystem), new WaitCommand(2)
  //   );

  // chooser.setDefaultOption("Auto Shoot Only", AutoShootOnly);
  // chooser.addOption("Auto Shoot and Collect", AutoShootAndCollect);
  // chooser.addOption("Auto Drive Only", AutoDriveOnly);
  // SmartDashboard.putData(chooser);

  driveTrain.SetDefaultCommand(frc2::RunCommand(
      [this] { driveTrain.Drive(GetLeftY(), GetRightY()); }, &driveTrain));
  // intakeSubsystem.setDefaultCommand(new RunCommand(() ->
  // intakeSubsystem.intakeIn(getAxisValue(3)), intakeSubsystem)); // Intake
  // balls   = hold xbox Right Trigger conveyorSubsystem.setDefaultCommand(new
  // ConveyorIndexBallCommand(conveyorSubsystem));

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command *RobotContainer::GetAutonomousCommand() {
  // return &m_autonomousCommand;
  return nullptr;
}

double RobotContainer::GetLeftY() { return leftJoy.GetY(); }
double RobotContainer::GetLeftX() { return leftJoy.GetX(); }
double RobotContainer::GetRightY() { return rightJoy.GetY(); }
double RobotContainer::GetRightX() { return rightJoy.GetX(); }
