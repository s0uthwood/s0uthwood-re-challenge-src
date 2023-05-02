from distutils.core import setup
from Cython.Build import cythonize
setup(ext_modules=cythonize("chall.py")) # 这里填写的就是你的参数，注意在同一目录下