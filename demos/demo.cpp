/**
 * @file
 * @brief Demo on how to use the SignalHandler class.
 * @copyright 2020, Max Planck Gesellschaft.  All rights reserved.
 * @license BSD 3-clause
 */
#include <iostream>
#include <signal_handler/signal_handler.hpp>

int main()
{
    // Initialize the signal handler (can safely be called multiple times, e.g.
    // in different modules).
    signal_handler::SignalHandler::initialize();

    std::cout << "Press Ctrl+C to send SIGINT" << std::endl;
    while (true)
    {
        // has_received_sigint() returns true if a SIGINT was received since
        // initialize() was called.
        if (signal_handler::SignalHandler::has_received_sigint())
        {
            std::cout << "Received SIGINT" << std::endl;
            break;
        }
    }

    return 0;
}
