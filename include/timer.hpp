#ifndef GUARD_TIMER_H
#define GUARD_TIMER_H

#include <boost/chrono.hpp>

class timer 
{
    using clock_type = std::conditional<boost::chrono::high_resolution_clock::is_steady,
    boost::chrono::high_resolution_clock,
    boost::chrono::steady_clock>::type;
    using  nanoseconds = boost::chrono::nanoseconds ;
public:
    explicit timer(bool run = true)
    {
        if (run) this->reset();
    }
    void reset()
    {
        this->start = clock_type::now();
    }
    nanoseconds elapsed() const
    {
        return boost::chrono::duration_cast<nanoseconds>(clock_type::now() - this->start);
    }
    template <typename Stream>
    friend Stream& operator<<(Stream& out, const timer& self)
    {
        return out << self.elapsed().count() * 1.0/1000000;
    }
private:
    clock_type::time_point start;
};

#endif
