
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/SpinnerSubsystem.h"

class SpinSpinnerCommand
    : public frc2::CommandHelper<frc2::CommandBase, SpinSpinnerCommand> {
 public:
  SpinSpinnerCommand(SpinnerSubsystem* subsystem,
                     bool spinnerOn);

  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

  private:
  SpinnerSubsystem* spinnerMotor;
  bool spinnerOn;
};
