
#include "commands/SpinSpinnerCommand.h"
#include "subsystems/SpinnerSubsystem.h"

SpinSpinnerCommand::SpinSpinnerCommand(SpinnerSubsystem* subsystem,
                                       bool spinnerOn)
  : spinnerMotor{subsystem}, spinnerOn{spinnerOn} {
    AddRequirements({subsystem});
}

void SpinSpinnerCommand::Initialize(){
}

void SpinSpinnerCommand::Execute(){
  spinnerOn ? spinnerMotor->Spin(1) : spinnerMotor->StopSpin();
}

void SpinSpinnerCommand::End(bool interrupted){
}

bool SpinSpinnerCommand::IsFinished(){
  return false;
}
