#pragma once

#include <networktables/NetworkTableInstance.h>

class Limelight {
public:
  // TODO: Do the values here need to be specified, and are they right?
  enum LedMode : unsigned int {
    ledPipeline = 0,
    ledOff = 1,
    ledBlink = 2,
    ledOn = 3,
  };

  enum CamMode : unsigned int { vision = 0, driving = 1 };

  Limelight() = default;

  /// Set the state of the LED
  void SetLedMode(LedMode mode);
  LedMode GetLedMode();

  /// Set the camera mode (vision processing or driving camera)
  void SetCamMode(CamMode mode);
  CamMode GetCamMode();

  /// Set the pipeline number (0-9)
  void SetPipeline(unsigned int pipeline);
  /// True active pipeline of the camera (0-9)
  unsigned int GetPipeline();

  /// Whether the limelight has any valid targets.
  // TODO: The original java had a double and a bool version of this function,
  // is that necessary? The comments indicate it will only ever return 0 or 1.
  bool GetTarget();

  /// Horizontal offset from limelight crosshair to target crosshair
  double GetXError();
  /// Vertical offset from limelight crosshair to target crosshair
  double GetYError();

  double GetAvgYError(double historic_weight);

  /// Target area (0% to 100% of image)
  double GetArea();
  /// Skew or rotation (-90 deg to 0 deg)
  double GetSkew();
  /// Pipeline latency contribution (ms)
  double GetLatency();

  /// Sidelength of shortest side of fitted box (pixels)
  double GetShortLength();
  /// Sidelength of longest side of fitted box (pixels)
  double GetLongLength();
  /// Horizontal sidelength of rough bouding box (0-320 pixels)
  double GetHorizontalLength();
  /// Vertical sidelength of rough bouding box (0-320 pixels)
  double GetVerticalLength();

  /// Horizontal distance from limelight to target
  double GetDistance();
  /// Horizontal distance from front bumper to target
  double GetBumperDistance();

private:
  std::shared_ptr<nt::NetworkTable> table =
      nt::NetworkTableInstance::GetDefault().GetTable("limelight");

  /// Used in calculating Limelight::GetAvgYError
  double avgYError;
};
