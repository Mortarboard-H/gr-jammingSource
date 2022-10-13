/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_JAMMINGSOURCE_CHIRP_H
#define INCLUDED_JAMMINGSOURCE_CHIRP_H

#include <gnuradio/jammingSource/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace jammingSource {

/*!
 * \brief <+description of block+>
 * \ingroup jammingSource
 *
 */
class JAMMINGSOURCE_API Chirp : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<Chirp> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of jammingSource::Chirp.
     *
     * To avoid accidental use of raw pointers, jammingSource::Chirp's
     * constructor is in a private implementation
     * class. jammingSource::Chirp::make is the public interface for
     * creating new instances.
     */
    static sptr make(double samp_rate, double min_freq, double max_freq, double period);

    virtual double sampling_freq() const = 0;

    virtual double period() const = 0;

    /*!
     * Sets the sampling frequency of the signal.
     * \param sampling_freq sampling frequency
     */
    virtual void set_sampling_freq(double sampling_freq) = 0;

    /*!
     * Sets the max frequency.
     * \param max_freq frequency of the signal
     */
    virtual void set_max_freq(double max_freq) = 0;

    /*!
     * Sets the min frequency.
     * \param min_freq frequency of the signal
     */
    virtual void set_min_freq(double min_freq) = 0;

    /*!
     * Sets the period of a signal.
     * \param period period of the every loop
     */
    virtual void set_period(double period) = 0;
};

} // namespace jammingSource
} // namespace gr

#endif /* INCLUDED_JAMMINGSOURCE_CHIRP_H */
