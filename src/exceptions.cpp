/**
 * @file
 * @brief Exceptions related to signal handling.
 * @copyright 2020, Max Planck Gesellschaft.  All rights reserved.
 * @license BSD 3-clause
 */
#include <signal_handler/exceptions.hpp>

#include <csignal>

namespace signal_handler
{
ReceivedSignal::ReceivedSignal(int signal)
    : message_("Received signal " + signal_name(signal))
{
}

std::string ReceivedSignal::signal_name(int signal)
{
    switch (signal)
    {
        case SIGINT:
            return "SIGINT";
        default:
            // in default case, simply convert the number to string
            return std::to_string(signal);
    }
}

const char* ReceivedSignal::what() const noexcept
{
    return message_.c_str();
}

}  // namespace signal_handler
