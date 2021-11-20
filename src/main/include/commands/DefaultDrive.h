// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DrivetrainSubsystem.h"

class DefaultDrive
    : public frc2::CommandHelper<frc2::CommandBase, DefaultDrive> {
 public:
  DefaultDrive(DrivetrainSubsystem* subsystem,
               std::function<double()> forward,
               std::function<double()> rotation);

  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

  private:
  DrivetrainSubsystem* drive;
  std::function<double()> forward;
  std::function<double()> rotation;
};
