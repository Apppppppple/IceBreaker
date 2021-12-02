// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <wpi/math>

// define a function for values that we may want to change at runtime in the future.
// TODO: is this actually useful or just YAGNI/premature?
#define CST(name, T, val) constexpr T name() { return val; }
#define FCST(name, val) CST(name, double, val)

namespace drive_constants {
    constexpr int leftMotorChannels[3] = { 12, 11, 10 };
    constexpr int rightMotorChannels[3] = { 5, 3, 6 };

    FCST(driveSpeedMultiplier, 1)
    FCST(driveMaxSpeed, 1)

    constexpr double wheelDiameter = 7;

    constexpr int driveTrainLeftEncoderChannelA = 2;
    constexpr int driveTrainLeftEncoderChannelB = 3;
    constexpr int driveTrainRightEncoderChannelA = 4;
    constexpr int driveTrainRightEncoderChannelB = 5;

    constexpr int driveTrainLeftEncoderAverageSamples = 5;
    constexpr double driveTrainLeftEncoderMinRate = 1;
    constexpr double driveTrainLeftEncoderPulseDistance = 1.0 / 8800 * wpi::math::pi * wheelDiameter;
    constexpr int driveTrainRightEncoderAverageSamples = 5;
    constexpr double driveTrainRightEncoderMinRate = 1;
    constexpr double driveTrainRightEncoderPulseDistance = 1.0 / 8800 * wpi::math::pi * wheelDiameter;

    constexpr int gearShiftHighChannel = 4;
    constexpr int gearShiftLowChannel = 5;
}

namespace auto_drive_constants {
    FCST(autoDriveSpeed, 0.6)
    FCST(straightkP, 0.3)
    FCST(distancekP, 0.02)
    FCST(distancekI, 0)
    FCST(distancekD, 0.005)
    FCST(autoDistanceIntegralWindow, 12)

    FCST(autoTurnSpeed, 0.8)
    FCST(turnkP, 0.05)
    FCST(turnkI, 0.2)
    FCST(turnkD, 0.001)
    FCST(autoTurnIntegralWindow, 5)
}

namespace oi_constants {
    constexpr int leftJoystick = 0;
    constexpr int rightJoystick = 1;
    constexpr int xboxController = 2;
}

namespace intake_constants {
    constexpr int intakeMotorChannel = 13;
    constexpr int intakeUpChannel = 0;
    constexpr int intakeDownChannel = 1;

    FCST(intakeSpeed, 1)
}

namespace climber_constants {
    constexpr int climberMotorChannel = 4;
    constexpr int climberUpChannel = 7;
    constexpr int climberDownChannel = 6;

    FCST(climberSpeed, 1)
}

namespace conveyor_constants {
    constexpr int topConveyorMotorChannel = 9;
    constexpr int bottomConveyorMotorChannel = 7;
    constexpr int conveyorButton1Port = 6;
    constexpr int conveyorButton2Port = 7;

    FCST(conveyorSpeedDivider, 0.91)
    FCST(conveyorIndexBallSpeed, 0.80)   // 0.70 old balls, 0.80 new balls
    FCST(conveyorShootBallSpeed, 1)
    FCST(conveyorReverseSpeed, -0.25)
}

namespace limelight_constants {
    FCST(h1, 22.25)                   // Distance from ground to limelight
    FCST(h2, 98.25)                   // Distance from ground to target
    FCST(a1, 22.407)                  // Limelight mount angle
    FCST(Lime2BumpDistance, 16.5)
    FCST(maxLimelightDriveSpeed, 0.6)
    FCST(maxLimelightTurnSpeed, 0.6)  // Make one for auto = 0.6
    FCST(distanceIntegralWindow, 1)
    FCST(turnIntegralWindow, 5)

    // Auto Position PID Values
    FCST(kpDistanceAuto, 0.5)
    FCST(kiDistanceAuto, 0.4)
    FCST(kdDistanceAuto, 0.05)
    FCST(kpAimAuto, 0.2)
    FCST(kiAimAuto, 0.25)
    FCST(kdAimAuto, 0.01)

    // Teleop Position PID Values
    FCST(kpAimTeleop, 0.2)
    FCST(kiAimTeleop, 0.3)
    FCST(kdAimTeleop, 0.01)

    FCST(distancePositionTolerance, 0.20)
    FCST(distanceVelocityTolerance, 0.025)
    FCST(headingPositionTolerance, 0.18)
    FCST(headingVelocityTolerance, 0.025)
}

namespace shooter_constants {
    constexpr int leftShooterMotorChannel = 8;
    constexpr int rightShooterMotorChannel = 1;
    constexpr int shooterUpChannel = 2;
    constexpr int shooterDownChannel = 3;
    FCST(shooterSpeedOffset, 0.85)
    constexpr int shooterEncoderChannelA = 0;
    constexpr int shooterEncoderChannelB = 1;
    CST(shooterEncoderAverageSamples, int, 127)
    CST(shooterMotorToRateSlope, int, 240000)
    CST(shooterMotorToRateIntercept, int, 25000)
    FCST(shooterSpeedDefault, 0.95)
    FCST(shooterSpeedAuto, 0.95)

    FCST(minimumShooterDistance, 140.0)
    FCST(thresholdShooterDistance, 225.0)
    FCST(maximumShooterDistance, 335.0)

    FCST(shooterSpeedClose, 0.86)    // 0.95 old balls, 0.86 new balls
    FCST(shooterSpeedFar, 0.82)      // 0.85 old balls, 0.82 new balls
}

#undef FCST
#undef CST
