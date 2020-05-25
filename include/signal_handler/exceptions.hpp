/**
 * @file
 * @brief Exceptions related to signal handling.
 * @copyright 2020, Max Planck Gesellschaft.  All rights reserved.
 * @license BSD 3-clause
 */
#pragma once
#include <exception>
#include <string>

namespace signal_handler
{
class ReceivedSignal : public std::exception
{
public:
    ReceivedSignal(int signal);

    static std::string signal_name(int signal);

    const char* what() const noexcept;

private:
    const std::string message_;
};

}  // namespace signal_handler
