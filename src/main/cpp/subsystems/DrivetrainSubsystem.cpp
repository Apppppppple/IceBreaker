
#include "subsystems/DrivetrainSubsystem.h"

DrivetrainSubsystem::DrivetrainSubsystem(){
    leftDriveMotors.SetInverted(false);
    rightDriveMotors.SetInverted(true);
}

void DrivetrainSubsystem::Periodic(){
}

void DrivetrainSubsystem::Drive(double forward, double rotation){
    drivetrain.ArcadeDrive(forward, rotation);
}

void DrivetrainSubsystem::StopDrive(){
    DrivetrainSubsystem::Drive(0,0);
}
