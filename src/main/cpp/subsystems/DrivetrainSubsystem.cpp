
#include "subsystems/DrivetrainSubsystem.h"

DrivetrainSubsystem::DrivetrainSubsystem(){
    rightDriveMotors.SetInverted(true);
}

void DrivetrainSubsystem::Periodic() {
}

void DrivetrainSubsystem::Drive(double forward, double rotation){
    drive.ArcadeDrive(forward, rotation);
}

void DrivetrainSubsystem::StopDrive(){
    DrivetrainSubsystem::Drive(0,0);
}
