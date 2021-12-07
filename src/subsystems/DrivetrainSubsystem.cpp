// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DrivetrainSubsystem.h"

#include <frc/CounterBase.h>
#include <frc/DoubleSolenoid.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"

DrivetrainSubsystem::DrivetrainSubsystem() {
  leftController.SetInverted(true);
  rightController.SetInverted(true);

  m_drive.SetDeadband(0.05);
  m_drive.SetMaxOutput(drive_constants::driveMaxSpeed());

  dtLeftEncoder.SetSamplesToAverage(
      drive_constants::driveTrainLeftEncoderAverageSamples);
  dtLeftEncoder.SetMinRate(drive_constants::driveTrainLeftEncoderMinRate);
  dtLeftEncoder.SetDistancePerPulse(
      drive_constants::driveTrainLeftEncoderPulseDistance);

  dtRightEncoder.SetSamplesToAverage(
      drive_constants::driveTrainRightEncoderAverageSamples);
  dtRightEncoder.SetMinRate(drive_constants::driveTrainRightEncoderMinRate);
  dtRightEncoder.SetDistancePerPulse(
      drive_constants::driveTrainRightEncoderPulseDistance);

  driveGyro.Calibrate();

  gearShiftStatus = GearShiftStatus::Low;
}

void DrivetrainSubsystem::Drive(double leftSpeed, double rightSpeed) {
  frc::SmartDashboard::PutNumber("Left Drive Speed: ", leftSpeed);
  frc::SmartDashboard::PutNumber("Right Drive Speed: ", rightSpeed);
  leftSpeed = leftSpeed * drive_constants::driveSpeedMultiplier();
  rightSpeed = rightSpeed * drive_constants::driveSpeedMultiplier();
  m_drive.TankDrive(leftSpeed, rightSpeed, false);
}

void DrivetrainSubsystem::StopDrive() { m_drive.TankDrive(0, 0, false); }

void DrivetrainSubsystem::ResetEncoders() {
  dtLeftEncoder.Reset();
  dtRightEncoder.Reset();
}

double DrivetrainSubsystem::GetLeftEncoder() {
  return dtLeftEncoder.GetDistance();
}

double DrivetrainSubsystem::GetRightEncoder() {
  return dtRightEncoder.GetDistance();
}

double DrivetrainSubsystem::GetAverageEncoder() {
  return (GetLeftEncoder() + GetRightEncoder()) / 2;
}

void DrivetrainSubsystem::ResetGyro() { driveGyro.Reset(); }

double DrivetrainSubsystem::GetGyroAngle() { return driveGyro.GetAngle(); }

double DrivetrainSubsystem::GetGyroRate() { return driveGyro.GetRate(); }

void DrivetrainSubsystem::ShiftDown() {
  gearShiftSolenoid.Set(
      frc::DoubleSolenoid::Value::kForward); // kForward is Low (down) speed
  gearShiftStatus = GearShiftStatus::Low;
}

void DrivetrainSubsystem::ShiftUp() {
  gearShiftSolenoid.Set(
      frc::DoubleSolenoid::Value::kReverse); // KReverse is High (up) speed
  gearShiftStatus = GearShiftStatus::High;
}

DrivetrainSubsystem::GearShiftStatus
DrivetrainSubsystem::GetGearShiftPosition() {
  return gearShiftStatus;
}

void DrivetrainSubsystem::Periodic() {
  frc::SmartDashboard::PutNumber("Gyro Angle: ", GetGyroAngle());
  frc::SmartDashboard::PutNumber("Left Drive Encoder: ", GetLeftEncoder());
  frc::SmartDashboard::PutNumber("Right Drive Encoder: ", GetRightEncoder());
}

void DrivetrainSubsystem::SimulationPeriodic() { Periodic(); }

DrivetrainSubsystem::GearShiftStatus DrivetrainSubsystem::gearShiftStatus =
    GearShiftStatus::Low;
