/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_JAMMINGSOURCE_GAINTEST_H
#define INCLUDED_JAMMINGSOURCE_GAINTEST_H

#include <gnuradio/jammingSource/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace jammingSource {

/*!
 * \brief <+description of block+>
 * \ingroup jammingSource
 *
 */
class JAMMINGSOURCE_API GainTest : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<GainTest> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of jammingSource::GainTest.
     *
     * To avoid accidental use of raw pointers, jammingSource::GainTest's
     * constructor is in a private implementation
     * class. jammingSource::GainTest::make is the public interface for
     * creating new instances.
     */
    static sptr
    make(double samp_rate, double length_per_gain, double gain_start, double gain_step);

    virtual double sampling_freq() const = 0;

    virtual double current_gain() const = 0;

    /*!
     * Sets the sampling frequency of the signal.
     * \param sampling_freq sampling frequency
     */
    virtual void set_sampling_freq(double sampling_freq) = 0;

    /*!
     * Sets the length of every gain.
     * \param length_per_gain length of every gain
     */
    virtual void set_length_per_gain(double length_per_gain) = 0;

    /*!
     * Sets start gain .
     * \param gain_start start gain.
     */
    virtual void set_gain_start(double gain_start) = 0;

    /*!
     * Sets the step of gain.
     * \param gain_step step of gain
     */
    virtual void set_gain_step(double gain_step) = 0;

    
};

} // namespace jammingSource
} // namespace gr

#endif /* INCLUDED_JAMMINGSOURCE_GAINTEST_H */
