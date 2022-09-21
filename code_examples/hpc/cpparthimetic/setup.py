from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext

cpparthimetic_module = Pybind11Extension('cpparthimetic', sources=['main.cc'])

setup(name = 'cpparthimetic',
    version='0.1.0',
    author = 'venkat Bala',
    author_email="venkat@agnostiq.ai",
    cmdclass={"build_ext": build_ext},
    ext_modules=[cpparthimetic_module])