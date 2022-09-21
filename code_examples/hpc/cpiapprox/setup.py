from distutils.core import setup, Extension

cpiapprox = Extension('cpiapprox', sources=['main.c'],
extra_compile_args=["-O3"])

setup(name='cpiapprox', version='1.0',
    description='A approximation to PI',ext_modules=[cpiapprox])