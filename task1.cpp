#include <vector>
#include <cstdint>
#include <cmath>

struct measurement {
    /** Distance in mm from the sensor */
    int SensorDistance = 4;
    double distance;
  
    /** Time in Nano seconds since the microcontroller started */
    uint64_t time;

  };

  
  
  /** Returns the values of the second derivative of a list of measurments
   * The units of the returned values are mm / ns ^ 2 -> (10^-3 m) / (10^-6 s) ^ 2
   * @example
   * measurments = { { 0, 0 }, { 2.8353, 100005 }, { 11.3502, 200090 }};
   * secondDerivative(measurments) -> { 0.566996 * 10^-9}
   */ 
  std::vector<double> secondDerivative(const std::vector<measurement>& measurements){
  std::vector <double> result;
if (measurements.size() < 3){
    return result;
}

for(size_t i = 1; i < measurements.size() - 1; ++i){
  double f_xh = measurements[i - 1].distance;
  double f_x = measurements[i].distance;
  double f_xmh = measurements[i + 1].distance;

  uint64_t t_xh = measurements[i - 1].time;
  uint64_t t_x = measurements[i].time;
  uint64_t t_xmh = measurements[i + 1].time;

    

    double h_squared = std::pow(static_cast<double>(t_xmh - t_xh) / 2.0, 2);
    double SecondDeriv = (f_xh - 2 * f_x + f_xmh) / h_squared;
    result.push_back(SecondDeriv);

}

  return result;
  }

  #include <iostream>

  