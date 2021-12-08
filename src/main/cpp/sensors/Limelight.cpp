#include "sensors/Limelight.h"

#include <units/angle.h>
#include <units/math.h>

#include "Constants.h"

void Limelight::SetLedMode(LedMode mode) {
  // TODO: Is this the correct function to call? SetNumber doesn't seem to
  // exist.
  table->GetEntry("ledMode").SetFlags(mode);
}

Limelight::LedMode Limelight::GetLedMode() {
  return LedMode{table->GetEntry("ledMode").GetFlags()};
}

void Limelight::SetCamMode(CamMode mode) {
  table->GetEntry("camMode").SetFlags(mode);
}

Limelight::CamMode Limelight::GetCamMode() {
  return CamMode{table->GetEntry("camMode").GetFlags()};
}

void Limelight::SetPipeline(unsigned int pipeline) {
  table->GetEntry("pipeline").SetFlags(pipeline);
}

unsigned int Limelight::GetPipeline() {
  return table->GetEntry("pipeline").GetFlags();
}

#define GD(name, entry) double Limelight::name() { return table->GetEntry(entry).GetDouble(0); }

bool Limelight::GetTarget() { return table->GetEntry("tv").GetDouble(0) == 1; }

GD(GetXError, "tx")
GD(GetYError, "ty")

double Limelight::GetAvgYError(double historic_weight) {
  // TODO: '/2' comes from
  // https://github.com/bow4290/Obi2021Rework/blob/7b972881c41ea245d1dd5eed8e9dbfff48beb345/src/main/java/frc/robot/sensors/Limelight.java#L72,
  // but should it be there? It seems like this would give half of the average
  // rather than the average
  avgYError = ((historic_weight * avgYError) +
               ((1.0 - historic_weight) * GetYError())) /
              2.0;
  return avgYError;
}

GD(GetArea, "ta")
GD(GetSkew, "ts")
GD(GetLatency, "tl")

GD(GetShortLength, "tshort")
GD(GetLongLength, "tlong")
GD(GetHorizontalLength, "thor")
GD(GetVerticalLength, "tvert")

double Limelight::GetDistance() {
  // TODO: Is this correct?
  return (limelight_constants::h2() - limelight_constants::h1()) /
         units::math::tan(
             units::angle::degree_t{limelight_constants::a1() + GetYError()});
}

double Limelight::GetBumperDistance() {
  return GetDistance() - limelight_constants::Lime2BumpDistance();
}
