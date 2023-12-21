//
// Copyright(c) 2018 Gabi Melman.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
//

#pragma once

#include "spdlog/details/null_mutex.h"
#include "spdlog/sinks/base_sink.h"
<<<<<<< HEAD
#include "spdlog/fmt/fmt.h"
#include <chrono>
#include <mutex>
#include <thread>
=======

#include <mutex>
>>>>>>> dea6bb1085466370ed6d629b4d462f299db75958

namespace spdlog {
namespace sinks {

<<<<<<< HEAD
template <class Mutex>
class test_sink : public base_sink<Mutex> {
    const size_t lines_to_save = 100;

public:
    size_t msg_counter() {
        std::lock_guard<Mutex> lock(base_sink<Mutex>::mutex_);
        return msg_counter_;
    }

    size_t flush_counter() {
        std::lock_guard<Mutex> lock(base_sink<Mutex>::mutex_);
        return flush_counter_;
    }

    void set_delay(std::chrono::milliseconds delay) {
        std::lock_guard<Mutex> lock(base_sink<Mutex>::mutex_);
        delay_ = delay;
    }

    // return last output without the eol
    std::vector<std::string> lines() {
        std::lock_guard<Mutex> lock(base_sink<Mutex>::mutex_);
        return lines_;
    }

protected:
    void sink_it_(const details::log_msg &msg) override {
        memory_buf_t formatted;
        base_sink<Mutex>::formatter_->format(msg, formatted);
        // save the line without the eol
        auto eol_len = strlen(details::os::default_eol);
        if (lines_.size() < lines_to_save) {
            lines_.emplace_back(formatted.begin(), formatted.end() - eol_len);
        }
        msg_counter_++;
        std::this_thread::sleep_for(delay_);
    }

    void flush_() override { flush_counter_++; }

    size_t msg_counter_{0};
    size_t flush_counter_{0};
    std::chrono::milliseconds delay_{std::chrono::milliseconds::zero()};
    std::vector<std::string> lines_;
=======
template<class Mutex>
class test_sink : public base_sink<Mutex>
{
public:
    size_t msg_counter()
    {
        return msg_counter_;
    }

    size_t flushed_msg_counter()
    {
        return flushed_msg_counter_;
    }

protected:
    void _sink_it(const details::log_msg &) override
    {
        msg_counter_++;
    }

    void _flush() override
    {
        flushed_msg_counter_ += msg_counter_;
    }
    size_t msg_counter_{0};
    size_t flushed_msg_counter_{0};
>>>>>>> dea6bb1085466370ed6d629b4d462f299db75958
};

using test_sink_mt = test_sink<std::mutex>;
using test_sink_st = test_sink<details::null_mutex>;

<<<<<<< HEAD
}  // namespace sinks
}  // namespace spdlog
=======
} // namespace sinks
} // namespace spdlog
>>>>>>> dea6bb1085466370ed6d629b4d462f299db75958
