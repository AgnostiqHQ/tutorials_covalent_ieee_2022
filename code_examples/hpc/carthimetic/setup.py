from distutils.core import setup, Extension

carthimetic_module = Extension('carthimetic', sources=['main.c'], extra_compile_args=['-O2', '-mavx'])

setup(name = 'carthimetic',
    version='0.1.0',
    author = 'venkat Bala',
    author_email="venkat@agnostiq.ai",
    ext_modules=[carthimetic_module])