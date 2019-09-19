/*!
 * \file cpu_autocorrelator_real_codes.h
 * \brief Highly optimized CPU vector multiTAP correlator class using real-valued local codes
 * \authors <ul>
 *          <li> Javier Arribas, 2015. jarribas(at)cttc.es
 *          <li> Cillian O'Driscoll, 2017, cillian.odriscoll(at)gmail.com
 *          </ul>
 *
 * Class that implements a highly optimized vector multiTAP correlator class for CPUs
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2018  (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software defined Global Navigation
 *          Satellite Systems receiver
 *
 * This file is part of GNSS-SDR.
 *
 * GNSS-SDR is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GNSS-SDR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNSS-SDR. If not, see <https://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------
 */

#ifndef GNSS_SDR_CPU_AUTOCORRELATOR_REAL_CODES_H_
#define GNSS_SDR_CPU_AUTOCORRELATOR_REAL_CODES_H_


#include <complex>

/*!
 * \brief Class that implements carrier wipe-off and correlators.
 */
class Cpu_Autocorrelator_Real_Codes
{
public:
    Cpu_Autocorrelator_Real_Codes();
    void set_high_dynamics_resampler(bool use_high_dynamics_resampler);
    ~Cpu_Autocorrelator_Real_Codes();
    bool init(int max_signal_length_samples, int n_correlators);
    bool set_local_code_and_taps(int code_length_chips, const float *local_code_in, float *shifts_chips);
    bool set_output_vector(float *corr_out);
    void update_local_code(int correlator_length_samples, float rem_code_phase_chips, float code_phase_step_chips, float code_phase_rate_step_chips = 0.0);
    bool free();

    bool Local_code_multi_autocorrelator_resampler(float rem_carrier_phase_in_rad, float phase_step_rad, float rem_code_phase_chips, float code_phase_step_chips, float code_phase_rate_step_chips, int signal_length_samples);


private:
    // Allocate the device input vectors
    const float *d_local_code_in;
    std::complex<float> *d_local_code_cx;
    float **d_local_codes_resampled;
    float *d_corr_out;
    std::complex<float> *d_corr_out_cx;
    float *d_shifts_chips;
    bool d_use_high_dynamics_resampler;
    int d_code_length_chips;
    int d_n_correlators;
};


#endif /* GNSS_SDR_CPU_AUTOCORRELATOR_REAL_CODES_H_ */
