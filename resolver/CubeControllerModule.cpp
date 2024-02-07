#include <boost/python.hpp>
#include "CubeController.hpp"

BOOST_PYTHON_MODULE(cube_controller) {
    using namespace boost::python;
    class_<CubeController, boost::noncopyable>("CubeController", no_init)
        .def("sendMove", &CubeController::sendMove);
}
