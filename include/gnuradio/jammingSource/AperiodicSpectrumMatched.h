/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_JAMMINGSOURCE_APERIODICSPECTRUMMATCHED_H
#define INCLUDED_JAMMINGSOURCE_APERIODICSPECTRUMMATCHED_H

#include <gnuradio/jammingSource/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace jammingSource {

/*!
 * \brief <+description of block+>
 * \ingroup jammingSource
 *
 */
class JAMMINGSOURCE_API AperiodicSpectrumMatched : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<AperiodicSpectrumMatched> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of
     * jammingSource::AperiodicSpectrumMatched.
     *
     * To avoid accidental use of raw pointers, jammingSource::AperiodicSpectrumMatched's
     * constructor is in a private implementation
     * class. jammingSource::AperiodicSpectrumMatched::make is the public interface for
     * creating new instances.
     */
    static sptr make(double samp_rate, double chipRate);

    virtual double sampling_freq() const = 0;
    virtual double chip_rate() const = 0;

    /*!
     * Sets the sampling frequency of the signal.
     * \param sampling_freq sampling frequency
     */
    virtual void set_sampling_freq(double sampling_freq) = 0;

    /*!
     * Sets the chiprate of a signal.
     * \param chiprate chiprate of jamming signal
     */
    virtual void set_chip_rate(double chip_rate) = 0;
};

} // namespace jammingSource
} // namespace gr

#endif /* INCLUDED_JAMMINGSOURCE_APERIODICSPECTRUMMATCHED_H */
