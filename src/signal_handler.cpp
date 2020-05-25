/**
 * @file
 * @copyright 2020, Max Planck Gesellschaft.  All rights reserved.
 * @license BSD 3-clause
 */
#include <signal_handler/signal_handler.hpp>

#include <atomic>
#include <csignal>

namespace signal_handler
{
std::sig_atomic_t SignalHandler::received_sigint_ = 0;

void SignalHandler::initialize()
{
    static std::atomic<bool> is_initialized(false);

    if (!is_initialized)
    {
        is_initialized = true;

        received_sigint_ = 0;

        struct sigaction signal_action;
        signal_action.sa_handler = SignalHandler::signal_handler;
        sigemptyset(&signal_action.sa_mask);
        signal_action.sa_flags = 0;
        sigaction(SIGINT, &signal_action, nullptr);
    }
}

void SignalHandler::signal_handler(int signal)
{
    if (signal == SIGINT)
    {
        received_sigint_ = 1;
    }
}

bool SignalHandler::has_received_sigint()
{
    return received_sigint_ != 0;
}

}  // namespace signal_handler
