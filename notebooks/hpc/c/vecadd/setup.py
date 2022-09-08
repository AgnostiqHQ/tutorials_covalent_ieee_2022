from distutils.core import setup, Extension

vecadd_module = Extension('_vecadd', sources=['vecadd_wrap.c', 'vecadd.c'])


setup(name = 'vecadd',
    version='0.1',
    author = 'venkat Bala',
    ext_modules = [vecadd_module],
    py_modules = ["vecadd"])