#include <boost/signals2.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/noncopyable.hpp> // Include this

class CubeController : public boost::noncopyable { // Indicate non-copyability here
public:
    boost::signals2::signal<void(char)> moveSignal;

    void sendMove(char move) {
        moveSignal(move);
    }
};