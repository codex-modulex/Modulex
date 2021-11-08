// Copyright 2014 Olivier Gillet.
//
// Author: Olivier Gillet (ol.gillet@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// See http://creativecommons.org/licenses/MIT/ for more information.
//
// -----------------------------------------------------------------------------
//
// Driver for ADC.

#ifndef CLOUDS_DRIVERS_ADC_H_
#define CLOUDS_DRIVERS_ADC_H_

#include "stmlib/stmlib.h"

namespace clouds {

enum AdcChannel {
  ADC_POSITION_POTENTIOMETER_CV, //(ADC2 - 1)
  ADC_DENSITY_POTENTIOMETER_CV,  //(ADC3 - 2)
  ADC_SIZE_POTENTIOMETER,        //(ADC10 - 3)
  ADC_SIZE_CV,                   //(ADC1 - 4)
  ADC_PITCH_POTENTIOMETER,       //(ADC11 - 5)
  ADC_V_OCT_CV,                  //(ADC4 - 6)
  ADC_BLEND_POTENTIOMETER,       //(ADC7 - 7)
  ADC_BLEND_CV,                  //(ADC5 - 8)
  ADC_STEREO_POTENTIOMETER_CV,   //(ADC9 - 9)
  ADC_FEEDBACK_POTENTIOMETER_CV, //(ADC12 - 10)
  ADC_REVERB_POTENTIOMETER_CV,   //(ADC13 - 11)
  ADC_TEXTURE_POTENTIOMETER,     //(ADC6 - 12)
  ADC_TEXTURE_CV,                //(ADC0 - 13)
  ADC_CHANNEL_LAST               //(* - 14)
};

class Adc {
 public:
  Adc() { }
  ~Adc() { }

  void Init();
  void DeInit();
  void Convert();
  inline uint16_t value(uint8_t channel) const { return values_[channel]; }
  inline float float_value(uint8_t channel) const {
    return static_cast<float>(values_[channel]) / 65536.0f;
  }
  inline const uint16_t* values() { return &values_[0]; }

 private:
  uint16_t values_[ADC_CHANNEL_LAST];

  DISALLOW_COPY_AND_ASSIGN(Adc);
};

}  // namespace clouds

#endif  // CLOUDS_DRIVERS_ADC_H_
