from setuptools import setup, Extension, find_packages
from Cython.Build import cythonize

setup(
    name="orchestra",
    version="0.1.dev0",
    ext_modules = cythonize([
        Extension("orchpy/context",
          sources = ["orchpy/context.pyx"], libraries=["orchlib"],
          library_dirs=['../orchlib/'])]), 
    packages=find_packages()
)
