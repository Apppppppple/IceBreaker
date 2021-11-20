
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
  DrivetrainSubsystem* drivetrain;
  std::function<double()> forward;
  std::function<double()> rotation;
};
