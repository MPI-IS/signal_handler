signal_handler - Utilities for C++ signal handling
--------------------------------------------------

This package provides the static ``SignalHandler`` class which registers a
signal handler for SIGINT and provides a method to check whether the signal was
received.

**Important:** In C++ only one handler can be registered for a specific signal.
This means if two modules of the software both try to register a handler for
SIGINT, the second one will silently overwrite the handler of the first one,
i.e. only the handler of the second module will actually be executed when the
signal is received.

The ``SignalHandler`` class of this package is supposed to solve this issue by
providing a globally accessible method to register a handler and check if the
signal was received.  When all modules of the software use this class, there is
no conflict because only one handler will be registered and all modules will use
the same static method to check the status.


### Usage Example

See the [demo](demos/demo.cpp).


### Copyright

Copyright (c) 2020 Max Planck Gesellschaft

### License

BSD 3-Clause License, see [LICENSE](LICENSE)
