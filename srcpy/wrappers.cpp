#include <pybind11/pybind11.h>
#include <signal_handler/signal_handler.hpp>

PYBIND11_MODULE(signal_handler_wrp, m)
{
    m.def("init", []() { signal_handler::SignalHandler::initialize(); });

    m.def("has_received_sigint", []() {
        return signal_handler::SignalHandler::has_received_sigint();
    });
}
