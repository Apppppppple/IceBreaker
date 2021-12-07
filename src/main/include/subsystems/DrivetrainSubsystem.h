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
  frc::Encoder dtLeftEncoder{drive_constants::driveTrainLeftEncoderChannelA,
                             drive_constants::driveTrainLeftEncoderChannelB,
                             false, frc::CounterBase::EncodingType::k4X},
      dtRightEncoder{drive_constants::driveTrainRightEncoderChannelA,
                     drive_constants::driveTrainRightEncoderChannelB, true,
                     frc::CounterBase::EncodingType::k4X};
  frc::ADXRS450_Gyro driveGyro;

  enum GearShiftStatus { High, Low };
  static GearShiftStatus gearShiftStatus;

  DrivetrainSubsystem();

  void Drive(double leftSpeed, double rightSpeed);
  void StopDrive();

  void ResetEncoders();

  double GetLeftEncoder();
  double GetRightEncoder();
  double GetAverageEncoder();

  void ResetGyro();
  double GetGyroAngle();
  double GetGyroRate();

  void ShiftDown();
  void ShiftUp();
  static GearShiftStatus GetGearShiftPosition();

  void Periodic() override;
  void SimulationPeriodic() override;

private:
  // Not an array because
  // https://stackoverflow.com/questions/60606947/initialising-member-aggregate-type-without-copy-constructor
  // https://stackoverflow.com/questions/29759441/is-a-class-with-deleted-copy-constructor-trivially-copyable
  // https://stackoverflow.com/questions/38224877/how-to-enforce-copy-elision-why-it-wont-work-with-deleted-copy-constructor
  VictorSPX leftMotor1{drive_constants::leftMotorChannels[0]},
      leftMotor2{drive_constants::leftMotorChannels[1]},
      leftMotor3{drive_constants::leftMotorChannels[2]},
      rightMotor1{drive_constants::rightMotorChannels[0]},
      rightMotor2{drive_constants::rightMotorChannels[1]},
      rightMotor3{drive_constants::rightMotorChannels[2]};

  // TODO: Do leftController and rightController need to be stored in the
  // class? Not really sure about the semantics for references.
  frc::DifferentialDrive m_drive{leftController, rightController};

  frc::DoubleSolenoid gearShiftSolenoid{drive_constants::gearShiftHighChannel,
                                        drive_constants::gearShiftLowChannel};

  frc::SpeedControllerGroup leftController{leftMotor1, leftMotor2, leftMotor3},
      rightController{rightMotor1, rightMotor2, rightMotor3};
};
