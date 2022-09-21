#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>

using dvec = std::vector<double>;

dvec vecadd(const dvec& a, const dvec& b) {
    dvec c;
    std::transform(a.begin(), a.end(), b.begin(), std::back_inserter(c), std::plus<double>());
    return c;
}

dvec vecmul(const dvec& a, const dvec& b) {
    dvec c;
    std::transform(a.begin(), a.end(), b.begin(), std::back_inserter(c), std::multiplies<double>());
    return c;
}

dvec vecdiv(const dvec& a, const dvec& b) {
    dvec c;
    std::transform(a.begin(), a.end(), b.begin(), std::back_inserter(c), std::divides<double>());
    return c;
}

PYBIND11_MODULE(cpparthimetic, m) {
    m.def("vecadd", &vecadd, "Add two python lists");
    m.def("vecmul", &vecmul, "Multiply two python lists");
    m.def("vecdiv", &vecdiv, "Divide two python lists elementwise");
}