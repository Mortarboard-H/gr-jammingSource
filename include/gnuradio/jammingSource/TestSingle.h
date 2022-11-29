/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_JAMMINGSOURCE_TESTSINGLE_H
#define INCLUDED_JAMMINGSOURCE_TESTSINGLE_H

#include <gnuradio/jammingSource/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace jammingSource {

/*!
 * \brief <+description of block+>
 * \ingroup jammingSource
 *
 */
class JAMMINGSOURCE_API TestSingle : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<TestSingle> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of jammingSource::TestSingle.
     *
     * To avoid accidental use of raw pointers, jammingSource::TestSingle's
     * constructor is in a private implementation
     * class. jammingSource::TestSingle::make is the public interface for
     * creating new instances.
     */
    static sptr make(
        double samp_rate, double start_freq, double step, double length, double interval);

    virtual double sampling_freq() const = 0;

    virtual double current_freq() const = 0;

    /*!
     * Sets the sampling frequency of the signal.
     * \param sampling_freq sampling frequency
     */
    virtual void set_sampling_freq(double sampling_freq) = 0;

    /*!
     * Sets the start frequency.
     * \param start_freq frequency of the signal
     */
    virtual void set_start_freq(double start_freq) = 0;

    /*!
     * Sets the step .
     * \param step frequency step.
     */
    virtual void set_step(double step) = 0;

    /*!
     * Sets the length of each frequency.
     * \param length length of each frequency
     */
    virtual void set_length(double length) = 0;

    /*!
     * Sets the interval between each frequency.
     * \param interval interval between each frequency
     */
    virtual void set_interval(double interval) = 0;
};

} // namespace jammingSource
} // namespace gr

#endif /* INCLUDED_JAMMINGSOURCE_TESTSINGLE_H */
